#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#define MAX 1000		

typedef struct big Big_Integer;

Big_Integer* create_Big_Integer();
void delete_Big_Integer(Big_Integer *x);
void set_Big_Integer(Big_Integer *x);
void print_Big_Integer(Big_Integer *x);
int get_num_Digits(Big_Integer *x);
int is_negative(Big_Integer *x);
Big_Integer *sum_Big_Integers(Big_Integer *a, Big_Integer *b);
Big_Integer *subtract_Big_Integers(Big_Integer *a, Big_Integer *b);
void multiply_Big_Integers(Big_Integer *a, Big_Integer *b);
/*Big_Integer *divide_Big_Integers(Big_Integer *a, Big_Integer *b);*/

#endif