/*Todos os comentarios sao delimitados pelos simbolos /**/ (Comentários balanceados)*/


/*
 Teste da Gramática C- presente no livro:
 COMPILADORES:PRINCÍPIOS E PRÁTICAS, 2ª EDIÇÃO, KENNETH C. LOUDEN. PG. 494
 
 As três primeiras regras definem a estrutura de um programa em C-:

 01. PROGRAMA -> DECLARACAO-LISTA 
 02. DECLARACAO-LISTA -> DECLARACAO-LISTA DECLARACAO | DECLARACAO
 03. DECLARACAO -> VAR-DECLARACAO | FUN-DECLARACAO

 Essas regras nos dizem que um programa é composto por uma 'lista de declarações'. Essa lista de declarações
 pode ser 'declarações de variáveis' ou 'declarações de funções'

 Uma declaração de variável é definida pelas regras:

 04. VAR-DECLARACAO -> TIPO-ESPECIFICADOR id ; | TIPO-ESPECIFICADOR id [ numero ];
 05. TIPO-ESPECIFICADOR -> int | void | string
 
 Assim, uma declaracao de variavel pode ser:
 1-Uma declaracao de variavel normal
 2-Uma declaração de um vetor (somente aceita vetor com alocação estática. Ex: int v[100])

 Obs: o tipo especificador 'string' foi adicionado a gramatica

 As proximas regras definem como é uma declaração de de função.

 06. FUN-DECLARACAO -> TIPO-ESPECIFICADOR id ( PARAMS) COMPOSTO-DECL
 07. PARAMS -> PARAM-LISTA | void
 08. PARAM-LISTA -> PARAM-LISTA,PARAM | PARAM
 09. PARAM -> TIPO-ESPECIFICADOR id | TIPO-ESPECIFICADOR id []
 
 Uma declaração de função é composta por:
 1. Um tipo especificador (int, void, string)
 2. Uma indentificacao (id)
 3. Parametros colocados entre parentesis
 4. E uma 'declaracao composta'

 Os parâmetros podem ser uma 'lista de parametros' ou simplesmente 'void', ou seja, uma declaracao tipo
 'int main()' eh inválida. O correto é 'int main(void)' caso não queira passar nenhum parâmetro a função
 
 A regra seguinte:

 10. COMPOSTO-DECL -> { LOCAL-DECLARACOES STATEMENT-LISTA }

 Essa produção define que 'declaração composta' é composta por 'declarações locais' seguidas de uma
 lista de afirmações(statements), e que essa estrutura é delimitada por abre chaves ( { ) e fecha chaves ( } )

 Em seguida:

 11. LOCAL-DECLARACOES -> LOCAL-DECLARACOES VAR-DECLARACAO | VAZIO
 12. STATEMENT-LISTA -> STATEMENT-LISTA STATEMENT | VAZIO

 Essas regras nos dizem que podem, ou não, ser declarada uma sequência de variáveis dentro do escopo da função
 e que elas  devem ser declaradas no início do escopo. Logo após a declaração de variáveis pode, ou não
 aparecer uma lista de statements

 13. STATEMENT -> EXPRESSAO-DECL | COMPOSTO-DECL | SELECAO-DECL | INTERACAO-DECL | RETORNO-DECL

 Um statement pode ser uma expressão, uma declaração composta(como na regra 10)
 , uma declaracao de seleção, uma declaração de interação ou uma declaração de retorno.

 14. EXPRESSAO-DECL -> EXPRESSAO ; | ;
 Uma expressão é uma instrução, caracterizada por um ponto e virgula no final

 15. SELECAO-DECL -> if( EXPRESSAO ) STATEMENT | if( EXPRESSAO ) STATEMENT else STATEMENT
 Uma declaracação de seleção é uma clássica declaração condicional (if-else-if-else....)

 16. INTERACAO-DECL -> while ( EXPRESSAO ) STATEMENT
 A declaração de interação é feita com somente com o while

 17. RETORNO-DECL -> return ; | return EXPRESSAO ;
 A declaracao de retorno pode ser um retorno vazio (return ;) ou pode ser retornada um expressão

 As expressões em C- são definidas pela regra:

 18. EXPRESSAO -> VAR = EXPRESSAO | SIMPLES-EXPRESSAO

 Que nos diz que a expressão pode ser um atribuição de uma expressao à uma variável ou uma
 'expressão simples'. Sendo que uma variável é definida como:

 19. VAR -> id | id [ EXPRESSAO ]

 Ou seja, VAR pode ser uma variável com nome(id) ou um vetor (caracterizado pelos colchetes [])

 20. SIMPLES-EXPRESSAO -> SOMA-EXPRESSAO RELACIONAL SOMA-EXPRESSAO | SOMA-EXPRESSAO
 
 Uma expressão simples pode ser uma expressão de soma simples ou duas expressoes de soma com um operador
 relacional no meio

 21. RELACIONAL -> <= | < | > | >= | == | !=
 Um operador relacional pode ser <=, <, >, >=, ==, !=

 22. SOMA-EXPRESSAO -> SOMA-EXPRESSAO SOMA TERMO | TERMO
 23. SOMA -> + | -
 24. TERMO -> TERMO MULT FATOR | FATOR
 25. MULT -> * | /

 Uma expressao de soma é uma sequência finita de TERMO conectados por sinais de '+' ou de '-':
 TERMO + TERMO - TERMO + TERMO + TERMO +.... - TERMO

 E TERMO pode ser uma sequência finita de multiplicações ou divisões de FATOR:
 FATOR*FATOR/...*FATOR + FATOR*FATOR/...*FATOR + FATOR*FATOR/...*FATOR -... + FATOR*FATOR/...*FATOR

 26. FATOR -> ( EXPRESSAO ) | VAR | ATIVACAO | numero | CADEIASTRING 
 E cada fator pode ser:
 1-Uma expressão entre parentesis
 2-Uma variável (regra 19)
 3-Uma ativação de função
 4-Um número
 5-Uma cadeia string (elemento adicionado a gramática do livro)

 27. ATIVACAO -> id ( ARGS )
 Uma ativação de função é feita atraves do ID da função, junto com os argumentos que sao passados

 28. ARGS -> ARG-LISTA | VAZIO
 Os argumentos passados podem ser:
 1-Nada(produção vazia). Exemplo: configurarRegistradores();
 2-Uma 'lista de argumentos'

 29. ARG-LISTA ->ARG-LISTA , EXPRESSAO | EXPRESSAO
 A lista de argumentos é uma sequencia de expressões

 */

