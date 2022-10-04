#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/*ADRIAN CALZADO*/

void main() {
  pid_t pid, pid_hijo;	
  

  pid = fork();		//creamos proceso hijo
  
  if(pid==0) {
   	/*EStamos en el proceso hijo*/
   	printf("- Soy el proceso hijo.\n");
	printf("Nombre del alumno: Adrian Calzado\n");
	
  } else{
  	/*Estamos en el proceso padre*/
   	pid_hijo = wait(NULL);					// espera a que termine el hijo y almacena el PID del hijo en la variable
     	printf("- Soy el proceso padre.\n");
     	printf("Mi PID (el del proceso padre) es: %d \n", getpid());
  	printf("El PID del hijo es %d \n", pid_hijo);	
  } 
  exit(0);
}
