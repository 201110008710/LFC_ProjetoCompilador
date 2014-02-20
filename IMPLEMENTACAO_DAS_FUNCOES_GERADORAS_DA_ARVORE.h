#include <stdlib.h>
#include "ESTRUTURAS_DA_ARVORE_SINTATICA.h" 

//01. PROGRAMA -> DECLARACAO-LISTA 
//Funcao para gerar o NO 'PROGRAMA'
PROGRAMA producao_programa__declaracaoLista(DECLARACAO_LISTA declLista){

	PROGRAMA prog = malloc(sizeof(*prog));

	prog->declLista = declLista;
	
	return prog;
}



//02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO
//Funcoes para gerar o NO 'DECLARACAO_LISTA'
DECLARACAO_LISTA producao_declLista__declLista_decl(DECLARACAO_LISTA declLista, DECLARACAO decl){
	
	DECLARACAO_LISTA declaracaoLista = malloc(sizeof(*declaracaoLista));

	declaracaoLista->producaoEscolhida = declLista_decl;

	declaracaoLista->uniao.estrutura.declLista = declLista;	
	declaracaoLista->uniao.estrutura.decl = decl;

	return declaracaoLista;
}
DECLARACAO_LISTA producao_declLista__decl(DECLARACAO decl){

	DECLARACAO_LISTA declaracaoLista = malloc(sizeof(*declaracaoLista));

	declaracaoLista->producaoEscolhida = decl;

	declaracaoLista->uniao.decl = decl;

	return declaracaoLista;
}



//03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO
//Funcoes para gerar o NO 'DECLARACAO'
DECLARACAO producao_declaracao__varDeclaracao(VAR_DECLARACAO varDecl){

	DECLARACAO declaracao = malloc(sizeof(*declaracao));

	declaracao->producaoEscolhida = var_decl;

	declaracao->uniao.varDecl = varDecl;

	return declaracao;

}
DECLARACAO producao_declaracao__funDeclaracao(FUN_DECLARACAO funDecl){

	DECLARACAO declaracao = malloc(sizeof(*declaracao));

	declaracao->producaoEscolhida = fun_decl;

	declaracao->uniao.funDecl = funDecl;

	return declaracao;
}



//04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ];
//Funcoes para gerar o NO 'VAR_DECLARACAO'
VAR_DECLARACAO producao_vardeclaracao__tipoEspec_id(TIPO_ESPECIFICADOR tipoEspec, string id){

	VAR_DECLARACAO varDeclaracao = malloc(sizeof(*varDeclaracao));

	varDeclaracao->producaoEscolhida = tipoespec_id;

	varDeclaracao->uniao.estrutura_Prod1.tipoEspec = tipoEspec;
	varDeclaracao->uniao.estrutura_Prod1.id = id;

	return varDeclaracao;

}
VAR_DECLARACAO producao_vardeclaracao__tipoEspec_id_AcolFcol(TIPO_ESPECIFICADOR tipoEspec, string id, int num){

	VAR_DECLARACAO varDeclaracao = malloc(sizeof(*varDeclaracao));

	varDeclaracao->producaoEscolhida = tipoespec_id_abreColNumFechaCol;

	varDeclaracao->uniao.estrutura_Prod2.tipoEspec = tipoEspec;
	varDeclaracao->uniao.estrutura_Prod2.id = id;
	varDeclaracao->uniao.estrutura_Prod2.num = num;

	return varDeclaracao;
}



//05. TIPO-ESPECIFICADOR -> int | void | string //String adicionada a limguagem C-
//Funcoes para gerar o NO 'TIPO_ESPECIFICADOR'
TIPO_ESPECIFICADOR producao_tipoEspec__int(){
	
	TIPO_ESPECIFICADOR tipoEspecificador = malloc(sizeof(*tipoEspecificador));

	tipoEspecificador->producaoEscolhida = tipo_int;

	return tipoEspecificador;
}
TIPO_ESPECIFICADOR producao_tipoEspec__void(){

	TIPO_ESPECIFICADOR tipoEspecificador = malloc(sizeof(*tipoEspecificador));

	tipoEspecificador->producaoEscolhida = tipo_void;

	return tipoEspecificador;
}
TIPO_ESPECIFICADOR producao_tipoEspec__string(){

	TIPO_ESPECIFICADOR tipoEspecificador = malloc(sizeof(*tipoEspecificador));

	tipoEspecificador->producaoEscolhida = tipo_string;

	return tipoEspecificador;
}



