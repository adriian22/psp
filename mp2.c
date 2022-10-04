#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*ADRIAN CALZADO*/

void main() {
  pid_t pid, pid_hijo;	
  

  pid = fork();		//creamos proceso P2
  
  if(pid==0) {
	pid_hijo = fork();	//creamos proceso P3	
	if(pid_hijo == 0) {
	/*Estamos en el proceso P3*/
	printf("- Soy el proceso P3.\n");
	printf("Mi PID es: %d \n", getpid());
	printf("Mi PPID es: %d \n", getppid());
	}else{
		/*Estamos en el proceso P2*/
		wait(NULL);
	   	printf("- Soy el proceso P2.\n");
		printf("Mi PID es: %d \n", getpid());
		printf("Mi PPID es: %d \n", getppid());
	}
	
  } else {
  	/*Estamos en el proceso P1*/
   	wait(NULL);		
     	printf("- Soy el proceso P1.\n");
     	printf("Mi PID es: %d \n", getpid());
  	printf("Mi PPID es: %d \n", getppid());
  } 
  exit(0);
}
