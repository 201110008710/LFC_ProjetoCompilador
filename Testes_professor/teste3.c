int variavel[42];
/*o identificador abaixo não é válido*/
int minha_var;

/*abaixo temos um erro sintático, mas não léxico*/
int main({
	/*a seguir, um erro semântico, mas nada de errado do ponto de vista léxico*/
	variavel = 1234;
	/*agora a gente tem um erro léxico*/
	variavel = 12ab;
	/*e isso também é um erro léxico*/
	minha_var = 12;
	/*e mais um erro léxico /*esquecendo de fechar um dos comentários*/
	/*o mesmo vale para strings*/
}