//06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS ) COMPOSTO-DECL
//Funcoes para gerar o NO 'FUN_DECLARACAO'
FUN_DECLARACAO producao_funDecl(TIPO_ESPECIFICADOR tipoEspec, string id,PARAMS params, COMPOSTO_DECL compostoDecl){

	FUN_DECLARACAO funDeclaracao = malloc(sizeof(*funDeclaracao));

	funDeclaracao->tipoEspec = tipoEspec;
	funDeclaracao->id = id;
	funDeclaracao->params = params;
	funDeclaracao->compostoDecl = compostoDecl;

	return funDeclaracao;

}



//07. PARAMS -> PARAM-LISTA | void
//Funcoes para gerar o NO 'PARAMS'
PARAMS producao_params__paramLista(PARAM_LISTA paramLista){

	PARAMS params = malloc(sizeof(*params));

	params->producaoEscolhida = paramlista;

	params->uniao.param_lista = paramLista;

	return params;
}
PARAMS producao_params__void(){

	PARAMS params = malloc(sizeof(*params));

	params->producaoEscolhida = tipoVOID;

	return params;
}



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
PARAM_LISTA producao_paramLista__paramLista_virg_param(PARAM_LISTA paramLista, PARAM param){

	PARAM_LISTA param_Lista = malloc(sizeof(*param_Lista));

	param_Lista->producaoEscolhida = paramlista_param;

	param_Lista->uniao.estrutura.paramLista = paramLista;
	param_Lista->uniao.estrutura.param = param;

	return param_Lista;
}
PARAM_LISTA producao_paramLista__param(PARAM param){

	PARAM_LISTA param_Lista = malloc(sizeof(*param_Lista));

	param_Lista->producaoEscolhida = param;

	param_Lista->uniao.param = param;

	return param_Lista;
}



//09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id []
//Funcoes para gerar o NO 'PARAM'
PARAM producao_param__tipoEspec_id(TIPO_ESPECIFICADOR tipoEspec, string id){

	PARAM param = malloc(sizeof(*param));

	param->producaoEscolhida = tipoespec_id;
 
	param->uniao.estrutura_Prod1.tipoEspec = tipoEspec;
	param->uniao.estrutura_Prod1.id = id;

	return param;
}
PARAM producao_param__tipoEspec_id_abrColFecCol(TIPO_ESPECIFICADOR tipoEspec, string id){

	PARAM param = malloc(sizeof(*param));

	param->producaoEscolhida = tipoespec_id_abreColFechaCol;

	param->uniao.estrutura_Prod2.tipoEspec = tipoespec_id_abreColFechaCol;
	param->uniao.estrutura_Prod2.id = id;

	return param;
}



//10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA }
//Funcoes para gerar o NO 'COMPOSTO_DECL'
COMPOSTO_DECL producao_compostoDecl(LOCAL_DECLARACOES localDecl, STATEMENT_LISTA statementLista){

	COMPOSTO_DECL compostoDecl = malloc(sizeof(*compostoDecl));

	compostoDecl->localDecl = localDecl;
	compostoDecl->statementLista = statementLista;

	return compostoDecl;
}



//11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO
//Funcoes para gerar o NO 'LOCAL_DECLARACOES'
LOCAL_DECLARACOES producao_localDecl__localDecl_varDecl(LOCAL_DECLARACOES localDecl, VAR_DECLARACAO varDecl){

	LOCAL_DECLARACOES localDeclaracoes = malloc(sizeof(*localDeclaracoes));

	localDeclaracoes->producaoEscolhida = localdecl_vardecl;

	localDeclaracoes->uniao.estrutura.localdecl = localdecl;
	localDeclaracoes->uniao.estrutura.vardecl = vardecl;

	return localDeclaracoes;
}
LOCAL_DECLARACOES producao_localDecl__vazio(){

	LOCAL_DECLARACOES localDeclaracoes = malloc(sizeof(*localDeclaracoes));

	localDeclaracoes->producaoEscolhida = vazio;

	return localDeclaracoes;
}



//12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO
//Funcoes para gerar o NO 'STATEMENT_LISTA'
STATEMENT_LISTA producao_stmLista__stmLista_stm(STATEMENT_LISTA stmLista, STATEMENT stm){

	STATEMENT_LISTA statement_Lista = malloc(sizeof(*statement_Lista));

	statement_Lista->producaoEscolhida = statementlista_statement;

	statement_Lista->uniao.estrutura.statementLista = stmLista;
	statement_Lista->uniao.estrutura.statement = stm;

	return statement_Lista;
}
STATEMENT_LISTA producao_stmLista__vazio(){

	STATEMENT_LISTA statement_Lista = malloc(sizeof(*statement_Lista));

	statement_Lista->producaoEscolhida = vazio;

	return statement_Lista;
}



