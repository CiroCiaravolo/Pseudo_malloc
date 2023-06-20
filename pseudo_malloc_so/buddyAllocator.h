#define PAGE_SIZE 4096 //assumiamo la grandezza di una pagina a 4096 bytes
#define SMALL_ALLOC_SIZE (PAGE_SIZE/4) //1/4 della size della pagina come da premessa
#define SMALL_ALLOC_BITMAP_SIZE (1024*1024) //1MB della bitmap



typedef struct BuddyAllocator
{
    unsigned char bitmap[SMALL_ALLOC_BITMAP_SIZE]; //bitmap per piccole allocazioni
};BuddyAllocator;


static BuddyAllocator buddyAllocator; //istanza globale buddyallocator