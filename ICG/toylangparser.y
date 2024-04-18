%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include<math.h>
    #include"lex.yy.c"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();

    struct node* mknode(struct node *left, struct node *right, char *token);
    void printBT(struct node*);
    void check_declaration(char *c);
    struct node *head;
    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    void insert_type();
    void add(char c);
    void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
    int search (char* type);
    char type[10];
    int count=0;
    extern int line_no;
    int q;

    int sem_errors=0;
	int label=0;
	char buff[100];
	char errors[10][100];
	char reserved[15][20] = {"tellme", "take", "checkif", "otherwise", "checktill", "return", "log", "exp", "right", "wrong", "number", "decimal", "letter", "boolean", "main"};
    int ic_idx=0;
    int temp_var=0;
    int is_for=0;
    
    char icg[100][100];

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
        float value;
	} nd_obj; 

    struct var_name2 { 
        char name[100]; 
        struct node* nd;
        char type[5];
        float value;
    } nd_obj2; 

    struct var_name3 { 
        char name[100]; 
        struct node* nd;
        char type[10];
        char if_body[5];
        char else_body[5];
        char after_else_body[5];
        float value;
    } nd_obj3;
}

%token <nd_obj> PRINTFF SCANFF IF ELSE WHILE RETURN DECLARE ADD SUBTRACT MULTIPLY DIVIDE LOG POW GTE LTE GT LT EQ NE TRUE FALSE AND OR INT FLOAT CHAR BOOL NUMBER FLOAT_NUM ID STR CHARACTER
%type <nd_obj> program entry datatype body block else statement exponent mulops addops relop return printparam
%type <nd_obj2> init value expression term factor base charbool valcharbool bools
%type <nd_obj3> condition
%define parse.error verbose
%%

program: entry '(' ')' '{' body return '}' { struct node *main = mknode($5.nd, $6.nd, "main"); $$.nd = mknode($1.nd, main, "program"); head = $$.nd; }
;


entry: datatype ID { add('F');}
;

datatype: INT { insert_type();  $$.nd = mknode(NULL, NULL, $1.name);}
| FLOAT  { insert_type(); $$.nd = mknode(NULL, NULL, $1.name);}
| CHAR { insert_type(); $$.nd = mknode(NULL, NULL, $1.name);}
| BOOL { insert_type(); $$.nd = mknode(NULL, NULL, $1.name);}
;

body: block body {$$.nd = mknode($1.nd, $2.nd, "body");}
| { $$.nd = NULL; }
;

block: WHILE {add('K'); is_for=1; } '(' condition ')' '{' body '}' { 
    $$.nd = mknode($4.nd, $7.nd, $1.name);
    sprintf(icg[ic_idx++], "JUMP to %s\n", $4.if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body);
}
| IF {add('K'); is_for =0;} '(' condition ')' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); } '{' body '}' {  sprintf(icg[ic_idx++], "\nJUMP to %s\n", $4.after_else_body); sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); } else { 
        struct node *iff = mknode($4.nd, $8.nd, $1.name); 
        $$.nd = mknode(iff, $11.nd, "if-else-block"); 
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.after_else_body);
    }
| statement ';' { $$.nd = $1.nd; }
| PRINTFF { add('K'); } '(' printparam ')' ';' { $$.nd = mknode($4.nd, NULL, $1.name); sprintf(icg[ic_idx++], "\nCALL print, 1 \n"); }
| SCANFF {add('K');} '(' STR ',' '&' ID { check_declaration($7.name); } ')' ';' { struct node* n1 = mknode(NULL,NULL,$4.name); struct node* n2 = mknode(NULL,NULL,$7.name); $$.nd = mknode(n1,n2,$1.name); };

printparam: valcharbool { 
    $$.nd = $1.nd;  
    sprintf(icg[ic_idx++], "\nPARAM %s\n", $1.name);
}
| STR { $$.nd = mknode(NULL, NULL, $1.name); sprintf(icg[ic_idx++], "\n t0 = %s\n PARAM t0\n", $1.name); }