//13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL
//Funcoes para gerar o NO 'STATEMENT'
STATEMENT producao_statement__expressaoDecl(EXPRESSAO_DECL expressaoDecl){

	STATEMENT statement = malloc(sizeof(*statement));

	statement->producaoEscolhida = expressao_decl;

	statement->uniao.expressaoDecl = expressaoDecl;

	return statement;
}
STATEMENT producao_statement__compostoDecl(COMPOSTO_DECL compostoDecl){

	STATEMENT statement = malloc(sizeof(*statement));

	statement->producaoEscolhida = composto_decl;

	statement->uniao.compostoDecl = compostoDecl;

	return statement;
}
STATEMENT producao_statement__selecaoDecl(SELECAO_DECL selecaoDecl){

	STATEMENT statement = malloc(sizeof(*statement));

	statement->producaoEscolhida = selecao_decl;

	statement->uniao.selecaoDecl = selecaoDecl;

	return statement;
}
STATEMENT producao_statement__interacaoDecl(INTERACAO_DECL interacaoDecl){

	STATEMENT statement = malloc(sizeof(*statement));

	statement->producaoEscolhida = interacao_decl;

	statement->uniao.interacaoDecl = interacaoDecl;

	return statement;
}
STATEMENT producao_statement__retornoDecl(RETORNO_DECL retornoDecl){

	STATEMENT statement = malloc(sizeof(*statement));

	statement->producaoEscolhida = retorno_decl;

	statement->uniao.retornoDecl = retornoDecl;

	return statement;
}



//14. EXPRESSAO-DECL -> EXPRESSAO ; | ;
//Funcoes para gerar o NO 'EXPRESSAO_DECL'
EXPRESSAO_DECL producao_expressaoDecl__expressao(EXPRESSAO expressao){

	EXPRESSAO_DECL expressaoDecl = malloc(sizeof(*expressaoDecl));

	expressaoDecl->producaoEscolhida = expressao_pontovirgula;

	expressaoDecl->uniao.estrutura_Prod1.expressao = expressao;

	return expressaoDecl;	
}
EXPRESSAO_DECL producao_expressaoDecl__pontoVirgula(){

	EXPRESSAO_DECL expressaoDecl = malloc(sizeof(*expressaoDecl));

	expressaoDecl->producaoEscolhida = pontovirgula;

	return expressaoDecl;	
}



//15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT
//Funcoes para gerar o NO 'SELECAO_DECL'
SELECAO_DECL producao_selecaoDecl__if_exp_stm(EXPRESSAO expressao, STATEMENT stm){

	SELECAO_DECL selecaoDecl = malloc(sizeof(*selecaoDecl));

	selecaoDecl->producaoEscolhida = if_exp_statement;

	selecaoDecl->uniao.estrutura_Prod1.expressao = expressao;
	selecaoDecl->uniao.estrutura_Prod1.statement = stm;

	return selecaoDecl;
}
SELECAO_DECL producao_selecaoDecl__if_exp_stm_else_stm(EXPRESSAO expressao, STATEMENT stm_if, STATEMENT stm_else){

	SELECAO_DECL selecaoDecl = malloc(sizeof(*selecaoDecl));

	selecaoDecl->producaoEscolhida = if_exp_statement_else_statement;

	selecaoDecl->uniao.estrutura_Prod2.expressao = expressao;
	selecaoDecl->uniao.estrutura_Prod2.statement_if = stm_if;
	selecaoDecl->uniao.estrutura_Prod2.statement_else = stm_else;

	return selecaoDecl;
}



//16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT
//Funcoes para gerar o NO 'INTERACAO-DECL'
INTERACAO-DECL producao_interacaoDecl(EXPRESSAO expressao, STATEMENT stm){

	INTERACAO_DECL interacaoDecl = malloc(sizeof(*interacaoDecl));

	interacaoDecl->expressao = expressao;
	interacaoDecl->statement = stm;

	return interacaoDecl;
}



//17. RETORNO-DECL -> return ; | return EXPRESSAO ;
//Funcoes para gerar o NO 'RETORNO-DECL'
RETORNO-DECL producao_retornoDecl__return_pontoVirgula(){

	RETORNO-DECL retornoDecl = malloc(sizeof(*retornoDecl));

	retornoDecl->producaoEscolhida = return_pontovirgula;

	return retornoDecl;
}
RETORNO-DECL producao_retornoDecl__return_expressao(EXPRESSAO expressao){

	RETORNO-DECL retornoDecl = malloc(sizeof(*retornoDecl));

	retornoDecl->producaoEscolhida = return_expressao;

	retornoDecl->uniao.estrutura.expressao = expressao;

	return retornoDecl;
}



