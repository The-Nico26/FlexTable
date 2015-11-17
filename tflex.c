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

Table *t_init(){
 Table *table = malloc(sizeof(Table));
 t_secuTable(table);
 table->start = NULL;
 table->end = NULL;
 table->y = 0;
 table->x = 0;
 return table;
}

void t_addRow(Table *table){
 table->x++;
 for(int x = 0; x < table->x; x++){
  t_addElement(table, 0, x, table->y);
 }
}

void t_addColumn(Table *table){
 table->y++;
 for(int y = 0; y < table->y; y++){
  t_addElement(table, 0, table->x, y);
 }
}

void t_addElement(Table *table, TYPE_VARIABLE valeur, int x, int y){
 Element *element = malloc(sizeof(Element));
 t_secuElement(element);
 element->valeur = valeur;
 element->y = y;
 element->x = x;
 element->center = element;
 if(y == 0){
  element->up = NULL;
 } else {
  element->up = t_getElement(table, x, y-1);
  element->up->down = element->center;
 }
 printf("TEST\n");
 if(y == table->y){
  element->down = NULL;
 } else {
  element->down = t_getElement(table, x, y+1);
  element->down->up = element->center;
 }
 printf("TEST\n");
 if(x == 0){
  element->left = NULL;
 } else {
  element->left = t_getElement(table, x-1, y);
  element->left->right = element->center;
 }
 printf("TEST\n");
 if(x == table->x){
  element->right = NULL;
 } else {
  element->right = t_getElement(table, x+1, y);
  element->right->left = element->center;
 }
 printf("TEST\n");
}

Element *t_getElement(Table *table, int x, int y){
 Element *element = table->start;
 for(int a = 0; a<x && element != NULL && x<table->x; a++){
  element = element->right;
 }
 for(int b = 0; b<y && element != NULL && y<table->y; b++){
  element = element->down;
 }
 return element;
}

void t_toString(Table *table){
  Element *x = table->start;
  if(x == NULL){
   printf("[Console]This table is empty !\n");
   return;
  }
  Element *y = table->start;
  int index_y = 0;
  while(index_y < table->y){
   printf("[%d] ", index_y);
   while(x != NULL){
    printf("%d ", x->valeur);
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
