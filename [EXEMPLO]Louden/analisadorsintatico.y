%{  
/* 
   ANALISADOR SINTÁTICO
	
   <S> -> <exp>

   <exp> -> <exp> <soma> <termo> | <termo>

   <soma> -> '+' | '-'

   <termo> -> <termo> <mult> <fator> | <fator>

   <fator> -> (<exp>) | 'numero'
*/

#include "treenodes.h"
#include "implementacao.h"

void yyerror(char *s);//Declaracao da funcao yyerror()

%}

%union{

	int numero;
	char* mais_OU_menos;

	S variavelInicial;
	EXP exp;
	SOMA soma;
	TERMO termo;
	FATOR fator;

};


%start S

%token ABREPARENTESIS 
%token FECHAPARENTESIS
%token MULT
%token <mais_OU_menos> MAIS
%token <mais_OU_menos> MENOS
%token <numero> NUMERO

%type <variavelInicial> S
%type <termo> TERMO
%type <exp> EXP
%type <soma> SOMA
%type <fator> FATOR

%%


S :		EXP { $$ = producao_S_exp($1); }
;

EXP :	EXP SOMA TERMO { $$ = producao_EXP_expSomaTermo($1, $2, $3); }
		| TERMO { $$ = producao_EXP_Termo($1); }
;


TERMO :	TERMO MULT FATOR { $$ = producao_TERMO_termoMultFator($1, $3); }
		| FATOR { $$ = producao_TERMO_fator($1); }
;

SOMA : 	MAIS { producao_SOMA_maismenos($1); }
		|MENOS { $$ = producao_SOMA_maismenos($1); }
;

FATOR :	ABREPARENTESIS EXP FECHAPARENTESIS { $$ = producao_FATOR_abrepExpfechap($2); }
		| NUMERO { $$ = producao_FATOR_numero($1); }
;

%%

#include <stdlib.h>
#include <stdio.h>

void yyerror(char *s)
{
   //fprintf(stderr,"Erro sintático.\n");
   //exit(1);
}

main(){	
  int ret;
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
  return 0;	
}
