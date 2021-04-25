# soal-shift-sisop-modul-2-IT09-2021

Nama Anggota | NRP
------------------- | --------------		
Daniel Evan | 05311940000016
Natasya Abygail N | 05111940000020
Muhammad Naufal Imantyasto | 05111940000041

## List of Contents :
- [No 1](#Cara-Pengerjaan)
	- [1a](#1A)
	- [1b](#1B)
	- [1c](#1C)
	- [1d](#1D)
	- [1e](#1E)
	- [1f](#1F)
- [No 2](#Cara-Pengerjaan)
	- [2a](#2A)
	- [2b](#2B)
	- [2c](#2C)
	- [2d](#2D)
	- [2e](#2E)
- [No 3](#Cara-Pengerjaan)
	- [3a](#3A)
	- [3b](#3B)
	- [3c](#3C)
	- [3d](#3D)
	- [3e](#3E)


## Nomor 1 :
### Soal :
(a) Menamai folder dengan Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg. <br/>
(b) Mendownload file dari link yang tersedia.<br/>
(c) Extract zip setelah download<br/>
(d) Memindahkan file ke dalam folder yang telah dibuat.<br/>
(e) Poin a-d berjalan otomatis 6 jam sebelum waktu ulang tahun Stevany. <br/>
(f) Pada waktu ulang tahunnya Stevany, semua folder akan di zip dengan nama Lopyu_Stevany.zip dan semua folder akan di delete.<br/>

### Source Code :
Berikut adalah source code yang kami buat :
```C
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
### Cara Pengerjaan :
#### Library yang kami gunakan <br/> 
```C
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
```
Meng-include beberapa library yang dibutuhkan untuk program yang dibuat.

#### Inisialiasi variabel
``` C
pid_t pid, sid;     
char date[100]; 
time_t rawDate;
struct tm *localDate;
int status;
pid_t cid = fork();
pid = fork();
```
<br/> Menginisialisasi varibel yang dibutuhkan dengan typedata yang sesuai.

#### 1A
Membuat directory Pyoto
``` C
if (cid == 0) {
    char *argv[] = {"mkdir", "-p", "Pyoto", NULL};
    execv("/bin/mkdir", argv);    
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk membuat sebuah direktori bernama Pyoto. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Membuat directory Musyik
``` C
else 
{
    cid = fork();
    if (cid == 0) {
    char *argv[] = {"mkdir", "-p", "Musyik", NULL};
    execv("/bin/mkdir", argv);                  
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk membuat sebuah direktori bernama Musyik. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Membuat directory Fylm
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {                    
    char *argv[] = {"mkdir", "-p", "Fylm", NULL};
    execv("/bin/mkdir", argv);           
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk membuat sebuah direktori bernama Fylm. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

#### 1B

Mendownload Zip Foto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", argv);                   
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk men-download sebuah file "Foto_for_Stevany.zip" dari link yang sudah disiapkan. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Mendownload Zip Musik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};                    
    execv("/usr/bin/wget", argv);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk men-download sebuah file "Musik_for_Stevany.zip" dari link yang sudah disiapkan. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Mendownload Zip Film
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};                    
    execv("/usr/bin/wget", argv);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk men-download sebuah file "Film_for_Stevany.zip" dari link yang sudah disiapkan. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

#### 1C

Unzip Foto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk meng-unzip file "Foto_for_Stevany.zip" yang telah didownload. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Unzip Musik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Musik_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```

Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk meng-unzip file "Musik_for_Stevany.zip" yang telah didownload. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Unzip Film
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```

Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk meng-unzip file "Film_for_Stevany.zip" yang telah didownload. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

#### 1D

Memindah Foto ke Pyoto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "FOTO", "Pyoto", NULL};
    execv("/bin/mv", argv); 
}

```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk memindahkan direktori FOTO(hasil unzip) ke direktori Pyoto. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Memindah Musik ke Musyik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "MUSIK", "Musyik", NULL};
    execv("/bin/mv", argv); 
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk memindahkan direktori MUSIK(hasil unzip) ke direktori Musyik. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Memindah Film ke Fylm
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "FILM", "Fylm", NULL};
    execv("/bin/mv", argv);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk memindahkan direktori FILM(hasil unzip) ke direktori Fylm. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

<br/> Setelah fungsi ini kami menambahkan break untuk menghentikan loop yang pertama.

#### 1E

Membandingkan waktu untuk menjalankan program sesuai jadwal yang ditentukan.
``` C
rawDate = time(NULL);
localDate = localtime(&rawDate);
strftime(date, 50, "%Y-%m-%d %H:%M:%S", localDate);
```
<br/> Pada command ini kami membandingkan waktu dengan cara menginisialisasi localtime (waktu saat ini) terlebih dahulu, dan membuat format date menggunakan fungsi `strftime`.
``` C
if(strcmp(date,"2021-04-09 16:22:00") == 0)
```

Kemudian localtime akan dicompare dengan waktu-waktu lain yang diperlukan menggunakan fungsi `strcmp`. Pada command dibawah, localtime cdi compare dengan H-6 Jam ulang tahun stevanny untuk melakukan beberapa perintah pada program,sesuai soal.
``` C
if(strcmp(date,"2021-04-09 22:22:00") == 0)
```
Sedangkan fungsi `strcmp` dibawah,digunakan untuk meng-compare localtime dengan waktu tepat saat ulang tahun stevanny. 

#### 1F

Zip Pyoto, Musyik, Fylm ke Lopyu_Stevany.zip
``` C
if (cid == 0) {
    char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Pyoto", "Musyik", "Fylm", NULL};
    execv("/usr/bin/zip", argv);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk men-zip seluruh direktori yang telah dipindahkan tadi(Pyoto, Musyikm, Fylm) dengan format nama file zipnya adalah "Loypu_Stevany.zip". Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Menghapus Folder yang tidak perlu
``` C
else{

while ((wait(&status)) > 0);
cid = fork();
if (cid == 0) {
    char *argv[] = {"rm", "-r", "FILM", "FOTO", "MUSIK", "Pyoto", "Fylm", "Musyik", NULL};
    execv("/bin/rm", argv);
}
while(wait(NULL) != cid);
}
```
Pada command ini, dilakukan `fork()` yang didalamnya terdapat suatu array `argv` yang memiliki fungsi untuk menghapus seluruh direktori(FILM, FOTO, MUSIK, Pyoto, Fylm, Musyik) beserta isinya. Dan nantinya akan dieksekusi menggunakan fungsi `exec`.

Setelah fungsi ini kami menambahkan break untuk menghentikan loop yang kedua.

### Kendala :
Pertama-tama kami mencoba untuk menulis program secara langsung (tidak menggunakan daemon) sebagai berikut :
``` C
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
```
Namun terjadi kendala pada fungsi waktu yang tidak berjalan, sehingga kami membuat dalam setiap percabangan variabel seconds dan seconds2 kurang dari 0, dimana seharusnya sama dengan 0. 

## Nomor 2 :
### Soal :
(a) Mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan. <br/>
(b)Foto peliharaan dikategorikan sesuai jenis peliharaan, untuk setiap jenis peliharaan dibuat 1 folder tersendiri. <br/>
(c)Program akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan. <br/>
(d)Dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai.
(e)Pada setiap folder dibuat sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut.

### Source Code :
``` C
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <wait.h>
#include <time.h>

void ganti(char *lokasi, char *file, char *nama);
void pindah(char *lokasi, char *file, char *nama)
{
  int status;

  pid_t child2 = fork();
  if (child2 == 0)
  {
    char *argv[] = {"mkdir", "-p", lokasi, NULL};
    execv("/bin/mkdir", argv);
  }
  while ((waitpid(child2, &status, 0)) > 0)
    ;
  pid_t child3 = fork();

  if (child3 == 0)
  {
    char nick[100];
    char petname[100];
    char umur[100];
    char ket[100];

    strcpy(nick, nama);
    char delim[] = ";";
    char *ptr = strtok(nick, delim);
    int id = 1;

    while (ptr != NULL)
    {
      if (id == 2)
      {
        sprintf(petname, "%s", ptr);
      }
      if (id == 3)
      {
        sprintf(umur, "%s", ptr);
        strtok(umur, "_");
        strtok(umur, "j");
        if (umur[strlen(umur) - 1] == '.')
        {
          umur[strlen(umur) - 1] = '\0';
        }
      }
      ptr = strtok(NULL, delim);
      id++;
    }

    char loc[100];
    strcpy(ket, lokasi);
    strcpy(loc, lokasi);
    strcat(loc, "/");
    strcat(loc, petname);
    strcat(loc, ".jpg");

    FILE *fptr;
    char st[100];
    char fname[50];
    strcpy(fname, lokasi);
    strcat(fname, "/keterangan.txt");
    fptr = fopen(fname, "a+");

    fprintf(fptr, "nama : %s\n", petname);
    fprintf(fptr, "umur : %s tahun\n\n", umur);

    fclose(fptr);

    char *argv[] = {"mv", file, loc, NULL};
    execv("/bin/mv", argv);
  }
}
void copy(char *src, char *dest, char *lokasi, char *nama)
{
  int status;
  pid_t child = fork();
  if (child == 0)
  {
    char *argv[] = {"cp", src, dest, NULL};
    execv("/bin/cp", argv);
  }

  while ((waitpid(child, &status, 0)) > 0);
  pid_t child2 = fork();
  if (child2 == 0)
  {
    char *argv[] = {"mkdir", "-p", lokasi, NULL};
    execv("/bin/mkdir", argv);
  }
  while ((waitpid(child2, &status, 0)) > 0)
    ;
  pid_t child3 = fork();

  if (child3 == 0)
  {
    char nick[100];
    char petname[100];
    char umur[100];
    char ket[100];

    strcpy(nick, nama);
    char delim[] = ";";
    char *ptr = strtok(nick, delim);
    int id = 1;

    while (ptr != NULL)
    {
      if (id == 2)
      {
        sprintf(petname, "%s", ptr);
      }
      if (id == 3)
      {
        sprintf(umur, "%s", ptr);
        strtok(umur, "_");
        strtok(umur, "j");
        if (umur[strlen(umur) - 1] == '.')
        {
          umur[strlen(umur) - 1] = '\0';
        }
      }
      ptr = strtok(NULL, delim);
      id++;
    }

    char loc[100];
    strcpy(ket, lokasi);
    strcpy(loc, lokasi);
    strcat(loc, "/");
    strcat(loc, petname);
    strcat(loc, ".jpg");

    FILE *fptr;
    char st[100];
    char fname[50];
    strcpy(fname, lokasi);
    strcat(fname, "/keterangan.txt");
    fptr = fopen(fname, "a+");

    fprintf(fptr, "nama : %s\n", petname);
    fprintf(fptr, "umur : %s tahun\n\n", umur);

    fclose(fptr);

    char *argv[] = {"mv", dest, loc, NULL};
    execv("/bin/mv", argv);
  }
}

int main()
{
  pid_t child, child1, child2, child3, child4, child5, child6;
  int status;
  child = fork();
  if (child == 0)
  {
    char *argv[] = {"unzip", "/home/daniel/Documents/shift2/soal2/pets.zip", "-d",
                    "/home/daniel/Documents/shift2/soal2/petshop", NULL};
    execv("/usr/bin/unzip", argv);
  }
  while ((waitpid(child, &status, 0)) > 0)
    ;
  child1 = fork();
  if (child1 == 0)
  {
    char *argv[] = {"find", "/home/daniel/Documents/shift2/soal2/petshop", "-mindepth", "1", "-type", "d", "-exec", "rm",
                    "-r", "{}", "+", NULL};
    execv("/usr/bin/find", argv);
  }

  while ((waitpid(child1, &status, 0)) > 0)
    ;
  child2 = fork();
  if (child2 == 0)
  {
    DIR *dp;
    struct dirent *ep;
    char path[] = {"/home/daniel/Documents/shift2/soal2/petshop"};

    dp = opendir(path);

    if (dp != NULL)
    {
      while ((ep = readdir(dp)))
      {
        //puts(ep->d_name);

        char str[100];

        char new[100];
        memset(str, 0, sizeof(str));
        memset(new, 0, sizeof(new));
        strcpy(str, ep->d_name);

        if (ep->d_name[0] != '.')
        {
          int i = 0;

          while (str[i] != ';')
          {
            new[i] = str[i];
            i++;
            if (str[i] == ';')
            {
              break;
            }
          }
          i = 0;
          char lokasi[100] = {"/home/daniel/Documents/shift2/soal2/petshop/"};
          char file[100] = {"/home/daniel/Documents/shift2/soal2/petshop/"};

          strcat(lokasi, new);
          strcat(file, ep->d_name);
          if (strchr(str, '_') != NULL)
          {

            char file[100];
            strcpy(file, str);
            char *file2 = strtok(file, "_");
            file2 = strtok(NULL, "_");
            char fol2[100];
            strcpy(fol2, file2);
            char *folder2 = strtok(fol2, ";");

            char src[100] = {"/home/daniel/Documents/shift2/soal2/petshop/"};
            char src2[100] = {"/home/daniel/Documents/shift2/soal2/petshop/"};
            char dest[100] = {"/home/daniel/Documents/shift2/soal2/petshop/"};
            strcat(src, str);
            strcat(dest, file2);
            strcat(src2, folder2);

            copy(src, dest, src2, file2);

          }

          pindah(lokasi, file, ep->d_name);
        }
      }

      (void)closedir(dp);
    }
    else
      perror("Couldn't open the directory");
  }
}
```

### Cara Pengerjaan :
#### Library
``` C
#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <unistd.h>

#include <string.h>

#include <dirent.h>

#include <wait.h>

#include <time.h>
```
#### 2A
``` C
child = fork();
if (child == 0)
{
	char *argv[] = {"unzip", "/home/daniel/Documents/shift2/soal2/pets.zip", "-d","/home/daniel/Documents/shift2/soal2/petshop", NULL};
	execv("/usr/bin/unzip", argv);
}
```
Fungsi diatas digunakan untuk melakukan unzip dari file pets.zip, kami menggunakan `execv` untuk melakukan unzip.
``` C
while ((waitpid(child, &status, 0)) > 0);
child1 = fork();
if (child1 == 0)
{
	char *argv[] = {"find", "/home/daniel/Documents/shift2/soal2/petshop", "-mindepth", "1", "-type", "d", "-exec", "rm","-r", "{}", "+", NULL};
	execv("/usr/bin/find", argv);
}
```
Kami menggunakan command `find` untuk menemukan directory yang tidak perlu dan menggunakan `rm` untuk menghapus directory yang tidak perlu.
#### 2B
``` C
 pid_t child2 = fork();
 if (child2 == 0)
 {
   char *argv[] = {"mkdir", "-p", lokasi, NULL};
   execv("/bin/mkdir", argv);
 }
```
Untuk membuat folder, kami menggunakan command `mkdir` yang dimasukkan ke dalam `execv`
#### 2C
``` C
void pindah(char *lokasi, char *file, char *nama)
{
  int status;

  pid_t child2 = fork();
  if (child2 == 0)
  {
    char *argv[] = {"mkdir", "-p", lokasi, NULL};
    execv("/bin/mkdir", argv);
  }
  while ((waitpid(child2, &status, 0)) > 0)
    ;
  pid_t child3 = fork();

  if (child3 == 0)
  {
    char nick[100];
    char petname[100];
    char umur[100];
    char ket[100];

    strcpy(nick, nama);
    char delim[] = ";";
    char *ptr = strtok(nick, delim);
    int id = 1;

    while (ptr != NULL)
    {
      if (id == 2)
      {
        sprintf(petname, "%s", ptr);
      }
      if (id == 3)
      {
        sprintf(umur, "%s", ptr);
        strtok(umur, "_");
        strtok(umur, "j");
        if (umur[strlen(umur) - 1] == '.')
        {
          umur[strlen(umur) - 1] = '\0';
        }
      }
      ptr = strtok(NULL, delim);
      id++;
    }

    char loc[100];
    strcpy(ket, lokasi);
    strcpy(loc, lokasi);
    strcat(loc, "/");
    strcat(loc, petname);
    strcat(loc, ".jpg");

    FILE *fptr;
    char st[100];
    char fname[50];
    strcpy(fname, lokasi);
    strcat(fname, "/keterangan.txt");
    fptr = fopen(fname, "a+");

    fprintf(fptr, "nama : %s\n", petname);
    fprintf(fptr, "umur : %s tahun\n\n", umur);

    fclose(fptr);

    char *argv[] = {"mv", file, loc, NULL};
    execv("/bin/mv", argv);
  }
}
```
Untuk memindah file sesuai dengan kategorinya kami membuat fungsi pindah dan menggunakan command `mv` dan melakukan rename dengan strcat.
#### 2D
``` C
void copy(char *src, char *dest, char *lokasi, char *nama)
{
  int status;
  pid_t child = fork();
  if (child == 0)
  {
    char *argv[] = {"cp", src, dest, NULL};
    execv("/bin/cp", argv);
  }

  while ((waitpid(child, &status, 0)) > 0)
    ;
  pid_t child2 = fork();
  if (child2 == 0)
  {
    char *argv[] = {"mkdir", "-p", lokasi, NULL};
    execv("/bin/mkdir", argv);
  }
  while ((waitpid(child2, &status, 0)) > 0)
    ;
  pid_t child3 = fork();

  if (child3 == 0)
  {
    char nick[100];
    char petname[100];
    char umur[100];
    char ket[100];

    strcpy(nick, nama);
    char delim[] = ";";
    char *ptr = strtok(nick, delim);
    int id = 1;

    while (ptr != NULL)
    {
      if (id == 2)
      {
        sprintf(petname, "%s", ptr);
      }
      if (id == 3)
      {
        sprintf(umur, "%s", ptr);
        strtok(umur, "_");
        strtok(umur, "j");
        if (umur[strlen(umur) - 1] == '.')
        {
          umur[strlen(umur) - 1] = '\0';
        }
      }
      ptr = strtok(NULL, delim);
      id++;
    }

    char loc[100];
    strcpy(ket, lokasi);
    strcpy(loc, lokasi);
    strcat(loc, "/");
    strcat(loc, petname);
    strcat(loc, ".jpg");

    FILE *fptr;
    char st[100];
    char fname[50];
    strcpy(fname, lokasi);
    strcat(fname, "/keterangan.txt");
    fptr = fopen(fname, "a+");

    fprintf(fptr, "nama : %s\n", petname);
    fprintf(fptr, "umur : %s tahun\n\n", umur);

    fclose(fptr);

    char *argv[] = {"mv", dest, loc, NULL};
    execv("/bin/mv", argv);
  }
}
```
Untuk file yang memiliki 2 atau lebih hewan kami menggunakan command `cp` untuk melakukan copy file
#### 2E
``` C
FILE *fptr;
char st[100];
char fname[50];
strcpy(fname, lokasi);
strcat(fname, "/keterangan.txt");
fptr = fopen(fname, "a+");

fprintf(fptr, "nama : %s\n", petname);
fprintf(fptr, "umur : %s tahun\n\n", umur);

fclose(fptr);
```
Berikut adalah fungsi yang kami gunakan untuk memasukkan data nama dan umur ke dalam file keterangan.txt, dengan menggunakan `fprintf` serta fungsi lainnya untuk menghandle file pada bahasa pemrograman C.

### Kendala :
Sebelum membuat code diatas kami sempat mencoba membuat code lain, namun belum bisa memasukkan file sesuai dengan kategorinya.
``` C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void makedir(){
    char *argv[] = {"mkdir", "cat", "dog", "frog", "guinea", "hamster", "iguana", "ilama", "otter", "parrot", "rabbit", "racoon", "sheep", "tiger", "betta", NULL};
    execvp("bin/unzip", argv);
    //system ("mkdir cat dog frog guinea hamster iguana ilama otter parrot rabbit racoon sheep tiger betta");
}

int main(int argc, char* argv[])
{
pid_t process_id = 0;
pid_t sid = 0;
// Create child process
process_id = fork();
// Indication of fork() failure
if (process_id < 0)
{
printf("fork failed!\n");
// Return failure in exit status
exit(1);
}
// PARENT PROCESS. Need to kill it.
if (process_id > 0)
{
printf("process_id of child process %d \n", process_id);
// return success in exit status
exit(0);
}
//unmask the file mode
umask(0);
//set new session
sid = setsid();
if(sid < 0)
{
// Return failure
exit(1);
}
// Change the current working directory to root.

while (1)
{
    pid_t id;
    system("unzip pets.zip -d pet");
    chdir ("pet");
    makedir();
}

return (0);
}
```

### Hasil Run :
Berikut adalah hasil run dari program kami <br/>
<img src="/pict/1.png" style="width:90%;height:auto"/> <br/>
<img src="/pict/2.png" style="width:90%;height:auto"/> <br/>
<img src="/pict/3.png" style="width:90%;height:auto"/> <br/>
<img src="/pict/4.png" style="width:90%;height:auto"/> <br/>
<img src="/pict/5.png" style="width:90%;height:auto"/> <br/>
<img src="/pict/6.png" style="width:90%;height:auto"/> <br/>

## Nomor 3 :
### Soal :
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.
Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].
Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.
Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan program bash.
Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dsdengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).
Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!
Note:
Tidak boleh menggunakan system() dan mkdir()
Program utama merupakan SEBUAH PROGRAM C
Wajib memuat algoritma Caesar Cipher pada program utama yang dibuat

### Source Code :
``` C
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <wait.h>

int mysignal = 1 ;

void custom_signal_x(int signum) {
    mysignal = 0 ;
}

void make_program(char b[]) {
    FILE* src = fopen("killer.sh", "w") ;
    fputs(b, src) ;
    fclose(src) ;
}

char* format_time()
{
    char* output;
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    sprintf(output, "[%d-%d-%d_%d:%d:%d]",timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return output;
}

int main(int argc,char* argv[]) //supaya dapat passing arguments
{ 
  char message[100]="Download Success", ch;
	int i;
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + 4;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + 4;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}

  if(argc == 1) // if user doesn't enter any arguments
  {
    printf("Enter the program mode! Try running the program again.\n");
    exit(EXIT_FAILURE);
  }

if (argc > 2) {
        return 0 ;
    }
    else if (argc == 2) {
        char b[80] ;
        if (!strcmp(argv[1], "-z")) {
            strcpy(b, "#!/bin/bash\nkillall -9 ./soal3\nrm $0\n") ;
            make_program(b) ;
        }
        else if (!strcmp(argv[1], "-x")) {
            strcpy(b, "#!/bin/bash\nkillall -15 ./soal3\nrm $0\n") ;
            make_program(b) ;
            signal(SIGTERM, custom_signal_x) ;
        }
        else {
            return 0 ;
        }
    }
    else {
        return 0 ;
    }

  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0)
  {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0)
  {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0)
  {
    exit(EXIT_FAILURE);
  }

  char cwd[100];
  getcwd(cwd, sizeof(cwd));

  if ((chdir("/")) < 0)
  {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (mysignal)
  {
    pid_t child_proc;
    child_proc = fork();

    time_t n = time(NULL); // getting local time
    struct tm tm = *localtime(&n);
    char datestr[50];
    sprintf(datestr, "%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    char lokasidownload[100]; //lokasi download
    strcpy(lokasidownload, cwd);
    strcat(lokasidownload, "/");
    strcat(lokasidownload, datestr);

    char linkdownload[80] = "https://picsum.photos/" ;
    int picsize = (n % 1000) + 50 ;
    char num[10] ;
    sprintf(num, "%d", picsize) ;
    strcat(linkdownload, num) ;

    char namazip[50];
    strcpy(namazip, datestr);
    strcat(namazip, ".zip");

    if(child_proc < 0)
    {
      exit(EXIT_FAILURE);
    }

    if(child_proc == 0) // Download per 5 detik & zip-> child
    {
      int i = 0;
      while(i < 10) //Download per 5 detik
      {
          pid_t download;
          download = fork();

          if(download < 0)
          {
            exit(EXIT_FAILURE);
          }

          if(download == 0)
          {
            char* namafile = format_time();
            char *wget[] = {"wget", "-q", "-O", namafile, linkdownload, NULL};
            chdir (lokasidownload);
            execv("/bin/wget", wget) ;
          }
          i++;
          sleep(5);
      }
      chdir(lokasidownload);
      FILE *fp;
      fp = fopen("status.txt", "w"); //w -> writE
      fputs(message, fp);
      fclose(fp);
      char directory[200];
      chdir(cwd);
      char *zip[6] = {"zip", "-m", "-r", namazip, datestr, NULL};
      execvp("zip", zip);
    sleep(1);
    }
    else // make new folder stiap 30s -> parent
    {

      pid_t makeDir;
        makeDir = fork();

        if(makeDir < 0)
        {
          exit(EXIT_FAILURE);
        }

        if(makeDir == 0)
        {
          char *mkdir[3] = {"mkdir", lokasidownload, NULL};

          execv("/bin/mkdir", mkdir);
        }
      
      sleep(40);
    }
  }
}
```

### Cara Pengerjaan dan Kendala :
Berikut adalah fungsi yang kami gunakan :
1. Fungsi custom signal
``` C
int mysignal = 1 ;

void custom_signal_x(int signum) {
    mysignal = 0 ;
}
```
2. Fungsi make program
``` C
void make_program(char b[]) {
    FILE* src = fopen("killer.sh", "w") ;
    fputs(b, src) ;
    fclose(src) ;
}
```
Fungsi ini digunakan untuk membuat file killer.sh yang akan digunakan untuk mematikan program yang sedang berjalan.
3. Fungsi format time
``` C
char* format_time()
{
    char* output;
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    sprintf(output, "[%d-%d-%d_%d:%d:%d]",timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    return output;
}
```
Fungsi ini digunakan untuk menyimpan waktu untuk digunakan dalam menamai file-file yang telah di download dan zip yang telah dibuat.
4. Fungsi cipher
``` C
char message[100]="Download Success", ch;
int i;

for(i = 0; message[i] != '\0'; ++i){
    ch = message[i];
    
    if(ch >= 'a' && ch <= 'z'){
        ch = ch + 5;
        
        if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
        }
        
        message[i] = ch;
    }
    else if(ch >= 'A' && ch <= 'Z'){
        ch = ch + 5;
        
        if(ch > 'Z'){
            ch = ch - 'Z' + 'A' - 1;
        }
        
        message[i] = ch;
    }
}
```
Fungsi ini digunakan untuk membuat isi dari status.txt menjadi kalimat yang sudah di enkripsi menggunakan caesar cipher dengan shift 5.
5. Membuat program killer
``` C
if(argc == 1) // if user doesn't enter any arguments
{
printf("Enter the program mode! Try running the program again.\n");
exit(EXIT_FAILURE);
}

if (argc > 2) {
    return 0 ;
}
else if (argc == 2) {
    char b[80] ;
    if (!strcmp(argv[1], "-z")) {
        strcpy(b, "#!/bin/bash\nkillall -9 ./soal3\nrm $0\n") ;
        make_program(b) ;
    }
    else if (!strcmp(argv[1], "-x")) {
        strcpy(b, "#!/bin/bash\nkillall -15 ./soal3\nrm $0\n") ;
        make_program(b) ;
        signal(SIGTERM, custom_signal_x) ;
    }
    else {
        return 0 ;
    }
}
else {
    return 0 ;
}
```
Fungsi di atas ini digunakan untuk membuat isi dari file killer.sh yang telah dibuat.
6. Mendapatkan timestamp
``` C
time_t n = time(NULL); // getting local time
struct tm tm = *localtime(&n);
char datestr[50];
sprintf(datestr, "%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
```
8. Mendapatkan lokasi download
``` C
char lokasidownload[100]; //lokasi download
strcpy(lokasidownload, cwd);
strcat(lokasidownload, "/");
strcat(lokasidownload, datestr);
```
Fungsi ini digunakan untuk membuat lokasi download dari file-file yang sudah di download akan dialokasikan dan dinamai dengan variabel datestr.
9. Mendapatkan link download
``` C
char linkdownload[80] = "https://picsum.photos/" ;
int picsize = (n % 1000) + 50 ;
char num[10] ;
sprintf(num, "%d", picsize) ;
strcat(linkdownload, num) ;
```
Fungsi ini digunakan untuk memasukkan link download ke dalam program yang akan berjalan, program akan mendownload dengan sendirinya yang menuju ke link di dalam variabel ini.
10. Memberi nama zip
``` C
char namazip[50];
strcpy(namazip, datestr);
strcat(namazip, ".zip");
```
Fungsi ini digunakan untuk memberi nama dari zip yang telah dibuat.
11. Mendownload file
``` C
while(i < 10) //Download per 5 detik
{
    pid_t download;
    download = fork();

    if(download < 0)
    {
        exit(EXIT_FAILURE);
    }

    if(download == 0)
    {
        char* namafile = format_time();
        char *wget[] = {"wget", "-q", "-O", namafile, linkdownload, NULL};
        chdir (lokasidownload);
        execv("/bin/wget", wget) ;
    }
    i++;
    sleep(5);
}
```
Fungsi ini digunakan untuk mendownload file-file dari link download yang sudah dimasukkan dan akan langsung dimasukkan ke dalam folder dengan variabel lokasidownload.
13. Memasukkan status.txt
``` C
chdir(lokasidownload);
FILE *fp;
fp = fopen("status.txt", "w"); //w -> writE
fputs(message, fp);
fclose(fp);
```
Fungsi ini digunakan untuk memasukkan isi char message ke dalam status.txt.
14. Melakukan zipping directory
``` C
char directory[200];
chdir(cwd);
char *zip[6] = {"zip", "-m", "-r", namazip, datestr, NULL};
execvp("zip", zip);
sleep(1);
```
Fungsi ini digunakan untuk melakukan zip folder dari file-file yang telah di download.
15. Membuat directory
``` C
else // make new folder stiap 40s -> parent
{

pid_t makeDir;
    makeDir = fork();

    if(makeDir < 0)
    {
    exit(EXIT_FAILURE);
    }

    if(makeDir == 0)
    {
    char *mkdir[3] = {"mkdir", lokasidownload, NULL};

    execv("/bin/mkdir", mkdir);
    }

sleep(40);
}
```
Fungsi ini digunakan untuk membuat folder agar file-file yang telah di download bisa masuk ke dalam folder yang telah dibuat sebelum di zip.
