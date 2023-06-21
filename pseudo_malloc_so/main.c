//test e funzionamento di una pseudo malloc 
// for small requests (< 1/4 of the page size) it uses a buddy allocator
//for large request (>=1/4 of the page size) uses a mmap



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include "mmap.h"
#include "buddyAllocator.h"
#include "buddyFree.h"





int main(void){
    //alcuni esempi d'uso
    // Utilizza le funzioni buddy_alloc e buddy_free per allocare e liberare la memoria
    void *ptr1 = buddy_alloc(100);
    
    // Libera la memoria precedentemente allocata
    buddy_free(ptr1);
   

    return 0;
}
    
