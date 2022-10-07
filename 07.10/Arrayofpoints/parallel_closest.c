#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "point.h"
#include "serial_closest.h"
#include "utilities_closest.h"

double closest_parallel(struct Point *p, int n, int pdmax, int *pcount) {
    
    if (n <= 3 || pdmax == 0){
        return closest_serial(p, n);
    } else { 
        int left_fd[2]; 
        int right_fd[2];
        int status; 
        
        //Find the middle point
        int mid = n / 2;
        struct Point mid_point = p[mid];
        
        /* Create the left child pipe */
        if ((pipe(left_fd)) == -1) {
            perror("pipe");
            exit(1);
        }
        int l = fork();
        if(l < 0){
            //error
            perror("fork");
            exit(1);
        } else if(l == 0){
            double result = closest_parallel(p, mid, (pdmax - 1), pcount);
            write(left_fd[1], &result, sizeof(double));
            close(left_fd[1]);
            exit(*pcount);
        }
        
        /* Create the right pipe */
        if ((pipe(right_fd)) == -1) {
            perror("pipe");
            exit(1);
        }
        int r = fork();
        if(r < 0){
            //error
            perror("fork");
            exit(1);
        } else if(r == 0){
            //left child runs function
            double result = closest_parallel(p + mid, n - mid, (pdmax - 1), pcount);
            //write answer to the pipe for parent to read
            write(right_fd[1], &result, sizeof(double));
            close(right_fd[1]);
            exit(*pcount);
        }
        
        double dl;
        double dr;
        
        int wpid;
        
        while((wpid = wait(&status)) > 0){
            if(wpid == l){
                if (WIFEXITED(status)){
                    (*pcount) += WEXITSTATUS(status) + 1;
                    read(left_fd[0], &dl, sizeof(double));
                    close(left_fd[0]);
                }
            } else{ 
                if (WIFEXITED(status)){
                    (*pcount) += WEXITSTATUS(status) + 1;
                    read(right_fd[0], &dr, sizeof(double));
                    close(right_fd[0]);
                }
            }
        }
        
        double d = min(dl, dr);
        
        
        struct Point *strip = malloc(sizeof(struct Point) * n);
        if (strip == NULL) {
            perror("malloc");
            exit(1);
        }
    
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (abs(p[i].x - mid_point.x) < d) {
                strip[j] = p[i], j++;
            }
        }
    
       double new_min = min(d, strip_closest(strip, j, d));
        free(strip);
        
        return new_min;
    }
    return 0.0;
}

