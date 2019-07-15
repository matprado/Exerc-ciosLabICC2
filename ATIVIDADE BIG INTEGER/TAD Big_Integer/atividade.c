#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Big_Integer.h"

int main(int argc, char *argv[]){
	char op[20];
	fgets(op, 20, stdin);
	Big_Integer *n1, *n2, *r;
	n1 = create_Big_Integer();
	n2 = create_Big_Integer();
    r = create_Big_Integer();
    set_Big_Integer(n1);
    set_Big_Integer(n2);
	if(!strcmp(op, "SOMA\n")){
		r = sum_Big_Integers(n1, n2);
	}else if(!strcmp(op, "SUBTRACAO\n")){
		r = subtract_Big_Integers(n1, n2);
	}else if(!strcmp(op, "MULTIPLICACAO\n")){
        multiply_Big_Integers(n1, n2);
    }
    delete_Big_Integer(n1);
    delete_Big_Integer(n2);
    delete_Big_Integer(r);
	return 0;
}