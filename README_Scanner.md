LFC_AnalisadorLexico
===========================================

Projeto de um analisador léxico utilizando FLEX (Fast Lexical Analyser). Para limguagem C- descrita no livro "COMPILADORES: Principios e práticas; Louden, Kenneth C.". A principal diferença para a limguagem descrita no livro é a presença do tipo 'string', no entanto, ainda existem outras diferenças.

Está sera a primeira etapa do projeto do compilador para disciplina de Limguagens Formais e Compiladores.

INFORMAÇÕES GERAIS
===========================================

Versão do Flex(Fast Lexical Analyser) utilizada : Flex 2.5.37

Sistema Operacional sobre o qual o Scanner foi codificado: OpenSuse 13.1(Bottle)

Editor de texto utilizado: SublimeText2

INSTRUÇÕES DE USO
===========================================
-O arquivo que contem as regras do scanner é o 'scanner.l'

Para utiliza-lo basta que, através do terminal/console, definir o diretório atual como sendo o mesmo no qual se encontra os arquivos deste repositório. Feito isso basta seguir os passos:

1.Para gerar o yy.lex.c deve-se executar o comando:

flex scanner.l

2.Logo após devemos compila-lo usando o GCC pelo seguinte comando:

gcc lex.yy.c -lfl

3. Por fim, deve-se passar o arquivo de entrada para o programa gerado da forma:

./a.out <entrada.c >saida.c

Pronto.

*O arquivo de saida é opcional, nele ficaram todas as mensagens impressas na tela e as informações do todos os tokens.

*Caso ele não seja usado as informações dos tokes só serão visualizadas na tela.

*O programa pode ser executado sem a passagem de nenhum parametrô, no entanto as entradas de texto teram de ser introduzidas manualmente, uma a uma, em tempo de execução

OBSERVAÇÕES
==========================================
Caso não seja passado nenhum parametro para o programa executar, e o usuario estiver inserindo entradas de texto manualmente, podem acontecer alguns bugs. No entanto essa obserção ńão é verdadeira se o arquivo de entrada for passado ao programa.





