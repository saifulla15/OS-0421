#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5 // number of philosophers

pthread_mutex_t forks[N];

void *philosopher(void *arg) {
  int id = *(int *)arg;
  int left = id;
  int right = (id + 1) % N;

  while (1) {
    // think
    printf("Philosopher %d is thinking...\n", id);
    sleep(rand() % 5);

    // pick up left fork
    pthread_mutex_lock(&forks[left]);
    printf("Philosopher %d picked up left fork %d\n", id, left);

    // pick up right fork
    pthread_mutex_lock(&forks[right]);
    printf("Philosopher %d picked up right fork %d\n", id, right);

    // eat
    printf("Philosopher %d is eating...\n", id);
    sleep(rand() % 5);

    // put down right fork
    pthread_mutex_unlock(&forks[right]);
    printf("Philosopher %d put down right fork %d\n", id, right);

    // put down left fork
    pthread_mutex_unlock(&forks[left]);
    printf("Philosopher %d put down left fork %d\n", id, left);
  }
}

int main() {
  pthread_t philosophers[N];
  int ids[N];

  // initialize mutex locks
  for (int i = 0; i < N; i++) {
    pthread_mutex_init(&forks[i], NULL);
  }

  // create philosopher threads
  for (int i = 0; i < N; i++) {
    ids[i] = i;
    pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
  }

  // wait for philosopher threads to finish
  for (int i = 0; i < N; i++) {
    pthread_join(philosophers[i], NULL);
  }

  // destroy mutex locks
  for (int i = 0; i < N; i++) {
    pthread_mutex_destroy(&forks[i]);
  }

  return 0;
}
