#ifndef DSTRING
#define DSTRING

typedef struct dynamic_string {
	char* chars;
	unsigned len;
} dynamic_string;

int len_str(char* str);

void dynamic_string_init(dynamic_string* str);

void dynamic_string_move(int l_selection, int r_selection, int to, dynamic_string* str);

void dynamic_string_add(char* ch, int index, dynamic_string* str);

void dynamic_string_rem(int l_selection, int r_selection, dynamic_string* str);

#define dynamic_string_append(chars, str) dynamic_string_add(chars, (*str).len, str)

#endif