#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
        void sigint_handler(int sig);
        void sigtstp_handler(int sig);
        void sigquit_handler(int sig);
        int anak;
        int pipefds[2];
        char buffer[50];
        char s[50];

        // Signal Handler
        if (signal(SIGINT, sigint_handler) == SIG_ERR){
                perror("signal SIGINT");
                exit(1);
        }
        else if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR){
                perror("signal SIGTSTP");
                exit(1);
        }
        else if (signal(SIGQUIT, sigquit_handler) == SIG_ERR){
                perror("signal SIGQUIT");
                exit(1);
        }


        // Pipe Check
        if(pipe(pipefds) == -1){
                perror("Pipe Error!!!");
                exit(EXIT_FAILURE);
        }


        // Parent Input Message
        printf("Enter a message for parent process:");

        // Parent Input Check
        if (fgets(s, sizeof(s), stdin) == NULL){
                perror("Parent input error!!!");
        }
        else {
                s[strcspn(s, "\n")] = '\0';
                printf("You entered: %s\n\n", s);
        }


        // How Many Looping Input
        printf("Enter how many child you want? : ");
        scanf("%d", &anak);
        
        // How Many Looping Input Check
        if (anak < 1){
                perror("Looping input error!!!");
        }
        else {
                printf("You entered: %d\n\n", anak);
        }


        // Pipe Write
        printf("Passing message to child...\n");
        write(pipefds[1], &s, sizeof(s));
        printf("Done.\n\n");

        // Pipe Read
        printf("Child receiving message from parent...\n");
        read(pipefds[0], &buffer, sizeof(buffer));
        printf("Done.\n\n");


        // Fork Looping
        for(int i = 0; i <("%d", anak) ; i++) {
                pid_t pid = fork();


                if(pid == 0) {
                        printf("This child receive '%s' from parent\n", buffer);
                        exit(0);
                }
                else {
                        printf("Waiting for child processes to finish...\n");
                        wait(NULL);
                        close(pipefds[1]);
                        close(pipefds[0]);
                        printf("child process finished.\n\n");
                }
        }
}

// Ctrl+C Signal Handler Message
void sigint_handler(int sig)
{
        printf("Ctrl + C Captured \n");
}

// Ctrl+Z Signal Handler Message
void sigtstp_handler(int sig)
{
        printf("Ctrl + Z Captured \n");
}

// Ctrl+Backspace Signal Handler Message
void sigquit_handler(int sig)
{
        printf("Ctrl + Backspace Captured \n");
}
