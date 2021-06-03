%{
#include <stdlib.h>
#include <stdio.h>
#include "SymbolTable.cpp"

//int yydebug;
int yyparse(void);
int yylex(void);
double var[26];

void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	return;
}

%}

%union {double dval; int ivar;}

%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token ASSIGNOP NOT INCOP DECOP LOGICOP RELOP ADDOP MULOP CONST_INT CONST_FLOAT
%token VOID IF ELSE FOR WHILE RETURN


%token <dval> DOUBLE
%token <ivar> ID
%type <dval> expr
%type <dval> mulex
%type <dval> term

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

program:
	line program		{printf("program->line program\n");}
	| line			{printf("program->line\n");}
	;

line:
	expr 	'\n' 		{ printf("line->expr\\n\n"); printf("%g\n",$1); }
	| ID '=' expr '\n' 	{ printf("line->ID = expr\\n\n"); var[$1] = $3; }
	;

expr:
	expr '+' mulex 		{ printf("expr->expr+mulex\n"); $$ = $1 + $3; }
	| expr '-' mulex 	{ printf("expr->expr-mulex\n"); $$ = $1 - $3; }
	| mulex 		{ printf("expr->mulex\n"); $$ = $1; }
	;
mulex:
	mulex '*' term 		{ printf("mulex->mulex*term\n"); $$ = $1 * $3; }
	| mulex '/' term 	{ printf("mulex->mulex/term\n"); $$ = $1 / $3; }
	| term 			{ printf("mulex->term\n"); $$ = $1; }
	;
term:
	'(' expr ')' 		{ printf("term->(expr)\n"); $$ = $2; }
	| ID 			{ printf("term->ID\n"); $$ = var[$1]; }
	| DOUBLE 		{ printf("term->DOUBLE\n"); $$ = $1; }
	;
%%

int main(void){
	/*yydebug=1;*/
	yyparse();
	return 0;
}
