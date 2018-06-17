%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "union.h"
int yylex(void);
void yyerror(const char *s);

FILE *javafile;

struct content{
	char id[256];
	int ival;
	float fval;
	int bval;
	char sval[256];
	char type[256];
	char bigtype[256];
	int isGlobal;	// 0 = Global; 1 = Local;
	int storeVal;
};

struct content symbolTable[256][256];
int id_total=0;
int scope = 0;
bool isAdd = false;
int count = 0;
int storeNum = 0;
char typekeeper[256][256];
bool shouldGet = false;
char tempId[256];
char tempFuncId[256];
int tempNum = 0;
bool isInvoke = false;
int orderCount = 0;
char orderToFile[256][256];
int label = 0;
int iflabel1=0;
int iflabel2=0;
int whilelabel=0;

int insert(struct content a){
	bool inSymbolTable = false ;
	for(int i = 0 ; i < id_total; i++)
	{
		if(strcmp(a.id, symbolTable[scope][i].id)==0)
		{
			inSymbolTable = true ;
		}
	}
	if (!inSymbolTable)
	{
		if(strcmp("int",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			symbolTable[scope][id_total].ival = a.ival;
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else if(strcmp("float",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			symbolTable[scope][id_total].fval = a.fval;
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}
			id_total++;
			}
		}else if(strcmp("str",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].sval,a.sval);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else if(strcmp("bool",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			symbolTable[scope][id_total].bval = a.bval;
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			symbolTable[scope][id_total].ival = a.ival;
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);

		}
	}
} 

int update(struct content a){
	for(int i = 0 ; i <= scope; i++)
	{
		for(int j = 0; j <=id_total;j++){
			if(strcmp(a.id, symbolTable[i][j].id)==0)
			{
	if(strcmp("const",symbolTable[i][j].bigtype)){
		printf("~~%s~not const~~~~~~~~~~~\n",symbolTable[i][j].id);
		if(strcmp("int",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].ival = a.ival;
			symbolTable[i][j].storeVal = a.storeVal;
			printf("~update~~~value:%d~~~istore~%d~~~~~~\n",symbolTable[i][j].ival,symbolTable[i][j].storeVal);
			}else{
			}
		}else if(strcmp("float",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].fval = a.fval;
			symbolTable[i][j].storeVal = a.storeVal;
			}else{
			}
		}else if(strcmp("str",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			strcpy(symbolTable[i][j].sval,a.sval);
			symbolTable[i][j].storeVal = a.storeVal;
			}else{
			
			}
		}else if(strcmp("bool",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].bval = a.bval;
			symbolTable[i][j].storeVal = a.storeVal;
			}else{		
			}
		}else{
		}
	}else{
		printf("----------%s----------\n","const can not change value!");
	}
			}
		}
	}
} 

int checkScope(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].isGlobal;
			}
		}
	}
}

int getStoreVal(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				printf("\t\tid:%s\n\t\tistore:%d\n",symbolTable[i][j].id,symbolTable[i][j].storeVal);
				return symbolTable[i][j].storeVal;
			}
		}
	}
}

int getInitScope(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return i;
			}
		}
	}
}

int getNowScope(char *c){
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[scope][j].id)==0){
			return scope; //true
			}
		}
}

char* getType(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j = 0 ; j<=id_total; j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].type;
			}
		}
	}
}

char* getBigType(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j = 0 ; j<=id_total; j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].bigtype;
			}
		}
	}
}

int getValue(char *c){
	for (int i = 0; i <= scope; i++)
	{
		for(int j=0;j<=id_total;j++){
		if (strcmp(c , symbolTable[i][j].id)==0)
		{			
			if(strcmp(symbolTable[i][j].type,"int")==0){
				return symbolTable[i][j].ival;
			}else{
				
			}
		}else{
		}
		}
	}
}

