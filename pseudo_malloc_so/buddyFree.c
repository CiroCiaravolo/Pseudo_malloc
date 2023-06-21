#include "buddyFree.h"
static uint8_t buddy_bitmap[BUDDY_SIZE / PAGE_SIZE];
static void *mmap_allocations[BUDDY_SIZE / PAGE_SIZE];
static size_t mmap_count = 0;




void buddy_free(void *ptr) {
    // Trova la posizione di memoria nel bitmap corrispondente al puntatore fornito
     size_t index = (size_t)ptr / MIN_ALLOC_SIZE;
    size_t buddy_size = MIN_ALLOC_SIZE;
    size_t buddy_index = index;

    while (buddy_index < sizeof(buddy_bitmap) * 8 && (buddy_bitmap[buddy_index / 8] & (1 << (buddy_index % 8))))
    {
        buddy_size *= 2;
        buddy_index++;
    }

    while (buddy_index < sizeof(buddy_bitmap) * 8 && buddy_size > MIN_ALLOC_SIZE && (buddy_bitmap[buddy_index / 8] & (1 << (buddy_index % 8))))
    {
        buddy_bitmap[buddy_index / 8] &= ~(1 << (buddy_index % 8));
        buddy_size /= 2;
        buddy_index--;
    }

   
    // e imposta quel bit a 0 per indicare che la memoria è stata liberata
     buddy_bitmap[buddy_index / 8] &= ~(1 << (buddy_index % 8));

}