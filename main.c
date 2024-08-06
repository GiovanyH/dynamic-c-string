/*
 * main.c
 * Dynamic C String using Stretchy Buffers
 *
 * This implementation provides a dynamic string in C using stretchy buffers.
 * Stretchy buffers automatically resize as elements are added, providing a
 * convenient way to handle dynamic arrays in C.
 * Everytime the buffer is full, it doubles the capacity: (h->cap *= 2).
 *
 *
 * License: Unlicense
 *
 * Author: GiovanyH
 * GitHub: https://github.com/GiovanyH
 */

 /* Example code: */

#include "dynamic_string.h"

int main(void) {
	char* string = string_new("Hello, World!");

	append_string(&string, "Teste");

	printf("string: %s\n", string);

	free(vec_get_hdr(string));
}
