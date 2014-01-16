%option nostdinit noyywrap
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "scannerDefi.h"

LETRA [a-zA-Z][a-zA-Z]*

DIGITO [0-9][0-9]*

SIMBOLOINV [_!@#$£%¢&§ª][_!@#$£%¢&§ª]*

%%

<<EOF>>									{printf("\n\nEnd of file\n\n"); return 0;}

"string"								printf("=> Palavra Reservada ----------- string\n\n");

"else"									printf("=> Palavra Reservada ----------- else\n\n");

"if"									printf("=> Palavra Reservada ----------- if\n\n");

"int" 									printf("=> Palavra Reservada ----------- int\n\n");
										
"return"								printf("=> Palavra Reservada ----------- return\n\n");
										
"void"									printf("=> Palavra Reservada ----------- void\n\n");
										
"while"									printf("=> Palavra Reservada ----------- while\n\n");

"+"										printf("=> Caractere especial ---------- +\n\n");

"-"										printf("=> Caractere especial ---------- -\n\n");

"*"										printf("=> Caractere especial ---------- *\n\n");

"/"										printf("=> Caractere especial ---------- /\n\n");

"<"										printf("=> Caractere especial ---------- <\n\n");

"<="									printf("=> Caractere especial ---------- <=\n\n");

">"										printf("=> Caractere especial ---------- >\n\n");

">="									printf("=> Caractere especial ---------- >=\n\n");

"=="									printf("=> Caractere especial ---------- ==\n\n");

"!="									printf("=> Caractere especial ---------- !=\n\n");

"="										printf("=> Caractere especial ---------- =\n\n");

";"										printf("=> Caractere especial ---------- ;\n\n");

","										printf("=> Caractere especial ---------- ,\n\n");

"("										printf("=> Caractere especial ---------- (\n\n");

")"										printf("=> Caractere especial ---------- )\n\n");

"["										printf("=> Caractere especial ---------- [\n\n");

"]"										printf("=> Caractere especial ---------- ]\n\n");

"{"										printf("=> Caractere especial ---------- {\n\n");

"}"										printf("=> Caractere especial ---------- }\n\n");


{LETRA}									printf("=> ID -------------------------- %s\n\n",yytext);

{DIGITO}								printf("=> Digito ---------------------- %s\n\n",yytext);

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
												printf("=> Cadeia de String ------------ \"%s",str);
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
int main(int argc, char* argv[]){

	//Verifica a quantidade de parametros que foram passados pra 'main'

	//Caso não seja passado parametros o yylex() sera executado normalmente
	int token;
	if(argc == 1){
		yylex();
		return 0;
	}

	//Caso hajam dois, o segundo parametro sera o nome do arquivo que os ados serão lidos
	if(argc >= 2){

		yyin = fopen(argv[1], "r");
		yyout = fopen("streamDeTokens.txt", "w");

	}else{//Caso contrario o programa é encerrado

		printf("\nParametros Insuficientes!\n");
		return 0;

	}


	//Se o arquivo de entrada não puder ser lido o programa para a execução
	if(yyin == NULL){

		printf("\nErro na leitura do arquivo de entrada!\n");
		return 0;

	}else if(yyout = NULL){//Arquivo de entrada valido e saida invalido. Só é mostrado o resultado na tela

		yylex();
		return 0;
	}

	//Arquivos de entrada e saida validos, começa a leitura.

	do{
		switch( token = yylex() ){

		}

	}while(token != EndOfFile);


	//Se tiver algum arquivo aberto ele sera fechado
	if(yyout != NULL){
		fclose(yyout);
	}
	if(yyin != NULL){
		fclose(yyin);
	}
	/*

	{
											char c;
											char Qa;
											char Q;
											int numComents = 1;
											int done = FALSE;
											printf("=> Comentario ------------------ ");
											ECHO;

											do{
												while( (c=input()) != '*')
													putchar(c);

												putchar(c);

												if(c == '/'){
													putchar(c);
													c = input();
													if(c == '*')
														putchar(c);

												}

												while( (c=input()) == '*')
													putchar(c);

												putchar(c);

												if(c=='/'){
													if((c=input()) == '\n')
													done = TRUE;
												}

											}while(!done);

											printf("\n\n");
										}

	*/

	return 0;

}


