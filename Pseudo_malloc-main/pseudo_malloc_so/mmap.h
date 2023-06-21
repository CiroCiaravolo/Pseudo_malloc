#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


#define PAGE_SIZE 4096  // Dimensione di una pagina in byte
#define BUDDY_SIZE (1 << 20)  // Dimensione del buddy allocator in byte (1 MB)
#define MIN_ALLOC_SIZE (PAGE_SIZE / 4)  // Dimensione minima per l'allocazione buddy

static uint8_t buddy_bitmap[BUDDY_SIZE / PAGE_SIZE];  // Bitmap per il buddy allocator
static void *mmap_allocations[BUDDY_SIZE / PAGE_SIZE];  // Array per le allocazioni mmap
static size_t mmap_count = 0;  // Conteggio delle allocazioni mmap

void *mmap_alloc(size_t size);