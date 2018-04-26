#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define n_threads 200

int vet[20], vet_t[20];
int vet_pos = 1, n_random;
int interesse = 0;

void * f_thread(void* i) {

    while(vet_pos < 20){

        if(interesse == 0){ //a thread entra no bloco do if e muda o interesse para bloquear outra thread de entrar
            interesse = 1;
            n_random = rand()%100; //gera um número entre 0 e 100

            if(n_random == vet[vet_pos-1]+1){
		int tid = (int)i;
                printf("Preenchendo vetor. thread %d\n", tid);
                vet[vet_pos] = n_random;
                vet_t[vet_pos] = (int)i;
                vet_pos++;
            }
            interesse = 0;
            sleep(1);
        }
    }
    return NULL;
}

int main() {

    int i;
    pthread_t thr[n_threads];
    vet[0] =11;

    for(i = 0; i<n_threads; i++)//Criação das threads
        pthread_create(&thr[i], NULL, f_thread, (void*)i);

    for(i= 0; i<n_threads; i++)//Espera todas as threads terminarem de executar para terminar o programa
        pthread_join(thr[i], NULL);

    for(i= 0; i<20; i++)//imprime o valor do vetor e a thread que preencheu a respectiva posição
        printf("%d | %d\n", vet[i], vet_t[i]);


    return 0;
}

