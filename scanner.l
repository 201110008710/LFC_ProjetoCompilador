%option main
	#include <stdio.h>
	#include "scannerDefi.h"

LETRA [a-zA-Z]
DIGITO [0-9]

%%

{LETRA}{LETRA}*							{printf("ID = %s\n",yytext);}

{DIGITO}{DIGITO}*						{printf("NUM = %s\n",yytext);}


.|\n|\r
%%