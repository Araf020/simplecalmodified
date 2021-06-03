%option noyywrap
%x END_WITH_SQ
%x END_WITH_DQ
%x STRING_LIT
%x SLINECOMMENT
%x MULTILINECOMMENT
%x MSCOMMENT
%x DUMMY


%{
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include "y.tab.h"
// #include "SymbolTable.cpp"


void yyerror(char*);
extern YYSTYPE yylval;
// extern YYSTYPE symbol_Info;

using namespace std;


 extern int line_count;
//  extern struct Symbol *sym;
 int ec=0;

//SymbolTable *sTable;

string c;
string String_literals1;
string String_literals2;

string const_character;


// FILE *logout;
// FILE *tokenout;

%}

NEWLINE \n
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*

IDENTIFIER_ERROR [0-9]+[a-zA-Z_]+[a-zA-Z_0-9]*

DECIMAL_POINT_ERROR ([0-9]*[.][0-9]*[.]+[0-9]*)+

ILL_FORMAT_ERROR ([0-9]*\.?[0-9]+[.]?)*[eE][-+]?[0-9]+[.][0-9]*


SPECIALS ['][\\]?[a-z]+[']
TAB ['][\\][t][']

CONST_c ['][a-zA-Z][']
IF_DQ [\"]
IF_END_DQ ((.*)[\\]?(.*)[\r\n]*(.*))*[\"]
DQ_CHECK  [\r\n]*(.*)[\r\n]*
DQ_ESCAPE [\\][ \r\n\t]*
DQ_END [\"]

ANYTHING ([^\r\n]|{NEWLINE})
STRINGERROR \"([^"\\\r\n]|[\\]{ANYTHING})*

STRINGLITERALS {STRINGERROR}\"

LITERALS [\"]((.*)[\\]?(.*)[\r\n]*)*[\"]

LIT [\"](.*)[\\]+?[\r\n]*?[\\]+?[\"]




LITERALS1 ^[^"]*?('[^"]+?')[\r\n]*[^"]*

CONST_INT [0-9]+[ \t]?
CONST_FLOAT [0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?

MULOP [*/%]
ADDOP [+-]
INCOP [+][+]|[-][-]
RELOP [<]|[<][=]|[>]|[>][=]|[=][=]|[!][=]
ASSIGNOP [=]
LOGICOP [&][&]|"||"

NOT [!]
LPAREN [(]
RPAREN [)]

LCURL [{]
RCURL [}]

LTHIRD [\[]	
RTHIRD [\]]

COMMA [,]
SEMICOLON [;]

CHECKNOTFINISHED ['][a-zA-Z]['](.*)

SQ_CHECK (['](.*)['])
END_SQ [a-zA-Z][']
SQ_MULTI_CHAR ['][a-zA-Z](.+)[']



SKIP1 [/][/](.*)[\\][\r\n](.*)[\r\n]

SKIP [\/][\/](.*)[\r\n]

SKIP2 ([/][\*]([^*]|[\r\n]|(\*([^/]|[\r\n])))*[\*][/\\])|[/][/]+(.*)[\r\n]
UNFINISHED_SKIP2 "/*"([^*]|\*+[^*/])*\*?

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]


%%

{NEWLINE} {line_count++;}




[']['] {
			printf("\nEmpty character constant error %d: %s\n",line_count,yytext);
			// //fprintf(logout,"\nError at line no %d: Empty character constant error %s\n",line_count,yytext);
			ec++;
}

['] {
	
	string str(yytext);
	c = str;
	BEGIN END_WITH_SQ;

	}


['][\\]['] {

			printf("sq UNFINISHED Error at line %d: %s\n",line_count,yytext);
			// //fprintf(logout,"\nError at line no %d: Unterminated character %s\n",line_count,yytext);
			ec++;
			}

<END_WITH_SQ>[a-zA-Z0-9]|[\\]  {
						    string str(yytext);
						    const_character = str;
						    c = c + str;

						  }

<END_WITH_SQ>[\r\n]       {
							char output[c.length()+1];
							strcpy(output,c.c_str());
							printf("\nError at line no %d: Unterminated character %s\n",line_count, output);
							// //fprintf(logout,"\nError at line no %d: Unterminated character %s\n",line_count, output);
							// line_count++;
							ec++;
							BEGIN INITIAL;

					      }


<END_WITH_SQ>['] {

			string str(yytext);
			c= c+str;
			char output[const_character.length()+1];
			strcpy(output,const_character.c_str());

			printf("<CONST_C, %s> at Line: %d\n",output,line_count);
			//fprintf(tokenout,"<CONST_CHAR, %c> ",output[1]);
		   	//fprintf(logout,"\nLine no %d: Token <CONST_CHAR> Lexeme %s found --> <CHAR_CONST, %c> \n",line_count,output,output[1]);
		   	string temp(output);
			//SymbolInfo sym("CONST_CHAR",temp);
			// sTable->push(sym,logout);

			////fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,const_character);
			BEGIN INITIAL;
		       
		        }

<END_WITH_SQ>[\\][t]['] {

	cout<<"CONST_CHAR: \t\n";
	//fprintf(tokenout,"<CONST_CHAR, \t");
	//fprintf(logout,"\nLine no %d: Token <CONST_CHAR> Lexeme %s found --> <CHAR_CONST, \t> ",line_count,yytext);
	string temp(yytext);
			//SymbolInfo sym("CONST_CHAR",temp);
			// sTable->push(sym,logout);


	BEGIN INITIAL;
}		        
<END_WITH_SQ>.          {
								printf("UnknownError ERROR at Line: %d\n",line_count);

								
							//fprintf(logout,"\nLine no: %d UnknownError %s\n",line_count, yytext);
							ec++;
								BEGIN INITIAL;
						  
						  }





{SQ_MULTI_CHAR}    {
							printf("\nError at line no %d: Multi character constant error %s\n",line_count,yytext);
							////fprintf(tokenout,"<CONST_MULTI_CHAR, %s> ",yytext);
							//fprintf(logout,"\nError at line no %d: Multi character constant error %s\n",line_count,yytext);
			//sTable.push("COsMMA",yytext);
							ec++;
									BEGIN INITIAL;

							    }



<END_WITH_DQ>{IF_END_DQ} {
							printf("LITERALS FOUND: <%s> \n",yytext);
							//fprintf(tokenout,"<STRING, %s> ",yytext);
							//fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",line_count,yytext);
			//sTable.push("COMMA",yytext);
							BEGIN INITIAL;
					     }

<END_WITH_DQ>. {printf("DQ NOT finished"); BEGIN INITIAL;}







<SLINECOMMENT>[\\][\r\n](.*)[\r\n]  {printf("we r here\n");line_count++;line_count++; BEGIN INITIAL;}
<SLINECOMMENT>[\r\n]            {printf("we r here\n");line_count++; BEGIN INITIAL;}
<SLINECOMMENT>(.*) {}


<MULTILINECOMMENT>(.*)[\r\n] 		{printf("we r multi\n");line_count++;}
<MULTILINECOMMENT>[\*]+[/]  		{printf("i m visited\n");BEGIN INITIAL;}
<MULTILINECOMMENT>. {printf("not finished\n"); BEGIN DUMMY;}

<DUMMY>(.*) {printf("i m in DUMMY\n"); BEGIN INITIAL;}






{SKIP2} {

	printf("NO ACTION\n %s\n",yytext);
	//fprintf(logout,"\nLine no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);
	string str2(yytext);
	
	char str1[str2.length()];

	strcpy(str1,str2.c_str());

	for(int i=0;i<str2.length();i++){
		if (str1[i]=='\n') {
			line_count++;
		}
	}


}

{UNFINISHED_SKIP2} {
					string str(yytext);
					char out[str.length()];
					ec++;
					strcpy(out,str.c_str());
					//if(out[str.length()-1] != '/' && out[str.length()-2] != '*'){
						printf("\ncomment not finished Error! at line:%d \n",line_count);
						//fprintf(logout,"\nError at line no %d: Unterminated Comment %s\n",line_count,yytext);
						
					//}
					for (int i=0;i<str.length() ;i++ ) {
						
						if (out[i]=='\n'|| out[i]=='\r') {
							line_count++;
						}
							
				   }
				    
				     
				}

[/][/](.*)[\\][\r\n](.+)[\r\n] {

								printf("single\n");line_count+=2;
								////fprintf(logout,"\nError at line no %d: Unterminated Comment %s....\n",line_count,yytext);
							    //fprintf(logout,"\nLine no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);

							    }

"//"(.*)[\r\n]			     {
								printf("single\n");line_count++;
								////fprintf(logout,"\nError at line no %d: Unterminated Comment %s....\n",line_count,yytext);
								//fprintf(logout,"\nLine no %d: Token <COMMENT> Lexeme %s found\n",line_count,yytext);


							 }

[ \t\v]+ {}

{IDENTIFIER_ERROR} {printf("\n%s is an IDENTIFIER_ERROR\n",yytext);
					//fprintf(logout,"\nError at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);

					ec++;
				
					}
{DECIMAL_POINT_ERROR} {printf("\n%s DECIMALPOINTER_ERROR\n",yytext);
						//fprintf(logout,"\nError at line no %d: Too many decimal points %s\n",line_count,yytext);
						ec++;
					}

{ILL_FORMAT_ERROR} {printf("\n%s is an ILL_FORMAT_ERROR\n",yytext);
				
					//fprintf(logout,"\nError at line no %d: Ill formed Number %s\n",line_count,yytext);
					ec++;


				}









(switch) {printf(" <%s> found\n",yytext);
		  //outputfile<<"<SWITCH> ";	
			//fprintf(tokenout,"<SWITCH> ");
			//fprintf(logout,"\nLine no %d: Token <SWITCH> Lexeme %s found\n",line_count,yytext);
			//sTable.push("SWITCH",yytext);
			//return SWITCH;
		  }
(default) {printf(" <%s> found\n",yytext);  
			//outputfile<<"<DEFAULT> ";
			//fprintf(tokenout,"<DEFAULT> ");
			//fprintf(logout,"\nLine no %d: Token <DEFAULT> Lexeme %s found\n",line_count,yytext);
		
			//return DEFAULT;
        }
(if) {printf(" <%s> found\n",yytext);
		//outputfile<<"<IF> "; 
			//fprintf(tokenout,"<IF> ");
			//fprintf(logout,"\nLine no %d: Token <IF> Lexeme %s found\n",line_count,yytext);
		return IF;
		}
(else) {printf(" <%s> found\n",yytext);
			//	outputfile<<"<ELSE> ";
		    //fprintf(tokenout,"<ELSE> ");
			//fprintf(logout,"\nLine no %d: Token <ELSE> Lexeme %s found\n",line_count,yytext);
			
			return ELSE;
			}
(for) {printf(" <%s> found\n",yytext);
				//outputfile<<"<FOR> ";
		    //fprintf(tokenout,"<FOR>");
			//fprintf(logout,"\nLine no %d: Token <FOR> Lexeme %s found\n",line_count,yytext);
			return FOR;
				}
(do) {printf(" <%s> found\n",yytext);
			//outputfile<<"<DO> ";
			//fprintf(tokenout,"<DO> ");
			//fprintf(logout,"\nLine no %d: Token <DO> Lexeme %s found\n",line_count,yytext);
			//return DO;
			}
(float) {printf(" <%s> found\n",yytext);
				//	outputfile<<"<FLOAT> ";
			//fprintf(tokenout,"<FLOAT> ");
			//fprintf(logout,"\nLine no %d: Token <FLOAT> Lexeme %s found\n",line_count,yytext);
			return FLOAT;
					}
(void) {printf(" <%s> found\n",yytext);
			// SymbolTable sTable(7);
				// outputfile<<"<VOID> ";
			//fprintf(tokenout,"<VOID> ");
			//fprintf(logout,"\nLine no %d: Token <VOID> Lexeme %s found\n",line_count,yytext);
				
			return VOID;
				}
(int) {
	
			printf(" <%s> found\n",yytext);
		//	printf("wtf");
		//outputfile<<"<INT> ";	
			//fprintf(tokenout,"<INT> ");
			//fprintf(logout,"\nLine no %d: Token <INT> Lexeme %s found\n",line_count,yytext);
		
			return INT;
			}
(char) {printf(" <%s> found\n",yytext);
			//outputfile<<"<CHAR> ";
			//fprintf(tokenout,"<CHAR> ");
			//fprintf(logout,"\nLine no %d: Token <CHAR> Lexeme %s found\n",line_count,yytext);
			return CHAR;
			}
(while) {   printf("<%s> found\n",yytext);
			//outputfile<<"<WHILE> ";
			//fprintf(tokenout,"<WHILE> ");
			//fprintf(logout,"\nLine no %d: Token <WHILE> Lexeme %s found\n",line_count,yytext);
	
			return WHILE;
		}
(break) {

			printf("<%s> found\n",yytext);
			//fprintf(tokenout,"<BREAK>");
			//fprintf(logout,"\nLine no %d: Token <BREAK> Lexeme %s found\n",line_count,yytext);
	//outputfile<<"<BREAK> ";
	//return BREAK;
}

(double) {

	printf("<%s> found\n",yytext);
				//fprintf(tokenout,"<DOUBLE> ");
			//fprintf(logout,"\nLine no %d: Token <DOUBLE> Lexeme %s found\n",line_count,yytext);
	//outputfile<<"<DOUBLE> ";
	return DOUBLE;
}

(return) {

	printf("<%s> found\n",yytext);
	//outputfile<<"<RETURN> ";
				//fprintf(tokenout,"<RETURN> ");
			//fprintf(logout,"\nLine no %d: Token <RETURN> Lexeme %s found\n",line_count,yytext);
			return RETURN;
}
(case) {

	printf("<%s> found\n",yytext);
	//outputfile<<"<CASE> ";
				//fprintf(tokenout,"<CASE> ");
			//fprintf(logout,"\nLine no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
	
	
	}
(continue) {

	printf("<%s> found\n",yytext);
				//fprintf(tokenout,"<CONTINUE> ");
			//fprintf(logout,"\nLine no %d: Token <CONTINUE> Lexeme %s found\n",line_count,yytext);
	//outputfile<<"<CONTINUE> ";

}


{TAB} {printf("TAB <\t> found\n");
			//fprintf(tokenout,"<CONST_CHAR, \t> ");
			
			//fprintf(logout,"\nLine no %d: Token <CONST_CHAR> Lexeme %s found --> <CHAR_CONST, \t>\n",line_count,yytext);
			string temp(yytext);
			//SymbolInfo sym("CONST_CHAR",temp);
			// sTable->push(sym,logout);
			
			
			//sTable.push("COMMA",yytext);
	//	outputfile<<"<COMMA, "<<yytext;
		return TAB;

		}
{SPECIALS} {printf("SPECIALS <%s> found\n",yytext);
			//fprintf(tokenout,"<CONST_CHAR, %c> ",yytext[1]);
			//fprintf(logout,"\nLine no %d: Token <CONST_CHAR> Lexeme %s found --> <CHAR_CONST, %c>\n",line_count,yytext, yytext[1]);
			
			string temp(yytext);
			//SymbolInfo sym("CONST_CHAR",temp);
			// sTable->push(sym,logout);
			//sTable.push("COMMA",yytext);
		//	return SPECIALS;
	//	outputfile<<"<COMMA, "<<yytext;
		}

{COMMA} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<COMMA, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <COMMA> Lexeme %s found\n",line_count,yytext);
			//sTable.push("COMMA",yytext);
			return COMMA;
	//	outputfile<<"<COMMA, "<<yytext;
		}
{LTHIRD} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<LTHIRD, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <LTHIRD> Lexeme %s found\n",line_count,yytext);
			//sTable.push("LTHIRD",yytext);
			return LTHIRD;
	//	outputfile<<"<LTHIRD, "<<yytext;
	}
	
{RTHIRD} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<RTHIRD, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <RTHIRD> Lexeme %s found\n",line_count,yytext);	
			//sTable.push("RTHIRD",yytext);	

		//outputfile<<"<RTHIRD, "<<yytext;
		return RTHIRD;
	}


{SEMICOLON} {printf(" <SEMICOLON, %s> found\n",yytext);
			//fprintf(tokenout,"<SEMICOLON, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <SEMICOLON> Lexeme %s found\n",line_count,yytext);
			//sTable.push("SEMICOLON",yytext);
		
			return SEMICOLON;
		//outputfile<<"<SEMICOLON, "<<yytext;
	}
{LCURL} {printf(" <%s> found\n",yytext);
			// sTable->EnterScope();
			//fprintf(tokenout,"<LCURL, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <LCURL> Lexeme %s found\n",line_count,yytext);
		
		//outputfile<<"<LCURL, "<<yytext;
		return LCURL;
	}
{RCURL} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<RCURL, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <RCURL> Lexeme %s found\n",line_count,yytext);
		// sTable->pop();
		//outputfile<<"<LCURL, "<<yytext;
		return RCURL;
	}
{LPAREN} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<LPAREN, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext);
		
		//outputfile<<"<LPAREN, "<<yytext;
		return LPAREN;
	}
{RPAREN} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<RPAREN, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <RPAREN> Lexeme %s found\n",line_count,yytext);
		//outputfile<<"<RPAREN, "<<yytext;
		return RPAREN;
	}
{NOT} {printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<NOT, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <NOT> Lexeme %s found\n",line_count,yytext);
		
		//outputfile<<"<NOT, "<<yytext;
		return NOT;
	}


