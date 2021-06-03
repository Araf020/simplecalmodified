%option noyywrap

%{
#include<iostream>
#include<string>
#include<fstream>

#include "table.h"
#include "y.tab.h"

using namespace std;

void yyerror(char*);  // yyerror() function for generating error message

extern YYSTYPE yylval;  
   // NOTICE

extern int line_count;
extern int error_count;  // NOTICE
%}

WHITESPACE [ \t\v\f\r]+
LETTER [A-Za-z]
DIGIT [0-9]
NEWLINE \n


%%


"if" {
	return IF;
}
"else"	{
	return ELSE;
}
"for"	{
	return FOR;
}
"while"	{
	return WHILE;
}
"int"	{
	return INT;
}
"float"	{
	return FLOAT;
}
"void"	{
    return VOID;
}
"return"	{
	return RETURN;
}
"println" {
    return PRINTLN;
}
			
{DIGIT}+	{
    string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "CONST_INT");
    yylval = (YYSTYPE) symbolInfo;
    return CONST_INT;
}
({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)([Ee][+-]?{DIGIT}+)?	{
    string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "CONST_FLOAT");
    yylval = (YYSTYPE) symbolInfo;
    return CONST_FLOAT;
}
			
"+"|"-"	{
    string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "ADDOP");
    yylval = (YYSTYPE) symbolInfo;
    return ADDOP;
}
"*"|"/"|"%"	{
	string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "MULOP");
    yylval = (YYSTYPE) symbolInfo;
    return MULOP;
}
"++"	{
	return INCOP;
}
"--" {
	return DECOP;
}
"<"|"<="|">"|">="|"=="|"!="	{
	string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "RELOP");
    yylval = (YYSTYPE) symbolInfo;
    return RELOP;
}
"="	{
	return ASSIGNOP;
}
"&&"|"||"	{
	string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "LOGICOP");
    yylval = (YYSTYPE) symbolInfo;
    return LOGICOP;
}
"!"	{
    return NOT;
}
"("	{
    return LPAREN;
}
")"	{
    return RPAREN;
}
"{"	{
    return LCURL;
}
"}"	{
    return RCURL;
}
"["	{
    return LTHIRD;
}
"]"	{
    return RTHIRD;
}
","	{
    return COMMA;
}
";"	{
    return SEMICOLON;
}
	
[A-Z_a-z][0-9A-Z_a-z]* {
	string temp(yytext);
    SymbolInfo* symbolInfo = new  SymbolInfo(temp, "ID");
    yylval = (YYSTYPE) symbolInfo;
    return ID;
 }

{WHITESPACE} {
    /* ignore them */
}

{NEWLINE}	{
    line_count++;
}


%%