else: ELSE {add('K');} '{' body '}' { $$.nd = mknode(NULL, $4.nd, $1.name); }
|  { $$.nd = NULL; }
;

condition: valcharbool relop valcharbool { 
    if(strcmp($1.type,$3.type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    }
    strcpy($$.type,"boolean");
    $$.nd = mknode($1.nd, $3.nd, $2.name);  
    if(is_for) {
		sprintf($$.if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
		sprintf($$.else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
		sprintf($$.if_body, "L%d", label++);
		sprintf($$.else_body, "L%d", label++);
        sprintf($$.after_else_body, "L%d", label++);
	}
}
| TRUE {add('K');} { $$.nd = NULL; strcpy($$.type,"boolean"); }
| FALSE {add('K');} { $$.nd = NULL; strcpy($$.type,"boolean"); }
;

statement: DECLARE datatype ID { add('V'); } init { $3.nd = mknode(NULL, NULL, $3.name);  
        if(check_types($2.name, $5.type)) { 
            success=0;
            sprintf(errors[sem_errors], "Line %d: Variable \"%s\" has a different type than expected!\n", line_no, $3.name);
            sem_errors++;
        } 
        else { 
            $1.nd = mknode($2.nd, $3.nd, $1.name);
        } 
        $$.nd = mknode($1.nd, $5.nd, "DECLARE");
        $3.value = $5.value;
        sprintf(icg[ic_idx++], "%s = %s\n", $3.name, $5.name);
    } 
| ID { check_declaration($1.name); } '=' expression {
        char *id_type = get_type($1.name);
        if(id_type!=NULL && strcmp(id_type,$4.type)){
            success=0;
            sprintf(errors[sem_errors], "Line %d: Variable \"%s\" has a different type than expected!\n", line_no, $1.name);
            sem_errors++;
        }
        $1.nd = mknode(NULL, NULL, $1.name); 
        $$.nd = mknode($1.nd, $4.nd, "="); 
        $1.value = $4.value;
        sprintf(icg[ic_idx++], "%s = %s\n", $1.name, $4.name);
    }
| ID { check_declaration($1.name); } relop expression { $1.nd = mknode(NULL, NULL, $1.name); $$.nd = mknode($1.nd, $4.nd, $3.name ); }
;

init: '=' charbool  { $$.nd = $2.nd; strcpy($$.type,$2.type); $$.value = $2.value; }
| '=' expression { $$.nd = $2.nd; strcpy($$.type,$2.type); strcpy($$.name,$2.name); $$.value = $2.value; }
;


expression : expression addops term {
        if(strcmp($1.type,$3.type)){
            success=0;
            sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
            sem_errors++;
        }
        sprintf($$.name,"t%d",temp_var++);
        strcpy($$.type,$1.type);
        $$.nd = mknode($1.nd, $3.nd, $2.name);
        $$.value = $1.value + $3.value;
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    } 
| term { $$.nd = $1.nd; strcpy($$.type,$1.type); $$.value = $1.value; }
;

term : term mulops factor {
    if(strcmp($1.type,$3.type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    } 
    strcpy($$.type,$1.type);
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
    sprintf($$.name,"t%d",temp_var++);
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    $$.value = $1.value * $3.value;
    } 
| factor { $$.nd = $1.nd; strcpy($$.type,$1.type); $$.value = $1.value; }
; 

factor : base exponent base {
    if(strcmp($1.type,$3.type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    }
    strcpy($$.type,$1.type);
    $$.nd = mknode($1.nd, $3.nd, $2.name); 
    sprintf($$.name,"t%d",temp_var++);
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);
    $$.value = pow($1.value, $3.value);
    } 
| LOG '(' value ',' value ')' { $$.nd = mknode($3.nd, $5.nd, $1.name);  }
| base { $$.nd = $1.nd; strcpy($$.type,$1.type); $$.value = $1.value; }
;

base : value { $$.nd = $1.nd; strcpy($$.type,$1.type); $$.value = $1.value;}
| '(' expression ')' { $$.nd = $2.nd; strcpy($$.type,$2.type); }
;


exponent: POW
;

mulops: MULTIPLY
| DIVIDE
;

addops: ADD 
| SUBTRACT 
;

relop: LT
| GT
| LTE
| GTE
| EQ
| NE
;

value: NUMBER { 
        strcpy(type, "number");
        add('C'); 
        strcpy($$.name, $1.name);
        strcpy($$.type, "number");
        $$.nd = mknode(NULL, NULL, $1.name);
        $$.value = atoi($1.name);
    }
| FLOAT_NUM { 
    strcpy(type, "decimal");
    add('C');
    strcpy($$.name, $1.name);
    strcpy($$.type, "decimal"); 
    $$.nd = mknode(NULL, NULL, $1.name); 
    $$.value = atof($1.name);
    }
| ID {
    check_declaration($1.name);
    strcpy($$.name, $1.name);
    char *id_type = get_type($1.name);
    if(id_type!=NULL) strcpy($$.type,id_type); 
    $$.nd = mknode(NULL, NULL, $1.name); 
    }
;

charbool: bools { $$.nd = $1.nd; strcpy($$.type,"boolean");  }
| CHARACTER { add('C'); $$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"letter"); }
;

valcharbool: value { $$.nd = $1.nd; strcpy($$.type,$1.type); }
| charbool { $$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,$1.type); }
;

bools: TRUE { strcpy(type,"boolean"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"boolean");}
| FALSE { strcpy(type,"boolean"); add('C'); $$.nd = mknode(NULL, NULL, $1.name); strcpy($$.type,"boolean");}
;

return: RETURN {add('K');} valcharbool ';' { check_return_type($3.type);  $$.nd = mknode($3.nd,NULL,$1.name); }
| { $$.nd = NULL; } 
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
    extern FILE *yyin, *yyout;
    int p = 0;
    p = yyparse();
    printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else { printf("Parsing Successful\n");
        printf("\n\n");
        printf("PARSE TREE");
        printf("\n\n");
        printBT(head);
        printf("\n\n");
    }

    printf("\n\n");
	printf("INTERMEDIATE CODE GENERATION \n\n");
	for(int i=0; i<ic_idx; i++){
		printf("%s", icg[i]);
	}
	printf("\n\n");


    return p;
}

void check_declaration(char *c) {    
    q = search(c);    
    if(!q || q==-2) {        
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", line_no, c);  
        sem_errors++;    
    }
}

int check_types(char *type1, char *type2){
    if(strcmp(type1,type2)){
        return 1;
    }
    return 0;
}

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	if(strcmp(main_datatype, value)) {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", line_no);
		sem_errors++;
    }
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

int search(char *type) { 
    int i; 
    for(i=count-1; i>=0; i--) {
         if(strcmp(symbol_table[i].id_name, type)==0) {

            if(!strcmp(symbol_table[i].type,"Function")){

                return -2;

            }   

            return -1;

            break;  

        }
    } 
    return 0;
}

void insert_type() {
    strcpy(type, yytext);
}

void add(char c) {
  q=search(yytext);
  if(c == 'V' && q) {
    sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", line_no, yytext);  
    sem_errors++;    
  }
  if(c == 'V') {  
        for(int i=0; i<10; i++) {   
            if(!strcmp(reserved[i], strdup(yytext))) {
                sprintf(errors[sem_errors], "Line %d: Variable name  \"%s\" is a reserved keyword!\n", line_no, yytext);
                sem_errors++;    
                return;
            }  
        } 
  }
  if(!q) {
        if(c == 'K') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Keyword\t");   
        count++;  
        }  else if(c == 'V') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Variable");   
        count++;  
        }  else if(c == 'C') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Constant");   
        count++;  
        }  else if(c == 'F') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Function");   
        count++;  
        }
    }
}


void printBTHelper(char* prefix, struct node* ptr, int isLeft) {

    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("○→  "); } 
		else { printf("●→  "); }
        printf("%s (%f)",ptr->token,ptr->value);
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