{LOGICOP} {

		printf(" <%s> found\n",yytext);
			//fprintf(tokenout,"<LOGICOP, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <LOGICOP> Lexeme %s found\n",line_count,yytext);		
		///outputfile<<"<LOGICOP, "<<yytext;
			return LOGICOP;
	}




{STRINGLITERALS} 	{

					printf("<STRING , %s>\n",yytext);
					string str(yytext);

					char output[str.length()];
					char output2[str.length()];

					strcpy(output,str.c_str());
					char qq;
					//fprintf(logout,"\nLine no %d: Token <STRING> Lexeme %s found --> <STRING, ",line_count,yytext);
					
					//fprintf(tokenout,"<STRING, ");

					
					for(int i=0;i<strlen(yytext);i++){
						if(output[i]=='\\' && output[i+1]=='t'){
							  output2[i]='\t';
							  qq = '\t';
							  printf("%c",qq);
							  //fprintf(tokenout,"%c",qq);
							  //fprintf(logout,"%c",qq);
							 
							  i++;
							  continue;

						}
						else if (output[i]=='\\' && output[i+1]=='n') {
							output2[i] = '\n';
							qq = '\n';
							  printf("%c",qq);
							   //fprintf(tokenout,"%c",qq);
							    //fprintf(logout,"%c",qq);
							i++;
							continue;
						}
						
						else if (output[i]=='\\' && output[i+1]=='b') {
							output2[i]='\b';
							qq = '\b';
							  printf("%c",qq);
							   //fprintf(tokenout,"%c",qq);
							    //fprintf(logout,"%c",qq);
							i++;
							continue;
						}
						else if(output[i]=='\n'){
							
							if(output[i-1]=='\\'){
								line_count++;
								
								continue;
							}

							output2[i]='\n';
							qq = '\n';
							printf("%c",qq);
							//fprintf(tokenout,"%c",qq);
							//fprintf(logout,"%c",qq);
							line_count++;
							
							continue;
						}
						else if(output[i]=='\\'){
							
							

						}
						

						
						else {
							output2[i] = output[i];

							printf("%c",output[i]);
							//fprintf(tokenout,"%c",output[i]);
							//fprintf(logout,"%c",output[i]);
						}


					}
					cout<<endl;
					//fprintf(tokenout,"> ");
					//fprintf(logout,">\n");
					
				
				
					
					

				}


