#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

sem_t empty, full;
pthread_mutex_t mutex;

int buffer[BUFFER_SIZE];
int count = 0;

void *producer(void *arg) {
    int item, i = 0;
    while (i < BUFFER_SIZE) {
        item = rand() % 100; // Generate random number
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[count++] = item;
        printf("Produced item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        i++;
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item, i = 0;
    while (i < BUFFER_SIZE) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = buffer[--count];
        printf("Consumed item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        i++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tid_producer, tid_consumer;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);

    // Cleanup semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
