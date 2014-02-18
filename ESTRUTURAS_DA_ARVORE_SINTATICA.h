#ifndef ESTRUTURAS_DA_ARVORE_SINTATICA_H
#define ESTRUTURAS_DA_ARVORE_SINTATICA_H

//Declaração dos tipos de Nos que pertencem a arvore sintatica

typedef char* string;

//#############################################################
typedef struct PROGRAMA *PROGRAMA;

typedef struct DECLARACAO_LISTA *DECLARACAO_LISTA;

typedef struct DECLARACAO *DECLARACAO;

typedef struct VAR_DECLARACAO *VAR_DECLARACAO;

typedef struct TIPO_ESPECIFICADOR *TIPO_ESPECIFICADOR;

typedef struct FUN_DECLARACAO *FUN_DECLARACAO;

typedef struct PARAMS *PARAMS;

typedef struct PARAMS_LISTA *PARAMS_LISTA;

typedef struct PARAM *PARAM;

typedef struct COMPOSTO_DECL *COMPOSTO_DECL;

typedef struct LOCAL_DECLARACOES *LOCAL_DECLARACOES;

typedef struct STATEMENT_LISTA *STATEMENT_LISTA;

typedef struct STATEMENT *STATEMENT;

typedef struct EXPRESSAO_DECL *EXPRESSAO_DECL;

typedef struct SELECAO_DECL *SELECAO_DECL;

typedef struct INTERACAO_DECL *INTERACAO_DECL;

typedef struct RETORNO_DECL *RETORNO_DECL;

typedef struct EXPRESSAO *EXPRESSAO;

typedef struct VAR *VAR;

typedef struct SIMPLES_EXPRESSAO *SIMPLES_EXPRESSAO;

typedef struct RELACIONAL *RELACIONAL;

typedef struct SOMA_EXPRESSAO *SOMA_EXPRESSAO;

typedef struct SOMA *SOMA;

typedef struct TERMO *TERMO;

typedef struct MULT *MULT;

typedef struct FATOR *FATOR;

typedef struct ATIVACAO *ATIVACAO;

typedef struct ARGS *ARGS;

typedef struct ARG_LISTA *ARG_LISTA;

typedef struct VAZIO *VAZIO;

//Definicao das estruturas

//01. PROGRAMA -> DECLARACAO-LISTA 
struct PROGRAMA{

	DECLARACAO_LISTA declLista;

};
//Funcoes para gerar o NO 'PROGRAMA'
PROGRAMA producao_programa__declaracaoLista(DECLARACAO_LISTA declLista);



//02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO
struct DECLARACAO_LISTA{

	enum{declLista_decl, decl} producaoEscolhida;

	union{

		struct{

			DECLARACAO_LISTA declLista;

			DECLARACAO decl;

		} estrutura;

		DECLARACAO decl;

	} uniao;

};
//Funcoes para gerar o NO 'DECLARACAO_LISTA'
DECLARACAO_LISTA producao_declLista__declLista_decl(DECLARACAO_LISTA declLista, DECLARACAO decl);
DECLARACAO_LISTA producao_declLista__decl(DECLARACAO decl);



//03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO
struct DECLARACAO{

	enum{var_decl, fun_decl} producaoEscolhida;

	union{

		VAR_DECLARACAO varDecl;

		FUN_DECLARACAO funDecl;

	} uniao;

};
//Funcoes para gerar o NO 'DECLARACAO'
DECLARACAO producao_declaracao__varDeclaracao(VAR_DECLARACAO varDecl);
DECLARACAO producao_declaracao__funDeclaracao(FUN_DECLARACAO funDecl);



//04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ];
struct VAR_DECLARACAO{

	enum{tipoespec_id, tipoespec_id_abreColNumFechaCol} producaoEscolhida;

	union{

		struct{

			TIPO_ESPECIFICADOR tipoEspec;

			string id;

		} estrutura_Prod1;

		struct{

			TIPO-ESPECIFICADOR tipoEspec;

			string id;

			int num;

		} estrutura_Prod2;		

	} uniao;

};
//Funcoes para gerar o NO 'VAR_DECLARACAO'
VAR_DECLARACAO producao_vardeclaracao__tipoEspec_id(TIPO_ESPECIFICADOR tipoEspec, string id);
VAR_DECLARACAO producao_vardeclaracao__tipoEspec_id_AcolFcol(TIPO_ESPECIFICADOR tipoEspec, string id, int num);



//05. TIPO-ESPECIFICADOR -> int | void | string //String adicionada a limguagem C-
struct TIPO_ESPECIFICADOR{

