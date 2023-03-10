#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// semaphore variables
sem_t room;
sem_t chopstick[5];

void *philosopher(void *);
void eat(int);
int main()
{
    int i, a[5];
    // threads
    pthread_t tid[5];
    // initialing the semaphore
    sem_init(&room, 0, 4);

    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < 5; i++)
    {
        a[i] = i; // creating threads
        pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
    }
    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);
}

// philosopher function to be run
void *philosopher(void *num)
{
    int phil = *(int *)num;

    sem_wait(&room);
    printf("\nPhilosopher %d has entered room", phil);
    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil + 1) % 5]);

    eat(phil);
    sleep(2);
    printf("\nPhilosopher %d has finished eating", phil);

    //  freeing the semaphores by calling the sem_post()
    //  we free all the semaphores
    sem_post(&chopstick[(phil + 1) % 5]);
    sem_post(&chopstick[phil]);
    sem_post(&room);
}
// Philosopher eating
void eat(int phil)
{
    printf("\nPhilosopher %d is eating", phil);
}