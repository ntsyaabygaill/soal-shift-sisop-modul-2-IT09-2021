#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <memory.h>

// void zipFinal(){
//     char *argv[] = {"zip", "-r" ,"Lopyu_Stevany.zip","Musyik/","Pyoto/", "Fylm", NULL};
//     execv("/bin/zip", argv);
// }
void delete(){
char *argv[] = {"rm", "-r" ,"Fylm/","Musyik/","Pyoto/",NULL};
        execv("/bin/rm", argv);
}
int main()
{
    int ret,ret2, ret3;
    time_t date1, date2, date3;

    struct tm info;
    char buffer[80];

    info.tm_year = 2001 - 1900;
    info.tm_mon = 4 - 1;
    info.tm_mday = 9;
    info.tm_hour = 16;
    info.tm_min = 22;
    info.tm_sec = 0;
    info.tm_isdst = -1;

    ret = mktime(&info);

    /*struct tm infoo;
    char buff[80];

    infoo.tm_year = 2021 - 1900;
    infoo.tm_mon = 4 - 1;
    infoo.tm_mday = 9;
    infoo.tm_hour = 22;
    infoo.tm_min = 22;
    infoo.tm_sec = 0;
    infoo.tm_isdst = -1;

    ret3 = mktime(&infoo);*/

    time_t     now;
    struct tm  ts;
    char       buf[80];

    // Get current time
    time(&now);

    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    ts = *localtime(&now);

    ret2 = mktime(&ts);

    date1 = ret;
    date2 = ret2;
    //date3 = ret3;
    double seconds = difftime(date1, date2);
    //double seconds2 = difftime(date3, date2);

    int n1 = fork();
    int n2 = fork();
    int status;
    // pid_t anjay;
    // anjay = fork();
    if (n1 == 0 && n2 == 0 && seconds < 0){
        while ((wait(&status)) > 0);

        pid_t anjes;
        anjes = fork();

        if (anjes < 0)
        {
        exit(EXIT_FAILURE);
        }
        if (anjes == 0)
        {
        char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
        execv("/bin/wget", argv);
        }
        else{
            while ((wait(&status)) > 0);
            
            pid_t anjas;
            anjas = fork();

            if (anjas < 0)
            {
            exit(EXIT_FAILURE);
            }
            if (anjas == 0)
            {
            char *argv[] = {"unzip", "Musik_for_Stevany.zip", NULL};
            execv("/bin/unzip", argv);
            }
            else{
                while ((wait(&status)) > 0);
                char *argv[] = {"mv", "MUSIK/","Musyik",NULL};
                execv("/bin/mv", argv);
            }
        }
        // system ("wget --no-check-certificate 'https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download' -O Musik_for_Stevany.zip");
        // system ("unzip Musik_for_Stevany.zip");
        // char *argv[] = {"mv", "MUSIK/","Musyik",NULL};
        // execv("/bin/mv", argv);
    }
    else if (n1 == 0 && n2 > 0 && seconds < 0){
        while ((wait(&status)) > 0);

        pid_t anjoy;
        anjoy = fork();

        if (anjoy < 0)
        {
        exit(EXIT_FAILURE);
        }
        if (anjoy == 0)
        {
        char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Photo_for_Stevany.zip", NULL};
        execv("/bin/wget", argv);
        }
        else{
            while ((wait(&status)) > 0);
            
            pid_t anjiy;
            anjiy = fork();

            if (anjiy < 0)
            {
            exit(EXIT_FAILURE);
            }
            if (anjiy == 0)
            {
            char *argv[] = {"unzip", "Photo_for_Stevany.zip", NULL};
            execv("/bin/unzip", argv);
            }
            else{
                while ((wait(&status)) > 0);
                char *argv[] = {"mv", "FOTO/","Pyoto",NULL};
                execv("/bin/mv", argv);
            }
        }
        // while ((wait(&status)) > 0);
        // system ("wget --no-check-certificate 'https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download' -O Photo_for_Stevany.zip");
        // system ("unzip Photo_for_Stevany.zip");
        // char *argv[] = {"mv", "FOTO/","Pyoto",NULL};
        // execv("/bin/mv", argv);
    }
    else if (n1 > 0 && n2 == 0 && seconds < 0){
        while ((wait(&status)) > 0);

        pid_t anjuy;
        anjuy = fork();

        if (anjuy < 0)
        {
        exit(EXIT_FAILURE);
        }
        if (anjuy == 0)
        {
        char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
        execv("/bin/wget", argv);
        }
        else{
            while ((wait(&status)) > 0);
            
            pid_t anjey;
            anjey = fork();

            if (anjey < 0)
            {
            exit(EXIT_FAILURE);
            }
            if (anjey == 0)
            {
            char *argv[] = {"unzip", "Film_for_Stevany.zip", NULL};
            execv("/bin/unzip", argv);
            }
            else{
                while ((wait(&status)) > 0);
                char *argv[] = {"mv", "FILM/","Fylm",NULL};
                execv("/bin/mv", argv);
            }
        }
        // system ("wget --no-check-certificate 'https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download' -O Film_for_Stevany.zip");
        // system ("unzip Film_for_Stevany.zip");
        // char *argv[] = {"mv", "FILM/","Fylm",NULL};
        // execv("/bin/mv", argv);
    }
    //else if (n1>0 && n2>0 && seconds2 > 0){
    else{
        while ((wait(&status)) > 0);

        pid_t anjay;
        anjay = fork();

        if (anjay < 0)
        {
        exit(EXIT_FAILURE);
        }
        if (anjay == 0)
        {
        char *argv[] = {"zip", "-r" ,"Lopyu_Stevany.zip","Musyik/","Pyoto/", "Fylm", NULL};
        execv("/bin/zip", argv);
        }
        // system ("zip -r Lopyu_Stevany.zip Musyik Pyoto Fylm");
        //rm -r Fylm/ Musyik/ Pyoto/
        // char *argv[] = {"rm", "-r" ,"Fylm/","Musyik/","Pyoto/",NULL};
        // execv("/bin/rm", argv);
        else{
            while ((wait(&status)) > 0);
            delete();
        }
    }
}
