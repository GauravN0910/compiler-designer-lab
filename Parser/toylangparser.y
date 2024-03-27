%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    extern int yylineno;
    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);
    struct node *head;
    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
    };
    int success = 1;
%}

%union { 
	struct var_name { 
		char name[100]; 
		struct node* nd;
	} nd_obj; 
}

%token <nd_obj> PRINTFF SCANFF IF ELSE WHILE RETURN DECLARE ADD SUBTRACT MULTIPLY DIVIDE LOG POW GTE LTE GT LT EQ NE TRUE FALSE AND OR INT FLOAT CHAR BOOL NUMBER FLOAT_NUM ID STR CHARACTER MAIN
%type <nd_obj> program entry datatype body block else condition statement init expression term factor base exponent mulops addops relop value charbool valcharbool bools return
%define parse.error verbose
%%

program: entry '(' ')' '{' body return '}' { struct node *main = mknode($5.nd, $6.nd, "main"); $$.nd = mknode($1.nd, main, "TOYLANG"); head = $$.nd; printf("applied entry to program %d \n",yylineno); }
;


entry: datatype MAIN { printf("applied datatype MAIN to entry %d \n",yylineno); }
;

datatype: INT { $$.nd = mknode(NULL, NULL, $1.name); printf("applied INT to datatype %d \n",yylineno); }
| FLOAT  { $$.nd = mknode(NULL, NULL, $1.name); printf("applied FLOAT to datatype  %d \n",yylineno); }
| CHAR { $$.nd = mknode(NULL, NULL, $1.name); printf("applied CHAR to datatype  %d \n",yylineno);}
| BOOL { $$.nd = mknode(NULL, NULL, $1.name); printf("applied BOOL to datatype  %d \n",yylineno);}
;

body: block body {$$.nd = mknode($1.nd, $2.nd, "body"); printf("applied block body to body %d \n",yylineno);}
| { $$.nd = NULL; printf("applied empty to body %d \n",yylineno);}
;

block: WHILE '(' condition ')' '{' body '}' { $$.nd = mknode($3.nd, $6.nd, $1.name); printf("applied while to block %d \n",yylineno);}
| IF '(' condition ')' '{' body '}' else { struct node *iff = mknode($3.nd, $6.nd, $1.name); $$.nd = mknode(iff, $8.nd, "if-else-block"); printf("applied if to block %d \n",yylineno);}
| statement ';' { $$.nd = $1.nd; printf("applied statement to block %d \n",yylineno);}
| PRINTFF '(' STR ')' ';' { struct node* n1 = mknode(NULL,NULL,$3.name); $$.nd = mknode(n1, NULL, $1.name); printf("applied PRINTFF for string to block %d \n",yylineno);}
| PRINTFF '(' valcharbool ')' ';' { $$.nd = mknode($3.nd, NULL, $1.name); printf("applied PRINTFF for other to block %d \n",yylineno);}
| SCANFF '(' STR ',' '&' ID ')' ';' { struct node* n1 = mknode(NULL,NULL,$3.name); struct node* n2 = mknode(NULL,NULL,$6.name); $$.nd = mknode(n1,n2,$1.name); printf("applied SCANFF to block %d \n",yylineno);}
;

else: ELSE '{' body '}' { $$.nd = mknode(NULL, $3.nd, $1.name); printf("applied ELSE to else %d \n",yylineno);}
|  { $$.nd = NULL; printf("applied empty to else %d \n",yylineno);}
;

condition:expression relop charbool { $$.nd = mknode($1.nd, $3.nd, $2.name); printf("applied exp rel charbool to condition %d \n",yylineno);}
| expression relop expression { $$.nd = mknode($1.nd,$3.nd,$2.name); printf("applied exp rel exp to condition %d \n",yylineno);}
| TRUE { $$.nd = NULL; printf("applied TRUE to condition %d \n",yylineno);}
| FALSE { $$.nd = NULL; printf("applied FALSE to condition %d \n",yylineno);}
;

statement: DECLARE datatype ID init { $3.nd = mknode(NULL, NULL, $3.name); $1.nd = mknode($2.nd, $3.nd, $1.name); $$.nd = mknode($1.nd, $4.nd, "DECLARE"); printf("applied DECLARE datatype to statement %d \n",yylineno);} 
| ID '=' expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $3.nd, "="); printf("applied ID = exp to statement %d \n",yylineno);}
;

