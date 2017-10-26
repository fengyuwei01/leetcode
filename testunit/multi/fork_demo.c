#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
int main(void)  
{  
    pid_t child;  
    if((child = fork()) == -1)  
    {  
        perror("fork");  
        exit(EXIT_FAILURE);  
    }  
    else if(child == 0)                 //子进程中  
    {  
        // sleep(1);
        puts("in child");  
        printf("\tchild pid = %d\n",getpid());  
        printf("\tchild ppid = %d\n",getppid());  
        /* while(1) {              */
        /*     printf("child!\n"); */
        /*     sleep(1);           */
        /* }                       */
        exit(EXIT_SUCCESS);
    }  
    else      
    {  
        puts("in parent");  
        printf("child_id %d\n",child);
        printf("\tparent pid = %d\n",getpid());  
        printf("\tparent ppid = %d\n",getppid());  
        /* while(1) {               */
        /*     printf("parent!\n"); */
        /*     sleep(1);            */
        /* }                        */
    }  
    exit(EXIT_SUCCESS);  
}
