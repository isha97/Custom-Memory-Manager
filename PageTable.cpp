#include <time.h>
#include<stdio.h>
class PageTable
  {
  public:
  PageTable (double a, double b): frameno (a), pageno (b) {}
  private:
  int frameno; // Real Part
  int pageno; // PageTable Part
  };

int main(int argc, char* argv[])
  {
  clock_t tStart = clock();
  PageTable* array[1000];
  for (int i = 0;i  < 6000; i++) {
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
