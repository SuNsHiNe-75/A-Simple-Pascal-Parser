FILE_lex=	B083040010.l
PROG_lex=	lex.yy.c
FILE_yacc=	B083040010.y
PROG_yacc=	y.tab.c
all:	$(PROG_yacc) $(PROG_lex)
	gcc y.tab.c $(PROG_lex) -ly -lfl

$(PROG_yacc):	$(FILE_yacc)
	bison -y -d $(FILE_yacc)

$(PROG_lex):	$(FILE_lex)
	flex $(FILE_lex)

clean:
	rm a.out $(PROG_lex) $(PROG_yacc) y.tab.h
