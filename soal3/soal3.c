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

void makeFile(char* args) // MAKING KILLER FILE!
{
  int i;
  FILE *fp; //file pointer

  if(strcmp(args, "-z") == 0) // DIRECTLY KILL THE FUCKING PROGRAM A.K.A. SIGKILL
  {
    fp = fopen("KILLTHEMALL.sh", "w"); //w -> write
    char str[] = "killall -SIGKILL soal22; rm KILLTHEMALL.sh;\n";
    for (i = 0; str[i] != '\n'; i++)
    {
      /* write to file using fputc() function */
      fputc(str[i], fp);
    }
    fclose(fp);
  }
  else if(strcmp(args, "-x") == 0) // SIGSTOP
  {
    fp = fopen("KILLTHEMALL.sh", "w"); //w -> write
    char str[] = "killall -SIGCHLD soal22; rm KILLTHEMALL.sh;\n";
    for (i = 0; str[i] != '\n'; i++)
    {
      /* write to file using fputc() function */
      fputc(str[i], fp);
    }
    fclose(fp);
  }
  else // WRONG ARGS
  {
    printf("MODE not found. Please try again.\n");
    exit(EXIT_FAILURE);
  }

  pid_t anjay;
  anjay = fork();
  if (anjay < 0)
  {
    exit(EXIT_FAILURE);
  }
  if (anjay == 0)
  {
    char *chmod[4] = {"chmod", "+x", "KILLTHEMALL.sh", NULL};
    execv("/bin/chmod", chmod);
  }
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

  if(argc > 2) // if user enter too many arguments
  {
    printf("Too much arguments! Try running the program again.\n");
    exit(EXIT_FAILURE);
  }

  char args[5];

  strcpy(args, argv[1]);

  makeFile(args);

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

  while (1)
  {
    pid_t child_proc;
    child_proc = fork();

    time_t n = time(NULL); // getting local time
    long int ukurangambar = (n % 1000) + 50;
    struct tm tm = *localtime(&n);
    char datestr[50];
    sprintf(datestr, "%d-%02d-%02d_%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    char lokasidownload[100]; //lokasi download
    strcpy(lokasidownload, cwd);
    strcat(lokasidownload, "/");
    strcat(lokasidownload, datestr);

    char linkdownload[100]; //link download
    strcpy(linkdownload, "https://picsum.photos/");
    char ukurangambarstr[50];
    sprintf(ukurangambarstr, "%ld", ukurangambar);
    strcat(linkdownload, ukurangambarstr);

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
            //char *wget[7] = {"wget", "-P", lokasidownload, "-O", namafile, linkdownload, NULL};
            char *wget[] = {"wget", "-O", namafile, linkdownload, NULL};
            chdir (lokasidownload);
            execl("/usr/bin/wget", "wget", "-O", namafile, linkdownload, NULL);
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