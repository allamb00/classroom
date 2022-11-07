#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char msg[4];
	//Allocate 4 bytes on the stack
	strcpy (msg, "Buenas tardes, soy overflow, un placer");
	//Overflow the stack frame
	printf("%s\n", msg);
	return 0;
}
