#ifndef AB_H
#define AB_H

#define MAX 100000

typedef struct node NODE;
typedef struct bt BT;

BT *create_bt(int h);
NODE *create_node(int value);
void delete_bt(BT *tree);
int put_ball(BT *tree);

#endif