{STRINGERROR} {	

					//fprintf(logout,"\nError at line no %d: Unterminated String %s",line_count,yytext);
					ec++;

					string str(yytext);

					char output[str.length()];
				
					 strcpy(output,str.c_str());

					 for (int i=0; i<str.length(); i++ ) {
					 	if (output[i]=='\n') {
					 		line_count++;
					 	}

					 }


		}



{CONST_INT} {printf("%s CONST_INT\n",yytext);
			//fprintf(tokenout,"<CONST_INT, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <CONST_INT> Lexeme %s found\n",line_count,yytext);
			string temp(yytext);
			//SymbolInfo sym("CONST_INT",temp);
			// sTable->push(sym,logout);
			return CONST_INT;
			}

{CONST_FLOAT} {printf("%s CONST_FLOAT\n",yytext);
			//fprintf(tokenout,"<CONST_FLOAT, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
			string temp(yytext);
			//SymbolInfo sym("CONST_FLOAT",temp);
			// sTable->push(sym,logout);
			return CONST_FLOAT;
			}

{ASSIGNOP} {printf("ASSIGNOP <%s> found\n",yytext);
			//fprintf(tokenout,"<ASSIGNOP, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
			return ASSIGNOP;
		//outputfile<<"<ASSIGNOP, "<<yytext;
	}

