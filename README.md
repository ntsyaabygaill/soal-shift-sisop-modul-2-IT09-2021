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
### Cara Pengerjaan dan Kendala :
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
Namun terjadi kendala pada fungsi waktu yang tidak berjalan, sehingga kamu membuat dalam setiap percabangan variabel seconds dan seconds2 kurang dari 0, dimana seharusnya sama dengan 0. Lalu kami mencoba memasukkan code ini ke daemon, namun ubuntu yang kami gunakan mengalami freeze kemudian black screen. Sehingga kami mencoba membuat code langsung di daemon seperti diatas, dengan penjelasan masing-masing fungsi sebagai berikut :
1. Library yang kami gunakan <br/> 
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
2. Inisialiasi variabel
``` C
pid_t pid, sid;     
char date[100]; 
time_t rawDate;
struct tm *localDate;
int status;
pid_t cid = fork();
pid = fork();
```
4. Membandingkan waktu
``` C
rawDate = time(NULL);
localDate = localtime(&rawDate);
strftime(date, 50, "%Y-%m-%d %H:%M:%S", localDate);
``` 
``` C
if(strcmp(date,"2021-04-09 16:22:00") == 0)
```
``` C
if(strcmp(date,"2021-04-09 22:22:00") == 0)
```
6. Membuat directory Pyoto
``` C
if (cid == 0) {
    char *argv[] = {"mkdir", "-p", "Pyoto", NULL};
    execv("/bin/mkdir", argv);    
}
```
8. Membuat directory Musyik
``` C
else 
{
    cid = fork();
    if (cid == 0) {
    char *argv[] = {"mkdir", "-p", "Musyik", NULL};
    execv("/bin/mkdir", argv);                  
}
```
10. Membuat directory Fylm
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {                    
    char *argv[] = {"mkdir", "-p", "Fylm", NULL};
    execv("/bin/mkdir", argv);           
}
```
12. Mendownload Zip Foto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/wget", argv);                   
}
```
14. Mendownload Zip Musik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};                    
    execv("/usr/bin/wget", argv);
}
```
16. Mendownload Zip Film
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"wget","--no-check-certificate", "-q", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};                    
    execv("/usr/bin/wget", argv);
}
```
18. Unzip Foto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Foto_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```
20. Unzip Musik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Musik_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```
22. Unzip Film
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```
24. Memindah Foto ke Pyoto
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "FOTO", "Pyoto", NULL};
    execv("/bin/mv", argv); 
}

```
26. Memindah Musik ke Musyik
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "MUSIK", "Musyik", NULL};
    execv("/bin/mv", argv); 
}
```
28. Memindah Film ke Fylm
``` C
while(wait(NULL) != cid);

cid = fork();
if (cid == 0) {
    char *argv[] = {"mv", "FILM", "Fylm", NULL};
    execv("/bin/mv", argv);
}
```
Setelah fungsi ini kami menambahkan break untuk menghentikan loop yang pertama.
30. Zip Pyoto, Musyik, Fylm ke Lopyu_Stevany.zip
``` C
if (cid == 0) {
    char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Pyoto", "Musyik", "Fylm", NULL};
    execv("/usr/bin/zip", argv);
}
```
32. Menghapus Folder yang tidak perlu
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
Setelah fungsi ini kami menambahkan break untuk menghentikan loop yang kedua.

## Nomor 2 :
### Soal :
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.
Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.
Contoh: Jenis peliharaan kucing akan disimpan dalam “/petshop/cat”, jenis peliharaan kura-kura akan disimpan dalam “/petshop/turtle”.
Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
Contoh: “/petshop/cat/joni.jpg”. 
Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “dog;baro;1_cat;joni;2.jpg” dipindah ke folder “/petshop/cat/joni.jpg” dan “/petshop/dog/baro.jpg”.
Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. Format harus sesuai contoh.

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

### Cara Pengerjaan dan Kendala :

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
### Cara Pengerjaan dan Kendala :
