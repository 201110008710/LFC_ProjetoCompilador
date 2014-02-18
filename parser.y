%{ 
/* 
  ANALISADOR SINTÁTICO BASEADO NA LIMGUAGEM C- DESCRITA NO LIVRO:
  COMPILADORES:PRINCIPIOS E PRATICAS, 2ª EDICAO, KENNETH C. LOUDEN. PG. 494

  01. PROGRAMA -> DECLARACAO-LISTA 
  02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO
  03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO

  04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ];
  05. TIPO-ESPECIFICADOR -> int | void

  06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS) COMPOSTO-DECL
  07. PARAMS -> PARAM-LISTA | void
  08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM
  09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id []

  10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA }

  11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO
  12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO

  13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL
  14. EXPRESSAO-DECL -> EXPRESSAO ; | ;

  15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT

  16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT

  17. RETORNO-DECL -> return ; | return EXPRESSAO ;

  18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO

  19. VAR -> id | id [ EXPRESSAO ]

  20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO
  21. RELACIONAL -> <= | < | > | >= | == | !=

  22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO
  23. SOMA -> + | -
  24. TERMO -> TERMO MULT FATOR | FATOR
  25. MULT -> * | /

  26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero
  
  27. ATIVACAO -> id ( ARGS )
  28. ARGS -> ARG-LISTA | VAZIO
  29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO

################################################################################################

  HEADERS:
  	-ESTRUTURAS_DA_ARVORE_SINTATICA.h
  		*Declaracao de todas as 'structs' que representam os nos da arvore sintatica
  		*Assinatura das funcoes que iram criar os nó durante a analise

  	-IMPLEMENTACAO_DAS_FUNCOES_GERADORAS_DA_ARVORE.h
  		*Implementacao do código das funcoes definidas em "ESTRUTURAS_DA_ARVORE_SINTATICA.h"

################################################################################################
  
  Ambiguidade do ELSE pendente:
  	-Regra de eliminação de ambiguidade do "aninhamento mais proximo"

################################################################################################

  bison -v -d -o parser.c parser.y
*/

#include "ESTRUTURAS_DA_ARVORE_SINTATICA.h"
#include "IMPLEMENTACAO_DAS_ESTRUTURAS_DA_ARVORE.h"


//Declaracao da funcao yyerror()
void yyerror(char *s);

%}


%expect 1

%union{

	char* id;
	int digito;
	char* string;

	PROGRAMA programa;

	DECLARACAO_LISTA declaracao_lista;

	DECLARACAO declaracao;

	VAR_DECLARACAO var_declaracao;

	TIPO_ESPECIFICADOR tipo_especificador;

	FUN_DECLARACAO fun_declaracao;

	PARAMS params;

	PARAMS_LISTA params_lista;

	PARAM param;

	COMPOSTO_DECL composto_decl;

	LOCAL_DECLARACOES local_declaracoes;

	STATEMENT_LISTA statement_lista;

	STATEMENT statement;

	EXPRESSAO_DECL expressao_decl;

	SELECAO_DECL selecao_decl;

	INTERACAO_DECL interacao_decl;

	RETORNO_DECL retorno_decl;
	
	EXPRESSAO expressao;

	VAR var;

	SIMPLES_EXPRESSAO simples_expressao;

	RELACIONAL relacional;

	SOMA_EXPRESSAO soma_expressao;

	SOMA soma;

	TERMO termo;

	MULT mult;

	FATOR fator;

	ATIVACAO ativacao;

	ARGS args;

	ARG_LISTA arg_lista;

	VAZIO vazio;

};


%token STRING IF ELSE INT RETURN VOID WHILE

%token MAIS MENOS VEZES BARRA MENOR MENORIGUAL MAIOR MAIORIGUAL IGUALIGUAL
%token DIFERENTE IGUAL PONTOVIRGULA VIRGULA ABREPARENTESIS FECHAPARENTESIS
%token ABRECOLCHETE FECHACOLCHETE ABRECHAVE FECHACHAVE

%token<id> ID
%token<digito> DIGITO
%token<string> CADEIASTRING