int dump(){
	for (int i = 0; i <= scope; i++)
	{
		for (int j=0; j <= id_total ;j++)
		{
			if(strcmp("int",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*d\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].ival,10,i);
				}
			}else if(strcmp("float",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*f\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].fval,10,i);
				}
			}else if(strcmp("str",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].sval,10,i);
				}
			}else if(strcmp("bool",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
			printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);

				}else{
				if(symbolTable[i][j].bval==0)
				{
				printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,"False",10,i);
				}else if(symbolTable[i][j].bval==1)
				{
				printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,"True",10,i);
				}
				}
			}else if(strcmp("null",symbolTable[i][j].type)==0)			{
			printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10," ",10,symbolTable[i][j].bigtype,10," ",10,i);
			}else{

			}
		}
	}
}


%}
%union{
  char m_sId[256];
  int m_nInt;
  float m_float;
  char m_str[256];
  char type[256];
  struct s sdec;
};

%start program 

%token COMMA COLON SEMICOLON LP RP LSB RSB LCB RCB PLUS MINUS MULTIPLY DIVIDE INCREMENT DECREMENT MODULUS LT LE GE GT EQ NE AND OR NOR EQUALS PLUSEQUALS MINUSEQUALS MULTIPLYEQUALS DIVIDEEQUALS

%token BREAK CHAR CONTINUE DO ELSE ENUM EXTERN FOR FN IF IN LET LOOP MATCH MUT PRINT PRINTLN PUB RETURN SELF STATIC STRUCT USE WHERE WHILE FALSE TRUE

%token<type>BOOL INT FLOAT STR

%token<m_sId>IDENTIFIER
%token<m_nInt>INTEGERVAL
%token<m_str>STRINGVAL
%token<m_float>FLOATVAL
%token<m_nInt>TRUEVAL
%token<m_nInt>FALSEVAL

%left OR
%left AND
%left NOR
%left LT LE EQ GE GT NE
%left PLUS MINUS
%left MULTIPLY DIVIDE

%nonassoc UMINUS
%type<sdec> value_declaration
%type<type> type_specifier 
%type<m_nInt> operation_exp expression relational_exp func_inv_list


%%

program
	: external_declaration 
		{printf("%s\n","Reducing to [program]");}
	| program external_declaration
		{printf("%s\n","Reducing to [program]");}
	;       

external_declaration
	: function_definition
		{printf("%s\n","Reducing to [external_declaration]");}

	| declaration_list
		{printf("%s\n","Reducing to [external_declaration]");}
	| simple_statment
		{printf("%s\n","Reducing to [external_declaration]");}
	;

func_expression : FN 
			{
				isAdd = false;
				scope++;
				printf("~~~~~~~~~~scope++ %d times~~~~~~~~~~\n",scope);
				printf("~~~~~FN~~~~~isAdd %d false~~~~~~~~~~\n",isAdd);
				//strcpy(orderToFile[0],"\tmethod public static ");
				fprintf(javafile,"\tmethod public static ");
				printf("%s\n","Reducing to [func_expression]");
			}
		;

function_definition 
	: func_expression IDENTIFIER LP RP 	
			{
			struct content a;
			strcpy(a.id,$2);
			strcpy(a.bigtype,"func");
			strcpy(a.type,"null");
			strcpy(a.sval,"null");
			insert(a);
			//sprintf(orderToFile[1],"void %s(java.lang.String[])\n",$2);
			fprintf(javafile,"void %s(java.lang.String[])\n",$2);
			//sprintf(orderToFile[2],"\tmax_stack 15\n\tmax_locals 15\n");
			//sprintf(orderToFile[3],"\t{\n");
			fprintf(javafile,"\tmax_stack 15\n");
			fprintf(javafile,"\tmax_locals 15\n");
			fprintf(javafile,"\t{\n");
			
			
			printf("%s\n","Reducing to [function_definition]");
		}block_statement{
			fprintf(javafile,"\t\treturn\n\t}\n");
		}

	| func_expression IDENTIFIER LP parameter_list RP MINUS GT type_specifier 
		{
			struct content a;
			strcpy(a.id,$2);
			strcpy(a.bigtype,"func");
			strcpy(a.type,$8);
			a.ival = 0;
			insert(a);
			strcpy(tempFuncId,$2);
			fprintf(javafile,"%s %s(",$8,$2);
			for(int i = 0; i < count; i++) {
				if(i != count-1)
					fprintf(javafile,"%s,",typekeeper[i]);
				else
					fprintf(javafile,"%s)\n",typekeeper[i]);
			}
			
			fprintf(javafile,"\tmax_stack 15\n");
			fprintf(javafile,"\tmax_locals 15\n");
			fprintf(javafile,"\t{\n");
			for(int i =0 ;i<count ; i++){
			fprintf(javafile,"\t\tiload %d\n",i);
			}
			printf("%s\n","Reducing to [function_definition]");
		} 

		block_statement{
			fprintf(javafile,"\t\tireturn\n\t}\n");
		}
	;

