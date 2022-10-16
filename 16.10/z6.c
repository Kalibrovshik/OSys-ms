#include <stdio.h>
#include <stdlib.h>
#define getName(var) #var
extern char **environ;
void main(){
char *extravariable;
putenv(extravariable);
setenv("extravariable", "changedvalue", 1);
                printf("extravariable - %s/n", getenv("extravariable"));
}