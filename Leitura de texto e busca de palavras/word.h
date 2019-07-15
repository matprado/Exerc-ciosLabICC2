#ifndef WORD_H
#define WORD_H

typedef struct word WORD;

WORD *word_create();
void word_free(WORD *w);
WORD *word_read(FILE *fp);
int word_compare(WORD *w1 , WORD *w2);
void word_copy(WORD *source, WORD *copy);
void word_print(WORD* w);

#endif