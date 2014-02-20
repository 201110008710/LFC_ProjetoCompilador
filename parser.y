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

  bison -v -d -o parser_generateByBison.c parser.y

  flex -v -t scanner.l > scanner_generateByFlex.c

  gcc parser_generateByBison.c scanner_generateByFlex.c -o compilador

*/

#include "ESTRUTURAS_DA_ARVORE_SINTATICA.h"
#include "IMPLEMENTACAO_DAS_FUNCOES_GERADORAS_DA_ARVORE.h"


//Declaracao da funcao yyerror()
void yyerror(char *s);

%}


%expect 1

%union{

	char* string;

	int digito;

	PROGRAMA programa;

	DECLARACAO_LISTA declaracao_lista;

	DECLARACAO declaracao;

	VAR_DECLARACAO var_declaracao;

	TIPO_ESPECIFICADOR tipo_especificador;

	FUN_DECLARACAO fun_declaracao;

	PARAMS params;

	PARAM_LISTA param_lista;

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

};


%token STRING IF ELSE INT RETURN VOID WHILE

%token MAIS MENOS VEZES BARRA MENOR MENORIGUAL MAIOR MAIORIGUAL IGUALIGUAL
%token DIFERENTE IGUAL PONTOVIRGULA VIRGULA ABREPARENTESIS FECHAPARENTESIS
%token ABRECOLCHETE FECHACOLCHETE ABRECHAVE FECHACHAVE

%token<string> ID
%token<string> CADEIASTRING
%token<digito> DIGITO



%type <programa>			PROGRAMA
%type <declaracao_lista>	DECLARACAO_LISTA
%type <declaracao>			DECLARACAO
%type <var_declaracao>		VAR_DECLARACAO
%type <tipo_especificador>	TIPO_ESPECIFICADOR
%type <fun_declaracao>		FUN_DECLARACAO
%type <params> 				PARAMS
%type <param_lista>			PARAM_LISTA
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


%start PROGRAMA



%%

/* 01. PROGRAMA -> DECLARACAO-LISTA */
PROGRAMA: 			  DECLARACAO_LISTA	{ $$ = producao_programa__declaracaoLista($1); }
;


/* 02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO */
DECLARACAO_LISTA :	  DECLARACAO_LISTA DECLARACAO 	{ $$ = producao_declLista__declLista_decl($1, $2); }
					| DECLARACAO 				  	{ $$ = producao_declLista__decl($1); }
;


/* 03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO */
DECLARACAO : 		  VAR_DECLARACAO 	{ $$ = producao_declaracao__varDeclaracao($1); }
					| FUN_DECLARACAO 	{ $$ = producao_declaracao__funDeclaracao($1); }
;


/* 04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ]; */
VAR_DECLARACAO : 	  TIPO_ESPECIFICADOR ID PONTOVIRGULA 									
					  { $$ = producao_vardeclaracao__tipoEspec_id($1, $2); }

					| TIPO_ESPECIFICADOR ID ABRECOLCHETE DIGITO FECHACOLCHETE PONTOVIRGULA
					  { $$ = producao_vardeclaracao__tipoEspec_id_AcolFcol($1, $2, $4); }
;


/* 05. TIPO-ESPECIFICADOR -> int | void | string*/
TIPO_ESPECIFICADOR:   INT    { $$ = producao_tipoEspec__int(); }
					| VOID   { $$ = producao_tipoEspec__void(); }
					| STRING { $$ = producao_tipoEspec__string(); }
;


/* 06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS ) COMPOSTO-DECL */
FUN_DECLARACAO : 	  TIPO_ESPECIFICADOR ID ABREPARENTESIS PARAMS FECHAPARENTESIS COMPOSTO_DECL 
					  { $$ = producao_funDecl($1, $2, $4, $6);}
;


/* 07. PARAMS -> PARAM-LISTA | void */
PARAMS : 			  PARAM_LISTA { $$ = producao_params__paramLista($1); }
					| VOID 		  { $$ = producao_params__void(); }
;


/* 08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM */
PARAM_LISTA : 		  PARAM_LISTA VIRGULA PARAM 	{ $$ = producao_paramLista__paramLista_virg_param($1, $3); }
					| PARAM 						{ $$ = producao_paramLista__param($1); }
;


/* 09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id [] */
PARAM : 			  TIPO_ESPECIFICADOR ID
					  { $$ = producao_param__tipoEspec_id($1, $2); }

					| TIPO_ESPECIFICADOR ID ABRECOLCHETE FECHACOLCHETE
					  { $$ = producao_param__tipoEspec_id_abrColFecCol($1, $2); }
;


/* 10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA } */
COMPOSTO_DECL :		  ABRECHAVE LOCAL_DECLARACOES STATEMENT_LISTA FECHACHAVE { $$ = producao_compostoDecl($2, $3); }
;


/* 11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO */
LOCAL_DECLARACOES :	  LOCAL_DECLARACOES VAR_DECLARACAO 	{ $$ = producao_localDecl__localDecl_varDecl($1, $2); }
					| 		 						 	{ $$ = producao_localDecl__vazio(); }
;

 
/* 12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO */
STATEMENT_LISTA :	  STATEMENT_LISTA STATEMENT 	{ $$ = producao_stmLista__stmLista_stm($1, $2); }
					| 		 						{ $$ = producao_stmLista__vazio(); }
;


