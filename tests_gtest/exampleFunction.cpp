#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>
#include <assert.h>

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  	unsigned int usum;
	if(((ui_b > 0) && (si_a > (INT_MAX - ui_b))) ||
		((ui_b < 0) && (ui_a < (INT_MIN - ui_b)))) {
		printf("Error: Overflow at wrapFunctionAdd");
		return -1;
	}
	usum = ui_a + ui_b;
  	return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  	unsigned umul;
  	unsigned long long tmp;
	assert(PRECISION(ULLONG_MAX) >= 2 * PRECISION(UINT_MAX));
	tmp = (signed long long)ui_a * (signed long long)ui_b;

	if((tmp > INT_MAX) || (tmp < INT_MIN)) {
		printf("Error: Overflow at wrapFunctionMul");
		return -1;
	}
	umul = tmp;
  	return umul;
}

uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
	uint32_t uShift;
	if((ui_a < 0)||(ui_b < 0)||
	ui_b >= PRECISION(UINT_MAX))||
	(ui_a > (INT_MAX >> ui_b))) {
		printf("Error: Overflow at wrapFunctionShift");
		return -1;
	}
	uShift = ui_a << ui_b;
	return uShift;
}
