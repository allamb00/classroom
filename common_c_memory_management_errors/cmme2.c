#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *msg = malloc(4);
	//Alocate 4 bytes
	strcpy(msg, "A las buenas tardes, señores");
	//Overflow the allocated memory
	printf("%s\n", msg);
	free(msg);
	//Free the allocated memory
	strcpy(msg, "Que me dejao una cosa, perate");
	//Write to freed memory
	printf("%s\n", msg);
	free(msg);
	//Free the freed memory
	realloc(msg, 2);
	//Reallocate freed memory
	strcpy(msg, "Qué pasa, artista");
	//Writing to erroneous memory
	printf("%s\n", msg);
	return 0;
}
