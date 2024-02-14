%{    
    int line_no = 1;
    int v[33] = {0};
%}

%option yylineno
alphabet          [a-zA-Z]
digit             [0-9]

%%

"tellme"       { v[0]++; printf("tellme \t line_no %d \n", line_no); }
"take"         { v[1]++; printf("take \t line_no %d \n", line_no); }

"checkif"      { v[2]++; printf("checkif \t line_no %d \n", line_no); }
"otherwise"    { v[3]++; printf("otherwise \t line_no %d \n", line_no); }
"checktill"    { v[4]++; printf("checktill \t line_no %d \n", line_no); }
"return"       { v[5]++; printf("return \t line_no %d \n", line_no); }

"remember"     { v[6]++; printf("remember \t line_no %d \n", line_no); }
"+"            { v[7]++; printf("operator \t line_no %d \n", line_no); }
"-"            { v[8]++; printf("operator \t line_no %d \n", line_no); }
"*"            { v[9]++; printf("operator \t line_no %d \n", line_no); }
"/"            { v[10]++; printf("operator \t line_no %d \n", line_no); }
"log"          { v[11]++; printf("logarithm \t line_no %d \n", line_no); }
"exp"          { v[12]++; printf("exponentiation \t line_no %d \n", line_no); }

">="           { v[13]++; printf("logical operator \t line_no %d \n", line_no); }
"<="           { v[14]++; printf("logical operator \t line_no %d \n", line_no); }
">"            { v[15]++; printf("logical operator \t line_no %d \n", line_no); }
"<"            { v[16]++; printf("logical operator \t line_no %d \n", line_no); }
"=="           { v[17]++; printf("logical operator \t line_no %d \n", line_no); }
"!="           { v[18]++; printf("logical operator \t line_no %d \n", line_no); }

"right"        { v[19]++; printf("boolean operator \t line_no %d \n", line_no); }
"wrong"        { v[20]++; printf("boolean operator \t line_no %d \n", line_no); }
"&&"           { v[21]++; printf("boolean operator \t line_no %d \n", line_no); }
"||"           { v[22]++; printf("boolean operator \t line_no %d \n", line_no); }

"number"       { v[23]++; printf("number \t line_no %d \n", line_no); }
"decimal"      { v[24]++; printf("decimal \t line_no %d \n", line_no); }
"letter"       { v[25]++; printf("letter \t line_no %d \n", line_no); }
"boolean"      { v[26]++; printf("boolean \t line_no %d \n", line_no); }

#.*             { ; }
[ \t]*          { ; }
[\n]            { v[27]++; line_no++; } 

[-]?{digit}+                    { v[28]++; printf("number_value \t line_no %d \n", line_no); }
[-]?{digit}+\.{digit}{1,6}      { v[29]++; printf("float value \t line_no %d \n", line_no); }
{alphabet}({alphabet}|{digit})* { v[30]++; printf("identifier name \t line_no %d \n", line_no); }

["].*["]                       { v[31]++; printf("str value \t line_no %d \n", line_no); }
['].[']                        { v[32]++; printf("char value \t line_no %d \n", line_no); }

"."|"="|","|"{"|"}"|"("|")"|"["|"]"|"*"|"+"|"-"|"/"|"?"|":"|"&"|"|"|"^"|"!"|"~"|"%"|"<"|">" {
    printf("operator \t line_no %d \n", line_no);
}

. {
    printf("Invalid Character at line %d", line_no);
}

%%

int yywrap(void) {
    return 1;
}

int yyerror (char const *s) {
   fprintf(stderr, "%s\n", s);
   return 1;
}

int main() { 
    yylex();
    
    printf("Total occurrences\n");

    printf("tellme      : %d\n", v[0]);
    printf("take        : %d\n", v[1]);
    printf("checkif     : %d\n", v[2]);       
    printf("otherwise   : %d\n", v[3]);
    printf("checktill   : %d\n", v[4]);
    printf("return      : %d\n", v[5]);
    printf("remember    : %d\n", v[6]);
    printf("+           : %d\n", v[7]);
    printf("-           : %d\n", v[8]);
    printf("*           : %d\n", v[9]);
    printf("/           : %d\n", v[10]);
    printf("log         : %d\n", v[11]);
    printf("exp         : %d\n", v[12]);
    printf(">=          : %d\n", v[13]);
    printf("<=          : %d\n", v[14]);
    printf(">           : %d\n", v[15]);
    printf("<           : %d\n", v[16]);
    printf("==          : %d\n", v[17]);
    printf("!=          : %d\n", v[18]);
    printf("right       : %d\n", v[19]);
    printf("wrong       : %d\n", v[20]);
    printf("&&          : %d\n", v[21]);
    printf("||          : %d\n", v[22]);
    printf("number      : %d\n", v[23]);
    printf("decimal     : %d\n", v[24]);
    printf("letter      : %d\n", v[25]);
    printf("boolean     : %d\n", v[26]);
    printf("new line    : %d\n", v[27]);
    printf("int value   : %d\n", v[28]);
    printf("float value : %d\n", v[29]);
    printf("id          : %d\n", v[30]);
    printf("string      : %d\n", v[31]);
    printf("char        : %d\n", v[32]);
    
    return 0;
}
