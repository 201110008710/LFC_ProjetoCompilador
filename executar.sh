bison -v -d -o parser_generateByBison.c parser.y

flex -v -t scanner.l > scanner_generateByFlex.c

gcc parser_generateByBison.c scanner_generateByFlex.c -o compilador