#include <stdlib.h>
#include <stdio.h>

void main(){
int hypervariable = 1;
unsetenv("hypervariable");
printf("hypervariable removed");
if (unsetenv("sjjaook") == -1){
printf("sjjaook deleted");
}
else{
clearenv();
printf("environment cleared");
}
}