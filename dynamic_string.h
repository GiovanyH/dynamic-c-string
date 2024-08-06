#ifndef C_STRING
#define C_STRING

#include <stdio.h>
#include <stdlib.h>

#define vec_get_hdr(SB) ((int*)(SB) - 2)
#define vec_push(SB, ELEM) ((void)((vec_get_hdr(SB)[0] >= vec_get_hdr(SB)[1]) ? \
    (*(void **)&(SB) = (void*)((int*)realloc(vec_get_hdr(SB), 2 * sizeof(int) + (vec_get_hdr(SB)[1] *= 2) + 1) + 2)) : 0), \
    (SB)[vec_get_hdr(SB)[0]++] = (ELEM))
#define vec_pop(SB) ((void)((--vec_get_hdr(SB)[0] < vec_get_hdr(SB)[1] - 8) ? \
    (*(void **)&(SB) = (void*)((int*)realloc(vec_get_hdr(SB), 2 * sizeof(int) + (vec_get_hdr(SB)[1] -= 8) + 1) + 2)) : 0))

void append_string(char** sb, const char* string) {
    while (*string) {
        vec_push(*sb, *string++);
    }
    (*sb)[vec_get_hdr(*sb)[0]] = '\0';
}

char* string_new(const char* string) {
    char* p = (char*)((int*)malloc(2 * sizeof(int) + 8) + 2);
    ((int*)p)[-2] = 0; ((int*)p)[-1] = 8;

    append_string(&p, string);

    return p;
}

#endif
