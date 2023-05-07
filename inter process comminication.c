#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MSG_SIZE 50

int main() {
  int fd[2];
  pid_t pid;
  char message[MSG_SIZE];
  
  if (pipe(fd) == -1) { // create a pipe
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  
  pid = fork(); // create a child process
  
  if (pid == -1) { // fork failed
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { // child process
    close(fd[1]); // close the write end of the pipe
    
    while (read(fd[0], message, MSG_SIZE) > 0) { // read messages from the pipe
      printf("Received message: %s\n", message);
    }
    
    close(fd[0]); // close the read end of the pipe
    exit(EXIT_SUCCESS);
  } else { // parent process
    close(fd[0]); // close the read end of the pipe
    
    strcpy(message, "Hello, child process!"); // create a message to send
    
    if (write(fd[1], message, strlen(message)+1) == -1) { // write the message to the pipe
      perror("write");
      exit(EXIT_FAILURE);
    }
    
    close(fd[1]); // close the write end of the pipe
    wait(NULL); // wait for the child process to terminate
    exit(EXIT_SUCCESS);
  }
}
