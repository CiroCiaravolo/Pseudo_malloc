#include "buddyAllocator.h"
static uint8_t buddy_bitmap[BUDDY_SIZE / PAGE_SIZE];
static void *mmap_allocations[BUDDY_SIZE / PAGE_SIZE];
static size_t mmap_count = 0;



void *buddy_alloc(size_t size) {
    // Controlla se la dimensione richiesta è inferiore alla dimensione minima allocabile
    if (size < MIN_ALLOC_SIZE) {
        // Implementa il buddy allocator per le allocazioni piccole
         size_t alloc_size = MIN_ALLOC_SIZE;
        size_t index = 0;

        while (alloc_size < size)
        {
            alloc_size *= 2;
            index++;
        }

        size_t buddy_size = alloc_size;

        // Utilizza il bitmap per trovare una porzione di memoria disponibile
         while (index < sizeof(buddy_bitmap) * 8 && (buddy_bitmap[index / 8] & (1 << (index % 8))))
        {
            buddy_size *= 2;
            index++;
        }

        if (index >= sizeof(buddy_bitmap) * 8) {
            return NULL;  // Non c'è abbastanza memoria disponibile
        }

        size_t buddy_index = index;

        while (buddy_size > alloc_size) {
            buddy_size /= 2;
            buddy_bitmap[buddy_index / 8] |= 1 << (buddy_index % 8);
            buddy_index--;
        }

        buddy_bitmap[buddy_index / 8] |= 1 << (buddy_index % 8);

        // e restituisci il puntatore a quella posizione
         return (void *)(buddy_index * alloc_size);
     
        return NULL;  // Restituisce NULL se non c'è abbastanza memoria disponibile
    } else {
        // Richiede una dimensione più grande o uguale alla dimensione minima allocabile
         return mmap_alloc(size);
    

        return NULL;  // Restituisce NULL se l'allocazione mmap fallisce
    }
}