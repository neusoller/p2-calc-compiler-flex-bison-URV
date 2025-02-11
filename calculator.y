%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stdarg.h>
	#include "calculator.tab.h"

	#define MAX_QUADS 500
	#define ARRAY 3
	
	// taula de símbols pròpia
	#define CUSTOM_MAX_SYMBOLS 100
	CustomSymbol customSymtab[CUSTOM_MAX_SYMBOLS];  // Taula de símbols
	int customSymtabCount = 0;                      // Comptador d'entrades

	int errflag = 0;
	int temp = 1;

	quad *quad_list;

	int currQuad = 0;

	extern FILE* yyin;
	extern int yylineno;

	//extern int yywrap( );
	extern int yylex();
	extern void yyerror(char *explanation);
	int yyterminate() { return 0; }

	FILE* fInfo;

	// funcions
		
	variable arithmeticCalc(variable v1, char* op, variable v2);
	variable powFunction(variable v1, variable v2, char* assign_name);
	
	char *newTemp(const char *prefix);
	
	void addQuad(int num_args, ...);
	void printQuads();
	void mostrarSymtab();
	
	// el meu "symtab"
	void customSymEnter(char *name, char *value, int type);
	void mostrarCustomSymtab();
	CustomSymbol *customSymLookup(char *name);
	
	
%}

%code requires {
  	#include "symtab.h"
	#include "structs.h"
}

%union { variable var; };

%token <var> FL INT ID A_ID ADD SUB MUL DIV MOD POW
%token ASSIGN LPAREN RPAREN EOL END SCOMMENT MCOMMENT LERR REPEAT DO DONE LB RB PC COMA
%type <var> exp statement statement_list arithmetic_op1 arithmetic_op2 arithmetic_op3 arithmetic iniciar_loop acabar_loop id

%start program

%%
program : statement_list;

statement_list : statement_list statement | statement | statement_list iniciar_loop  | iniciar_loop  | statement_list acabar_loop;

iniciar_loop : REPEAT exp {	if($2.type == UNDEFINED){
						fprintf(fInfo, "ERROR: Condició no vàlida en el bucle REPEAT a la línia %d\n", yylineno);
						$$.type = UNDEFINED;
						yyerror($2.place);
						yylineno++;
				} else {
					if($2.type == FLOAT){
						fprintf(fInfo, "ERROR: La condició del bucle REPEAT ha de ser de tipus ENTER a la línia %d\n", yylineno);
						$$.type = UNDEFINED;
						yyerror("SEMANTIC ERROR\n");
						yylineno++;
					} else {
						
						yylineno++;
						$$ = $2;
						$$.ctr = (char *)malloc(100);
						strcpy($$.ctr, newTemp(NULL));
						addQuad(2, $$.ctr, "0");
						$$.repeat = currQuad +1;
					}
				}											
			};

acabar_loop: iniciar_loop DO EOL statement_list DONE { 
				fprintf(fInfo, "Línia %d: --- FINAL LOOP ---\n", yylineno);
				if($1.type == UNDEFINED){}
				else if($4.type == UNDEFINED){
					$$.type = UNDEFINED;
					yyerror("SEMANTIC ERROR\n");
					fprintf(fInfo, "SEMANTIC ERROR: Error in loop error detected.%d\n", yylineno);
				} else{
					if($1.type == INTEGER) addQuad(4, $1.ctr, "ADDI", $1.ctr, "1");
					else addQuad(4, $1.ctr, "ADDF", $1.ctr, "1");
					
					char str[20];
					sprintf(str, "%d", $1.repeat);
					if ($1.type == INTEGER)	{
						addQuad(4, $1.ctr, "LTI", $1.place, str);
					} else {
						addQuad(4, $1.ctr, "LTF", $1.place, str);
					}
				}
			};



