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

	DECLARACAO-LISTA declLista;

};

//02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO
struct DECLARACAO_LISTA{

	enum{declaracao_listaDeclaracao, declaracao} producaoEscolhida;

	union{

		struct{

			DECLARACAO_LISTA declLista;

			DECLARACAO decl;

		} estrutura;

		DECLARACAO decl;

	} uniao;

};

//03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO
struct DECLARACAO{

	enum{var_declaracao, fun_declaracao} producaoEscolhida;

	union{

		VAR_DECLARACAO varDecl;

		FUN_DECLARACAO funDecl;

	} uniao;

};

//04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ];
struct VAR_DECLARACAO{

	enum{tipo_especificador_id, tipo_especificador_id_abColNumFechaCol} producaoEscolhida;

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

//05. TIPO-ESPECIFICADOR -> int | void | string //String adicionada a limguagem C-
struct TIPO_ESPECIFICADOR{

	enum{tipo_int, tipo_void, tipo_string} producaoEscolhida;

	union{

		struct{} tipoINT;

		struct{} tipoVOID;

		struct{} tipoSTRING;

	} uniao;

};
//06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS ) COMPOSTO-DECL
struct FUN_DECLARACAO {

	TIPO_ESPECIFICADOR tipoEspec;

	string id;

	PARAMS params;

	COMPOSTO_DECL compostoDecl;

};
//07. PARAMS -> PARAM-LISTA | void
struct PARAMS {

	enum{param_lista, tipoVOID} producaoEscolhida;

	union{

		PARAM_LISTA param_lista;

		struct{} tipoVOID;

	} uniao;
};
//08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM
struct PARAM-LISTA {

	enum{param_lista_param, param} producaoEscolhida;

	union{

		struct{

			PARAM_LISTA paramLista;

			PARAM param;

		} estrutura;

		PARAM param;

	} uniao;

};
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
//10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA }
struct COMPOSTO_DECL{

	LOCAL_DECLARACOES localDecl;

	STATEMENT_LISTA statementLista;

};

//11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO
struct LOCAL_DECLARACOES{

	enum{local_decl_var_decl, vazio} producaoEscolhida;

	union{
		struct{

			LOCAL_DECLARACOES localDecl;

			VAR_DECLARACAO varDecl;

		}estrutura;

		VAZIO vazio;

	} uniao;

};
//12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO
struct STATEMENT_LISTA{

	enum{statement_lista_statement, vazio} producaoEscolhida;

	union{
		struct{

			STATEMENT_LISTA statementLista;

			STATEMENT statement;

		}estrutura;

		VAZIO vazio;

	} uniao;

};

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
//16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT
struct INTERACAO_DECL{

	EXPRESSAO expressao;

	STATEMENT statement;

};

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
//18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO
struct EXPRESSAO{

	enum{var_igual_expressao, simples_expressao} producaoEscolhida;

	union{

		struct{

			VAR var;

			EXPRESSAO esxpressao;

		} estrutura_Prod1;

		SIMPLES_EXPRESSAO simplesExpressao;

	} uniao;

};
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
//20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO
struct SIMPLES_EXPRESSAO{

	enum{somaexp_relacional_somaexp, somaexp} producaoEscolhida;

	union{

		struct{

			SOMA_EXPRESSAO somaexp1;

			RELACIONAL relacional;

			SOMA_EXPRESSAO somaexp2;

		} estrutura_Prod1;

	} uniao;

};
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
//22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO
struct SOMA_EXPRESSAO{

	enum{somaexp_soma_termo, termo} producaoEscolhida;

	union{

		struct{

			SOMA_EXPRESSAO somaexp;

			SOMA soma;

			TERMO termo;

		}estrutura_Prod1;

		TERMO termo;

	} uniao;
};
//23. SOMA -> + | -
struct SOMA{

	enum{sinalmais, sinalmenos} producaoEscolhida;

	union{

		struct{} sinalMais;

		struct{} sinalMenos;
	
	}

};
//24. TERMO -> TERMO MULT FATOR | FATOR
struct TERMO{

	enum{termo_mult_fator, fator} producaoEscolhida;

	union{

		struct{

			TERMO termo;

			MULT mult;

			FATOR fator;

		} estrutura_Prod1;

		FATOR fator;
	
	}uniao;

};
//25. MULT -> * | /
struct SOMA{

	enum{vezes, divisao} producaoEscolhida;

	union{

		struct{} vezes;

		struct{} divisao;
	
	} uniao;

};
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
//27. ATIVACAO -> id ( ARGS )
struct ATIVACAO{

	ARGS argumentos;

};
//28. ARGS -> ARG-LISTA | VAZIO
struct ARGS{
	enum{arglista, vazio} producaoEscolhida;
	
	union{
		ARG_LISTA listaArgumentos;

		VAZIO vazio;
	}uniao;
};
//29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO
struct ARG_LISTA{
	enum{arglista_expressao, expressao} producaoEscolhida;

	union{

		ARG_LISTA listaArgumentos;

		EXPRESSAO expressao;

	};

	EXPRESSAO expressao;

};
//Definicao da producao vazia
struct VAZIO{

};






















#endif

