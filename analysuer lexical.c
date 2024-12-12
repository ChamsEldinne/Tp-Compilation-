%{
#include "parser.tab.h"
#include <stdio.h>
%}

digit       [0-9]
letter      [a-zA-Z]

%%

"int"       { return INT; }
"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }
{letter}({letter}|{digit})*   { return IDENTIFIER; }
{digit}+    { return NUMBER; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"="         { return '='; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }

/* Capture any unknown character or sequence */
.           { fprintf(stderr, "Erreur lexicale: caractère inconnu '%s'\n", yytext); }

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