//18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO
//Funcoes para gerar o NO 'EXPRESSAO'
EXPRESSAO producao_expressao__var_igual_expressao(VAR var, EXPRESSAO expressao){

	EXPRESSAO expr = malloc(sizeof(*expr));

	expr->producaoEscolhida = var_igual_expressao;

	expr->uniao.estrutura.var = var;
	expr->uniao.estrutura.expressao = expressao;

	return expr;
}
EXPRESSAO producao_expressao__simplesExpressao(SIMPLES_EXPRESSAO simplesExpressao){

	EXPRESSAO expr = malloc(sizeof(*expr));

	expr->producaoEscolhida = simples_expressao;

	expr->uniao.simplesExpressao = simplesExpressao;

	return expr;
}



//19. VAR -> id | id [ EXPRESSAO ]
//Funcoes para gerar o NO 'VAR'
VAR producao_var__id(string id){

	VAR var = malloc(sizeof(*var));

	var->producaoEscolhida = only_id;

	var->uniao.id = id;

	return var;
}
VAR producao_var__id_abrCol_exp_fecCol(string id, EXPRESSAO expressao){

	VAR var = malloc(sizeof(*var));

	var->producaoEscolhida = id_abreColExpFechaCol;

	var->uniao.estrutura.id = id;
	var->uniao.estrutura.expressao = id;

	return var;
}



//20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO
//Funcoes para gerar o NO 'SIMPLES_EXPRESSAO'
SIMPLES_EXPRESSAO producao_simplesExp__sumExp_rel_sumExp(SOMA_EXPRESSAO sumExp1, RELACIONAL rel, SOMA_EXPRESSAO sumExp2){

	SIMPLES_EXPRESSAO simplesExpressao = malloc(sizeof(*simplesExpressao));

	simplesExpressao->producaoEscolhida = somaexp_relacional_somaexp;

	simplesExpressao->uniao.estrutura.somaexp1 = sumExp1;
	simplesExpressao->uniao.estrutura.relacional = rel;
	simplesExpressao->uniao.estrutura.somaexp2 = sumExp2;

	return simplesExpressao;
}
SIMPLES_EXPRESSAO producao_simplesExp__somaExp(SOMA_EXPRESSAO somaExp){

	SIMPLES_EXPRESSAO simplesExpressao = malloc(sizeof(*simplesExpressao));

	simplesExpressao->producaoEscolhida = somaexp;

	simplesExpressao->uniao.somaExp = sumExp;

	return simplesExpressao;
}

//21. RELACIONAL -> <= | < | > | >= | == | !=
//Funcoes para gerar o NO 'RELACIONAL'
RELACIONAL producao_relacional__menorIgual(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = menorigual;

	return rel;
}
RELACIONAL producao_relacional__menor(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = menor;

	return rel;
}
RELACIONAL producao_relacional__maior(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = maior;

	return rel;
}
RELACIONAL producao_relacional__maiorIgual(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = maiorigual;

	return rel;
}
RELACIONAL producao_relacional__igualIgual(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = igualigual;

	return rel;
}
RELACIONAL producao_relacional__diferente(){

	RELACIONAL rel = malloc(sizeof(*rel));

	rel->producaoEscolhida = diferente;

	return rel;
}



//22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO
//Funcoes para gerar o NO 'SOMA_EXPRESSAO'
SOMA_EXPRESSAO producao_somaExp__somaExp_soma_termo(SOMA_EXPRESSAO sumExp, SOMA soma, TERMO termo){

	SOMA_EXPRESSAO somaExpressao = malloc(sizeof(*somaExpressao));

	somaExpressao->producaoEscolhida = somaexp_soma_termo;

	somaExpressao->uniao.estrutura.somaexp = sumExp;
	somaExpressao->uniao.estrutura.soma = soma;
	somaExpressao->uniao.estrutura.termo = termo;

	return somaExpressao;

}
SOMA_EXPRESSAO producao_somaExp__termo(TERMO t){

	SOMA_EXPRESSAO somaExpressao = malloc(sizeof(*somaExpressao));

	somaExpressao->producaoEscolhida = termo;

	somaExpressao->uniao.termo = t;

	return somaExpressao;
}



