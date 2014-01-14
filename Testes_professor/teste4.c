int a;
string b;

int func(){
	/*aqui uma string não fechada causa um erro até as próximas aspas ou fim de linha... tudo fica bagunçado*/
	b = "uma string dando trabalho
	a = 27;
	/*a seguir, mais um erro semântico, nada de errado do ponto de vista sintático ou léxico.*/
	a = "minha \t \" string";
	
	b = "mais uma string não fechada; b = "aqui a gente vai ter um monte de identificadores perdidos por causa das aspas faltantes" /*e, por fim, uma string não fechada*/
}