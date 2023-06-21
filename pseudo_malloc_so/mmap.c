#include "mmap.h"




void *mmap_alloc(size_t size) {
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;  // Restituisce NULL se l'allocazione mmap fallisce
    }
    mmap_allocations[mmap_count++] = ptr;  // Salva il puntatore all'allocazione per la successiva liberazione
    return ptr;
}