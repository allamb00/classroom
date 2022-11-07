#include <stdlib.h>

/*  DCL38-C  */

struct flexArrayStruct {
	int num;
	/*  Se usa un array flexible para conseguir un struct de tamaño dinámico, 
	 *  aunque enla ISO 90 no están soportados.
	 */
	int data[];
};

void func(size_t array_size) {
	/*  Declaración de variables fuera del bucle y del código  */
	size_t i;
	/*  Space is allocated for the struct  */
	struct flexArrayStruct *structP = (struct flexArrayStruct *)
		malloc(sizeof(struct flexArrayStruct) + sizeof(int) * array_size);
	if(structP == NULL) {
		/*  Handle malloc failure  */
	}

	structP -> num = array_size;

	/*
	 *  Access data[] as if it had been allocated
	 *  as data[array_size].
	 */
	for(i = 0; i < array_size; ++i) {
		structP -> data[i] = 1;
	}
}
