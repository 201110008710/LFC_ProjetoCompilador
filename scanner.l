%option nostdinit noyywrap
	#include <stdio.h>
	#include <string.h>
	#include "scannerDefi.h"

LETRA [a-zA-Z]
DIGITO [0-9]

%%

<<EOF>>									return EndOfFile;

"string"								return STRING;

"else"									return ELSE;

"if"									return IF;

"int" 									return INT;
										
"return"								return RETURN;
										
"void"									return VOID;
										
"while"									return WHILE;

"+"										return MAIS;

"-"										return MENOS;

"*"										return ASTERISCO;

"/"										return BARRA;

"<"										return MENOR;

"<="									return MENOR_IGUAL;

">"										return MAIOR;

">="									return MAIOR_IGUAL;

"=="									return IGUAL_IGUAL;

"!="									return DIFERENTE;

"="										return IGUAL;

";"										return PONTO_E_VIRGULA;

","										return VIRGULA;

"("										return ABRE_PARENTESE;

")"										return FECHA_PARENTESE;

"["										return ABRE_COLCHETE;

"]"										return FECHA_COLCHETE;

"{"										return ABRE_CHAVE;

"}"										return FECHA_CHAVE;

"/*"									return BARRA_ASTERISCO;

"*/"									return ASTERISCO_BARRA;


{LETRA}{LETRA}*							return ID;


.|\n|\r

%%
int main(int argc, char* argv[]){

	int token;
	if(argc == 1){
		yylex();
		return 0;
	}

	//Verifica a quantidade de parametros que foram passados pra 'main'
	if(argc >= 2){

		yyin = fopen(argv[1], "r");
		yyout = fopen("streamDeTokens.txt", "w");

	}else{

		printf("\nParametros Insuficientes!\n");
		return 0;

	}


	//Se o arquivo de entrada não puder ser lido o programa para a execução
	if(yyin == NULL){

		printf("\nErro na leitura do arquivo de entrada!\n");
		return 0;

	}else if(yyout = NULL){//Arquivo de entrada valido e saida invalido. Só é mostrado o resultado na tela

		printf("\nNao é possivel criar o arquivo de saida.\nO resultado SO sera exibido na tela\n");
		while( yylex() != EndOfFile);
	}

	//Arquivos de entrada e saida validos

	do{
		switch( token = yylex() ){

			case STRING:
				printf("Palavra Reservada = string\n");
				break;

			case INT:
				printf("Palavra Reservada = int\n");
				break;

			case ELSE:
				printf("Palavra Reservada = else\n");
				break;

			case IF:
				printf("Palavra Reservada = if\n");
				break;

			case RETURN:
				printf("Palavra Reservada = return\n");
				break;

			case VOID:
				printf("Palavra Reservada = void\n");
				break;

			case WHILE:
				printf("Palavra Reservada = while\n");
				break;

			case ID:
				printf("ID = %s\n",yytext);
				break;

			case EndOfFile:
				printf("\nEnd Of File\n");
				break;


		}

	}while(token != EndOfFile);

	fflush(yyout);

	fclose(yyout);

	/*
	//Força o salvamento os arquivos em disco
	

	//Se tiver algum arquivo aberto ele sera fechado
	if(yyout != NULL){
		fclose(yyout);
	}
	if(yyin != NULL){
		fclose(yyin);
	}
	*/

	return 0;
}















