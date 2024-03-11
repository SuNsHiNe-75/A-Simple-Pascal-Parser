%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int yylex();
int max=0, can_in=1, tempnum=0, temp_size, temp_isarray=0, findit=0;
char* temp_id[256], temp_t; 
extern int position, line, pre_p, ok, pre_l; // For recording previous token's "position" and "line", for finding the "ERROR position".
char* output;
char* temp;
char* temp2;
void yyerror(const char* msg){ // used to deal with ERROR msgs.
	ok=0;
	printf("\rLine %d, at char %d, ",pre_l,pre_p);
	printf("%s                    \n",msg);
};
struct table{ // ID table : for Error of "ID".
	char* id;
	char* type;
	int isarray;
	int arraysize;
}idtable[256];
void insert(char* temp_type){ // For inserting ID or type etc into the idtable[].
	for (int k=0;k<tempnum;k++){
		for (int j=0 ; j < max ; j++){
			if (idtable[j].id==temp_id[k]){
				can_in=0;break;
			}
		}
		if (can_in==1){
			if (temp_isarray==1){
				idtable[max].isarray=1;
				idtable[max].arraysize=temp_size;
			}
			idtable[max].id=temp_id[k];
			for (int l=0;l<strlen(temp_type);l++) temp_type[l]=tolower(temp_type[l]);
			idtable[max++].type=temp_type;
		}
		else { // Repeated Declaration.
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Duplicate identifier '%s'                    \n",temp_id[k]);
			can_in=1;break;
		}
	}
	temp_isarray=0;tempnum=0;
};
char* find(char* findid){ // To find "type".(expected)
	for (int l=0;l<strlen(findid);l++) findid[l]=tolower(findid[l]);
	for (int i=0;i<max;i++) if (strcmp(idtable[i].id,findid)==0) return idtable[i].type;
	return "";
}
char* findexp(char* findid){ // what we got.
	if (strcmp(findid,"ntype")==0) return "ntype";
	for (int i=0;i<strlen(findid);i++) if (findid[i]=='.') return "real";
	for (int i=0;i<strlen(findid);i++) if (findid[i]>=48&&findid[i]<=57) return "integer";
	for (int l=0;l<strlen(findid);l++) findid[l]=tolower(findid[l]);
	for (int i=0;i<max;i++) if (strcmp(idtable[i].id,findid)==0) return idtable[i].type;
	return "";
}
%}
%error-verbose // To learn the entire ERROR msg.
%union {
	char* name;
}
%type <name> prog prog_name dec_list dec type standtype arraytype id_list stmt_list stmt assign ifstmt exp relop simpexp term factor read write write_list for index_exp varid body error
%token <name> ABSOLUTE AND BBEGIN BREAK CASE CONST CONTINUE DO ELSE END FOR FUNCTION IF MOD NIL NOT OBJECT OF OR PROGRAM THEN TO VAR WHILE ARRAY INTEGER DOUBLE WRITE WRITELN STRING CHAR FLOAT READ REALTYPE //reserved word
%token <name> ASSIGNMENT COLON COMMA DOT EQUAL GE GT LBRAC LE LPAREN LT MINUS NOTEQUAL PLUS RBRAC RPAREN SEMICOLON SLASH STAR UPARROW //symbol
%token <name> INT REAL STR ID IOI IOR ROI ROR IDOI IDOR
%%
// prog: Same as the simplified grammar presented by the Specification. In addition, dealing with the condition that "End in no DOT". And added "| error" for keep running.
prog : PROGRAM prog_name SEMICOLON VAR dec_list SEMICOLON BBEGIN stmt_list SEMICOLON END DOT
	| PROGRAM prog_name SEMICOLON VAR dec_list SEMICOLON BBEGIN stmt_list SEMICOLON END{	
		ok=0;
		printf("\rLine %d, at char %d, ",pre_l,pre_p+3);
		printf("syntax error, unexpected $end, expecting DOT\n");
	}|error;
// prog_name: Same as the simplified grammar presented by the Specification.
prog_name :  ID;
// dec_list: Same as the simplified grammar presented by the Specification.
dec_list : dec 
	| dec_list SEMICOLON dec;
// dec: There may be syntax error, so "| error" to keep running.
dec : id_list COLON type 
	| error;
// type: Same as the simplified grammar presented by the Specification.
type : standtype {insert($1);}
	| arraytype ;
// standtype: Additionally dealing with "STRING", "CHAR".
standtype : INTEGER
	| REALTYPE
	| STRING
	| CHAR; 