/*Testes para verificar se as regras estão sendo obedecidas.
  Testes de robuztes e corretude em outros exemplos.*/
int a;
string r[11];
int b;
string q[15];
int c;
string p[16];
void d;
int j[20];
void e;
int k[14];
void f;
int l[1];
string g;
void m[19];
string h;
void o[13];
string i;
void n[10];

int nomeDeVariavelMuitoGrandeSoPraTestar;

void outraVariavelComNomeGrande;

int declaracao; void de; int mais;int variaveis;void dispostas;
int das; void maneiras;
int maisVariadas; int possiveis;

string agora;string testando; string strings;

string repetindo; int asdeclaracoes; void das; string maisVariadas;int formas;
void soQue;int dessa; string vez;int incluindo;
void otipoString;

string ePorqueNaoColocarOutraVariavelDeNomeMuitoGrande;

string passouNoTestedasDeclaracoes;

/*Testando a declaração de funções*/

/* 
LOCAL-DECLARACOES => Ɛ 
STATEMENT-LISTA   => Ɛ
*/
int funcaoUm(void){
}
void funcaoDois(int a, void b, string c[], int k, int m, void n, string str[], void vv[]){}

/* 
STATEMENT-LISTA   => Ɛ
*/
string funcaoTres(void){
	int exemplo;void padrao[3]; string deuma; int listaextensa[3]; void devariaveis;
	string paraserem[6];
	int declaradas;
	void dentro[12];
	string doescopo;
	int dasfuncoes[17];
}
int funcaoQuatro(int a, void b, string c[], int k, int m, void n, string str[], void vv[]){
	int exemplo;void padrao[3]; string deuma; int listaextensa[3]; void devariaveis;
	string paraserem[6];
	int declaradas;
	void dentro[12];
	string doescopo;
	int dasfuncoes[17];
}