/* 13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL */
STATEMENT : 		  EXPRESSAO_DECL { $$ = producao_statement__expressaoDecl($1); }
					| COMPOSTO_DECL  { $$ = producao_statement__compostoDecl($1); }
					| SELECAO_DECL   { $$ = producao_statement__selecaoDecl($1); }
					| INTERACAO_DECL { $$ = producao_statement__interacaoDecl($1); }
					| RETORNO_DECL   { $$ = producao_statement__retornoDecl($1); }
;


/* 14. EXPRESSAO-DECL -> EXPRESSAO ; | ; */
EXPRESSAO_DECL : 	  EXPRESSAO PONTOVIRGULA 	{ $$ = producao_expressaoDecl__expressao($1); }
					| PONTOVIRGULA          	{ $$ = producao_expressaoDecl__pontoVirgula(); }  
;


/* 15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT */
SELECAO_DECL : 		  IF ABREPARENTESIS EXPRESSAO FECHAPARENTESIS STATEMENT
					  { $$ = producao_selecaoDecl__if_exp_stm($3, $5); }

					| IF ABREPARENTESIS EXPRESSAO FECHAPARENTESIS STATEMENT ELSE STATEMENT
					  { $$ = producao_selecaoDecl__if_exp_stm_else_stm($3, $5, $7); }
;


/* 16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT */
INTERACAO_DECL : 	  WHILE ABREPARENTESIS EXPRESSAO FECHAPARENTESIS STATEMENT
					  { $$ = producao_interacaoDecl($3, $5); }
;


/* 17. RETORNO-DECL -> return ; | return EXPRESSAO ; */
RETORNO_DECL : 		  RETURN PONTOVIRGULA 				{ $$ = producao_retornoDecl__return_pontoVirgula(); }
					| RETURN EXPRESSAO PONTOVIRGULA 	{ $$ = producao_retornoDecl__return_expressao($2); }  
;


/* 18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO */
EXPRESSAO : 		  VAR IGUAL EXPRESSAO 	{ $$ = producao_expressao__var_igual_expressao($1, $3); }
					| SIMPLES_EXPRESSAO 	{ $$ = producao_expressao__simplesExpressao($1); }
;


/* 19. VAR -> id | id [ EXPRESSAO ] */
VAR : 				  ID 										{ $$ = producao_var__id($1); }
					| ID ABRECOLCHETE EXPRESSAO FECHACOLCHETE 	{ $$ = producao_var__id_abrCol_exp_fecCol($1, $3);}
;

  
/* 20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO */
SIMPLES_EXPRESSAO :   SOMA_EXPRESSAO RELACIONAL SOMA_EXPRESSAO 
					  { $$ = producao_simplesExp__sumExp_rel_sumExp($1, $2,$3); }

					| SOMA_EXPRESSAO
					  { $$ = producao_simplesExp__somaExp($1); }
;


/* 21. RELACIONAL -> <= | < | > | >= | == | != */
RELACIONAL : 		  MENORIGUAL { $$ = producao_relacional__menorIgual(); }
					| MENOR      { $$ = producao_relacional__menor(); }
					| MAIOR 	 { $$ = producao_relacional__maior(); }
					| MAIORIGUAL { $$ = producao_relacional__maiorIgual(); }
					| IGUALIGUAL { $$ = producao_relacional__igualIgual(); }
					| DIFERENTE  { $$ = producao_relacional__diferente(); }
;


/* 22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO */
SOMA_EXPRESSAO: 	  SOMA_EXPRESSAO SOMA TERMO { $$ = producao_somaExp__somaExp_soma_termo($1, $2, $3); }
					| TERMO 					{ $$ = producao_somaExp__termo($1); }
;


/* 23. SOMA -> + | - */
SOMA : 				  MAIS  { $$ = producao_soma__mais(); }
					| MENOS { $$ = producao_soma__menos(); } 
;


/* 24. TERMO -> TERMO MULT FATOR | FATOR */
TERMO : 			  TERMO MULT FATOR { $$ = producao_termo__termo_mult_fator($1, $2, $3); }
					| FATOR 		   { $$ = producao_termo__fator($1); }
;


/* 25. MULT -> * | / */
MULT : 				  VEZES { $$ = producao_mult__vezes(); }
					| BARRA { $$ = producao_mult__divisao(); }
;


/* 26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero */
FATOR : 			  ABREPARENTESIS EXPRESSAO FECHAPARENTESIS 	{ $$ = producao_fator__abrP_exp_fecP($2); }
					| VAR 										{ $$ = producao_fator__var($1);}
					| ATIVACAO 									{ $$ = producao_fator__ativacao($1); }
					| DIGITO 									{ $$ = producao_fator__numero($1); }
					| CADEIASTRING 								{ $$ = producao_fator__cadeiaString($1); }
;


/* 27. ATIVACAO -> id ( ARGS ) */
ATIVACAO : 			  ID ABREPARENTESIS ARGS FECHAPARENTESIS 	{ $$ = producao_ativacao__argumentos($1, $3);}
;


/* 28. ARGS -> ARG-LISTA | VAZIO */
ARGS : 				  ARG_LISTA { $$ = producao_args__argLista($1); }
					| 			{ $$ = producao_args__vazio(); } 
;


/* 29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO */
ARG_LISTA : 		  ARG_LISTA VIRGULA EXPRESSAO
					  { $$ = producao_argLista__argLista_pontoVirgula_exp($1, $3); }

					| EXPRESSAO
					  { $$ = producao_argLista__exp($1); }
%%

#include <stdlib.h>
#include <stdio.h>

void yyerror(char *s)
{
   printf("Erro sintático.\n");
   exit(1);
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
 