statement: id ASSIGN exp 	{	
					if($3.type == UNDEFINED){
						fprintf(fInfo, "SEMANTIC ERROR: Assignació no vàlida a la línia %d\n", yylineno);
						yyerror($3.place);
					} else {
						customSymEnter($1.name, $3.place, $3.type);

						addQuad(3, $1.name, ":=", $3.place);
						yylineno++; 
						
					}
				}
		| exp	{	
					if($1.type == UNDEFINED){
						yyerror($1.place);
					} else {	
						if(sym_lookup($1.name, &$1) == SYMTAB_NOT_FOUND) {	
							yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); errflag = 1; YYERROR;
						} else { 
							addQuad(2, "PARAM", $1.name);
														
							if($1.type == INTEGER){
								addQuad(3, "CALL", "PUTI", "1");	
							} else {
								addQuad(3, "CALL", "PUTF", "1");	
							}
						}
					}	
					yylineno++;
				}
		| id LB INT RB {
				    	char *size_str = (char *)malloc(50);
				    	sprintf(size_str, "%s", $3.place);

				    	customSymEnter($1.name, size_str, ARRAY);
				    	addQuad(3, $1.name, ":= ARRAY", size_str);
				}
		| id LB INT RB ASSIGN exp {
				    	CustomSymbol *sym = customSymLookup($1.name);
				    	if (sym == NULL || sym->type != ARRAY) {
						yyerror("ERROR: La variable no és una taula o no està definida.");
				    	} else {

						char *index = newTemp($1.name);
						addQuad(4, index, "SUBI", $3.place, "1"); // Calcula l'índex correcte (base 1)

						char *addr = newTemp($1.name);
						addQuad(4, addr, "ADDI", sym->name, index); // Adreça base + desplaçament

						addQuad(3, addr, ":=", $6.place);
				    	}
				}
		| EOL		{ yylineno++; }
		| SCOMMENT	{ yylineno++; }
		| MCOMMENT	{ yylineno++; }
		| END		{ YYABORT; }
		| LERR EOL	{ yyerror("Error lèxic: caràcter invàlid. (LERR EOL)\n"); yylineno++; }
		| LERR 		{ yyerror("Error lèxic: caràcter invàlid. (LERR)\n"); }
		| error	EOL	{	if (errflag == 1) errflag = 0;
					else fprintf(fInfo,"\nLínia %d: Error síntàctic: No hi ha cap regla que coicideixi. (error EOL)\n", yylineno);
					yylineno++;
				} ;

id: ID | A_ID;

exp: arithmetic;

arithmetic: arithmetic_op1 
		| arithmetic ADD arithmetic_op1		{ $$ = arithmeticCalc($1, "+", $3); }
		| arithmetic SUB arithmetic_op1		{ $$ = arithmeticCalc($1, "-", $3); }
		| ADD arithmetic_op1			{ ($$ = $2); }
		| SUB arithmetic_op2			{	$$.type = $2.type;
								$$.place = newTemp(NULL);
								
								if ($2.type == INTEGER) sprintf($$.place, "-%s", $2.place);
							    	else sprintf($$.place, "-%s", $2.place);

								if($2.type == INTEGER) addQuad(3, $$.place, "CHSI", $2.place);
								else addQuad(3, $$.place, "CHSF", $2.place);
							} ;
							
arithmetic_op1: arithmetic_op2 
		| arithmetic_op1 MUL arithmetic_op2 	{ $$ = arithmeticCalc($1, "*", $3); }
		| arithmetic_op1 DIV arithmetic_op2 	{ $$ = arithmeticCalc($1, "/", $3); }
		| arithmetic_op1 MOD arithmetic_op2	{ $$ = arithmeticCalc($1, "%", $3); };

arithmetic_op2: arithmetic_op3 
		| arithmetic_op3 POW arithmetic_op2	{ $$ = arithmeticCalc($1, "**", $3); };

