%{    
    int line_no = 0;
    #include "y.tab.h"
%}

%option yylineno
%option noinput nounput
alphabet          [a-zA-Z]
digit             [0-9]

%%

"tellme"       { strcpy(yylval.nd_obj.name,(yytext)); return PRINTFF; }
"take"         { strcpy(yylval.nd_obj.name,(yytext)); return SCANFF; }
"start"        { strcpy(yylval.nd_obj.name,(yytext)); return MAIN;}

"checkif"      { strcpy(yylval.nd_obj.name,(yytext)); return IF; }
"otherwise"    { strcpy(yylval.nd_obj.name,(yytext)); return ELSE; }
"checktill"    { strcpy(yylval.nd_obj.name,(yytext)); return WHILE; }
"return"       { strcpy(yylval.nd_obj.name,(yytext)); return RETURN; }

"remember"     { strcpy(yylval.nd_obj.name,(yytext)); return DECLARE; }
"+"            { strcpy(yylval.nd_obj.name,(yytext)); return ADD; }
"-"            { strcpy(yylval.nd_obj.name,(yytext)); return SUBTRACT; }
"*"            { strcpy(yylval.nd_obj.name,(yytext)); return MULTIPLY; }
"/"            { strcpy(yylval.nd_obj.name,(yytext)); return DIVIDE; }
"log"          { strcpy(yylval.nd_obj.name,(yytext)); return LOG; }
"exp"          { strcpy(yylval.nd_obj.name,(yytext)); return POW; }

">="           { strcpy(yylval.nd_obj.name,(yytext)); return GTE; }
"<="           { strcpy(yylval.nd_obj.name,(yytext)); return LTE; }
">"            { strcpy(yylval.nd_obj.name,(yytext)); return GT; }
"<"            { strcpy(yylval.nd_obj.name,(yytext)); return LT; }
"=="           { strcpy(yylval.nd_obj.name,(yytext)); return EQ; }
"!="           { strcpy(yylval.nd_obj.name,(yytext)); return NE; }

"right"        { strcpy(yylval.nd_obj.name,(yytext)); return TRUE; }
"wrong"        { strcpy(yylval.nd_obj.name,(yytext)); return FALSE; }
"&&"           { strcpy(yylval.nd_obj.name,(yytext)); return AND; }
"||"           { strcpy(yylval.nd_obj.name,(yytext)); return OR; }

"number"		{ strcpy(yylval.nd_obj.name,(yytext)); return INT; }
"decimal"		{ strcpy(yylval.nd_obj.name,(yytext)); return FLOAT; }
"letter"		{ strcpy(yylval.nd_obj.name,(yytext)); return CHAR; }
"boolean"		{ strcpy(yylval.nd_obj.name,(yytext)); return BOOL; }

\#.*             { ; }
[ \t]*          { ; }
[\n]            { line_no++; } 

[-]?{digit}+                    { strcpy(yylval.nd_obj.name,(yytext)); return NUMBER; }
[-]?{digit}+\.{digit}{1,6}      { strcpy(yylval.nd_obj.name,(yytext)); return FLOAT_NUM; }
{alphabet}({alphabet}|{digit})* { strcpy(yylval.nd_obj.name,(yytext)); return ID; }

["].*["]                    { strcpy(yylval.nd_obj.name,(yytext)); return STR; }
['].[']                     { strcpy(yylval.nd_obj.name,(yytext)); return CHARACTER; }

"."|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">"|";" {return yytext[0];}

%%

int yywrap(void) {
    return 1;
}