	enum{tipo_int, tipo_void, tipo_string} producaoEscolhida;

	union{

		struct{} tipoINT;

		struct{} tipoVOID;

		struct{} tipoSTRING;

	} uniao;

};
//Funcoes para gerar o NO 'TIPO_ESPECIFICADOR'
TIPO_ESPECIFICADOR producao_tipoEspec__int();
TIPO_ESPECIFICADOR producao_tipoEspec__void();
TIPO_ESPECIFICADOR producao_tipoEspec__string();



//06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS ) COMPOSTO-DECL
struct FUN_DECLARACAO {

	TIPO_ESPECIFICADOR tipoEspec;

	string id;

	PARAMS params;

	COMPOSTO_DECL compostoDecl;

};
//Funcoes para gerar o NO 'FUN_DECLARACAO'
FUN_DECLARACAO producao_funDecl(TIPO_ESPECIFICADOR tipoEspec, string id,PARAMS params, COMPOSTO_DECL compostoDecl);



//07. PARAMS -> PARAM-LISTA | void
struct PARAMS {

	enum{paramlista, tipoVOID} producaoEscolhida;

	union{

		PARAM_LISTA param_lista;

		struct{} tipoVOID;

	} uniao;
};
//Funcoes para gerar o NO 'PARAMS'
PARAMS producao_params__paramLista(PARAM_LISTA paramLista);
PARAMS producao_params__void();



//08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM
struct PARAM_LISTA {

	enum{paramlista_param, param} producaoEscolhida;

	union{

		struct{

			PARAM_LISTA paramLista;

			PARAM param;

		} estrutura;

		PARAM param;

	} uniao;

};
//Funcoes para gerar o NO 'PARAM-LISTA'
PARAM_LISTA producao_paramLista__paramLista_virg_param(PARAM_LISTA paramLista, PARAM param);
PARAM_LISTA producao_paramLista__param(PARAM param);



//09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id []
struct PARAM{

	enum{tipoespec_id, tipoespec_id_abreColFechaCol} producaoEscolhida;

	union{

		struct{

			TIPO_ESPECIFICADOR tipoEspec;

			string id;

		}estrutura_Prod1;

		struct{

			TIPO_ESPECIFICADOR tipoEspec;

			string id;

		}estrutura_Prod2;
	} uniao;

};
//Funcoes para gerar o NO 'PARAM'
PARAM producao_param__tipoEspec_id(TIPO_ESPECIFICADOR tipoEspec, string id);
PARAM producao_param__tipoEspec_id_abrColFecCol(TIPO_ESPECIFICADOR tipoEspec, string id);



//10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA }
struct COMPOSTO_DECL{

	LOCAL_DECLARACOES localDecl;

	STATEMENT_LISTA statementLista;

};
//Funcoes para gerar o NO 'COMPOSTO_DECL'
COMPOSTO_DECL producao_param__tipoEspec_id(LOCAL_DECLARACOES localDecl, STATEMENT_LISTA statementLista);




//11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO
struct LOCAL_DECLARACOES{

	enum{localdecl_vardecl, vazio} producaoEscolhida;

	union{
		struct{

			LOCAL_DECLARACOES localDecl;

			VAR_DECLARACAO varDecl;

		}estrutura;

		VAZIO vazio;

	} uniao;

};
//Funcoes para gerar o NO 'LOCAL_DECLARACOES'
LOCAL_DECLARACOES producao_localDecl__localDecl_varDecl(LOCAL_DECLARACOES localDecl, VAR_DECLARACAO varDecl);
LOCAL_DECLARACOES producao_localDecl__vazio();



//12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO
struct STATEMENT_LISTA{

	enum{statementlista_statement, vazio} producaoEscolhida;

	union{
		struct{

			STATEMENT_LISTA statementLista;

			STATEMENT statement;

		}estrutura;

		VAZIO vazio;

	} uniao;

};
//Funcoes para gerar o NO 'STATEMENT_LISTA'
STATEMENT_LISTA producao_stmLista__stmLista_stm(STATEMENT_LISTA stmLista, STATEMENT stm);
STATEMENT_LISTA producao_stmLista__vazio();



//13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL
struct STATEMENT{

	enum{expressao_decl, composto_decl, selecao_decl, interacao_decl, retorno_decl} producaoEscolhida;

	union{

		EXPRESSAO_DECL expressaoDecl;

		COMPOSTO_DECL compostoDecl;

		SELECAO_DECL selecaoDecl;

		INTERACAO_DECL interacaoDecl;

