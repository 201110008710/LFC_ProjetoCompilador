#include <stdlib.h>
#include "treenodes.h"

//S -> EXP
S producao_S_exp(EXP e){
	S ret = malloc(sizeof(*ret));

	ret->exp = e;
	
	return ret;
}

//EXP -> EXP SOMA TERMO | TERMO
EXP producao_EXP_expSomaTermo(EXP e, SOMA s, TERMO t){

	EXP ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = exp_soma_termo;

	ret->uniao.expSomaTermo.exp = e;
	ret->uniao.expSomaTermo.soma = s;
	ret->uniao.expSomaTermo.termo = t;
	
	return ret;
}
EXP producao_EXP_Termo(TERMO t){

	EXP ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = termo;

	ret->uniao.termo = t;

	return ret;
}

//TERMO -> TERMO MULT FATOR | FATOR
TERMO producao_TERMO_termoMultFator(TERMO t, FATOR f){

	TERMO ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = termo_mult_fator;

	ret->uniao.termoMultFator.termo = t;
	ret->uniao.termoMultFator.fator = f;

	return ret;
}
TERMO producao_TERMO_fator(FATOR f){

	TERMO ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = fator;

	ret->uniao.fator = f;

	return ret;
}

//SOMA -> '+' | '-'
SOMA producao_SOMA_maismenos(char* mais_OU_menos){

	SOMA ret = malloc(sizeof(*ret));

	ret->mais_OU_menos = mais_OU_menos;

	return ret;
}

//FATOR -> ( EXP ) | numero
FATOR producao_FATOR_abrepExpfechap(EXP e){

	FATOR ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = abrep_exp_fechap;

	ret->uniao.exp = e;

	return ret;
}
FATOR producao_FATOR_numero(int num){

	FATOR ret = malloc(sizeof(*ret));

	ret->producaoEscolhida = numero;

	ret->uniao.numero = num;

	return ret;
}
