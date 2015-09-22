#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


#define WORKING_THREADS_COUNT 3

void *work(void *p) {
  int* param = (int*) p;
  *param++;
   printf("WORKER %d has value %d\n", (int) pthread_self(), *param);
}

int main() {
   pthread_t workingThreads[WORKING_THREADS_COUNT];
   int param = 15;

  for (int i = 0; i < WORKING_THREADS_COUNT; ++i) {
       pthread_create(&workingThreads[i], NULL, work, &param);
   }
   sleep(3);


  }
