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
	new_vector(char, v); // declaring the vector / this is our string

	// Printing the capacity (no need to do this)
	printf("string capacity is %d chars\n", vec_get_capacity(v));

	// Appending a string
	append_string(&v, "Hello, World!");

	// Printing capacity and string
	printf("length: %d, capacity: %d\n", vec_get_len(v) - 1, vec_get_capacity(v));
	printf("string: %s\n", v);

	vec_free(v); // freeing the string
}
