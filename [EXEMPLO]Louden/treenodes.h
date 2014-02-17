#ifndef TREENODES_H
#define TREENODES_H

//Declaração dos Nos sao parte da arvore abstrata

typedef struct S *S;

typedef struct EXP *EXP;

typedef struct TERMO *TERMO;

typedef struct SOMA *SOMA;

typedef struct FATOR *FATOR;


//S -> EXP
struct S {

	EXP exp;

};

//EXP -> EXP SOMA TERMO | TERMO
struct EXP {

	enum{exp_soma_termo, termo} producaoEscolhida;

	union{

		struct{
			EXP exp;

			SOMA soma;

			TERMO termo;

		}expSomaTermo;

		TERMO termo;

	}uniao;

};

//TERMO -> TERMO MULT FATOR | FATOR
struct TERMO {

	enum{termo_mult_fator, fator} producaoEscolhida;

	union{

		struct{
			TERMO termo;

			FATOR fator;

		}termoMultFator;

		FATOR fator;

	}uniao;

};

//SOMA -> '+' | '-'
struct SOMA {
	char* mais_OU_menos;
};

//FATOR -> ( EXP ) | numero
struct FATOR{

	enum{abrep_exp_fechap, numero} producaoEscolhida;

	union{

		EXP exp;

		int numero;

	}uniao;

};


//S -> EXP
S producao_S_exp(EXP e);

//EXP -> EXP SOMA TERMO | TERMO
EXP producao_EXP_expSomaTermo(EXP e, SOMA s, TERMO t);
EXP producao_EXP_Termo(TERMO t);

//TERMO -> TERMO MULT FATOR | FATOR
TERMO producao_TERMO_termoMultFator(TERMO t, FATOR f);
TERMO producao_TERMO_fator(FATOR f);

//SOMA -> '+' | '-'
SOMA producao_SOMA_maismenos(char* mais_OU_menos);

//FATOR -> ( EXP ) | numero
FATOR producao_FATOR_abrepExpfechap(EXP e);
FATOR producao_FATOR_numero(int num);

#endif
