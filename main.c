#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat s;
  stat("main.c", &s);
  printf("Testing stat on main.c\n\n");
  printf("File size: %d bytes\n\n", s.st_size);

  printf("File permissions (in octal): %o\n\n", s.st_mode);

  time_t time = s.st_atime;
  printf("Time of last access: %s\n", ctime(&time));

  char s1[100];
  int size = s.st_size;
  if (size > 1000) sprintf(s1, "size in B: %0.1f KB", size/1000.0);
  else if (size > 1000000) sprintf(s1, "size in KB: %0.3f MB", size/1000000.0);
  else if (size > 1000000000) sprintf(s1, "size in MB: %0.6f MGB", size/1000000000.0);
  else sprintf(s1, "Size in readable form: %0.1f B", size/1.0);
  printf("%s\n\n", s1);

  printf("Printing permissions in ls -l format: ");
  char s2[10];
  mode_t perm = s.st_mode;
  sprintf(s2, "%o\n", perm);
  sprintf(s2, "%s\n", &s2[3]);
  for (int i = 0; i < 3; i++){
    switch(s2[i] - 48){
      case 0:
        printf("---");
        break;
      case 1:
        printf("--x");
        break;
      case 2:
        printf("-w-");
        break;
      case 3:
        printf("-wx");
        break;
      case 4:
        printf("r--");
        break;
      case 5:
        printf("r-x");
        break;
      case 6:
        printf("rw-");
        break;
      case 7:
        printf("rwx");
        break;
    }
  }
  printf("\n");
  return 0;
}
