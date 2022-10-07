#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*ADRIAN CALZADO*/

void main() {
  pid_t pid2, pid3;	
  

pid2 = fork();			//creamos proceso P2
  
  if(pid2==0) {
  	printf("Soy el P2, me voy a dormir\n");			
  	sleep(10);
  	printf("Despierto\n");
  } else {
  	wait(NULL);
 	pid3 = fork();		//creamos proceso P3
 		if(pid3==0) {
 		  	printf("Soy el P3\n");	
  			printf("Mi PID es: %d \n", getpid());
  			printf("Mi PPID es: %d \n", getppid());
 		} else{
 			printf("Soy el P1\n");	
  			printf("Mi PID es: %d \n", getpid());
 			wait(NULL);
 
  	}	

  } 
  	
  exit(0);
  
  
  }
  
