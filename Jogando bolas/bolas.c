#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

int main(void){
	int h, n, last;
	scanf("%d%d", &h, &n);
	BT *tree = create_bt(h);
	for(int i=0; i<n; i++){
		last = put_ball(tree);
	}
	printf("%d\n", last);
	delete_bt(tree);
	return 0;
}