arithmetic_op3: LPAREN arithmetic RPAREN	{ $$ = $2; }
		| INT 				{	if($1.type == UNDEFINED) yyerror($1.name);
							else $$ = $1;
						}
		| FL				{ 	if($1.type == UNDEFINED) yyerror($1.name);
							else $$ = $1;
						}
		| A_ID				{ 	
							CustomSymbol *sym = customSymLookup($1.name);
							if (sym == NULL) {
								yyerror("Error Semàntic: Variable not found (ID).");
							      	$$ = (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
							} else {
							      	$$ = (variable){
								 	.type = sym->type,
								  	.place = strdup(sym->value),
								 	.name = strdup($1.name)
							      	};
							}
						}
		|ID				{ 	
							CustomSymbol *sym = customSymLookup($1.name);
							if (sym == NULL) {
								yyerror("Error Semàntic: Variable not found (ID).");
							      	$$ = (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
							} else {
							      	$$ = (variable){
								  	.type = sym->type,
								  	.place = strdup(sym->value),
								  	.name = strdup($1.name)
							      };
							}
						}
		| LERR EOL			{ $$.type = UNDEFINED; yyerror("Error lèxic: caràcter invàlid. (LERR EOL 2)\n"); yylineno++; }
		| LERR 				{ $$.type = UNDEFINED; yyerror("Error lèxic: caràcter invàlid. (LERR 2)\n"); } 
		| error	EOL			{	$$.type = UNDEFINED;
							if (errflag == 1) errflag = 0;
							else fprintf(fInfo,"\t Error síntàctic: No hi ha cap regla que coicideixi. (error EOL 2)\n");	
							yylineno++;
						} ;
%%

void yyerror(char *explanation) {
	if (strcmp(explanation, "--- FINAL DE FITXER --- Execució completada :)\n") == 0)	fprintf(fInfo,"%s", explanation);
	else 	fprintf(fInfo,"Línia %d\t%s", yylineno, explanation);
}

void addQuad(int num_args, ...) {
	va_list args;
	va_start(args, num_args);
	
	quad q;
	q.one = (char *)malloc(100);
	q.two = (char *)malloc(100);
	q.three = (char *)malloc(100);
	q.four = (char *)malloc(100);
	  
	if (num_args > 0) strcpy(q.one, va_arg(args, char*));
	if (num_args > 1) strcpy(q.two, va_arg(args, char*));
	if (num_args > 2) strcpy(q.three, va_arg(args, char*));
	if (num_args > 3) strcpy(q.four, va_arg(args, char*));

	quad_list[currQuad] = q;
		
	currQuad++;
	va_end(args);
}

char *newTemp(const char *prefix) {
   	char *tempPointer = (char *)malloc(50);
	
    	if (prefix) sprintf(tempPointer, "$%s_t%d", prefix, temp++);
     	else sprintf(tempPointer, "$t%d", temp++);

    	return tempPointer;
}


variable arithmeticCalc(variable v1, char *op, variable v2) {
    	variable result = {.type = UNDEFINED};
    	result.place = (char *)malloc(100);
    
    	if(strcmp(op, "**")==0) return powFunction(v1, v2, v1.name);
    	
	// Busca els valors a la taula de símbols
	CustomSymbol *sym1 = customSymLookup(v1.place);
	CustomSymbol *sym2 = customSymLookup(v2.place);

    	if (sym1 != NULL) v1.place = sym1->value;
    	if (sym2 != NULL) v2.place = sym2->value;

    	// Tractament per a tipus enters
    	if (v1.type == INTEGER && v2.type == INTEGER) {
        	result.type = INTEGER;
        	strcpy(result.place, newTemp(NULL));

		int val1 = atoi(v1.place);
		int val2 = atoi(v2.place);
		char tempValue[50];
		if (strcmp(op, "+") == 0) {		
			addQuad(4, result.place, "ADDI", v1.place, v2.place);		// SUMA
			sprintf(tempValue, "%d", val1 + val2);
		} else if (strcmp(op, "-") == 0) {
			addQuad(4, result.place, "SUBI", v1.place, v2.place);		// RESTA
			sprintf(tempValue, "%d", val1 - val2);
		} else if (strcmp(op, "*") == 0) {
			addQuad(4, result.place, "MULI", v1.place, v2.place);		// MULT
			sprintf(tempValue, "%d", val1 * val2);
		} else if (strcmp(op, "/") == 0) {
			if (strcmp(v2.place, "0") == 0) {
				fprintf(fInfo, "ERROR: Division by zero a la línia %d\n", yylineno);
       				return (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
		    	}
			addQuad(4, result.place, "DIVI", v1.place, v2.place);
		    	sprintf(tempValue, "%d", val1 / val2);				// DIV
		} else if (strcmp(op, "%") == 0) {		
			if (strcmp(v2.place, "0") == 0) {
				fprintf(fInfo, "ERROR: Modulo by zero a la línia %d\n", yylineno);
        			return (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" }; 
			}     
			sprintf(result.place, "%d", val1 % val2);
			addQuad(4, result.place, "MODI", v1.place, v2.place);		// MOD
		}

		customSymEnter(result.place, tempValue, INTEGER);
    	} else if ((v1.type == INTEGER || v1.type == FLOAT) && (v2.type == INTEGER || v2.type == FLOAT)) {
        	result.type = FLOAT;

		float val1 = atof(v1.place);
		float val2 = atof(v2.place);
		char tempValue[50];

        	if (v1.type == INTEGER) {
			char *temp = newTemp(NULL);
			addQuad(3, temp, "I2F", v1.place);
		    	sprintf(temp, "%.2f", atof(v1.place)); // Conversió
		    	v1.place = temp;
		    	v1.type = FLOAT;
        	}
        	if (v2.type == INTEGER) {
            		char *temp = newTemp(NULL);
            		addQuad(3, temp, "I2F", v2.place);
            		sprintf(temp, "%.2f", atof(v2.place)); // Conversió
            		v2.place = temp;
            		v2.type = FLOAT;
        	}

        	strcpy(result.place, newTemp(NULL));

        	if (strcmp(op, "+") == 0) {
        		addQuad(4, result.place, "ADDF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 + val2);
        	} else if (strcmp(op, "-") == 0) {
        		addQuad(4, result.place, "SUBF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 - val2);
        	} else if (strcmp(op, "*") == 0) {
        		addQuad(4, result.place, "MULF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 * val2);
        	} else if (strcmp(op, "/") == 0) {
           		if (atof(v2.place) == 0.0) {
				strcpy(result.place, "SEMANTIC ERROR: Division by zero");
				return result;
            		}
            		addQuad(4, result.place, "DIVF", v1.place, v2.place);
            		sprintf(tempValue, "%.2f", val1 / val2);
        	}

        	customSymEnter(result.place, tempValue, FLOAT);
	} else {
		result.type = UNDEFINED;
		strcpy(result.place, "SEMANTIC ERROR: Invalid operation");
    	}
    	return result;
}

long potenciaRecursiva(long base, long exponent) {
	if (exponent == 0) return 1;
    	else return base * potenciaRecursiva(base, exponent - 1);
}

variable powFunction(variable v1, variable v2, char* assign_name) {
    	variable result;
    	result.place = (char *)malloc(100);

    	if (v2.type != INTEGER) {
        	result.type = UNDEFINED;
        	strcpy(result.place, "SEMANTIC ERROR: L'exponent ha de ser enter.");
        	return result;
    	}

    	long base = atol(v1.place);
    	long exponent = atol(v2.place);

    	if (exponent < 0) {
        	result.type = UNDEFINED;
        	strcpy(result.place, "SEMANTIC ERROR: Exponent negatiu no suportat.");
        	return result;
    	}

    	long result_value = potenciaRecursiva(base, exponent); // Calcula la potència

	result.type = v1.type;
    	sprintf(result.place, "%ld", result_value);

    	addQuad(4, assign_name, "POWI", v1.place, v2.place);

    	customSymEnter(assign_name, result.place, result.type);

    	return result;
}

void printQuads() {
    	if (currQuad == 0) {
        	printf("quad_list is empty\n");
        	return;
    	}

    	int i = 0;
    	for (int i = 0; i < currQuad; i++) {
        	quad *q = &quad_list[i];

        	// Manté el nom original de q->one i busca el seu valor real
		char *destValue = q->one;
		CustomSymbol *symOne = customSymLookup(q->one);
		if (symOne != NULL) destValue = symOne->value;

		// Busca els valors reals dels operands de la dreta (q->three i q->four)
		char *valueThree = q->three;
		char *valueFour = q->four;

		CustomSymbol *symThree = customSymLookup(q->three);
		if (symThree != NULL) valueThree = symThree->value;

		CustomSymbol *symFour = customSymLookup(q->four);
		if (symFour != NULL) valueFour = symFour->value;

		// Maneig de quads segons el tipus
		if (strcmp(q->one, "PARAM") == 0)		printf("%d: PARAM %s\n", i + 1, q->two);
		else if (strcmp(q->one, "CALL") == 0)		printf("%d: CALL %s, %s\n", i + 1, q->two, q->three);
		else if (strcmp(q->two, "I2F") == 0)		printf("%d: %s := I2F %s\n", i + 1, q->one, valueThree);
		else if (strcmp(q->two, "CHSI") == 0)		printf("%d: %s := CHSI %s\n", i + 1, q->one, valueThree);
		else if (strcmp(q->two, "MODI") == 0)		printf("%d: %s := MODI %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, "MODF") == 0)		printf("%d: %s := MODF %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, ":=") == 0)		printf("%d: %s := %s\n", i + 1, q->one, q->three);
		else if (q->one[0] == '$')			printf("%d: %s := %s %s %s\n", i + 1, q->one, q->two, q->three, q->four);
		else if (strcmp(q->two, "POWI") == 0)		printf("%d: %s := POWI %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, "ADDI") == 0)		printf("%d: %s := ADDI %s, %s\n", i + 1, q->one, q->three, q->four); // pel comptador del bucle
		else if (strcmp(q->one, "GOTO") == 0)		printf("%d: GOTO %s\n", i + 1, q->two);
		/*else if (strcmp(q->one, "IF_FALSE") == 0) {
			CustomSymbol *cond = customSymLookup(q->two);
			if (cond != NULL && strcmp(cond->value, "0") == 0) {
				// La condició és falsa, saltem a l'etiqueta
				//printf("DEBUG: Saltant a %s (condició falsa)\n", q->three);
				for (int j = 0; j < currQuad; j++) {
				    if (strcmp(quad_list[j].one, q->three) == 0) {
					i = j - 1;  // Ajusta l'índex per continuar l'execució des de l'etiqueta
					break;
				    }
				}
			}
		} */ 
		else if (strcmp(q->two, "LTI") == 0) {
			printf("%d: %s := LTI %s, %s\n", i + 1, q->one, q->three, q->four);
		
		    	int v1 = atoi(q->three);
		    	int v2 = atoi(q->four);

		   	if (v1 < v2)	customSymEnter(q->one, "1", INTEGER);	// Afegeix l'entrada a la taula de símbols amb resultat 1 (true)
		    	else 	customSymEnter(q->one, "0", INTEGER);	// Afegeix l'entrada a la taula de símbols amb resultat 0 (false)
		
		} else if (strcmp(q->two, ":= ARRAY") == 0)	printf("%d: %s := ARRAY [%s]\n", i + 1, q->one, q->three);
		else printf("%d: %s := %s\n", i + 1, q->one, destValue);
   	}
    	printf("%d: HALT\n", i + 1);
}


void customSymEnter(char *name, char *value, int type) {
	
	// Comprova si és una variable temporal i la ignora
	if (name[0] == '$' && strstr(name, "_t") != NULL) {
		return; // No afegir temporals
	}
	
	for (int i = 0; i < customSymtabCount; i++) {
        	if (strcmp(customSymtab[i].name, name) == 0) {
            		free(customSymtab[i].value);
            		customSymtab[i].value = strdup(value);
			customSymtab[i].type = type;
			
            		// Detecta si el nom té un prefix associat a una taula i ajusta el tipus
            		/*if (type == INTEGER && strstr(name, "_t") != NULL)	customSymtab[i].type = ARRAY;
            		else customSymtab[i].type = type;*/
            		return;
        	}
    	}

    	if (customSymtabCount < CUSTOM_MAX_SYMBOLS) {
        	customSymtab[customSymtabCount].name = strdup(name);
        	customSymtab[customSymtabCount].value = strdup(value);
		customSymtab[customSymtabCount].type = type;
		
		// Detecta si el nom té un prefix associat a una taula i ajusta el tipus
		/*if (type == INTEGER && strstr(name, "_t") != NULL) {
		    customSymtab[customSymtabCount].type = ARRAY;
		} else {
		    customSymtab[customSymtabCount].type = type;
		}*/

        	customSymtabCount++;
	} else {
		printf("Error: Taula de símbols plena!\n");
	}
}

CustomSymbol *customSymLookup(char *name) {
	for (int i = 0; i < customSymtabCount; i++) {
        	if (strcmp(customSymtab[i].name, name) == 0)	return &customSymtab[i];
    	}
    	return NULL;
}

void mostrarCustomSymtab() {
    fprintf(fInfo, "Mostrant la taula de símbols personalitzada:\n");
    for (int i = 0; i < customSymtabCount; i++) {
        fprintf(fInfo, "Variable %s:\n\t->Valor: %s\n\t->Tipus: %s\n",
       customSymtab[i].name,
       customSymtab[i].value,
       customSymtab[i].type == INTEGER ? "INTEGER" :
       customSymtab[i].type == FLOAT ? "FLOAT" :
       customSymtab[i].type == ARRAY ? "ARRAY" : "UNDEFINED");
    }
}

int main(int argc, char** argv) {

    fInfo = fopen("sortida_proves.txt", "w");
    
    if (fInfo == NULL) {
        printf("Error: Unable to open log file sortida_proves.txt\n");
        return 1;
    }

    // Comprova si s'ha passat un fitxer d'entrada
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Error: Unable to open file %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("Error: No input file specified\n");
        return 1;
    }

    quad_list = (quad *)malloc(sizeof(quad) * MAX_QUADS);
    if (quad_list == NULL) {
    	printf("Error: No s'ha pogut al·locar memòria per a quad_list\n");
    	exit(1);
    }
    yyparse();

    mostrarCustomSymtab();
    printQuads();
    free(quad_list);

    if (fclose(fInfo) != 0) {
        printf("Error: Unable to close log file sortida_proves.txt\n");
        return 1;
    }

    return 0;
}


