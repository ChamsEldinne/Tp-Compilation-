%{
#include <stdio.h>
#include <stdlib.h>
%}

%token INT IF ELSE FOR WHILE IDENTIFIER NUMBER

%%

program:
    declarations
    ;

declarations:
    declarations declaration
    | declaration
    ;

declaration:
    "int" IDENTIFIER ';'
    | statement
    ;

statement:
    "if" '(' expression ')' '{' statements '}'
    | "for" '(' expression ';' expression ';' expression ')' '{' statements '}'
    | "while" '(' expression ')' '{' statements '}'
    ;

statements:
    statements statement
    | statement
    ;

expression:
    NUMBER
    | IDENTIFIER
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    ;

%%

int main(int argc, char **argv) {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erreur syntaxique: %s\n", s);
}

