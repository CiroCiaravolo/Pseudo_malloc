#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>


#define PAGE_SIZE 4096  // Dimensione di una pagina in byte
#define BUDDY_SIZE (1 << 20)  // Dimensione del buddy allocator in byte (1 MB)
#define MIN_ALLOC_SIZE (PAGE_SIZE / 4)  // Dimensione minima per l'allocazione buddy



void *buddy_alloc(size_t size);