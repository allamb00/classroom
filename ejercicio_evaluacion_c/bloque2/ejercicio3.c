/* fib.c */
#include <stdio.h>
#include <stdlib.h>

int fib(int x){
	if(x==0) return 0; 	/*  Esta es la instrucción que más tiempo de cpu requiere. Se debe a  */
	else if(x==1) return 1; /*  que todas las iteraciones de fib tienen una comparación de x con 0*/
	return fib(x - 1) + fib(x - 2); /* mientras que una menor parte entran en la comparación de x /*
}				/*  con 1 o de la doble llamada recursiva a fib

int main(int argc, char *argv[]) {

	for (size_t i = 0; i < 45; ++i) {
		printf("%d\n", fib(i));
	}
	return 0;
}
