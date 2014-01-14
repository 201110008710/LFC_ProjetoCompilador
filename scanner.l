%option nostdinit noyywrap
	#include <stdio.h>
	#include <string.h>
	#include "scannerDefi.h"

LETRA [a-zA-Z]
DIGITO [0-9]

%%

{LETRA}{LETRA}*							return ID;

{DIGITO}{DIGITO}*						return NUM;


<<EOF>>									return EndOfFile;

.|\n|\r
%%
int main(int argc, char* argv[]){

	int token;

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

			case ID:
				printf("ID = %s\n",yytext);
				break;

			case NUM:
				printf("NUM = %s\n",yytext);
				break;

			case EndOfFile:
				printf("\nEnd Of File\n");
				break;


		}

	}while(token != EndOfFile);

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















