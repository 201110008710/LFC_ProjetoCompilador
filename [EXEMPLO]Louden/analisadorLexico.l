/*
   Exemplo - Analisador léxico
   
   Uma linguagem que reconhece a declaração de uma variável simples e uma atribuição de um valor inteiro.
   
   Este analisador léxico não considera os casos de erro léxico
   
   // só isso! (quantas vezes quiser)
   int ID;
   ID = VALORINTEIRO;
   
*/

%option noyywrap

%{ 

#include "treenodes.h"
#include "analisadorsintatico.h"

%}


NUM [0-9]+

%% 

"("		{ return ABREPARENTESIS; }

"("		{ return FECHAPARENTESIS; }

"\*"	{ return MULT; }

"+"		{ return MAIS; }

"-"     { return MENOS; }

{NUM} 	{ return NUMERO; }


.|\n|\r

%% 
