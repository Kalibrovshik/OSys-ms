#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


//...
void main(){
    printf("PATH : %s\n", getenv("PATH"));
    printf("randomwords : %s\n", getenv("randomwords"));
}