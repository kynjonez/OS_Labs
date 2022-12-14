/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

//****

COPY YOUR SIGNAL.C INTO THIS FILE

UPDATE YOUR MAKEFILE

*******/

bool signaled = true;
int alarms;
time_t start, end; 

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarms++;
  signaled = false;
  alarm(1);
}

void handler_2 (int signum)
{ 
  time(&ending);
  double elapsed = difftime(end, start);
  
  print("\nAlarms: %d, Duration: %fs\n", alarms, elapsed)
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  signal(SIGINT, handler_2);
  
  alarm(1); //Schedule a SIGALRM for 1 second
  
  time(&start);
  while (1) 
  {
    signaled = true;
    while(signaled); //busy wait for signal to be delivered
    printf("Turing was right!\n");
  };

  return 0; //never reached
}