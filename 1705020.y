%{
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "SymbolTable.cpp"
// #define YYSTYPE SymbolInfo*
// #define YYSTYPE string

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE* yyin;

int line_count = 1;  // NOTICE
int error_count = 0;
int scope_count = 1;

SymbolTable symbolTable(7);


// YYSTYPE symbol_Info;
FILE* input;
FILE* mylog;
ofstream logout;
ofstream error;
// std::ofstream logout;
// std::ofstream error;

/* auxiliary variables and structures and containers */
string type, type_final;  // basially for function declaration-definition
string name, name_final;  // basically for function declaration-definition


struct var{
	//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    string var_name;
    int var_size;  // it is set to -1 for variables
} temp_var;

struct fuclsym{
	SymbolInfo *fucksym;
	
};
vector<var> var_list;  // for identifier(variable, array) insertion into symbolTable

struct parameter {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    string param_type;
    string param_name;  // it is set to empty string "" for function declaration
} temp_parameter;

struct symbol_attribute{
		string key;
		char* value;
};
struct Symbol {
		char* key;
		char* value;
} *sym;


vector<parameter> param_list;  // parameter list for function declaration, definition

vector<string> arg_list;  // argument list for function call

/* auxiliary functions */

void insertVar(string _type, var var_in) {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    // /* symbolTable insertion for variable and array */
    // SymbolInfo* symbolInfo = new SymbolInfo(var_in.var_name, "ID");
    // symbolInfo->set_Type(_type);  // setting variable type
    // symbolInfo->set_arrSize(var_in.var_size);

    // symbolTable.insertSymbol(*symbolInfo);
    // return ;
}

void insertFunc(string _type, string name, int _size) {
    // /* symbolTable insertion for function(declaration and definition) */
    // SymbolInfo* symbolInfo = new SymbolInfo(name, "ID");
    // symbolInfo->set_Type(_type);  // setting return type
    // symbolInfo->set_arrSize(_size);  // NOTICE: for distinguishing between declaration and definition
    
    // for(int i=0; i<param_list.size(); i++) {
    //     symbolInfo->addParam(param_list[i].param_type, param_list[i].param_name);
    // }

    // symbolTable.insertSymbol(*symbolInfo);
    // return ;
}





/* yyerror function for reporting syntax error */
void yyerror(char*); 
%}

// %union { symbol sym;}

%union {
		char *str;
		struct symbol_attribute *fs;
		// struct Symbol *symbol;
		
	} 
// %define api.value.type {SymbolInfo*}
%token CONST_INT CONST_FLOAT ID
%token INT CHAR DOUBLE TAB FLOAT VOID IF ELSE FOR WHILE PRINTLN RETURN
%token ASSIGNOP NOT INCOP DECOP LOGICOP RELOP ADDOP MULOP
%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON 

%token <fs> SYMBOLA;
// %token <sym> S

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE


%%