//23. SOMA -> + | -
//Funcoes para gerar o NO 'SOMA'
SOMA producao_soma__mais(){

	SOMA soma = malloc(sizeof(*soma));

	soma->producaoEscolhida = sinalmais;

	return soma;
}
SOMA producao_soma__menos(){

	SOMA soma = malloc(sizeof(*soma));

	soma->producaoEscolhida = sinalmenos;

	return soma;
}



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
TERMO producao_termo__termo_mult_fator(TERMO termo, MULT mult, FATOR fator){

	TERMO t = malloc(sizeof(*t));

	t->producaoEscolhida = termo_mult_fator;

	t->uniao.estrutura.termo = termo;
	t->uniao.estrutura.mult = mult;
	t->uniao.estrutura.fator = fator;

	return t;
}
TERMO producao_termo__fator(FATOR f){


	TERMO t = malloc(sizeof(*t));

	t->producaoEscolhida = fator;

	t->uniao.fator = f;

	return t;
}



//25. MULT -> * | /
//Funcoes para gerar o NO 'MULT'
MULT producao_mult__vezes(){

	MULT mult = malloc(sizeof(*mult));

	mult->producaoEscolhida = vezes;

	return mult;
}
MULT producao_mult__divisao(){


	MULT mult = malloc(sizeof(*mult));

	mult->producaoEscolhida = divisao;

	return mult;
}



//26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero
//Funcoes para gerar o NO 'FATOR'
FATOR producao_fator__abrP_exp_fecP(EXPRESSAO expressao){

	FATOR fator = malloc(sizeof(*fator));

	fator->producaoEscolhida = abrePExpFechaP;

	fator->uniao.expressao = expressao;

	return fator;
}
FATOR producao_fator__var(VAR var){

	FATOR fator = malloc(sizeof(*fator));

	fator->producaoEscolhida = variavel;

	fator->uniao.variavel = var;

	return fator;
}
FATOR producao_fator__ativacao(ATIVACAO ativ){


	FATOR fator = malloc(sizeof(*fator));

	fator->producaoEscolhida = ativacao;

	fator->uniao.ativacao = ativ;

	return fator;
}
FATOR producao_fator__numero(int num){

	FATOR fator = malloc(sizeof(*fator));

	fator->producaoEscolhida = numero;

	fator->uniao.numero = num;

	return fator;
}



//27. ATIVACAO -> id ( ARGS )
//Funcoes para gerar o NO 'ATIVACAO'
ATIVACAO producao_ativacao__argumentos(string id, ARGS argumentos){

	ATIVACAO ativacao = malloc(sizeof(*ativacao));

	ativacao->id = id;

	ativacao->argumentos = argumentos;

	return ativacao;
}



//28. ARGS -> ARG-LISTA | VAZIO
struct ARGS{
	enum{arglista, vazio} producaoEscolhida;
	
	union{
		ARG_LISTA listaArgumentos;

		VAZIO vazio;
	}uniao;
};
//Funcoes para gerar o NO 'ARGS'
ARGS producao_args__argLista(ARG_LISTA listaArgumentos){

	ARGS args = malloc(sizeof(*args));

	args->producaoEscolhida = arglista;

	args->uniao.listaArgumentos = listaArgumentos;

	return args;
}
ARGS producao_args__vazio(){

	ARGS args = malloc(sizeof(*args));

	args->producaoEscolhida = vazio;

	return args;
}



//29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO
struct ARG_LISTA{
	enum{arglista_expressao, expressao} producaoEscolhida;

	union{

		struct{

			ARG_LISTA listaArgumentos;

			EXPRESSAO expressao;

		} estrutura;
		
		EXPRESSAO expressao;

	}uniao;

};
//Funcoes para gerar o NO 'ARG_LISTA'
ARG_LISTA producao_argLista__argLista_pontoVirgula_exp(ARG_LISTA listaArgumentos, EXPRESSAO expressao){

	ARG_LISTA argLista = malloc(sizeof(*argLista));

	argLista->producaoEscolhida = arglista_expressao;

	argLista->uniao.estrutura.listaArgumentos = listaArgumentos;
	argLista->uniao.estrutura.expressao = expressao;

	return argLista;
}
ARG_LISTA producao_argLista__exp(EXPRESSAO expr){

	ARG_LISTA argLista = malloc(sizeof(*argLista));

	argLista->producaoEscolhida = expressao;

	argLista->uniao.expressao = expr;

	return argLista;
}

//Definicao da producao vazia
struct VAZIO{

};
VAZIO producao_vazio__(){

	VAZIO vazio = malloc(sizeof(*vazio));

	return vazio;
}

//FIM