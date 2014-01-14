%option nostdinit noyywrap
	#include <stdio.h>
	#include <string.h>
	#include "scannerDefi.h"

LETRA [a-zA-Z]

DIGITO [0-9]

%%

<<EOF>>									{printf("\n\nEnd of file\n\n"); return 0;}

["string"]{6}							printf("=> Palavra Reservada : 'string'\n");

"else"									printf("=> Palavra Reservada : 'else'\n");

"if"									printf("=> Palavra Reservada : 'if'\n");

"int" 									printf("=> Palavra Reservada : 'int'\n");
										
"return"								printf("=> Palavra Reservada : 'return'\n");
										
"void"									printf("=> Palavra Reservada : 'void'\n");
										
"while"									printf("=> Palavra Reservada : 'while'\n");

"+"										printf("=> Caractere especial : '+'\n");

"-"										printf("=> Caractere especial : '-'\n");

"*"										printf("=> Caractere especial : '*'\n");

"/"										printf("=> Caractere especial : '/'\n");

"<"										printf("=> Caractere especial : '<'\n");

"<="									printf("=> Caractere especial : '<='\n");

">"										printf("=> Caractere especial : '>'\n");

">="									printf("=> Caractere especial : '>='\n");

"=="									printf("=> Caractere especial : '=='\n");

"!="									printf("=> Caractere especial : '!='\n");

"="										printf("=> Caractere especial : '='\n");

";"										printf("=> Caractere especial : ';'\n");

","										printf("=> Caractere especial : ','\n");

"("										printf("=> Caractere especial : '('\n");

")"										printf("=> Caractere especial : ')'\n");

"["										printf("=> Caractere especial : '['\n");

"]"										printf("=> Caractere especial : ']'\n");

"{"										printf("=> Caractere especial : '{'\n");

"}"										printf("=> Caractere especial : '}'\n");


{LETRA}{LETRA}*							printf("=> ID : '%s'\n",yytext);

{DIGITO}{DIGITO}*						printf("=> Digito : '%s'\n",yytext);

{DIGITO}{DIGITO}*{LETRA}{LETRA}*					printf("=> Indentificador Invalido : '%s'\n",yytext);
{LETRA}{LETRA}*{DIGITO}{DIGITO}*					printf("=> Indentificador Invalido : '%s'\n",yytext);
{LETRA}{LETRA}*{DIGITO}{DIGITO}*{LETRA}{LETRA}*		printf("=> Indentificador Invalido : '%s'\n",yytext);

["][^"]*["]								printf("=> Cadeia String : '%s'\n",yytext);


"/*"([^*]|[*]|[^/])*[*]+[/$]				printf("=> Comentario : '%s'\n",yytext);


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

	return 0;

}


