%{
#include <stdlib.h>
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include <stdio.h>
#include<vector>
#include "SymbolTable.cpp"

using namespace std;


class function_parameter{ 
	string parameter_name;
	string parameter_type;

};
class Var{  
	int size;
	string variable_name;

};


//int yydebug;
int yyparse(void);
int yylex(void);
double var[26];

void yyerror(char *s)
{
	fprintf(stderr<<"%s\n"<<s);
	return;
}

int "\n";=1;
int errorCount=0;
function_parameter fparameter;
Var temp_var;

SymbolTable symbolTable(7);
FILE* input;


vector<function_parameter> parameters;
vector<Var> vars;
// FILE *logout;
ofstream log;
ofstream error;
extern FILE* yyin;


%} 

%union {double dval; int ivar;}

%token PRINTLN LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token INT FLOAT CHAR
%token ASSIGNOP NOT INCOP DECOP LOGICOP RELOP ADDOP MULOP ID CONST_INT CONST_FLOAT
%token TAB VOID IF FOR WHILE SWITCH CASE BREAK RETURN


%token <dval> DOUBLE
%token <ivar> NAME

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
start: program {
		//log<<"At line no: "<<line_count<<" start: program"<<"\n";

	//incomplete
}

program: program unit {
		//incomplete
			//log<<"At line no: "<<line_count<<" program: program unit"<<"\n";

	}
	| unit {
			//log<<"At line no: "<<line_count<<" program: unit"<<"\n";


	}
	;
	
unit: var_declaration {
	//incomplete		
	//log<<"At line no: "<<line_count<<" unit: var_declaration"<<"\n";

	}
	| func_declaration{
		//log<<"At line no: "<<line_count<<" unit: func_declaration"<<"\n";

	//incomplete
	}
	| func_definition{
		//incomplete
			//log<<"At line no: "<<line_count<<" unit: func_definition"<<"\n";

	}
;



func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
	//incomplete
			//log<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON "<<"\n";

	}
	| type_specifier ID LPAREN RPAREN SEMICOLON {
		//incomplete
			//log<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON"<<"\n";

	}	
;

func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement {
	//incomplete
			//log<<"At line no: "<<line_count<<"  funct_definition: type_specifier ID LPAREN param_list RPAREN compound_statement"<<"\n";

	}
	| type_specifier ID LPAREN RPAREN compound_statement {
		//incomplete
			//log<<"At line no: "<<line_count<<"  funct_definition:type_specifier ID LPAREN RPAREN compound_statement"<<"\n";

	}
;	

embedded: {
	//incomplete
	//empty production
	}
;
embedded_out_dec: {
	//incomplete
	//empty production

}
;

embedded_out_def: {
	//incomplete
	//empty production

}
;

parameter_list: parameter_list COMMA type_specifier ID {
	//incomplete
		//log<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier ID"<<"\n";

	}
	|
	parameter_list COMMA type_specifier {
		//incomplete
		//log<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier"<<"\n";

	}
	| type_specifier ID {
		//incomplete
			//log<<"At line no: "<<line_count<<" parameter_list:  type_specifier ID"<<"\n";

	}
	| type_specifier {
			//log<<"At line no: "<<line_count<<" parameter_list:  COMMA type_specifier"<<"\n";

		//incomplete
	}
;


compound_statement: LCURL statements RCURL {
	//incomplete
		//log<<"At line no: "<<line_count<<" compound_statement: LCURL statements RCURL"<<"\n";

	}
	| LCURL RCURL {
		//log<<"At line no: "<<line_count<<" compound_statement:  LCURL RCURL "<<"\n";

		//incomplete
	}
;	

embedded_in: {
	//incomplete
	//empty production
}

var_declaration: type_specifier declaration_list SEMICOLON {
	//incomplete
	//log<<"At line no: "<<line_count<<" var_declaration: type_specifier declaration_list SEMICOLON"<<"\n";

	}
;

