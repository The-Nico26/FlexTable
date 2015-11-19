#include <stdio.h>
#include <stdlib.h>
#include "tflex.h"
void t_addElement(Table *table, TYPE_VARIABLE valeur, int x, int y);

struct Element{
  TYPE_VARIABLE valeur;
  short y; //Index y - column
  short x; //Index x - row
  Element *up;
  Element *down;
  Element *left;
  Element *right;
  Element *center;
};
struct Table{
 Element *start;
 Element *end;
 short y; //Length column
 short x; //Length row
};

Table *t_initEmpty(){
 Table *table = malloc(sizeof(Table));
 t_secuTable(table);
 table->start = NULL;
 table->end = NULL;
 table->y = 0;
 table->x = 0;
 t_addElement(table, 0, 0, 0);
 return table;
}
Table *t_init(int x, int y){
 Table *table = malloc(sizeof(Table));
 t_secuTable(table);
 table->start = NULL;
 table->end = NULL;
 table->y = 0;
 table->x = 0;
 t_addElement(table, 0, 0, 0);
 for(;x>0;x--){
  t_addRow(table);
 }
 for(;y>0;y--){
  t_addColumn(table);
 }
 return table;
}
void t_addRow(Table *table){
 table->x++;
 for(int y = 0; y <= table->y; y++){
  t_addElement(table, 0, table->x, y);
 }
}

void t_addColumn(Table *table){ //
 table->y++;
 for(int x = 0; x <= table->x; x++){
  t_addElement(table, 0, x, table->y);
 }
}

void t_addElement(Table *table, TYPE_VARIABLE valeur, int x, int y){
 Element *element = malloc(sizeof(Element));
 t_secuElement(element);
 element->center = element;
 element->valeur = valeur;
 element->y = y;
 element->x = x;
 if(x == table->x){
  element->right = NULL;
  element->down = NULL;
  element->up = t_getElement(table, x, y-1);
  if(element->up != NULL)
   element->up->down = element->center;

  element->left = t_getElement(table, x-1, y);
  if(element->left != NULL)
   element->left->right = element->center;
 } else if(y == table->y){
  element->down = NULL;
  element->right = NULL;

  element->up = t_getElement(table, x, y-1);
  if(element->up != NULL)
   element->up->down = element->center;

  element->left = t_getElement(table, x-1, y);
  if(element->left != NULL)
   element->left->right = element->center;
 }
 if(x == table->x && y == table->y){
 table->end = element;
 }
 if(x == 0 && y == 0){
  table->start = element;
 }

}

Element *t_getElement(Table *table, int x1, int y1){
 Element *x = table->start;
 Element *y = table->start;
 if(x == NULL){
  return NULL;
 }
 int index_y = 0;
 while(index_y <= table->y){
  while(x != NULL){
   if(x->x == x1 && x->y == y1){
    return x;
   }
   x = x->right;
  }
  x = y->down;
  y = y->down;
  index_y++;
 }
 return NULL;
}
void t_setElement(Table *table, int x, int y, TYPE_VARIABLE valeur){
 Element *element = table->start;
 for(int a = 0; a < x && element != NULL; a++){
  element = element->right;
 }
 for(int a = 0; a < y && element != NULL; a++){
  element = element->down;
 }
 if(element == NULL){
  return;
 }
 element->valeur = valeur;
}
void t_toString(Table *table){
  Element *x = table->start;
  if(x == NULL){
   printf("[Console] This table is empty !\n");
   return;
  }
  Element *y = table->start;
  int index_y = 0;
  for(int a = -1; a <= table->x; a++){
   if(a == -1)
    printf("[ ]\t");
   else
    printf("[%d]\t", a);
  }
  printf("\n");
  while(index_y <= table->y){
   printf("[%d]\t", index_y);
   while(x != NULL){
    printf("%d\t", x->valeur);
    x = x->right;
   }
   printf("\n");
   x = y->down;
   y = y->down;
   index_y++;
  }
}

void t_secuTable(Table *table){
 if(table == NULL)
  printf("[WARNING] Table is not initialize !\n");
}
void t_secuElement(Element *element){
 if(element == NULL)
  printf("[WARNING] Element is not initialize !\n");
}
