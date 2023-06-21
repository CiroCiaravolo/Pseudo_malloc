#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pseudo_malloc.h"
#include "buddyAllocator.h"


/*
void *pseudo_malloc(size_t size){

     //small allocation quindi uso buddy allocator con bitmap
    if (size<SMALL_ALLOC_SIZE)
   
    {
        int blockSize=SMALL_ALLOC_SIZE;
        int index=0;
        while (blockSize<size)
        {
          blockSize<<=1;  //raddoppio il blocksize
          index++;
        }

           int blockCount=SMALL_ALLOC_BITMAP_SIZE /blockSize;
           int blockOffset=-1;
           for (int i = 0; i < blockCount; i++)
           {
                if(BuddyAllocator.bitmap[i]==0xFF)
                continue;   //quando tutti i blocchi di questo gruppo sono allocati
           }
           
        
    }

 
    
}
*/