		RETORNO_DECL retornoDecl;

	} uniao;

};
//Funcoes para gerar o NO 'STATEMENT'
STATEMENT producao_statement__expressaoDecl(EXPRESSAO_DECL expressaoDecl);
STATEMENT producao_statement__compostoDecl(COMPOSTO_DECL compostoDecl);
STATEMENT producao_statement__selecaoDecl(SELECAO_DECL selecaoDecl);
STATEMENT producao_statement__interacaoDecl(INTERACAO_DECL interacaoDecl);
STATEMENT producao_statement__retornoDecl(RETORNO_DECL retornoDecl);



//14. EXPRESSAO-DECL -> EXPRESSAO ; | ;
struct EXPRESSAO_DECL{

	enum{expressao_pontovirgula, pontovirgula} producaoEscolhida;

	union{

		struct{

			EXPRESSAO expressao;

		} estrutura_Prod1;

		struct{
		} estrutura_Prod2;

	} uniao;

};
//Funcoes para gerar o NO 'EXPRESSAO_DECL'
EXPRESSAO_DECL producao_expressaoDecl__expressao(EXPRESSAO expressao);
EXPRESSAO_DECL producao_expressaoDecl__pontoVirgula();



//15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT
struct SELECAO_DECL{

	enum{if_exp_statement, if_exp_statement_else_statement} producaoEscolhida;

	union{

		struct{

			EXPRESSAO expressao;

			STATEMENT statement;

		} estrutura_Prod1;

		struct{

			EXPRESSAO expressao;

			STATEMENT statement_if;

			STATEMENT statement_else;

		} estrutura_Prod2;

	} uniao;

};
//Funcoes para gerar o NO 'SELECAO_DECL'
SELECAO_DECL producao_selecaoDecl__if_exp_stm(EXPRESSAO expressao, STATEMENT stm);
SELECAO_DECL producao_selecaoDecl__if_exp_stm_else_stm(EXPRESSAO expressao, STATEMENT stm_if, STATEMENT stm_else);



//16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT
struct INTERACAO_DECL{

	EXPRESSAO expressao;

	STATEMENT statement;

};
//Funcoes para gerar o NO 'INTERACAO-DECL'
INTERACAO-DECL producao_interacaoDecl(EXPRESSAO expressao, STATEMENT stm);



//17. RETORNO-DECL -> return ; | return EXPRESSAO ;
struct RETORNO_DECL{

	enum{return_pontovirgula, return_expressao} producaoEscolhida;

	union{

		struct{} retornoVOID;

		struct{

			EXPRESSAO expressao;

		} estrutura;

	} uniao;

};
//Funcoes para gerar o NO 'RETORNO-DECL'
RETORNO-DECL producao_retornoDecl__return_pontoVirgula();
RETORNO-DECL producao_retornoDecl__return_expressao(EXPRESSAO expressao);



//18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO
struct EXPRESSAO{

	enum{var_igual_expressao, simples_expressao} producaoEscolhida;

	union{

		struct{

			VAR var;

			EXPRESSAO expressao;

		} estrutura;

		SIMPLES_EXPRESSAO simplesExpressao;

	} uniao;

};
//Funcoes para gerar o NO 'EXPRESSAO'
EXPRESSAO producao_expressao__var_igual_expressao(VAR var, EXPRESSAO expressao);
EXPRESSAO producao_expressao__simplesExpressao(SIMPLES_EXPRESSAO simplesExpressao);



//19. VAR -> id | id [ EXPRESSAO ]
struct VAR{

	enum{only_id, id_abreColExpFechaCol} producaoEscolhida;

	union{

		string id;

		struct{

			string id;

			EXPRESSAO expressao;

		} estrutura;

	} uniao;

};
//Funcoes para gerar o NO 'VAR'
VAR producao_var__id(string id);
VAR producao_var__id_abrCol_exp_fecCol(string id, EXPRESSAO expressao);



//20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO
struct SIMPLES_EXPRESSAO{

	enum{somaexp_relacional_somaexp, somaexp} producaoEscolhida;

	union{

		struct{

			SOMA_EXPRESSAO somaexp1;

			RELACIONAL relacional;

			SOMA_EXPRESSAO somaexp2;

		} estrutura;

		SOMA_EXPRESSAO somaExp;

	} uniao;

};
//Funcoes para gerar o NO 'SIMPLES_EXPRESSAO'
SIMPLES_EXPRESSAO producao_simplesExp__sumExp_rel_sumExp(SOMA_EXPRESSAO sumExp1, RELACIONAL rel, SOMA_EXPRESSAO sumExp2);
SIMPLES_EXPRESSAO producao_simplesExp__somaExp(SOMA_EXPRESSAO somaExp);

