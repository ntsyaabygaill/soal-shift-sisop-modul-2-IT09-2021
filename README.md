# soal-shift-sisop-modul-2-IT09-2021

## Anggota Kelompok :
<br/> -. Daniel Evan (05311940000016)
<br/> -. Natasya Abygail N (05311940000020)
<br/> -. Muhammad Naufal Imantyasto (05311940000041)

## Nomor 1 :
### Soal :
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. (a) Dikarenakan Stevany sangat menyukai huruf Y, Steven ingin nama folder-foldernya adalah Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg (b) untuk musik Steven mendownloadnya dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). (c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu meng-extract-nya setelah didownload serta (d) memindahkannya ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany). (f) Setelah itu pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!
### Source Code :
Berikut adalah source code yang kami buat :
```
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
```

## Nomor 2 :
## Nomor 3 :
