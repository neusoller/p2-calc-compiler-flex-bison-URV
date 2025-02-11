%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "structs.h"
	#include "symtab.h"
	extern FILE *yyin;
	extern FILE* yyout;
	#include "calculator.tab.h"

%}

%option noinput nounput

%option noyywrap

int [0-9]*
float [0-9]*\.[0-9]*([eE][-+]?[0-9]+)?
string \".*\"



%%
 /* SENTÈNCIES ITERATIVES */
"repeat"  { return REPEAT; }
"do"      { return DO; }
"done"    { return DONE; }

 /* ENTER */
{int} {
	yylval.var.type = INTEGER;
	yylval.var.place = (char *)malloc(sizeof(char)*yyleng+1);
	strncpy(yylval.var.place, yytext, yyleng+1);
	return INT;
}

 /* REAL */
{float} {
	yylval.var.type = FLOAT;
	yylval.var.place = (char *)malloc(sizeof(char)*yyleng+1);
	strncpy(yylval.var.place, yytext, yyleng+1);
	return FL;
}

 /* COMENTARI SIMPLE */
"//".*		 { //yylval.var.type = STRING;
		   //yylval.var.value.sval = strdup(yytext);
		   return SCOMMENT; }
		      
"#".*            { //yylval.var.type = STRING;
		   //yylval.var.value.sval = strdup(yytext);
		   return SCOMMENT; }

 /* COMENTARI MULTIPLE */
"/*"([^#=].|\n)*"*/"    { // yylval.var.type = STRING;
			  // yylval.var.value.sval = strdup(yytext); /* copio tot el comentari */
			  return MCOMMENT; }

 /* OPERADORS ARITMÈTICS */
\*\*            { return POW; }

"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }

"+"             { return ADD; }
"-"             { return SUB; }

"("             { return LPAREN; }
")"             { return RPAREN; }

"["		{ return LB; }
"]"      	{ return RB; }

":="		{ return ASSIGN; }
";"		{ return PC; }
","		{ return COMA; }

"\n"            { return EOL; }
"\t"            {}
"\r"            {}
" "             {}

[a-zA-Z0-9]*   { 
    yylval.var.name = (char *)malloc(sizeof(char) * yyleng + 1);
    strncpy(yylval.var.name, yytext, yyleng);
    yylval.var.name[yyleng] = '\0';

    variable aux;

    if (sym_lookup(yytext, &aux) == SYMTAB_NOT_FOUND) {
        return ID;
    } else {
        return A_ID;
    }
}

. {return LERR;}


<<EOF>>                 { return END; }

%%
