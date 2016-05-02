#ifndef _MMANAGER_H_INCLUDED_
#define _MMANAGER_H_INCLUDED_
#define POOLSIZE 32
class IMemoryManager
{
    public:
    virtual void* allocate(size_t) = 0;
    virtual void   free(void*) = 0;
};
class MemoryManager: public IMemoryManager
{
    struct FreeStore
    {
        FreeStore *next;
    };
    void expandPoolSize ();
    void cleanUp ();
    FreeStore* freeStoreHead;
    public:
    MemoryManager () {
      freeStoreHead = 0;
      expandPoolSize ();
      }
    virtual ~MemoryManager () {
      cleanUp ();
      }
    virtual void* allocate(size_t);
    virtual void   free(void*);
};
inline void* MemoryManager::allocate(size_t size)
{
  if (0 == freeStoreHead)
    expandPoolSize ();

  FreeStore* head = freeStoreHead;
  freeStoreHead = head->next;
  return head;
}
inline void MemoryManager::free(void* deleted)
{
  FreeStore* head = static_cast <FreeStore*> (deleted);
  head->next = freeStoreHead;
  freeStoreHead = head;
}


void MemoryManager::cleanUp()
{
    FreeStore* nextPtr = freeStoreHead;
    for (; nextPtr; nextPtr = freeStoreHead) {
      freeStoreHead = freeStoreHead->next;
      delete [] nextPtr; // remember this was a char array
      }
}
#endif