init: '=' charbool  { $$.nd = $2.nd; printf("applied = charbool to init %d \n",yylineno);}
| '=' expression { $$.nd = $2.nd; printf("applied = exp to init %d \n",yylineno);}
;


expression : expression addops term { $$.nd = mknode($1.nd, $3.nd, $2.name); printf("applied expression adops term to expression %d \n",yylineno);} 
| term { $$.nd = $1.nd; printf("applied term to expression %d \n",yylineno);}
;

term : term mulops factor { $$.nd = mknode($1.nd, $3.nd, $2.name); printf("applied term mulops factor to term %d \n",yylineno);} 
| factor { $$.nd = $1.nd; printf("applied factor to term %d \n",yylineno);}
; 

factor : base exponent base { $$.nd = mknode($1.nd, $3.nd, $2.name); printf("applied base exponent base to factor %d \n",yylineno);} 
| LOG '(' value ',' value ')' { $$.nd = mknode($3.nd, $5.nd, $1.name); printf("applied log to factor %d \n",yylineno);}
| base { $$.nd = $1.nd; printf("applied base to factor %d \n",yylineno);}
;

base : value { $$.nd = $1.nd; printf("applied value to base %d \n",yylineno);}
| '(' expression ')' { $$.nd = $2.nd; printf("applied (exp) to base %d \n",yylineno);}
;


exponent: POW {printf("applied pow to exponent %d \n",yylineno);}
;

mulops: MULTIPLY {printf("applied MULTIPLY to mulops %d \n",yylineno);}
| DIVIDE {printf("applied DIVIDE to mulops %d \n",yylineno);}
;

addops: ADD {printf("applied ADD to addops %d \n",yylineno);}
| SUBTRACT {printf("applied SUBTRACT to addops %d \n",yylineno);}
;

relop: LT {printf("applied LT to relop %d \n",yylineno);}
| GT {printf("applied GT to relop %d \n",yylineno);}
| LTE {printf("applied LTE to relop %d \n",yylineno);}
| GTE{printf("applied GTE to relop %d \n",yylineno);}
| EQ{printf("applied EQ to relop %d \n",yylineno);}
| NE{printf("applied NE to relop %d \n",yylineno);}
;

value: NUMBER { $$.nd = mknode(NULL, NULL, $1.name); printf("applied NUMBER to value %d \n",yylineno);}
| FLOAT_NUM { $$.nd = mknode(NULL, NULL, $1.name); printf("applied FLOAT to value %d \n",yylineno);}
| ID { $$.nd = mknode(NULL, NULL, $1.name); printf("applied ID to value %d \n",yylineno);}
;

charbool: bools { $$.nd = $1.nd; printf("applied bools to charbool %d \n",yylineno);}
| CHARACTER { $$.nd = mknode(NULL, NULL, $1.name); printf("applied CHARACTER to charbool %d \n",yylineno);}
;

valcharbool: value { $$.nd = $1.nd; printf("applied value to valcharbool %d \n",yylineno);}
| charbool { $$.nd = mknode(NULL, NULL, $1.name); printf("applied charbool to valcharbool %d \n",yylineno);}
;

bools: TRUE { $$.nd = mknode(NULL, NULL, $1.name); printf("applied TRUE to bools %d \n",yylineno);}
| FALSE { $$.nd = mknode(NULL, NULL, $1.name); printf("applied FALSE to bools %d \n",yylineno);}
;

return: RETURN valcharbool ';' { $$.nd = mknode($2.nd,NULL,$1.name); printf("applied RETURN valcharbool; to return %d \n",yylineno);}
| { $$.nd = NULL; printf("applied empty to return %d \n",yylineno);} 
;

%%

int yyerror(const char *msg)
{
    extern int yylineno;
    printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
    success = 0;
    return 0;
}

int main() {
    int p = 0;
    p = yyparse();
    if(success) { printf("Parsing Successful\n");
        printf("\n\n");
        printf("PARSE TREE");
        printf("\n\n");
        printBT(head);
        printf("\n\n");
    }
    return p;
}

void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("○→  "); } 
		else { printf("●→  "); }
        printf("%s",ptr->token);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}