//21. RELACIONAL -> <= | < | > | >= | == | !=
struct RELACIONAL{

	enum{menorigual, menor, maior, maiorigual, igualigual, diferente} producaoEscolhida;

	union{
		struct{} menorigual;
		struct{} menor;
		struct{} maior;
		struct{} maiorigual;
		struct{} igualigual;
		struct{} diferente;
	}uniao;


};
//Funcoes para gerar o NO 'RELACIONAL'
RELACIONAL producao_relacional__menorIgual();
RELACIONAL producao_relacional__menor();
RELACIONAL producao_relacional__maior();
RELACIONAL producao_relacional__maiorIgual();
RELACIONAL producao_relacional__igualIgual();
RELACIONAL producao_relacional__diferente();



//22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO
struct SOMA_EXPRESSAO{

	enum{somaexp_soma_termo, termo} producaoEscolhida;

	union{

		struct{

			SOMA_EXPRESSAO somaexp;

			SOMA soma;

			TERMO termo;

		}estrutura;

		TERMO termo;

	} uniao;
};
//Funcoes para gerar o NO 'SOMA_EXPRESSAO'
SOMA_EXPRESSAO producao_somaExp__somaExp_soma_termo(SOMA_EXPRESSAO sumExp, SOMA soma, TERMO termo);
SOMA_EXPRESSAO producao_somaExp__termo(TERMO t);



//23. SOMA -> + | -
struct SOMA{

	enum{sinalmais, sinalmenos} producaoEscolhida;

	union{

		struct{} sinalMais;

		struct{} sinalMenos;
	
	}

};
//Funcoes para gerar o NO 'SOMA'
SOMA producao_soma__mais();
SOMA producao_soma__menos();



//24. TERMO -> TERMO MULT FATOR | FATOR
struct TERMO{

	enum{termo_mult_fator, fator} producaoEscolhida;

	union{

		struct{

			TERMO termo;

			MULT mult;

			FATOR fator;

		} estrutura;

		FATOR fator;
	
	}uniao;

};
//Funcoes para gerar o NO 'TERMO'
TERMO producao_termo__termo_mult_fator(TERMO termo, MULT mult, FATOR fator);
TERMO producao_termo__fator(FATOR f);



//25. MULT -> * | /
struct MULT{

	enum{vezes, divisao} producaoEscolhida;

	union{

		struct{} vezes;

		struct{} divisao;
	
	} uniao;

};
//Funcoes para gerar o NO 'MULT'
MULT producao_mult__vezes();
MULT producao_mult__divisao();



//26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero
struct FATOR{

	enum{abrePExpFechaP, variavel, ativacao, numero} producaoEscolhida;

	union{

		EXPRESSAO expressao;

		VAR variavel;

		ATIVACAO ativacao;

		int numero;
	}

};
//Funcoes para gerar o NO 'FATOR'
FATOR producao_fator__abrP_exp_fecP(EXPRESSAO expressao);
FATOR producao_fator__var(VAR variavel);
FATOR producao_fator__ativacao(ATIVACAO ativacao);
FATOR producao_fator__numero(int num);



//27. ATIVACAO -> id ( ARGS )
struct ATIVACAO{

	string id;

	ARGS argumentos;

};
//Funcoes para gerar o NO 'ATIVACAO'
ATIVACAO producao_ativacao__argumentos(string id, ARGS argumentos);



//28. ARGS -> ARG-LISTA | VAZIO
struct ARGS{
	enum{arglista, vazio} producaoEscolhida;
	
	union{
		ARG_LISTA listaArgumentos;

		VAZIO vazio;
	}uniao;
};
//Funcoes para gerar o NO 'ARGS'
ARGS producao_args__argLista(ARG_LISTA listaArgumentos);
ARGS producao_args__vazio();



//29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO
struct ARG_LISTA{
	enum{arglista_expressao, expressao} producaoEscolhida;

	union{

		ARG_LISTA listaArgumentos;

		EXPRESSAO expressao;

	};

	EXPRESSAO expressao;

};
//Funcoes para gerar o NO 'ARG_LISTA'
ARG_LISTA producao_argLista__argLista_pontoVirgula_exp(ARG_LISTA listaArgumentos, EXPRESSAO expressao);
ARG_LISTA producao_argLista__exp(EXPRESSAO expressao);

//Definicao da producao vazia
struct VAZIO{

};


#endif