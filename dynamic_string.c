#include "dynamic_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>

int len_str(char* str) {
	size_t len = 0;
    while (*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void dynamic_string_init(dynamic_string* str) {
	str->len = 0;
	str->chars = (char*)malloc(1);
	str->chars[0] = '\0';
}

void dynamic_string_move(int l_selection, int r_selection, int to, dynamic_string* str) {
	int selection_size = r_selection-l_selection;
	
	char* tempStr = malloc(selection_size + 1);
	for(int n = l_selection; n < r_selection; n++) {
		tempStr[n-l_selection] = str->chars[n];
		str->chars[n] = str->chars[to+(n-l_selection)];
	}

	for(int n = to; n < to+(r_selection-l_selection); n++) {
		str->chars[n] = tempStr[n-to];
	}

	free(tempStr);
}

void dynamic_string_add(char* chars, int index, dynamic_string* str) {
	str->chars = (char*)realloc(str->chars, str->len+len_str(chars)+1);

	dynamic_string_move(0, str->len, len_str(chars), str);
	dynamic_string_move(len_str(chars), index+len_str(chars), 0, str);

	for(int n = index; n < index+len_str(chars); n++) {
		str->chars[n] = chars[n-index];
	}

	str->len+=len_str(chars);
	str->chars[str->len] = '\0';
}

void dynamic_string_rem(int l_selection, int r_selection, dynamic_string* str) {
	int selection_size = r_selection-l_selection;

	for(int n = 0; n < str->len-r_selection; n++) {
		str->chars[n+l_selection] = str->chars[n+r_selection];
	}

	str->chars[str->len-selection_size] = '\0';
	str->len = len_str(str->chars);
}
