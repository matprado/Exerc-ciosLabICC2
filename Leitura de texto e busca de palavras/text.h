#ifndef TEXT_H
#define TEXT_H
#include "word.h"

typedef struct text TEXT;

TEXT *text_create();
void text_free(TEXT *t);
TEXT *text_read(FILE *fp);
void text_sort(TEXT *t);
int text_word_equals(TEXT *t, int pos, int *after);
int binary_search(TEXT *t, WORD *w, int ini, int fim);
WORD *text_get_word(TEXT *t, int pos);
int text_get_n_words(TEXT* t);
void text_print_word(TEXT *t, int pos);
void text_print(TEXT *t);

#endif