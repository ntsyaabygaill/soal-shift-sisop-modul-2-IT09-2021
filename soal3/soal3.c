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
