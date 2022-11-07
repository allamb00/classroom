#include <stdio.h>

/*  DCL41-C  */

extern void f(int i);

void func(int expr) {
	/*  Se saca el código que no está en los case fuera del switch  */
	int i = 4;
	f(i);

	switch (expr) {
		case 0:
			i = 17;
		default:
			printf("%d\n", i);
	}
}
