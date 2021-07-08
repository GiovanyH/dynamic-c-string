#include "dynamic_string.h"
#include <stdio.h>

int main(void) {
	dynamic_string str1;
	dynamic_string_init(&str1);

	dynamic_string_append("Hello World!", &str1);

	printf("%s\n", str1.chars);

	dynamic_string_add(" saojfosa", 5, &str1);

	printf("%s\n", str1.chars);

	dynamic_string_rem(5, 14, &str1);

	printf("%s\n", str1.chars);
}