/* 
LOCAL_DECLARACOES => Ɛ 
STATEMENT_LISTA   => EXPRESSAO_DECL
*/
void funcaoTestexpressaoUm(void){

	;;;;;;;
	;;;;;;
	;;;;;
	;;;;
	;;;
	;;
	;
	;
	;
	
	a = 2;
	b = 3;
	
	c = "atribuição de string a uma variável \t qualquer";
	d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
	
	vetor[v=10] = 100;
	vetor[v = "erro semântico"] = "erro semântico";
	
	variavelAleatoriaUm = chamadaFuncaoUm();
	variavelAleatoriadois = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424");

	2+3 < 3+5;
	2+3 <= 5;
	200+300 > 36+52;
	1000 >= 10000;
	1 != 1;

	2+3+4+5+666-7-3-234;

	(2*2 + 1 - 4 + 7/3) + (4/2) + (2*2) + (20-5) + 666 - 7 - 3 - 234;
	(2*2 + 1 - 4 + 7/3) + (4/2) + soma(2,2) + subtracao(20,5) + wx["hell"] - 7 - 3 - 234;

	valal = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424") + (2*2) + 4 - funk();

	(2*2 + 1 - 4 + 7/3) - 7 - 3 - 234 < (2*2) + (20-5) + 666 - 7 - 3 - 234;
	2+3+(2*2*4 + 8/2) <= 5+2+1+2+3+445+45;
	200+300+(2+3*5-funk()) > 36+52;
	1000+(12*12-mmm()) >= 10000-(3*LALR(1));
	LR(0) != SLR(1);

}

/* 
LOCAL_DECLARACOES => LISTA_DECLARACOES
STATEMENT_LISTA   => EXPRESSAO_DECL
*/
void funcaoTestexpressaoDois(int a, void b, string c[], int k, int m, void n, string str[], void vv[]){	

	int exemplo;void padrao[3]; string deuma; int listaextensa[3]; void devariaveis;
	string paraserem[6];
	int declaradas;
	void dentro[12];
	string doescopo;
	int dasfuncoes[17];

	;;;;;;;
	;;;;;;
	;;;;;
	;;;;
	;;;
	;;
	;
	;
	;
	
	a = 2;
	b = 3;
	
	c = "atribuição de string a uma variável \t qualquer";
	d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
	
	vetor[v=10] = 100;
	vetor[v = "erro semântico"] = "erro semântico";
	
	variavelAleatoriaUm = chamadaFuncaoUm();
	variavelAleatoriadois = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424");

	2+3 < 3+5;
	2+3 <= 5;
	200+300 > 36+52;
	1000 >= 10000;
	1 != 1;

	2+3+4+5+666-7-3-234;

	(2*2 + 1 - 4 + 7/3) + (4/2) + (2*2) + (20-5) + 666 - 7 - 3 - 234;
	(2*2 + 1 - 4 + 7/3) + (4/2) + soma(2,2) + subtracao(20,5) + wx["hell"] - 7 - 3 - 234;

	valal = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424") + (2*2) + 4 - funk();

	(2*2 + 1 - 4 + 7/3) - 7 - 3 - 234 < (2*2) + (20-5) + 666 - 7 - 3 - 234;
	2+3+(2*2*4 + 8/2) <= 5+2+1+2+3+445+45;
	200+300+(2+3*5-funk()) > 36+52;
	1000+(12*12-mmm()) >= 10000-(3*LALR(1));
	LR(0) != SLR(1);

}

/* 
LOCAL_DECLARACOES => Ɛ 
STATEMENT_LISTA   => INTERACAO_DECL
*/

string testeInteracao(void){
	while((2*2 + 1 - 4 + 7/3) - 7 - 3 - 234 < (2*2) + (20-5) + 666 - 7 - 3 - 234){
		return ;
	}
	while(ascendente != descendente){
		return 2+2;
	}
	while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		return null;
	}
	while(variavelAleatoriaUm = chamadaFuncaoUm()){
		"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
		2+2;
	}
}

int testeSelecao(void){
	if(2+2){
		while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		}
	}

	if(LR(1) != LALR(1)){
		while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		}
	}else{
		while(variavelAleatoriaUm = chamadaFuncaoUm()){
		"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
		2+2;
		}		
	}

	if(a){
		if(2+2){
			while(vetor[v = "erro semântico"] = "erro semântico"){
			c = "atribuição de string a uma variável \t qualquer";
			d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
			1000+(12*12-mmm()) >= 10000-(3*LALR(1));
			LR(0) != SLR(1);
			}
		}else{
			while(variavelAleatoriaUm = chamadaFuncaoUm()){
			"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
			2+2;
			}
		}
	}

	if(a){
		if(b){
			if(c){
				return 1>2;
			}else{
				return 1;
			}
			return "12223";
		}
	 return "string";
	}
}