"println" {
	return PRINTLN;
}

{IDENTIFIER} {

			printf("IDENTIFIER <%s> found\n",yytext);
			//symbol_Info->setKey("ID");

			printf("azob duniya: %s\n",yytext);
			yylval.str = yytext;
			// yylval.fs("ID",yytext);
			//yylval.fs->value = yytext;
			
			// string temp(yytext);
			// YYSTYPE symbol_info = new YYSTYPE("ID",temp);
			// yylval =  symbol_info;
			//fprintf(tokenout,"<ID, %s> ",yytext);
			//fprintf(logout,"\nLine no %d: Token <ID> Lexeme %s found\n",line_count,yytext);
			//string temp(yytext);
			//SymbolInfo sy("ID",temp);

			// sTable->push(sy,logout);
		
		//outputfile<<"<ID, "<<yytext;
		return ID;
	}






{MULOP} {printf("<%s, MULOP>\n",yytext);
			//fprintf(tokenout,"<MULOP, %s> ",yytext);
			//fprintf(logout,"Line no %d: Token <MULOP> Lexeme %s found\n",line_count,yytext);
			return MULOP;
			}
{ADDOP} {printf("<%s, ADDOP>\n",yytext);
			//fprintf(tokenout,"<ADDOP, %s> ",yytext);
			//fprintf(logout,"Line no %d: Token <ADDOP> Lexeme %s found\n",line_count,yytext);
			return ADDOP;
			}

{INCOP} {
			printf("<%s incop>\n",yytext);
			
			//fprintf(tokenout,"<INCOP, %s> ",yytext);
			
			//fprintf(logout,"Line no %d: Token <INCOP> Lexeme %s found\n",line_count,yytext);
			return INCOP;
			}
{RELOP} {printf("%s RELOP\n",yytext);
			
			
			//fprintf(tokenout,"<RELOP, %s> ",yytext);
			//fprintf(logout,"Line no %d: Token <RELOP> Lexeme %s found\n",line_count,yytext);
			return RELOP;
			}



<<EOF>> {

		// sTable->printAllScopeTable(logout);

		printf("Total Line Number: %d \n",line_count);
		
		printf("Total errors: %d \n",ec);
		 //fprintf(logout,"\nTotal lines: %d\n",line_count);
		 //fprintf(logout,"Total errors: %d",ec);
		  return 0;
		}
. {//fprintf(logout,"Error at line no %d: Unrecognized character %s ",line_count,yytext);ec++;

	// char msg[25];
	// 	sprintf(msg, "%s <%s>","invalid character", yytext);
	// 	yyerror(msg);
}

%%

