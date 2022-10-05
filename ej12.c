#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	printf("\nNombre del alumno: Adrian Calzado \n4 ultimas cifras de DNI: 3811\n");
	system("ls -l -S /home/alumno/Descargas\n");
	printf("\n\nEl proceso se esta ejecutando en la terminal:");
	system("tty");
	printf("\nMe voy a dormir dos minutos...\n\n");
	sleep(120);
	printf("Informacion del proceso:\n");
	system("ps -efl | grep 'ej11'");
	
	exit(0);

}
