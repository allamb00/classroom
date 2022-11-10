


#include <stdio.h>
#include <stdlib.h> /*es necesaria esta libreria para que funcione atoi */

unsigned long long int factorial(unsigned int i){
	if(i <= 1){ /* Si i es <= 1 se devuelve 1 */
		return 1;
	}
	return i * factorial(i - 1); /* en cualquier otro caso, devuelve su factorial de forma recursiva.
				      * Aquí se encuentra la instrucción que más tiempo consume.
				      * En concreto, la multiplicación de i por el output de
				      * factorial (un 47% del tiempo de ejecucion se pierde aquí)
				      */
}

int main(int argc, char *argv[]) {
	/*  DCL04-C  */
	int i = 12, j = 3, f = 0; /* Se inicializan tres variables en la misma linea */

	if (argc==1){ /* En caso de que argc sea 1 */
		printf("Factorial of %d is %lld\n", i, factorial(i)); /*imprime el factorial de i (12) */
	}
	else{
		j=atoi(argv[1]); /* Parsea el primer valor de argv a entero y lo almacena en j */
		for(f=0;f<j;f++){ /*mientras f sea menor que j */
			printf("Factorial of %d is %lld\n", f, factorial(f)); /*imprime el factorial de f */
	 	}
	}
	return 0;
}
