%option nostdinit noyywrap
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser_generateByBison.h"

LETRA [a-zA-Z][a-zA-Z]*

DIGITO [0-9][0-9]*

SIMBOLOINV [_!@#$£%¢&§ª][_!@#$£%¢&§ª]*

%%

"string"								{ return STRING; }

"else"									{ return ELSE; }

"if"									{ return IF; }

"int" 									{ return INT; }
										
"return"								{ return RETURN; }
										
"void"									{ return VOID; }
										
"while"									{ return WHILE; }

"+"										{ return MAIS; }

"-"										{ return MENOS; }

"*"										{ return VEZES; }

"/"										{ return BARRA; }

"<"										{ return MENOR; }

"<="									{ return MENORIGUAL; }

">"										{ return MAIOR; }

">="									{ return MAIORIGUAL; }

"=="									{ return IGUALIGUAL; }

"!="									{ return DIFERENTE; }

"="										{ return IGUAL; }

";"										{ return PONTOVIRGULA; }

","										{ return VIRGULA; }

"("										{ return ABREPARENTESIS; }

")"										{ return FECHAPARENTESIS; }

"["										{ return ABRECOLCHETE; }

"]"										{ return FECHACOLCHETE; }

"{"										{ return ABRECHAVE; }

"}"										{ return FECHACHAVE; }


{LETRA}									{ return ID; }

{DIGITO}								{ return DIGITO; }

{SIMBOLOINV}							printf("=> Simbolo Invalido ------------ %s\n\n",yytext);


{SIMBOLOINV}{LETRA}{DIGITO}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{SIMBOLOINV}{DIGITO}{LETRA}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);

{LETRA}{DIGITO}{SIMBOLOINV}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{DIGITO}{LETRA}{SIMBOLOINV}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);

{SIMBOLOINV}{LETRA}{DIGITO}{SIMBOLOINV}				printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{SIMBOLOINV}{DIGITO}{LETRA}{SIMBOLOINV}				printf("=> Indentificador Invalido ----- %s\n\n",yytext);

{LETRA}{SIMBOLOINV}{DIGITO}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{DIGITO}{SIMBOLOINV}{LETRA}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);

{LETRA}{SIMBOLOINV}{LETRA}							printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{DIGITO}{SIMBOLOINV}{DIGITO}						printf("=> Indentificador Invalido ----- %s\n\n",yytext);

{LETRA}{DIGITO}										printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{DIGITO}{LETRA}										printf("=> Indentificador Invalido ----- %s\n\n",yytext);
{LETRA}{DIGITO}{LETRA}								printf("=> Indentificador Invalido ----- %s\n\n",yytext);


["]										{
											char Q;
											char Qaux;
											char *str;
											int strlen;
											int numAspas = 1;
											int escapeInvalido = 0;

											str = (char*) malloc(sizeof(char));
											strlen = 0;

											do{
												Q = input();

												if(Q == '\\'){
													
													strlen++;
													str = (char*) realloc(str, strlen*sizeof(char));
													str[strlen-1] = Q;

													Qaux = input();
													strlen++;
													str = (char*) realloc(str, strlen*sizeof(char));
													str[strlen-1] = Qaux;
													
													if(Qaux == '"' || Qaux == 't'){
														
														continue;
													}else{

														escapeInvalido = 1;
														continue;

													}

												}

												strlen++;
												str = (char*) realloc(str, strlen*sizeof(char));
												str[strlen-1] = Q;

											}while(Q != '\n' && Q != EOF && Q != '"');

											if(Q == '\n'|| Q == EOF || escapeInvalido){
												str[strlen-1] = 0;
												printf("=> Cadeia de String invalida --- \"%s",str);
											}
											if(Q == '"' && !escapeInvalido){
												return CADEIASTRING;
											}
											printf("\n\n");

										}


"/*"									{
											char *cmt;
											char Qaux;
											char Q;
											int escapeInvalido = 0;
											int numComents = 1;//Abriu um comentario
											int lenCmt = 0;
											cmt = (char*)malloc(sizeof(char));
											

											do{
												Q = input();

												while(Q != '*' && Q != '/' && Q != '\\' && Q != EOF){
													lenCmt++;
													cmt = (char*) realloc(cmt, lenCmt*sizeof(char));
													cmt[lenCmt-1] = Q;
													Q = input();
												}

												lenCmt++;
												cmt = (char*) realloc(cmt, lenCmt*sizeof(char));
												cmt[lenCmt-1] = Q;

												Qaux = input();

												if(Q == '\\'){
													if(Qaux != 'r' || Qaux != 't' || Qaux != 'n'){
														escapeInvalido = 1;
													}
												}

												if(Q=='*' && Qaux == '/'){
													lenCmt++;
													cmt = (char*) realloc(cmt, lenCmt*sizeof(char));
													cmt[lenCmt-1] = Qaux;
													numComents--;
												}

												if(Q == '/' && Qaux == '*'){
													lenCmt++;
													cmt = (char*) realloc(cmt, lenCmt*sizeof(char));
													cmt[lenCmt-1] = Qaux;
													numComents++;
													continue;
												}

												while(Qaux == '*'){
													lenCmt++;
													cmt = (char*) realloc(cmt, lenCmt*sizeof(char));
													cmt[lenCmt-1] = Qaux;
													Qaux = input();
												}




											}while(Q != EOF && numComents != 0);

											if(Q == EOF || numComents != 0 || escapeInvalido){
												cmt[lenCmt-1] = 0;
												printf("=> Comentario Invalido --------- /*%s",cmt);
											
											}else if(numComents == 0){

												printf("=> Comentario ------------------ /*%s",cmt);

											}

											printf("\n\n");
										}


.|\n|\r

%%
