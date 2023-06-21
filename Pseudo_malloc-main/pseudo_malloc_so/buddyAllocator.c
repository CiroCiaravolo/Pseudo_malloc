#include "buddyAllocator.h"



void *buddy_alloc(size_t size) {
    // Controlla se la dimensione richiesta è inferiore alla dimensione minima allocabile
    if (size < MIN_ALLOC_SIZE) {
        // Implementa il buddy allocator per le allocazioni piccole

        // Utilizza il bitmap per trovare una porzione di memoria disponibile

        // e restituisci il puntatore a quella posizione
     
        return NULL;  // Restituisce NULL se non c'è abbastanza memoria disponibile
    } else {
        // Richiede una dimensione più grande o uguale alla dimensione minima allocabile
        
        // Utilizza mmap per allocare la memoria richiesta e restituisci il puntatore

        return NULL;  // Restituisce NULL se l'allocazione mmap fallisce
    }
}