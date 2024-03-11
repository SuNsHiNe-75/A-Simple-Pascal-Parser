%{
#include "y.tab.h"
#include <stdio.h>
unsigned int line=1,position=1,pre_p=1,pre_l=1,ok=1;
%}
%x sc
letter [a-zA-Z]
digit [0-9]
eol \r\n|\n
id [a-zA-Z_][a-zA-Z0-9_]{0,14}
integer [+-]?0|[+-]?[1-9][0-9]*
fraction [0-9][1-9]*
string [']([^'\n\r\n]|[']['][^'\n\r\n]*)*[']
comment [(][*]([^*]|{eol}|([*]+([^*)]|{eol})))*[*]+[)]{eol}*
real ({integer}|{integer}"."{fraction})([Ee]{integer})?
%%
<*>[Aa][Bb][Ss][Oo][Ll][Uu][Tt][Ee] {
if (position==1&&ok==1) printf("Line %d: ",line);
if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return ABSOLUTE;}
<*>[Aa][Nn][Dd] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return AND;}
<*>[Bb][Ee][Gg][Ii][Nn] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return BBEGIN;}
<*>[Bb][Rr][Ee][Aa][Kk] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return BREAK;}
<*>[Cc][Aa][Ss][Ee] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return CASE;}
<*>[Cc][Oo][Nn][Ss][Tt] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return CONST;}
<*>[Cc][Hh][Aa][Rr] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return CHAR;}
<*>[Cc][Oo][Nn][Tt][Ii][Nn][Uu][Ee] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return CONTINUE;}
<*>[Dd][Oo] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return DO;}
<*>[Ee][Ll][Ss][Ee]  {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return ELSE;}
<*>[Ee][Nn][Dd] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return END;}
<*>[Ff][Oo][Rr] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return FOR;}
<*>[Ff][Uu][Nn][Cc][Tt][Ii][Oo][Nn] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return FUNCTION;}
<*>[Ii][Ff] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return IF;}
<*>[Mm][Oo][Dd] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return MOD;}
<*>[Nn][Ii][Ll] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return NIL;}
<*>[Nn][Oo][Tt] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return NOT;}
<*>[Oo][Bb][Jj][Ee][Cc][Tt] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return OBJECT;}
<*>[Oo][Ff] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return OF;}
<*>[Oo][Rr] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return OR;}
<*>[Pp][Rr][Oo][Gg][Rr][Aa][Mm] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return PROGRAM;}
<*>[Tt][Hh][Ee][Nn] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return THEN;}
<*>[Tt][Oo] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return TO;}
<*>[Vv][Aa][Rr] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return VAR;}
<*>[Ww][Hh][Ii][Ll][Ee] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return WHILE;}
<*>[Aa][Rr][Rr][Aa][Yy] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return ARRAY;}
<*>[Ii][Nn][Tt][Ee][Gg][Ee][Rr] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return INTEGER;}
<*>[Dd][Oo][Uu][Bb][Ll][Ee] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return DOUBLE;}
<*>[Ww][Rr][Ii][Tt][Ee] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return WRITE;}
<*>[Ww][Rr][Ii][Tt][Ee][Ll][Nn] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return WRITELN;}
<*>[Ss][Tt][Rr][Ii][Nn][Gg] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return STRING;}
<*>[Ff][Ll][Oo][Aa][Tt] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return FLOAT;}
<*>[Rr][Ee][Aa][Dd] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return READ;} 
<*>[Rr][Ee][Aa][Ll] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return REALTYPE;} 
<*>[ ] {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1) printf(" ");position++;} 
<*>[ ]*{eol} {if (position!=1&&ok==1) printf("\n");ok=1;position=1;line++;} 
{integer} {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN sc;return INT;} 
{real} {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN sc;return REAL;} 
{string} {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return STR;}	
<*>":="    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return ASSIGNMENT;} 
<*>":"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return COLON;}
<*>","    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return COMMA;}
<*>"."    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return DOT;}
<*>"="    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return EQUAL;}
<*>">="    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return GE;}
<*>">"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return GT;}
<*>"["    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return LBRAC;}
<*>"<="    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return LE;}
<*>"("    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return LPAREN;}
<*>"<"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return LT;}
<sc>"-"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return MINUS;}
<*>"<>"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return NOTEQUAL;}
<sc>"+"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return PLUS;}
<*>"]"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return RBRAC;}
<*>")"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return RPAREN;}
<*>";"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return SEMICOLON;}
<*>"/"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return SLASH;}
<*>"*"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return STAR;}
<*>"^"    {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN 0;return UPARROW;}	
<*>{id} {if (position==1&&ok==1) printf("Line %d: ",line);if (ok==1){printf("%s",yytext);}pre_p=position;pre_l=line;position+=yyleng;yylval.name=strdup(yytext);BEGIN sc;return ID;}
<*>[ ]*{comment} {
	for (int i=0;i<yyleng;i++) {if (yytext[i]==10){line++;position=1;} else position++;}BEGIN 0;
}	//comment
%%

