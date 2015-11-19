#define TYPE_VARIABLE int
typedef struct Element Element;
typedef struct Row Row;
typedef struct Column Column;
typedef struct Table Table;

Table *t_initEmpty();
Table *t_init(int x, int y);
void t_secuTable(Table *table);
void t_addRow(Table *table);
void t_addColumn(Table *table);
void t_toString(Table *table);
void t_secuElement(Element *element);
Element *t_getElement(Table *table, int x, int y);
void t_setElement(Table *table, int x, int y, TYPE_VARIABLE valeur);
