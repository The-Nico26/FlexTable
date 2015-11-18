#include <stdlib.h>
#include <stdio.h>
#include "tflex.h"

void main(){
 Table *table = t_init();
 t_addColumn(table);
 t_addRow(table);
 t_addRow(table);
 t_addColumn(table);
 t_addColumn(table);
 t_addRow(table);
 t_addRow(table);
 t_addColumn(table);
 t_addColumn(table);
 t_addRow(table);
 t_addRow(table);
 t_addColumn(table);
 t_addRow(table);
 t_addRow(table);
 t_toString(table);
}
