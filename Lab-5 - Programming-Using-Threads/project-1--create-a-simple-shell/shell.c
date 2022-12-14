#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[256];
char delimiters[] = " \t\r\n";
extern char **environ;

pid_t pid;
int time = 0;

int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];
    char cmd_bak[MAX_COMMAND_LINE_LEN];
  
    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
    char *env_string
    unsigned int i;
    	
    while (true) {
      
        do{ 
            // Print the shell prompt.
            printf("%s%s", getcwd(s, 100), prompt);
            fflush(stdout);

            // Read input from stdin and store it in command_line. If there's an
            // error, exit immediately. (If you want to learn more about this line,
            // you can Google "man fgets")
        
            if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
                fprintf(stderr, "fgets error");
                exit(0);
            }
 
        }while(command_line[0] == 0x0A);  // while just ENTER pressed

      
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }

        // TODO:
        // 
        
			  // 0. Modify the prompt to print the current working directory

			
        // 1. Tokenize the command line input (split it on whitespace)
        arguments[0] = strtok(command_line, delimiters);
        i=0;
        while (arguments[i] != NULL)
        {
          i++;
          arguments[i] = strtok(NULL, delimiters);
        }
      
        // 2. Implement Built-In Commands
        if (strcmp(arguments[0], "cd") == 0) 
        {
          chdir(arguments[1]);
        }
        else if (strcmp(arguments[0], "pwd") == 0)
        {
          printf("%s\n", prompt);
        }
        else if (strcmp(arguments[0], "echo") == 0)
        {
          i=1;
          while (arguments[i] != NULL) {
            if (*arguments[i] == '$') {
              if ((env_string = getenv(arguments[i] + 1)) != NULL ) {
                printf("%s\n", env_string)
              }
            }
            else {
              printf("% ", arguments[i]);
            }
            i++;
          }
          printf("\n");
        }
        else if (strcmp(arguents[0], "exit") == 0) {
          exit(0);
        }
        else if (strcmp(arguments[0], "env") == 0) {
          if (arguments[1] != NULL) {
            if ((env_string = geetenv(arguments[1])) != NULL) {
              printf("%s\n", env_string);
            }
          }
          else if (arguments[1] == NULL) {
            i = 1;
            while (environ[i] != NULL) {
              getenv(environ[i]);
              printf("%s\n", environ[i]);
              i++;
              if (environ[i] == NULL) {
                break;
              }
            }
          }
        }
        else if (strcmp(arguments[0], "setenv") == 0) {
          arguments[1] = strtok(arguments[1], "=");
          arguments[2] = strtok(NULL, "=");

          setenv(arguments[1], arguments[2], 1);
        }
        else 
        {
          pid = fork();
          if (pid == 0) 
          {
            execvp(arguments[0], arguements);
          }
          else if (pid < 0) {
            perror("error in fork\n");
            exit(1);
          }
          else {
            wait(&status)
          }
        }
    
        // 3. Create a child process which will execute the command line input
        else 
        {
          void killer(int signum) {
            if (getpid() == 0) kill(getpid(), SIGKILL);
          }
          void timer(int signum) {
            kill(getpid(), SIGKILL);
          }
          signal(SIGINT, killer);
          signal(SIGALARM, timer);

          int status;
          pid_t pid;
          int runinbackground = strcmp(last, "&") == 0;
          pid = fork();

          if (pid < 0) print("Error: Fork Op\n");
          else if (pid == 0) {
            char cmd[10];
            strcpy(cmd, tokens[0]);
            if (runinbackground) {
              tokens[lastindex] = NULL;
            }
            alarm(10);
            status = execvp(cmd, tokens);

            if (status == -1) {
              printf("execvp() failed:NO such file or director\nAn error occured.\n");
              exit(1);
            }
          }
        }
  
        // 4. The parent process should wait for the child to complete unless its a background process
        else if (!runinbackground) {
          wait(&status);
        }
      
        // Hints (put these into Google):
        // man fork
        // man execvp
        // man wait
        // man strtok
        // man environ
        // man signals
        
        // Extra Credit
        // man dup2
        // man open
        // man pipes
    }
    // This should never be reached.
    return -1;
}