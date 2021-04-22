#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <time.h>

int main(){

    pid_t pid, sid;     
    char date[100]; 
    time_t rawDate;
    struct tm *localDate;
    int status;
    pid_t cid = fork();
    pid = fork();   

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {
        rawDate = time(NULL);
        localDate = localtime(&rawDate);
        strftime(date, 50, "%Y-%m-%d %H:%M:%S", localDate);
        if(strcmp(date,"2021-04-09 16:22:00") == 0){

            if (cid == 0) {
                char *argv[] = {"mkdir", "-p", "Pyoto", NULL};
                execv("/bin/mkdir", argv);    
            }
            else 
            {
                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"mkdir", "-p", "Musyik", NULL};
                    execv("/bin/mkdir", argv);                  
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {                    
                    char *argv[] = {"mkdir", "-p", "Fylm", NULL};
                    execv("/bin/mkdir", argv);           
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
                    execv("/usr/bin/wget", argv);                   
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};                    
                    execv("/usr/bin/wget", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};                    
                    execv("/usr/bin/wget", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"unzip", "-q", "Foto_for_Stevany.zip", NULL};
                    execv("/usr/bin/unzip", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"unzip", "-q", "Musik_for_Stevany.zip", NULL};
                    execv("/usr/bin/unzip", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
                    execv("/usr/bin/unzip", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"rm", "-r", "Pyoto", "Fylm", "Musyik", NULL};
                    execv("/bin/rm", argv);
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"mv", "FOTO", "Pyoto", NULL};
                    execv("/bin/mv", argv); 
                }

                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"mv", "MUSIK", "Musyik", NULL};
                    execv("/bin/mv", argv); 
                }
                while(wait(NULL) != cid);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"mv", "FILM", "Fylm", NULL};
                    execv("/bin/mv", argv);
                }
                while(wait(NULL) != cid);

            }
            break;
        } 
    }

    while (1) {

        rawDate = time(NULL);
        localDate = localtime(&rawDate);
        strftime(date, 50, "%Y-%m-%d %H:%M:%S", localDate);
        if(strcmp(date,"2021-04-09 22:22:00") == 0){

            cid = fork();
            if (cid == 0) {
                char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Pyoto", "Musyik", "Fylm", NULL};
                execv("/usr/bin/zip", argv);
            }
            else{

                while ((wait(&status)) > 0);

                cid = fork();
                if (cid == 0) {
                    char *argv[] = {"rm", "-r", "FILM", "FOTO", "MUSIK", "Pyoto", "Fylm", "Musyik", NULL};
                    execv("/bin/rm", argv);
                }
                while(wait(NULL) != cid);

            }
            break;
        }
    }
}
