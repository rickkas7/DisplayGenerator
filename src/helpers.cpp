#include "Particle.h"

extern "C"
char *itoa ( int value, char * str, int base ) {

	if (base == 16) {
		sprintf(str, "%x", value);
	}
	else
	if (base == 8) {
		sprintf(str, "%o", value);
	}
	else {
		sprintf(str, "%d", value);
	}

	return str;
}

extern "C"
char *utoa ( unsigned int value, char * str, int base ) {

	if (base == 16) {
		sprintf(str, "%x", value);
	}
	else
	if (base == 8) {
		sprintf(str, "%o", value);
	}
	else {
		sprintf(str, "%u", value);
	}

	return str;
}

extern "C"
char *ltoa (unsigned long value, char * str, int base ) {

	if (base == 16) {
		sprintf(str, "%lx", value);
	}
	else
	if (base == 8) {
		sprintf(str, "%lo", value);
	}
	else {
		sprintf(str, "%ld", value);
	}

	return str;
}

extern "C"
char *ultoa (unsigned long value, char * str, int base ) {

	if (base == 16) {
		sprintf(str, "%lx", value);
	}
	else
	if (base == 8) {
		sprintf(str, "%lo", value);
	}
	else {
		sprintf(str, "%lu", value);
	}

	return str;
}

extern "C"
uint32_t HAL_RNG_GetRandomNumber(void) {
	// This isn't right, there should be a cryptographically sound random number here,
	// but for testing this will be fine.
	return (uint32_t) rand();
}
