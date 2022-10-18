#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//el padre envia señal al hijo y el hijo le envia señal al padre

void manejador( int numsenal ) {
    printf("Hijo recibe señal número..%d\n", numsenal);
 
}

void manejadorPadre(int numsenal) {
    printf("Padre recibe señal.. %d\n", numsenal);
}

int main()
{
  int pid_hijo;  
  pid_hijo = fork(); //creamos hijo   
  
  switch(pid_hijo)
     case -1:
  {
          printf( "Error al crear el proceso hijo...\n");
          exit( -1 );        
     case 0:   //HIJO     	         
          signal(SIGUSR1, manejador); //Función manejadora de la señal
          pause();	//se queda bloqueado a la espera de recibir una señal
          printf("Mandando señal a  papa %d \n",getppid());
          kill(getppid(), SIGUSR1);
          
          break;    
     default: 
          //PADRE envia 2 señales
          signal(SIGUSR1, manejadorPadre);
          sleep(1);
          kill(pid_hijo, SIGUSR1);//ENVIA SEÑAL AL HIJO 
          pause();	//se queda bloqueado a la espera de recibir una señal
          sleep(1);
          break;
  } 
  return 0;
}
