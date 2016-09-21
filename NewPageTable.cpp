// It uses overrode new and delete functions
#include <sys/types.h>
#include<bits/stdc++.h>
#include<time.h>
#include<stdio.h>
#include "mmanager.h"
//#define POOLSIZE 32
class PageTable
{
  public:
    PageTable (double a, double b): frameno (a), pageno (b) {}
    inline void* operator new(size_t);
    inline void   operator delete(void*);
  private:
    int frameno; // Real Part
    int pageno; // PageTable Part
  };
void MemoryManager::expandPoolSize ()
{
    size_t size = (sizeof(PageTable) > sizeof(FreeStore*)) ?
    sizeof(PageTable) : sizeof(FreeStore*);
    FreeStore* head = reinterpret_cast <FreeStore*> (new char[size]);
    freeStoreHead = head;

    for (int i = 0; i < POOLSIZE; i++) {
      head->next = reinterpret_cast <FreeStore*> (new char [size]);
      head = head->next;
    }

    head->next = 0;
}
MemoryManager gMemoryManager;


void* PageTable::operator new (size_t size)
{
  return gMemoryManager.allocate(size);
}

void PageTable::operator delete (void* pointerToDelete)
{
  gMemoryManager.free(pointerToDelete);
}
using namespace std;
int main(int argc, char* argv[])
  {
  clock_t tStart = clock();
  PageTable* array[1000];
  for (int i = 0;i  <  6000; i++) {
    for (int j = 0; j  <  1000; j++) {
      array[j] = new PageTable (i, j);
      }
    for (int j = 0; j  <  1000; j++) {
      delete array[j];
      }
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
  }
