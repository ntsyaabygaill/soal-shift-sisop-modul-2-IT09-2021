#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <memory.h>
#include <errno.h>

int main(){
    int n1 = fork();
    int n2 = fork();
    int status;
    if (n1 == 0 && n2 == 0){
        char *argv[] = {"unzip", "pets.zip", "-d","petshop", NULL};
        execv("/bin/unzip", argv);
        //system("unzip pets.zip -d pet");
    }
    else if (n1==0 && n2>0){
        while ((wait(&status)) > 0);
        chdir ("petshop");
        pid_t child_id;
        child_id = fork();
        if (child_id < 0) {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }
        else if (child_id==0){
            char *argv[] = {"rm", "-r", "apex_cheats", "musics", "unimportant_files" , NULL};
            execv("/bin/rm", argv);
        }
        else {
            while ((wait(&status)) > 0);
            char *argv[] = {"mkdir","-p" ,"cat", "dog", "frog", "guinea", "hamster", "iguana", "ilama", "otter", "parrot", "rabbit", "racoon", "sheep", "tiger", "betta", NULL};
            execv ("bin/mkdir", argv); 
            //system ("mkdir cat dog frog guinea hamster iguana ilama otter parrot rabbit racoon sheep tiger betta");
        }
        //char *argv[] = {"mkdir", "cat", "dog", "frog", "guinea", "hamster", "iguana", "ilama", "otter", "parrot", "rabbit", "racoon", "sheep", "tiger", "betta", NULL};
        //execvp("bin/mkdir", argv);
        //system ("rm -r apex_cheats musics unimportant_files");
        //system ("mkdir cat dog frog guinea hamster iguana ilama otter parrot rabbit racoon sheep tiger betta");
    }
    //while(wait(NULL) !=-1 || errno!=ECHILD);
}