%type <programa>			PROGRAMA
%type <declaracao_lista>	DECLARACAO_LISTA
%type <declaracao>			DECLARACAO
%type <var_declaracao>		VAR_DECLARACAO
%type <tipo_especificador>	TIPO_ESPECIFICADOR
%type <fun_declaracao>		FUN_DECLARACAO
%type <params> 				PARAMS
%type <params_lista>		PARAMS_LISTA
%type <param>				PARAM
%type <composto_decl>		COMPOSTO_DECL
%type <local_declaracoes>	LOCAL_DECLARACOES
%type <statement_lista> 	STATEMENT_LISTA
%type <statement> 			STATEMENT
%type <expressao_decl> 		EXPRESSAO_DECL
%type <selecao_decl> 		SELECAO_DECL
%type <interacao_decl> 		INTERACAO_DECL
%type <retorno_decl> 		RETORNO_DECL
%type <expressao> 			EXPRESSAO
%type <var>					VAR
%type <simples_expressao> 	SIMPLES_EXPRESSAO
%type <relacional> 			RELACIONAL
%type <soma_expressao> 		SOMA_EXPRESSAO
%type <soma> 				SOMA
%type <termo> 				TERMO
%type <mult> 				MULT
%type <fator> 				FATOR
%type <ativacao> 			ATIVACAO
%type <args>				ARGS
%type <arg_lista>			ARG_LISTA
%type <vazio>				VAZIO


%start PROGRAMA



%%

/* 01. PROGRAMA -> DECLARACAO-LISTA */
PROGRAMA: DECLARACAO-LISTA {}
;



/* 02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO */
DECLARACAO_LISTA :	DECLARACAO_LISTA DECLARACAO   {}
					| DECLARACAO 				  {}
  
/* 03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO */
  
/* 04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ]; */
  
/* 05. TIPO-ESPECIFICADOR -> int | void */
  
/* 06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS) COMPOSTO-DECL */
  
/* 07. PARAMS -> PARAM-LISTA | void */
  
/* 08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM */
  
/* 09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id [] */
  
/* 10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA } */
  
/* 11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO */
  
/* 12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO */
  
/* 13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL */
  
/* 14. EXPRESSAO-DECL -> EXPRESSAO ; | ; */
  
/* 15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT */
  
/* 16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT */
  
/* 17. RETORNO-DECL -> return ; | return EXPRESSAO ; */
  
/* 18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO */
  
/* 19. VAR -> id | id [ EXPRESSAO ] */
  
/* 20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO */
  
/* 21. RELACIONAL -> <= | < | > | >= | == | != */
  
/* 22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO */
  
/* 23. SOMA -> + | - */
  
/* 24. TERMO -> TERMO MULT FATOR | FATOR */
  
/* 25. MULT -> * | / */
  
/* 26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero */
  
/* 27. ATIVACAO -> id ( ARGS ) */
  
/* 28. ARGS -> ARG-LISTA | VAZIO */
  
/* 29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO */
  
%%

#include <stdlib.h>
#include <stdio.h>

void yyerror(char *s)
{
   //fprintf(stderr,"Erro sintático.\n");
   //exit(1);
}

main(){
	
	//Se modoTeste = 1 a entrada e saida sao padroes
	//Se modoTeste = 0, o programa devera receber um arquivo texto como entrada

	int modoTeste = 0;
  	int ret;

  	if(modoTeste){
  		printf("\e[H\e[2J");
  		while(1){
		    printf("\nINSIRA SUA ENTRADA E NO FIM FACA (ENTER) E EM SEGUIDA (CTRL + D) PARA COMECAR A ANALISE\n");
		  	printf("\nPARA ENCERRAR O PROGRAMA FACA (CTRL + C)\n");

		  	printf("\nInicio da analise sintatica \nEntrada:\n");

		  	ret = yyparse();

		  	if(ret == 0){
		  		printf("\n\nFim da analise sintatica - NAO HOUVE erro sintatico -\nPRESSIONE ENTER PARA TENTAR NOVAMENTE");
		  	}else{
		  		printf("\n\nFim da analise sintatica - HOUVE erro sintatico -\nPRESSIONE ENTER PARA TENTAR NOVAMENTE");
		  	}
		  	scanf("%c",&ret);
		  	printf("\e[H\e[2J");
  		}
  	}else{

  		yyparse();

  	}
  
  
  return 0;	
}
 