block_start : LCB 
	    	{
			printf("*!!**********isAdd:::%d\n",isAdd);
			if (isAdd == 1)
			{		
				scope++;
				printf("~~~~~~~~~~scope touched %d ~~~~~~~~~\n",scope);
			}else{
				isAdd = true;
printf("~~~~~~~~~~isAdd %d touched~~~~~~~~~~\n",isAdd);
			}
			printf("***********scope:::%d\n",scope);
			printf("%s\n","Reducing to [block_start]");
		}
	    ;

block_end : RCB
	  	{
			printf("***********when } come out:::%d\n",scope);
			printf("%s\n","Reducing to [block_end]");
		}
	  ;

block_statement
	: block_start statement_list block_end
		{printf("%s\n","Reducing to [block_statement]");}
	| block_start declaration_list block_end
		{printf("%s\n","Reducing to [block_statement]");}
	| block_start declaration_list statement_list block_end
		{printf("%s\n","Reducing to [block_statement]");}
	| block_start block_end
		{printf("%s\n","Reducing to [block_statement]");}
	;

declaration_list
	: declaration
		{printf("%s\n","Reducing to [declaration_list]");}
	| declaration_list declaration
		{printf("%s\n","Reducing to [declaration_list]");}
	;

declaration
	: LET IDENTIFIER EQUALS value_declaration SEMICOLON 
		{
			struct content a;
			strcpy(a.id,$2);
			strcpy(a.bigtype,"const");
			if($4.type == 0){
			strcpy(a.type,"int");
			a.ival = $4.uval.ival;
			}else if($4.type == 1){
			strcpy(a.type,"float");
			a.fval = $4.uval.fval;
			}else if($4.type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,$4.uval.sval);
			}else if($4.type == 3){
			strcpy(a.type,"bool");
			a.bval = $4.uval.bval;
			}else if($4.type == 4){
			strcpy(a.type,"bool");
			a.bval = $4.uval.bval;	
			}
			insert(a);
		
			fprintf(javafile,"\t\tsipush %d\n",$4.uval.ival);			

			printf("%s\n","Reducing to [declaration]");
		}
	| LET IDENTIFIER COLON type_specifier EQUALS value_declaration SEMICOLON
		{
			struct content a;
			strcpy(a.id,$2);
			strcpy(a.bigtype,"const");
			if($6.type == 0){
			strcpy(a.type,"int");
			a.ival = $6.uval.ival;
			}else if($6.type == 1){
			strcpy(a.type,"float");
			a.fval = $6.uval.fval;
			}else if($6.type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,$6.uval.sval);
			}else if($6.type == 3){
			strcpy(a.type,"bool");
			a.bval = $6.uval.bval;
			}else if($6.type == 4){
			strcpy(a.type,"bool");
			a.bval = $6.uval.bval;	
			}
			insert(a);
			fprintf(javafile,"\t\tsipush %d\n",$6.uval.ival);
			printf("%s\n","Reducing to [declaration]");

		}
	| LET MUT IDENTIFIER COLON type_specifier EQUALS value_declaration SEMICOLON
		{
			struct content a;
			strcpy(a.id,$3);
			strcpy(a.bigtype,"var");
			if(strcmp("int",$5)==0)
			{
			strcpy(a.type,"int");
			a.ival = $7.uval.ival;
			}else if(strcmp("float",$5)==0)
			{
			strcpy(a.type,"float");
			a.fval = $7.uval.fval;
			}else if(strcmp("str",$5)==0)
			{
			strcpy(a.type,"str");
			strcpy(a.sval,$7.uval.sval);
			}else if(strcmp("bool",$5)==0)
			{
			strcpy(a.type,"bool");
			a.bval = $7.uval.bval;
			}else{
			printf("%s","ERROR!!!");
			}
			insert(a);
			if(checkScope($3)==0)
			{
				if(strcmp("int",$5)==0)
				{
				fprintf(javafile,"\tfield static int %s = %d ", $3,$7.uval.ival );
				}else if(strcmp("float",$5)==0)
				{
				fprintf(javafile,"\tfield static float %s = %f ", $3,$7.uval.fval );
				}else if(strcmp("str",$5)==0)
				{
				fprintf(javafile,"\tfield static string %s = %s ", $3,$7.uval.sval );
				}else if(strcmp("bool",$5)==0)
				{
					if($7.uval.bval == 0)
					{
					fprintf(javafile,"\tfield static bool %s = true ", $3 );		
					}else{
					fprintf(javafile,"\tfield static bool %s = false ", $3);

					}	
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				fprintf(javafile,"\t\tsipush %d\n",$7.uval.ival);
				fprintf(javafile,"\t\tistore %d\n",storeNum);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal($3));
				storeNum++;
			}

			printf("%s\n","Reducing to [declaration]");

		}
	| LET MUT IDENTIFIER COLON type_specifier SEMICOLON
		{
			struct content a;
			strcpy(a.id,$3);
			strcpy(a.bigtype,"var");
			if(strcmp("int",$5)==0){
				strcpy(a.type,"int");
				a.ival = 0 ;
			}else if(strcmp("float",$5)==0){
				strcpy(a.type,"float");
				a.fval = 0 ;
			}else if(strcmp("str",$5)==0){
				strcpy(a.type,"string");
				strcpy(a.sval ,"NULL") ;
			}else if(strcmp("bool",$5)==0){
				strcpy(a.type,"bool");
				a.bval = 0 ;
			}
			insert(a);

			if(checkScope($3)==0)
			{
				if(strcmp("int",$5)==0)
				{
				fprintf(javafile,"\tfield static integer %s ", $3);
				}else if(strcmp("float",$5)==0)
				{
				fprintf(javafile,"\tfield static float %s ", $3);
				}else if(strcmp("str",$5)==0)
				{
				fprintf(javafile,"\tfield static string %s ", $3);
				}else if(strcmp("bool",$5)==0)
				{
				fprintf(javafile,"\tfield static bool %s ", $3 );			
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal($3));
				storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");

		}
	| LET MUT IDENTIFIER EQUALS value_declaration SEMICOLON
		{
			struct content a;
			strcpy(a.id,$3);
			strcpy(a.bigtype,"var");
			if($5.type == 0){
			strcpy(a.type,"int");
			a.ival = $5.uval.ival;
			}else if($5.type == 1){
			strcpy(a.type,"float");
			a.fval = $5.uval.fval;
			}else if($5.type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,$5.uval.sval);
			}else if($5.type == 3){
			strcpy(a.type,"bool");
			a.bval = $5.uval.bval;
			}else if($5.type == 4){
			strcpy(a.type,"bool");
			a.bval = $5.uval.bval;	
			}
			insert(a);

			if(checkScope($3)==0)
			{
				if($5.type==0)
				{
				fprintf(javafile,"\tfield static int %s = %d \n", $3,$5.uval.ival );
				}else if($5.type==1)
				{
				fprintf(javafile,"\tfield static float %s = %f \n", $3,$5.uval.fval );
				}else if($5.type==2)
				{
				fprintf(javafile,"\tfield static string %s = %s \n", $3,$5.uval.sval );
				}else if($5.type==3)
				{
					if($5.uval.bval == 0)
					{
					fprintf(javafile,"\tfield static bool %s = true \n", $3 );		
					}else{
					fprintf(javafile,"\tfield static bool %s = false \n", $3);

					}	
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				fprintf(javafile,"\t\tsipush %d\n",$5.uval.ival);
				fprintf(javafile,"\t\tistore %d\n",storeNum);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal($3));
				storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");

		}
	| LET MUT IDENTIFIER SEMICOLON	
		{
			struct content a;
			strcpy(a.id,$3);
			strcpy(a.type,"int");
			strcpy(a.bigtype,"var");
			a.ival = 0 ;
			insert(a);
			if(checkScope($3)==0)
			{
			fprintf(javafile,"\tfield static int %s \n", $3);
			}else{
			a.storeVal = storeNum;
			update(a);
			storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");
		}
	| LET MUT IDENTIFIER LSB type_specifier COMMA INTEGERVAL RSB SEMICOLON
		{
			struct content a;
			strcpy(a.id,$3);
			strcpy(a.bigtype,"arrays");
			if(strcmp("int",$5)==0){
				strcpy(a.type,"int");
			}else if(strcmp("float",$5)==0){
				strcpy(a.type,"float");
			}else if(strcmp("str",$5)==0){
				strcpy(a.type,"str");
			}else if(strcmp("bool",$5)==0){
				strcpy(a.type,"bool");
			}
			insert(a);
			printf("%s\n","Reducing to [declaration]");
		}
	;

func_inv_list
	: expression
	| IDENTIFIER LP expression COMMA func_inv_list RP
		{
			$3,$5;
			fprintf(javafile,"\t\tinvokestatic %s test.%s(",getType($1),$1);
				for(int i = 0; i<count ; i++){
				if(i != count -1){
					fprintf(javafile,"%s,",typekeeper[i]);
				}else{
					fprintf(javafile,"%s)\n",typekeeper[i]);
					}
				}
			printf("%s\n","Reducing to [func_inv_list]");
		}
	; 

value_declaration
	: STRINGVAL 
		{
  			$$.type = 2;
			strcpy($$.uval.sval,$1);
			printf("%s\n","Reducing to [value_declaration]");

		}
	| TRUEVAL
		{
			$$.type = 3;
			$$.uval.bval = 1;
			printf("%s\n","Reducing to [value_declaration]");
		}
	| FALSEVAL
		{
			$$.type = 4;
			$$.uval.bval = 0;
			printf("%s\n","Reducing to [value_declaration]");
		}
	| INTEGERVAL 
		{
			$$.type = 0;
			$$.uval.ival = $1;
			printf("%s\n","Reducing to [value_declaration]");
		}
	| FLOATVAL
		{	
			$$.type = 1;
			$$.uval.fval = $1;
			printf("%s\n","Reducing to [value_declaration]");
		}
	;


operation_exp
	: MINUS operation_exp %prec UMINUS
		{
			$$ = -$2;
			fprintf(javafile,"\t\tineg\n");
		printf("%s\n","Reducing to [unary_expression]");
		}
	| operation_exp MULTIPLY operation_exp
		{
			$$ = $1 * $3 ;
			fprintf(javafile,"\t\timul\n");
		printf("%s\n","Reducing to [multiplicative_expression]");
		}		
	| operation_exp DIVIDE operation_exp
		{
			$$ = $1 / $3 ;
			fprintf(javafile,"\t\tidiv\n");
			printf("%s\n","Reducing to [multiplicative_expression]");

		}
	| operation_exp MODULUS operation_exp
		{
			$$ = $1 % $3;
			fprintf(javafile,"\t\tirem\n");
			printf("%s\n","Reducing to [multiplicative_expression]");

		}
	| operation_exp PLUS operation_exp
		{
			$$ = $1 + $3 ;
			fprintf(javafile,"\t\tiadd\n");
			printf("%s\n","Reducing to [additive_expression]");
		}
	| operation_exp MINUS operation_exp
		{
			$$ = $1 - $3;
			fprintf(javafile,"\t\tisub\n");
			printf("%s\n","Reducing to [additive_expression]");
		}
	| value_declaration
		{
			if($1.type == 0){
				$$ = $1.uval.ival;
				tempNum = $$;
				fprintf(javafile,"\t\tsipush %d\n",$$);
				printf("!!!!!Number %d : sipush!!!!!\n",orderCount);
				//sprintf(orderToFile[orderCount],"\t\tsipush %d\n",$$);
				//orderCount++;
			}else if($1.type == 1){
				$$ = $1.uval.fval;
			}else{

			}
			printf("%s\n","Reducing to [func_inv]");
		}
	| IDENTIFIER 
		{
			$$=getValue($1);
			printf("Id : %s\nNow Scope : %d\nwhatScopeWeCreate: %d\ninNowscope: %d\nvalue:%d\nstoreVal:%d\n",$1,scope,getInitScope($1),getNowScope($1),$$,getStoreVal($1));
			if(getInitScope($1)!=scope){
				if(checkScope($1)==0){								fprintf(javafile,"\t\tgetstatic %s test.%s\n",getType($1),$1);	
				}else{
				printf("????????%s and istore:%d\n",$1,getStoreVal($1));
				fprintf(javafile,"\t\tiload %d\n",getStoreVal($1));
				}
			}else{
				if(checkScope($1)==1 && strcmp("var",getBigType($1))==0){
				printf("~~~!!!!%s\n~~~!!!!%d\n",$1,getStoreVal($1));
				fprintf(javafile,"\t\tiload %d\n",getStoreVal($1));
				}else if(checkScope($1)==1 && strcmp("const",getBigType($1))==0){
				fprintf(javafile,"\t\tsipush %d\n",getValue($1));
			}
			printf("%s\n","Reducing to [operation_exp]");
		}
	}
	;


relational_exp
	: operation_exp LT operation_exp 
		{
		//<
		if($1 < $3){
			$$ = 1 ;
		}else{	
			$$ = 0 ;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tiflt L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
	| operation_exp GT operation_exp
		{
		if($1>$3){
			$$ = 1 ;
		}else{
			$$ = 0 ;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifgt L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);	
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
	| operation_exp LE operation_exp
		{
		if($1 <= $3){
			$$ = 1;
		}else{
			$$ = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifle L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
	| operation_exp GE operation_exp
		{
		if($1 >= $3){
			$$ = 1;
		}else{
			$$ = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifge L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
	| operation_exp EQ operation_exp
		{
		if($1 == $3){
			$$ = 1;
		}else{
			$$ = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifeq L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
	| operation_exp NE operation_exp
		{
		if($1 != $3){
			$$ = 1;
		}else{
			$$ = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifne L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
	| operation_exp AND operation_exp
		{
		if($1 && $3){
			$$ = 1;
		}else{
			$$ = 0;
		}
		fprintf(javafile,"\t\tiand\n");
		}
	| operation_exp OR operation_exp
		{
		fprintf(javafile,"\t\tior\n");
		printf("%s\n","Reducing to [relational_expression]");}
	| TRUE
		{
			$$ = 1 ;//true
		}
	| FALSE
		{
			$$ = 0; //false
		}
	;

expression
	: operation_exp
		{
		$$=$1;
		printf("%s\n","Reducing to [expression]");
		}
	| relational_exp
		{
		$$=$1;
		printf("%s\n","Reducing to [expression]");
		}
	| func_inv_list
	;


type_specifier
	: BOOL	
		{
			strcpy($$,"bool");
			printf("%s\n","Reducing to [type_specifier]");
		}
	| STR	
		{
			strcpy($$,"str");
			printf("%s\n","Reducing to [type_specifier]");
		}
	| FLOAT	
		{
			strcpy($$,"float");
			printf("%s\n","Reducing to [type_specifier]");
		}
	| INT	
		{
			strcpy($$,"int");
			printf("%s\n","Reducing to [type_specifier]");
		}
	;

parameter_list
	: parameter_declaration
		{
		printf("%s\n","Reducing to [parameter_list]");
		}
	| parameter_list COMMA parameter_declaration
		{
		printf("%s\n","Reducing to [parameter_list]");
		}
	;

parameter_declaration
	: IDENTIFIER COLON type_specifier 
		{
			struct content a;	
			strcpy(a.id,$1);
			strcpy(a.type,$3);
			strcpy(a.bigtype,"func_parameter");
			a.ival = 0;
			insert(a);
			//fprintf(javafile,"\t\t%s\n",$3);
			strcpy(typekeeper[count],$3);
			count++;
			printf("%s\n","Reducing to [parameter_declaration]");
		}
	;

simple_statment
	: IDENTIFIER EQUALS expression SEMICOLON
		{
		struct content a;	
		strcpy(a.id,$1);
		a.ival = $3;
		printf("..id---(%s)...value(%d)...storeVal(%d)\n",$1,getValue($1),getStoreVal($1));
		a.storeVal = getStoreVal($1);
		update(a);
		printf("..id---(%s)...value(%d)...storeVal(%d)\n",$1,getValue($1),getStoreVal($1));
		if(checkScope($1)==0){
		fprintf(javafile,"\t\tputstatic %s test.%s\n",getType($1),$1);
		}else{
			fprintf(javafile,"\t\tistore %d\n",getStoreVal($1));
		}
		printf("%s\n","Reducing to [simple_statment]");
		}
	| PRINT	
		{
		fprintf(javafile,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}expression SEMICOLON{
		fprintf(javafile,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
		}
	| PRINTLN 
		{
		fprintf(javafile,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		printf("%s\n","Reducing to [simple_statment]");
		}expression SEMICOLON{
		fprintf(javafile,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
		}
	| RETURN SEMICOLON
		{
		printf("%s\n","Reducing to [simple_statment]");
		}
	| RETURN expression SEMICOLON
		{
		printf("~~~~~~~scope:::%d~~~~~~~~~\n",scope);
		printf("%s\n","Reducing to [simple_statment]");
		}
	;

selection_statement
	: IF LP expression RP  
		{
		fprintf(javafile,"\t\tifeq L%d\n",label);
		iflabel1=label;
		printf("%s\n","Reducing to [selection_statment]");
		}statement{
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		iflabel2=label+1;
		fprintf(javafile,"\tL%d:\n",iflabel1);
		} else_statement
	;
else_statement
	: ELSE statement
		{
		fprintf(javafile,"\tL%d:\n",iflabel2);
		}
	;

iteration_statement
	: WHILE 
		{
		fprintf(javafile,"\tL%d:\n",label);
		label++;
		}
		LP expression RP
		{
		fprintf(javafile,"\t\tifeq L%d\n",label);
		whilelabel=label;
		label++;
		}
		 statement
		{
		fprintf(javafile,"\t\tgoto L0\n");
		fprintf(javafile,"\tL%d:\n",whilelabel);
		printf("%s\n","Reducing to [iteration_statment]");}
	;

statement_list
	: statement
		{printf("%s\n","Reducing to [statment_list]");}
	| statement_list statement
		{printf("%s\n","Reducing to [statment_list]");}
	;

statement
	: simple_statment
		{printf("%s\n","Reducing to [statment]");}
	| block_statement
		{printf("%s\n","Reducing to [statment]");}
	| selection_statement 
		{printf("%s\n","Reducing to [statment]");}
	| else_statement
		{printf("%s\n","Reducing to [statment]");}
	| iteration_statement
		{printf("%s\n","Reducing to [statment]");}
	;


%%

void yyerror(const char *s)
{
	printf("%s\n",s);
}

int main()
{
	isAdd = false;
	scope = 0;
	storeNum =0;
	

	javafile = fopen("test.jasm","w");

	fprintf(javafile,"%s\n", "/*-------------------------------------------------*/");
	fprintf(javafile,"%s\n", "/*              Java Assembly Code                 */");
 	fprintf(javafile,"%s\n", "/*-------------------------------------------------*/");   	

	fprintf(javafile,"class test\n{\n");
	yyparse();
	printf("\n\n%s\n", "-----------------------------Symbol Table:-----------------------------");
	printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*s\n",10,"Identifier",10,"Type",10,"Belong",10,"Value",10,"Scope");
        dump();
	fprintf(javafile,"}\n");
	fclose(javafile);
	for(int i  = 0; i< sizeof(orderToFile)/sizeof(orderToFile[0]); i++){
		printf("%s",orderToFile[i]);
	}
	return 0 ;
}
