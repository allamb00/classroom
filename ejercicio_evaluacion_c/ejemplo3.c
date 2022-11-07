#include <stdio.h>

/*  DCL41-C  */
/*  Se define f  */
extern void f(int i){}

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

int main (void) {
	func(0);
	func(1);
	return 0;
}