/*Juntando tudo*/
int main(void){
	int a;
	string r[11];
	int b;
	string q[15];
	int c;
	string p[16];
	void d;
	int j[20];
	void e;
	int k[14];
	void f;
	int l[1];
	string g;
	void m[19];
	string h;
	void o[13];
	string i;
	void n[10];

	int nomeDeVariavelMuitoGrandeSoPraTestar;

	void outraVariavelComNomeGrande;

	int declaracao; void de; int mais;int variaveis;void dispostas;
	int das; void maneiras;
	int maisVariadas; int possiveis;

	string agora;string testando; string strings;

	string repetindo; int asdeclaracoes; void das; string maisVariadas;int formas;
	void soQue;int dessa; string vez;int incluindo;
	void otipoString;

	string ePorqueNaoColocarOutraVariavelDeNomeMuitoGrande;

	string passouNoTestedasDeclaracoes;

	int exemplo;void padrao[3]; string deuma; int listaextensa[3]; void devariaveis;
	string paraserem[6];
	int declaradas;
	void dentro[12];
	string doescopo;
	int dasfuncoes[17];

	if(2+2){
		while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		}
	}

	if(LR(1) != LALR(1)){
		while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		}
	}else{
		while(variavelAleatoriaUm = chamadaFuncaoUm()){
		"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
		2+2;
		}		
	}

	if(a){
		if(2+2){
			while(vetor[v = "erro semântico"] = "erro semântico"){
			c = "atribuição de string a uma variável \t qualquer";
			d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
			1000+(12*12-mmm()) >= 10000-(3*LALR(1));
			LR(0) != SLR(1);
			}
		}else{
			while(variavelAleatoriaUm = chamadaFuncaoUm()){
			"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
			2+2;
			}
		}
	}

	if(a){
		if(b){
			if(c){
				return 1>2;
			}else{
				return 1;
			}
			return "12223";
		}
	 return "string";
	}


	while((2*2 + 1 - 4 + 7/3) - 7 - 3 - 234 < (2*2) + (20-5) + 666 - 7 - 3 - 234){
		return ;
	}
	while(ascendente != descendente){
		return 2+2;
	}
	while(vetor[v = "erro semântico"] = "erro semântico"){
		c = "atribuição de string a uma variável \t qualquer";
		d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
		1000+(12*12-mmm()) >= 10000-(3*LALR(1));
		LR(0) != SLR(1);
		return null;
	}
	while(variavelAleatoriaUm = chamadaFuncaoUm()){
		"asdasd" + "asdsadas" + 2 + (3*4 - 3/5);
		2+2;
	}

	;;;;;;;
	;;;;;;
	;;;;;
	;;;;
	;;;
	;;
	;
	;
	;
	
	a = 2;
	b = 3;
	
	c = "atribuição de string a uma variável \t qualquer";
	d = "Testando tambem a declaracação de uma string dentro de uma string \"quebrando o codigo\" ";
	
	vetor[v=10] = 100;
	vetor[v = "erro semântico"] = "erro semântico";
	
	variavelAleatoriaUm = chamadaFuncaoUm();
	variavelAleatoriadois = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424");

	2+3 < 3+5;
	2+3 <= 5;
	200+300 > 36+52;
	1000 >= 10000;
	1 != 1;

	2+3+4+5+666-7-3-234;

	(2*2 + 1 - 4 + 7/3) + (4/2) + (2*2) + (20-5) + 666 - 7 - 3 - 234;
	(2*2 + 1 - 4 + 7/3) + (4/2) + soma(2,2) + subtracao(20,5) + wx["hell"] - 7 - 3 - 234;

	valal = chamadaFuncaoDois(k=1, l="teste",2,3,"string parametro",z[q="w"] = "33424") + (2*2) + 4 - funk();

	(2*2 + 1 - 4 + 7/3) - 7 - 3 - 234 < (2*2) + (20-5) + 666 - 7 - 3 - 234;
	2+3+(2*2*4 + 8/2) <= 5+2+1+2+3+445+45;
	200+300+(2+3*5-funk()) > 36+52;
	1000+(12*12-mmm()) >= 10000-(3*LALR(1));
	LR(0) != SLR(1);

}

/*




	

	

	

	

	



*/














