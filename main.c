#include <stdlib.h>
#include <stdio.h>
#include "tflex.h"

void main(){
 //Table *table = t_initEmpty();
 //t_addRow(table);
 Table *table = t_init(5, 4);
 //t_setElement(table, 5, 5, 10);
 t_toString(table);
 printf("Size of Table : %d octects\n", t_size(table));
}
