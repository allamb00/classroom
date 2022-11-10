#include <stdarg.h>
#include <stdio.h>
#include <strings.h>

/* Compiled with -std=c11
 * -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wdisabled-optimization
 * -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wredundant-decls
 * -Wshadow -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros
*/

/* Parámetros que no aplican por estar orientados a C++
 * -Wctor-dtor-privacy -Wnoexcept -Wold-style-cast -Woverloaded-virtual
 * -Wsign-promo -Wstrict-null-sentinel
 */

/* Parámetros no encontrados en la documentación (¿Puede que estén mal escritos?)
 * -Wno-parentheses -fdiagnostics-show-option
 */

/* va_eol se utiliza para saber cuándo se acaba el array de variables */
enum { va_eol = -1 };

unsigned int average(int first, ...){
	unsigned int count = 0; /* Se inicializa una variable para contar elementos */
	unsigned int sum = 0; /* Se inicializa una variable para almacenar una suma */
	int i = first;
	va_list args; /* Se guarda en va_list los argumentos que han pasado */

	va_start(args, first); /* se inicia el iterador va_start con los argumentos */

	while(i != va_eol) { /* mientras siga habiendo valores en la lista */
		sum += i; /* se siguen sumando */
		count++; /* y se incrementa el numero de valores */
		i = va_arg(args, int); /* se sustituye el valor de i por el siguiente de la lista */
	}

	va_end(args); /* se libera el iterador */
	return (count ? (sum/count) : 0); /* Se devuelve 0 si los valores son 0, y la media en otro caso */
}

int main(void)
{
  int n1 = 1;
  int n2 = 6;
  int n3 = 13;

  unsigned int res = average(n1, n2);
  printf("El resultado es %d", res);

  return 0;
}
