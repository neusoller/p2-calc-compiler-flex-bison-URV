#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100


#ifndef VARIABLE_TYPE
#define VARIABLE_TYPE
typedef enum
{
    INTEGER,
    FLOAT,
    STRING,
    BOOLEAN,
    UNDEFINED,
    ARRAY
} varType;


typedef struct variable_t
{
    char * name;         // Nom de la variable
    varType type;        // Tipus de variable (INTEGER, FLOAT, etc.)
    char * place;        // Representació simbòlica (ex: $t1)
    char * ctr;          // Comptador per als bucles
    int repeat;          // Línia de salt per al bucle REPEAT

    int size;            // Grandària d'arrays (si aplica)
    int * values;        // Per arrays: valors associats (si aplica)
    double value;        // Valor numèric (real o enter)

    // Camps per al control del bucle REPEAT
    char * limit;        // Límits del bucle
    char * startLabel;   // Etiqueta d'inici del bucle
    char * endLabel;     // Etiqueta de final del bucle
} variable;



typedef struct quad_t
{
    char * one; //resultat o primer parametre a emetre
    char * two; //primera variable
    char * three; //operand
    char * four;    //segona variable
} quad;

typedef struct {
    char *name;   // Nom de la variable
    char *value;  // Valor de la variable com a cadena
    int type;     // Tipus de variable: 0 = INTEGER, 1 = FLOAT
} CustomSymbol;

#endif