// arraytype: { Just to deal with $x, array. }
arraytype : ARRAY LBRAC INT DOT DOT INT RBRAC OF standtype {temp_size=$6-$3-91;temp_isarray=1;insert($9);};
// id_list: { Put "ID" into temp to be able to put into idtable0 }. There might be error.
id_list : ID {temp_id[tempnum++] = $1;}
	| id_list COMMA ID {temp_id[tempnum++] = $3;}
	| error;
// stmt_list: Same as the simplified grammar presented by the Specification.
stmt_list : stmt 
	| stmt_list SEMICOLON stmt;
// stmt: Same as the simplified grammar presented by the Specification.
stmt : assign 
	| read 
	| write 
	| for 
	| ifstmt 
	| WRITELN;
// assign
assign : varid ASSIGNMENT simpexp { // Error of ASSIGNMENT.
		if (find($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
		else if (findexp($3)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$3);
		}
		else if (findexp($3)=="ntype"){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",temp,temp2);
		}
		else if (strcmp(find($1),findexp($3))!=0 && strcmp(findexp($3),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),find($1));
		}
	}
	| varid relop simpexp { // Error of ":=".
		ok=0;
		if (find($1)==""){
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
		else{
			printf("\rLine %d, ",pre_l);
			printf("syntax error, unexpected '%s', expecting ':='\n",$2);
		}
	}
	| varid ASSIGNMENT STR{ // Error of "STR(string)".
		if (find($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
		else if (strcmp(find($1),"string")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected 'string'\n",find($1));
		}
	}
	| varid relop STR {
		ok=0;
		if (find($1)==""){
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
		else{
			printf("\rLine %d, ",pre_l);
			printf("syntax error, unexpected '%s', expecting ':='\n",$2);
		}
	}
	| error;
// ifstmt: Same as the simplified grammar presented by the Specification.
ifstmt : IF LPAREN exp RPAREN THEN body;
// exp: like what "assign" does.
exp : simpexp {
		if (findexp($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
	}
	| exp relop simpexp{
		if (findexp($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}
		else if (findexp($3)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$3);
		}
		else if (strcmp(findexp($1),findexp($3))!=0 && strcmp(findexp($3),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),findexp($1));
		}
	};
// relop: Same as the simplified grammar presented by the Specification.
relop : GT 
	| LT 
	| GE 
	| LE 
	| NOTEQUAL 
	| EQUAL;
simpexp : term
	| simpexp PLUS term {
		temp=strdup(findexp($3));
		temp2=strdup(findexp($1));
		if (strcmp(findexp($1),findexp($3))!=0) $$=strdup("ntype");
		else $$=$1;
	}
	| simpexp MINUS term {
		if (strcmp(findexp($1),findexp($3))!=0 && strcmp(findexp($3),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),findexp($1));$$=strdup("ntype");
		}
		else if (strcmp(findexp($3),"ntype")==0) {$$="ntype";}
		else $$=$1;
	};
// term: "*", "/", "%".
term : factor 
	| term STAR factor {
		if (strcmp(findexp($1),findexp($3))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),findexp($1));$$=strdup("ntype");
		}
		else $$=$1;
	}
	| term SLASH factor {
		if (strcmp(findexp($1),findexp($3))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),findexp($1));$$=strdup("ntype");
		}
		else $$=$1;
	}
	| term MOD factor {
		if (strcmp(findexp($1),findexp($3))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp($3),findexp($1));$$=strdup("ntype");
		}
		else $$=$1;
	};
// factor: Same as the simplified grammar presented by the Specification.
factor : varid 
	| INT 
	| REAL 
	| LPAREN simpexp RPAREN;
// read: Same as the simplified grammar presented by the Specification.
read : READ LPAREN read_list RPAREN;
// id-list => read/write_list, for detailed discussion.
read_list : varid {
		if (findexp($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}temp_isarray=0;tempnum=0;
	}
	| STR 
	| read_list COMMA varid {
		if (findexp($3)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$3);
		}temp_isarray=0;tempnum=0;
	}
	| read_list COMMA STR;
write : WRITE LPAREN write_list RPAREN;
write_list : varid {
		if (findexp($1)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$1);
		}temp_isarray=0;tempnum=0;
	}
	| STR 
	| write_list COMMA varid {
		if (findexp($3)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$3);
		}temp_isarray=0;tempnum=0;
	}
	| write_list COMMA STR;
for : FOR index_exp DO body;
index_exp : varid ASSIGNMENT simpexp TO exp;
varid : ID
	| ID LBRAC simpexp RBRAC{
		if (findexp($3)==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",$3);
		}
		else if (strcmp(findexp($3),"integer")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s'                     ,expected 'integer'\n",findexp($3));
		}
	};
body : stmt 
	| BBEGIN stmt_list SEMICOLON END;
%%
int main(){
	yyparse();
	return 0;
}
