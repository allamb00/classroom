#include <stdio.h>

extern void f(int i);

void func(int expr) {
	switch(expr) {
		int i = 4;
		f(i);
		case 0:
			i = 17;
		default:
			printf("%d\n", i);
	}
}

int main(void)
{
  func(0);
  func(1);
}
