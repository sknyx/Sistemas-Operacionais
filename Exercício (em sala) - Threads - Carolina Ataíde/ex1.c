
/**
Disciplina: sistemas Operacionais 
Nome: Carolina Ataíde de Assis
Data: 15/09/2017
**/
#include <pthread.h>
#include <stdio.h>
#define NUMBER_OF_THREADS 10

void *PrintHello(void *threadid)
{
   int tid;
   tid = (int)threadid;
   printf("Hello World! Processo: #%ld!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUMBER_OF_THREADS];
   int rc;
   int t;
   for(t=0; t<NUMBER_OF_THREADS; t++){
      printf("Criando a thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   pthread_exit(NULL);
}