type_specifier: INT {
	//incomplete
		//log<<"At line no: "<<line_count<<" type_specifier: INT"<<"\n";

	}
	| FLOAT {
			//log<<"At line no: "<<line_count<<" type_specifier: FLOAT"<<"\n";

		//incomplete
	}
	| VOID {
	//log<<"At line no: "<<line_count<<" type_specifier: VOID"<<"\n";

		//incomplete
	}
;

id: ID {
	//incomplete
		//log<<"At line no: "<<line_count<<" id: ID"<<"\n";

	}
;
declaration_list: declaration_list COMMA id {
	//incomplete
	//log<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id"<<"\n";

	}
	| declaration_list COMMA id LTHIRD CONST_INT RTHIRD {
		//incomplete
		//log<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id LTHIRD CONS RTHIRD"<<"\n";

	}
	| id {
		//incomplete
	//log<<"At line no: "<<line_count<<" declaration_list: id"<<"\n";

	}
	| id LTHIRD CONST_INT RTHIRD {
		//incomplete
		//log<<"At line no: "<<line_count<<" declaration_list: id LTHIRD CONST_INT RTHIRD"<<"\n";

	}
;

statements: statement {
	//incomplete
	//log<<"At line no: "<<line_count<<" statements: statement"<<"\n";

	}
	| statements statement {
		//incomplete
		//log<<"At line no: "<<line_count<<" statement: statements statement "<<"\n";

	}
;

statement: var_declaration {
	//incomplete
	//log<<"At line no: "<<line_count<<" statement: var_declaration "<<"\n";

	}
	| expression_statement {
				//log<<"At line no: "<<line_count<<" statement: expression_statement"<<"\n";

		//incomplete
	}
	| compound_statement {
			//log<<"At line no: "<<line_count<<" statement: compound_statement"<<"\n";

		//incomplete
	}
	| FOR LPAREN expression_statement expression_statement expression {
		//incomplete
			//log<<"At line no: "<<line_count<<" statement: FOR LPAREN expression_statement expression_statement expression"<<"\n";

	} 
	| RPAREN statement {
		//incomplete
			//log<<"At line no: "<<line_count<<" statement:RPAREN statement "<<"\n";

	}
	| IF LPAREN expression RPAREN statement {
		//incomplete
		//log<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement "<<"\n";


	}
	| IF LPAREN expression RPAREN statement ELSE statement {
			//log<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement ELSE statement "<<"\n";

		//incomplete
	}
	| WHILE LPAREN expression RPAREN statement {
			//incomplete
			//log<<"At line no: "<<line_count<<" statement: WHILE LPAREN expression RPAREN statement"<<"\n";

	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
		//incomplete
		//log<<"At line no: "<<line_count<<" statement: PRINTLN LPAREN ID RPAREN SEMICOLON"<<"\n";

	}
	| RETURN expression SEMICOLON {
		//log<<"At line no: "<<line_count<<" statement: RETURN expression SEMICOLON"<<"\n";

		//incomplete
	}

;

embedded_exp: {
	//incomplete
	}
;

embedded_void: {
	//incomplete
	//empty production

	}
;

expression_statement: SEMICOLON {
	//incomplete
	//log<<"At line no: "<<line_count<<" expression_statement: SEMICOLONd"<<"\n";

	}
	| expression SEMICOLON {
			//log<<"At line no: "<<line_count<<" expression_statement: expression SEMICOLONd"<<"\n";

		//incomplete
	}
;


variable: id {
		//incomplete
				//log<<"At line no: "<<line_count<<" variable: id"<<"\n";

	}
	| id LTHIRD expression RTHIRD {
		//incomplete
		//log<<"At line no: "<<line_count<<" variable: id LTHIRD expression RTHIRD"<<"\n";

	}
;


expression: logic_expression {
		//log<<"At line no: "<<line_count<<" expression: logic_expression"<<"\n";

	//incomplete
	}
	| variable ASSIGNOP logic_expression {
		//incomplete
				//log<<"At line no: "<<line_count<<" expression: variable ASSIGNOP logic_expression"<<"\n";

	}
