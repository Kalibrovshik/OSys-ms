#include <unistd.h>
#include <stdio.h>
#include <sys/utsname.h>

struct utsname unameData;
extern char **environ;
//...
void main(){
  uname(&unameData);
  char hostbuffer[256];
    struct hostent *host_entry;
    int hostname;
    printf("%s\n", hostname);
  printf("%s", unameData.sysname);

}