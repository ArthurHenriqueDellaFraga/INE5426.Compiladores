%{
    #include "parser.h"

    #include <string>

    using namespace std;

    extern int yylineno;
    void yyerror(const char* s, ...);
%}

%option noyywrap nodefault yylineno

digito [0-9]
letra [a-zA-Z]

%%

"<sair>"                      {
                                  cout << "-- fim da compilacao --" << endl;
                                  exit(0);
                              }

[ \t]                         ; //ignora espaços
\n                            ;
";"                           {return NOVA_LINHA;}

"="                           {return ATRIBUICAO;}
"def"                         {return DEFINICAO;}

"+"                           {return SOMA;}
"-"                           {return SUBTRACAO;}
"*"                           {return MULTIPLICACAO;}
"/"                           {return DIVISAO;}

"=="                          {return IGUAL;}
"!="                          {return DIFERENTE;}
">"                           {return MAIOR;}
"<"                           {return MENOR;}
">="                          {return MAIOR_IGUAL;}
"<="                          {return MENOR_IGUAL;}

"&&"                          {return AND;}
"||"                          {return OR;}
"!"                           {return NEGACAO_BOOLEANA;}

"print"                       {return PRINT;}

","                           {return VIRGULA;}
"."                           {return PONTO;}

"["                           {return ABRE_COLCHETE;}
"]"                           {return FECHA_COLCHETE;}
"("                           {return ABRE_PARENTESES;}
")"                           {return FECHA_PARENTESES;}
"{"                           {return ABRE_CHAVES;}
"}"                           {return FECHA_CHAVES;}

"if"                          {return IF;}
"else"                        {return ELSE;}
"while"                       {return WHILE;}
"for"                         {return FOR;}
"repeat"                      {return REPEAT;}

"return"                      {return RETORNO;}

{digito}+                     {
                                  yylval._int = atoi(yytext);
                                  return INTEIRO;
                              }
{digito}*"."{digito}+         {
                                  yylval._double = atof(yytext);
                                  return RACIONAL;
                              }
"TRUE"                        {
                                  yylval._bool = true;
                                  return BOOLEANO;
                              }
"FALSE"                       {
                                  yylval._bool = false;
                                  return BOOLEANO;
                              }
"\'"."\'"                     {
                                  yylval._char = yytext[1];
                                  return CARACTER;
                              }
"\"".+"\""                    {
                                  yylval._string = new string(yytext);
                                  yylval._string = new string(yylval._string->substr(1, yylval._string->size() -2));
                                  return SENTENCA;
                              }
{letra}({letra}|{digito})*    {
                                  yylval._string = new string(yytext);
                                  return IDENTIFICADOR;
                              }

"//".*\n                      {
                                  yylval._string = new string(yytext);
                                  return COMENTARIO;
                              }

"/*"(.|\n)*"*/"               {
                                  yylval._string = new string(yytext);
                                  return COMENTARIO;
                              }

.                             {yyerror("léxico: simbolo desconhecido: '%c'\n", *yytext);}

%%

void yyerror(const char *s, ...){
    va_list ap;
    va_start(ap, s);
    fprintf(stderr, "[Linha %d] Erro ", yylineno);
    vfprintf(stderr, s, ap);
}
