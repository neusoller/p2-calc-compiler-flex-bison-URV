# --------- definir compilador
CC = gcc

# al compilador C
# -Wall-> warnings
# -g -> errors (debug)
# -I. -> --------------------------------------------------------------------
CFLAGS=-g -Wall -I.

######################################################################

# calculator: nom de l'objectiu final
# calculator.tab.o lex.yy.o symtab.o functions.o: 
#		Per generar "calculator", s'hauran de compilar aquests fitxers.

# $(CC) -o $@ $^ -lm: 
#		Executa el compilador gcc per enllaçar els fitxers objecte i generar l'executable.
#		-> $@: calculator
#		-> $^: fitxers objecte
#		-> -lm: biblioteca matemàtica libm (sin, cos, etc.)
calculator: calculator.tab.o lex.yy.o symtab.o
	$(CC) -o $@ $^ -lm

# calculator.tab.o:
#		Es compilarà a partir de calculator.tab.c.
#
# La regla utilitza $(CC) amb $(CFLAGS) per compilar el fitxer font en un fitxer objecte.
#		-> $<: primer prerequisit (calculator.tab.c)
#		-> -c: Només es compila el fitxer font, no enllaçar-lo.
calculator.tab.o: calculator.tab.c
	$(CC) $(CFLAGS) -c $<

# bison:
#	Genera el fitxer calculator.tab.c i el fitxer d'encapçalament calculator.tab.h 
#	a partir del fitxer calculator.y 
calculator.tab.c: calculator.y
	bison -d $<

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $<

# flex:
#	Genera el fitxer lex.yy.c a partir del fitxer calculator.l
lex.yy.c: calculator.l
	flex $<

# symtab.o i functions.o:
#	Es compilen a partir dels fitxers fonts symtab.c i functions.c respectivament
symtab.o: symtab.c
	$(CC) $(CFLAGS) -c $<

# Neteja dels fitxers generats
.PHONY: clean
clean:
	rm -f calculator calculator.tab.c calculator.tab.h lex.yy.c *.o log.txt