start: program {
	fprintf(mylog,"At line No.%d start: program\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" start: program"<<"\n";

	//incomplete
}

program: program unit {
	fprintf(mylog,"At line No.%d program: program unit\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" program: program unit"<<"\n";

	}
	| unit {
		fprintf(mylog,"At line No.%d program: unit\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" program: unit"<<"\n";


	}
	;
	
unit: var_declaration {
	fprintf(mylog,"At line No.%d unit: var declaration\n\n",line_count);
	//incomplete		
	//logout<<"At line no: "<<line_count<<" unit: var_declaration"<<"\n";

	}
	| func_declaration{
		fprintf(mylog,"At line No.%d unit: func_declaration\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" unit: func_declaration"<<"\n";

	//incomplete
	}
	| func_definition{
		fprintf(mylog,"At line No.%d unit: func_definition\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" unit: func_definition"<<"\n";

	}
;



func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
	fprintf(mylog,"At line No.%d func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON "<<"\n";

	}
	| type_specifier ID LPAREN RPAREN SEMICOLON {
		fprintf(mylog,"At line No.%d func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON \n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON"<<"\n";

	}	
;

func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement {
	fprintf(mylog,"At line No.%d func_definition: type_specifier ID LPAREN param_list RPAREN compound_statement\n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<"  funct_definition: type_specifier ID LPAREN param_list RPAREN compound_statement"<<"\n";

	}
	| type_specifier ID LPAREN RPAREN compound_statement {
		fprintf(mylog,"At line No.%d func_definition:type_specifier ID LPAREN RPAREN compound_statement\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<"  funct_definition:type_specifier ID LPAREN RPAREN compound_statement"<<"\n";

	}
;	





parameter_list: parameter_list COMMA type_specifier ID {
	fprintf(mylog,"At line No.%d parameter_list: parameter_list COMMA type_specifier ID\n\n",line_count);
	//incomplete
		//logout<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier ID"<<"\n";

	}
	|
	parameter_list COMMA type_specifier {
		fprintf(mylog,"At line No.%d  parameter_list: parameter_list COMMA type_specifier\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier"<<"\n";

	}
	| type_specifier ID {
		fprintf(mylog,"At line No.%d  parameter_list:  type_specifier ID\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" parameter_list:  type_specifier ID"<<"\n";

	}
	| type_specifier {
		fprintf(mylog,"At line No.%d parameter_list:  type_specifier\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" parameter_list:  COMMA type_specifier"<<"\n";

		//incomplete
	}
;


compound_statement: LCURL embedded_in statements RCURL {
	fprintf(mylog,"At line No.%d compound_statement: LCURL statements RCURL\n\n",line_count);
	// printf("%g\n",$1);
	//fprintf(mylog,"{\n%s\n}",$3);
	//incomplete
		//logout<<"At line no: "<<line_count<<" compound_statement: LCURL statements RCURL"<<"\n";

	
		/*** scoptable exiting******/
		symbolTable.printAllScopeTable(mylog);
		symbolTable.pop();

	}
	| LCURL embedded_in RCURL {
		fprintf(mylog,"At line No.%d compound_statement:  LCURL RCURL\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" compound_statement:  LCURL RCURL "<<"\n";

		//incomplete
		symbolTable.printAllScopeTable(mylog);
		symbolTable.pop();
	}


;

embedded_in: {
            /* NOTICE: embedded action */
            symbolTable.EnterScope(mylog);   // #bucket_in_each_scopeTable = 7

            // /* add parameters (if exists) to symbolTable */
            // if(param_list.size()==1 && param_list[0].param_type=="void") {
            //     /* only parameter is void */
            // } else {
            //     for(int i=0; i<param_list.size(); i++) {
            //         temp_var.var_name = param_list[i].param_name;
            //         temp_var.var_size = -1;

            //         insertVar(param_list[i].param_type, temp_var);
            //     }
            // }

            // param_list.clear();  // NOTICE
    }
        ;	


var_declaration: type_specifier declaration_list SEMICOLON {
	fprintf(mylog,"At line No.%d var_declaration: type_specifier declaration_list SEMICOLON\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" var_declaration: type_specifier declaration_list SEMICOLON"<<"\n";

	}
;

type_specifier: INT {
	fprintf(mylog,"At line No.%d  type_specifier: INT\n\n",line_count);
	//incomplete
		// logout<<"At line no: "<<line_count<<" type_specifier: INT"<<"\n";
        // fprintf(mylog,"At line no:%d type_specifier: INT\n",line_count);
	}
	| FLOAT {
		fprintf(mylog,"At line No.%d type_specifier: FLOAT\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" type_specifier: FLOAT"<<"\n";

		//incomplete
	}
	| VOID {
		fprintf(mylog,"At line No.%d type_specifier: VOID\n\n",line_count);
	//logout<<"At line no: "<<line_count<<" type_specifier: VOID"<<"\n";

		//incomplete
	}
;

id: ID {
	fprintf(mylog,"At line No.%d  id: ID\n\n",line_count);
	fprintf(mylog,"%s\n\n",yylval.str);
	string value(yylval.str);
	SymbolInfo sss("ID",value);
	symbolTable.push(sss);	
	// string value(yylval);
	// SymbolInfo sym("ID",value);
	// symbolTable.push(sym,mylog);
	//std::cout<<"At line No."<<line_count<<"  id: ID\n\n";
	//std::cout<<$1->getKey()<<":"<<$1->getValue();
	//incomplete
		//logout<<"At line no: "<<line_count<<" id: ID"<<"\n";
                // fprintf(mylog,"At line no:%d id: ID\n",line_count);
                // fprintf(mylog,$$);


	}
;
declaration_list: declaration_list COMMA id {
	fprintf(mylog,"At line No.%d  declaration_list:  declaration_list COMMA id\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id"<<"\n";

	}
	| declaration_list COMMA id LTHIRD CONST_INT RTHIRD {
		fprintf(mylog,"At line No.%d declaration_list:  declaration_list COMMA id LTHIRD CONS RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id LTHIRD CONS RTHIRD"<<"\n";

	}
	| id {
		fprintf(mylog,"At line No.%d  declaration_list: id \n\n",line_count);
		//incomplete
	//logout<<"At line no: "<<line_count<<" declaration_list: id"<<"\n";

	}
	| id LTHIRD CONST_INT RTHIRD {
		fprintf(mylog,"At line No.%d  declaration_list: id LTHIRD CONST_INT RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" declaration_list: id LTHIRD CONST_INT RTHIRD"<<"\n";

	}
;

statements: statement {
	fprintf(mylog,"At line No.%d statements: statement\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" statements: statement"<<"\n";

	}
	| statements statement {
		fprintf(mylog,"At line No.%d statement: statements statement\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: statements statement "<<"\n";

	}
;

statement: var_declaration {
	fprintf(mylog,"At line No.%d  statement: var_declaration\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" statement: var_declaration "<<"\n";

	}
	| expression_statement {
		fprintf(mylog,"At line No.%d  statement: expression_statement\n\n",line_count);
				//logout<<"At line no: "<<line_count<<" statement: expression_statement"<<"\n";

		//incomplete
	}
	| compound_statement {
		fprintf(mylog,"At line No.%d statement: compound_statement\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" statement: compound_statement"<<"\n";

		//incomplete
	}
	| FOR LPAREN expression_statement expression_statement expression {
		fprintf(mylog,"At line No.%d  statement: FOR LPAREN expression_statement expression_statement expression\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" statement: FOR LPAREN expression_statement expression_statement expression"<<"\n";

	} 
	| RPAREN statement {
		fprintf(mylog,"At line No.%d statement:RPAREN statement\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" statement:RPAREN statement "<<"\n";

	}
	| IF LPAREN expression RPAREN statement {
		fprintf(mylog,"At line No.%d statement: IF LPAREN expression RPAREN statement \n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement "<<"\n";


	}
	| IF LPAREN expression RPAREN statement ELSE statement {
		fprintf(mylog,"At line No.%d statement: IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement ELSE statement "<<"\n";

		//incomplete
	}
	| WHILE LPAREN expression RPAREN statement {
		fprintf(mylog,"At line No.%d statement: WHILE LPAREN expression RPAREN statement\n\n",line_count);
			//incomplete
			//logout<<"At line no: "<<line_count<<" statement: WHILE LPAREN expression RPAREN statement"<<"\n";

	}
	| PRINTLN LPAREN ID RPAREN SEMICOLON {
		fprintf(mylog,"At line No.%d  statement: PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: PRINTLN LPAREN ID RPAREN SEMICOLON"<<"\n";

	}
	| RETURN expression SEMICOLON {
		fprintf(mylog,"At line No.%d  statement: RETURN expression SEMICOLON\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" statement: RETURN expression SEMICOLON"<<"\n";

		//incomplete
	}

;





expression_statement: SEMICOLON {
	fprintf(mylog,"At line No.%d expression_statement: SEMICOLONd\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" expression_statement: SEMICOLONd"<<"\n";

	}
	| expression SEMICOLON {
		fprintf(mylog,"At line No.%d expression_statement: expression SEMICOLON\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" expression_statement: expression SEMICOLONd"<<"\n";

		//incomplete
	}
;


variable: id {
	fprintf(mylog,"At line No.%d  variable: id\n\n",line_count);
		//incomplete
				//logout<<"At line no: "<<line_count<<" variable: id"<<"\n";

	}
	| id LTHIRD expression RTHIRD {
		fprintf(mylog,"At line No.%d variable: id LTHIRD expression RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" variable: id LTHIRD expression RTHIRD"<<"\n";

	}
;


expression: logic_expression {
	fprintf(mylog,"At line No.%d expression: logic_expression\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" expression: logic_expression"<<"\n";

	//incomplete
	}
	| variable ASSIGNOP logic_expression {
		fprintf(mylog,"At line No.%d expression: variable ASSIGNOP logic_expression\n\n",line_count);
		//incomplete
				//logout<<"At line no: "<<line_count<<" expression: variable ASSIGNOP logic_expression"<<"\n";

	}
;



logic_expression: rel_expression {
	fprintf(mylog,"At line No.%d expression: rel_expression\n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<" expression: rel_expression"<<"\n";
	}
	| rel_expression LOGICOP rel_expression {
		fprintf(mylog,"At line No.%d logic_expression: rel_expression\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";
		//incomplete
	}
;

rel_expression: simple_expression {
	fprintf(mylog,"At line No.%d logic_expression: rel_expression\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";

	//incomplete
	}
	| simple_expression RELOP simple_expression {
		fprintf(mylog,"At line No.%d logic_expression:  simple_expression RELOP simple_expression\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" logic_expression:  simple_expression RELOP simple_expression"<<"\n";

	}
;

simple_expression: term {
	fprintf(mylog,"At line No.%d  simple_expression: term\n\n",line_count);
				//logout<<"At line no: "<<line_count<<" simple_expression: term"<<"\n";

		//incomplete
	}
	| simple_expression ADDOP term {
		fprintf(mylog,"At line No.%d simple_expression: simple_expression ADDOP term\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" simple_expression: simple_expression ADDOP term"<<"\n";

	}
;

term: unary_expression {
	fprintf(mylog,"At line No.%d  term: unary_expressionm\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" term: unary_expressionm"<<"\n";

	
	}
	| term MULOP unary_expression {
		fprintf(mylog,"At line No.%d term:  term MULOP unary_expression\n\n",line_count);
		//incomplete
	//logout<<"At line no: "<<line_count<<" term:  term MULOP unary_expression"<<"\n";

	}
;

unary_expression: ADDOP unary_expression {
	fprintf(mylog,"At line No.%d unary_expression: ADDOP unary_expression\n\n",line_count);
	//logout<<"At line no: "<<line_count<<" unary_expression: ADDOP unary_expression "<<"\n";

	//incomplete
	}
	| NOT unary_expression {
		fprintf(mylog,"At line No.%d unary_expression: NOT unary_expression\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" unary_expression: NOT unary_expression "<<"\n";

		//incomplete
	}
	| factor {
		fprintf(mylog,"At line No.%d unary_expression: factor\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" unary_expression: factor"<<"\n";

		//incomplete
	}
;

factor: variable {
	fprintf(mylog,"At line No.%d factor: variable\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: variable"<<"\n";

	//incomplete
	}
	| id LPAREN argument_list RPAREN {
		fprintf(mylog,"At line No.%d factor: id LPAREN argument_list RPAREN\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: id LPAREN argument_list RPAREN"<<"\n";

		//incomplete
	}
	| LPAREN expression RPAREN {
		fprintf(mylog,"At line No.%d factor: LPAREN expression RPAREN\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" factor: LPAREN expression RPAREN"<<"\n";

	}
	| CONST_INT {
		fprintf(mylog,"At line No.%d  factor:CONST_INT\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:CONST_INT"<<"\n";

		//incomplete
	}
	| CONST_FLOAT {
		fprintf(mylog,"At line No.%d  factor:CONST_FLOAT\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:CONST_FLOAT"<<"\n";

		//incomplete
	}
	| variable INCOP {
		fprintf(mylog,"At line No.%d factor: variable INCOP\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:variable INCOP"<<"\n";

		//incomplete
	}
	| variable DECOP {
		fprintf(mylog,"At line No.%d factor: DECOP\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: DECOP"<<"\n";

		//incomplete
	}
;	
argument_list: arguments {
	fprintf(mylog,"At line No.%d argument_list: arguments\n\n",line_count);
	//incomplete
			//logout<< "\narguments mathed at line No: "<<line_count<<"\n";<<"\n";

	}
	| {
		fprintf(mylog,"At line No.%d argument_list: empty_string \n\n",line_count);
		//incomplete
		//empty production
	}
arguments: arguments COMMA logic_expression {
	fprintf(mylog,"At line No.%d arguments: arguments COMMA logic_expression \n\n",line_count);
	//logout<<"\narguments COMMA logic_expression mathced at line No.:"<<line_count<<"\n";<<"\n";
	//incomplete
	}
	| logic_expression{
		fprintf(mylog,"At line No.%d arguments: logic_expression\n\n",line_count);
		//logout<< "\nlogic_expression mathed at line No: "<<line_count<<"\n";<<"\n";
		//incomplete
	}
;


%%



int main(int argc, char* argv[]) {
	//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	if(argc != 2) {
		fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
		cout << "input file name not provided, terminating program..." << endl;
		return 0;
	}

    input = fopen(argv[1], "r");
    mylog = fopen("logfile_1705020.txt","w");
    
    logout.open("1705020_log.txt", ios::out);
	error.open("1705020_error.txt", ios::out);
   
    if(input == NULL) {
		//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
		cout << "input file not opened properly, terminating program..." << endl;
		exit(EXIT_FAILURE);
	}

	// symbol_Info = new SymbolInfo("dummy","dummy");
	//std::cout<<symbol_Info->getKey()<<endl;
	// logout.open("1605023_log.txt", ios::out);
	// error.open("1605023_error.txt", ios::out);
	
	// if(logout.is_open() != true) {
		// fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	// 	cout << "logout file not opened properly, terminating program..." << endl;
	// 	fclose(input);
		
	// 	exit(EXIT_FAILURE);
	// }
	
	// if(error.is_open() != true) {
		// fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	// 	cout << "error file not opened properly, terminating program..." << endl;
	// 	fclose(input);
	// 	logout.close();
		
	// 	exit(EXIT_FAILURE);
	// }
	
	// //symbolTable.enterScope(scope_count++, 7, logout);   // #bucket_in_each_scopeTable = 7
	
	yyin = input;
	symbolTable.EnterScope();
    yyparse();  // processing starts

   // logout << endl;
	//symbolTable.printAll(logout);
	//symbolTable.exitScope(logout);

	// logout << "Total Lines: " << (--line_count) << endl;  // NOTICE here: line_count changed (July 19) -> works for sample
	// logout << "\n" << "Total Errors: " << error_count << endl;
    // error << "\n" << "Total Errors: " << error_count << endl;
	
	fclose(yyin);
	// logout.close();
	// error.close();
	
	return 0;
} 


void yyerror(char* s) {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    /* it may be modified later */
 //logout << "At line no: " << line_count << " " << s << endl;

    line_count++;
    error_count++;
    
    return ;
}

/*
    yaccFile=1605023.y
    lexFile=1605023.l
    inputFile=input.txt
    ####################################################################
    #Created by Mir Mahathir Mohammad 1605011
    ####################################################################
    DIR="$(cd "$(dirname "$0")" && pwd)"
    cd $DIR
    bison -d -y -v ./$yaccFile
    g++ -w -c -o ./y.o ./y.tab.c
    flex -o ./lex.yy.c ./$lexFile
    g++ -fpermissive -w -c -o ./l.o ./lex.yy.c
    g++ -o ./a.out ./y.o ./l.o -lfl -ly	
    ./a.out ./input.txt
*/