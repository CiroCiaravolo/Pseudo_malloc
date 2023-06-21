//test e funzionamento di una pseudo malloc 
// for small requests (< 1/4 of the page size) it uses a buddy allocator
//for large request (>=1/4 of the page size) uses a mmap



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>



int main(void){
    //alcuni esempi d'uso
    printf("hello world");
    
}