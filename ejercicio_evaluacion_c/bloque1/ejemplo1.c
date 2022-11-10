#include <stdio.h>
#include <stddef.h>
#include <string.h>

/*  DCL30-C  */

void funcion1(char *p_param) {
	strcpy(p_param, "Mi cadena");
}

void funcion2(char *p_param) {
	strcpy(p_param, "Todo va bien");
}

void funcion3(char *p_param) {
	printf("%s\n", p_param);
}

int main(void) {
	char p[20];

	funcion1(p);
	printf("%s\n", p);
	funcion2(p);
	funcion3(p);
	printf("%s\n", p);

	return 0;
}
