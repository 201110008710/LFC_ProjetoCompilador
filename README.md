LFC_ProjetoCompilador
=====================

Projeto de um compilador usando o FLEX (Fast Lexical Analyser) como analisador léxico e o BISON como análisador sintático.

Este é o projeto de um compilador (utilizando o FLEX (Fast Lexical Analyser) e o BISON) para limguagem C-, descrita no livro "COMPILADORES: Princípios e práticas; Louden, Kenneth C.".

A principal diferença para a limguagem descrita no livro é a inclusão do tipo 'string'

-----------------------------------------------------------------------------------------------------------------------

=> Informações Gerais

Versão do Flex(Fast Lexical Analyser) utilizada: Flex 2.5.37

Versão do Bison Utilizada: Bison (GNU bison) 2.7

Sistema Operacional sobre o qual o foi compilado: OpenSuse 13.1(Bottle)

-----------------------------------------------------------------------------------------------------------------------





=> Partes feitas

1ª Etapa - Analisador Léxico

Data de Entrega: 17/01/2014 às 23h59

Data em que foi entregue: 16/01/2014

Commit relacionado: "Todos os testes passados estão funcionando corretamente"

Código sha(Secure Hash Algorithm) = 8eaeb66b8588c0d680a1f91e483c22f16e8bf5c7

-----------------------------------------------------------------------------------------------------------------------

2ª Etapa - Analisador Sintático

Data de entrega: 17/02/2014 até às 23h59

Data em que foi entregue: 21/02/2014 (três dias de atraso)

Commit relacionado: "Testes realizados e analisador sintatico funcionando"

Código sha(Secure Hash Algorithm) = 367cf68db119b660311de2a10b2d0f4772a891ad

-----------------------------------------------------------------------------------------------------------------------

3ª Etapa - Analisador Semântico

Não entregue.

-----------------------------------------------------------------------------------------------------------------------





=> Arquivos relacionados ao projeto:

*scanner.l

*parser.y

*IMPLEMENTACAO_DAS_FUNCOES_GERADORAS_DA_ARVORE.h

*ESTRUTURAS_DA_ARVORE_SINTATICA.h





=> Os comandos, executados no prompt, para gerar o compilador são:

bison -v -d -o parser_generateByBison.c parser.y

flex -v -t scanner.l > scanner_generateByFlex.c

gcc parser_generateByBison.c scanner_generateByFlex.c -o compilador


=> Essa sequência de comandos podem ser executados com o script 'executar.sh' presente neste repositório. Isso é feito no prompt com o comando:

./executar.sh

Obs: Caso o sistema operacional não permita executar o script, basta alterar as permições do arquivo com o comando:

chmod u+x executar.sh

Ao final será gerado o executavel 'compilador' que é usado dessa maneira:

./compilador <[arquivo].c




=> Feita a compilação do compilador, alguns testes podem ser executados como os seguintes:

./compilador <Testes_professor/teste1.c [erro léxico]

./compilador <Testes_professor/teste2.c [erro léxico]

./compilador <Testes_professor/teste3.c [erro léxico]

./compilador <Testes_professor/teste4.c [erro léxico]

./compilador <Testes_professor/teste6.c [erro léxico]

./compilador <TesteDaAnaliseSintatica/teste0.c

./compilador <TesteDaAnaliseSintatica/teste1.c

./compilador <TesteDaAnaliseSintatica/teste2.c

-----------------------------------------------------------------------------------------------------------------------

A primeira versão do analisador léxico indicava, na saida padrão (TELA), todos os tokens reconhecidos e erros léxicos. As saídas produzidas por ele podem ser encontrados na pasta 'Testes_professor' presente ne repósitorio.
Essa versão é a do dia 16/01/2014 mostrada no ínicio desse README.

-----------------------------------------------------------------------------------------------------------------------

Dúvidas, enviar e-mail para: elwyslan@gmail.com