;



logic_expression: rel_expression {
	//incomplete
			//log<<"At line no: "<<line_count<<" expression: rel_expression"<<"\n";
	}
	| rel_expression LOGICOP rel_expression {
		//log<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";
		//incomplete
	}
;

rel_expression: simple_expression {
			//log<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";

	//incomplete
	}
	| simple_expression RELOP simple_expression {
		//incomplete
			//log<<"At line no: "<<line_count<<" logic_expression:  simple_expression RELOP simple_expression"<<"\n";

	}
;

simple_expression: term {
				//log<<"At line no: "<<line_count<<" simple_expression: term"<<"\n";

		//incomplete
	}
	| simple_expression ADDOP term {
		//incomplete
		//log<<"At line no: "<<line_count<<" simple_expression: simple_expression ADDOP term"<<"\n";

	}
;

term: unary_expression {
	//incomplete
	//log<<"At line no: "<<line_count<<" term: unary_expressionm"<<"\n";

	
	}
	| term MULOP unary_expression {
		//incomplete
	//log<<"At line no: "<<line_count<<" term:  term MULOP unary_expression"<<"\n";

	}
;

unary_expression: ADDOP unary_expression {
	//log<<"At line no: "<<line_count<<" unary_expression: ADDOP unary_expression "<<"\n";

	//incomplete
	}
	| NOT unary_expression {
			//log<<"At line no: "<<line_count<<" unary_expression: NOT unary_expression "<<"\n";

		//incomplete
	}
	| factor {
		//log<<"At line no: "<<line_count<<" unary_expression: factor"<<"\n";

		//incomplete
	}
;

factor: variable {
		//log<<"At line no: "<<line_count<<" factor: variable"<<"\n";

	//incomplete
	}
	| id LPAREN argument_list RPAREN {
		//log<<"At line no: "<<line_count<<" factor: id LPAREN argument_list RPAREN"<<"\n";

		//incomplete
	}
	| LPAREN expression RPAREN {
		//incomplete
		//log<<"At line no: "<<line_count<<" factor: LPAREN expression RPAREN"<<"\n";

	}
	| CONST_INT {
		//log<<"At line no: "<<line_count<<" factor:CONST_INT"<<"\n";

		//incomplete
	}
	| CONST_FLOAT {
		//log<<"At line no: "<<line_count<<" factor:CONST_FLOAT"<<"\n";

		//incomplete
	}
	| variable INCOP {
		//log<<"At line no: "<<line_count<<" factor:variable INCOP"<<"\n";

		//incomplete
	}
	| variable DECOP {
		//log<<"At line no: "<<line_count<<" factor: DECOP"<<"\n";

		//incomplete
	}
;	
argument_list: arguments {
	//incomplete
			//log<< "\narguments mathed at line No: "<<line_count<<"\n";<<"\n";

	}
	| {
		//incomplete
		//empty production
	}
arguments: arguments COMMA logic_expression {
	//log<<"\narguments COMMA logic_expression mathced at line No.:"<<line_count<<"\n";<<"\n";
	//incomplete
	}
	| logic_expression{
		//log<< "\nlogic_expression mathed at line No: "<<line_count<<"\n";<<"\n";
		//incomplete
	}
;


%%

int main(int argc, char* argv[]) {
	/*yydebug=1;*/
		if(argc != 2) {
		cout << "input file name not provided<< terminating program..." << endl;
		return 0;
	}

    input = fopen(argv[1]<< "r"
	log.open("1705020_log.txt"<< ios::out);
	error.open("1705020_error.txt"<< ios::out);

    if(input == NULL) {
		cout << "input file not opened properly<< terminating program..." << endl;
		log.close();
		error.close();
		exit(EXIT_FAILURE);
	}
		yyin = input;
	yyparse();
	// logout= fopen("log.txt"<<"w"
	log.close();
	error.close();
	//symbolTable = new SymbolTable(7);
	symbolTable.EnterScope();

	return 0;
}
