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
	unsigned int count = 0;
	unsigned int sum = 0;
	int i = first;
	va_list args;

	va_start(args, first);

	while(i != va_eol) {
		sum += i;
		count++;
		i = va_arg(args, int);
	}

	va_end(args);
	return (count ? (sum/count) : 0);
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
