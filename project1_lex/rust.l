%{
#include <stdio.h>
#include <ctype.h>
#define LIST		strcat(buf,yytext)
#define token(t)	{LIST; printf("<'%s'>\n",t);}
#define tokenId		{insert(yytext);LIST; printf("<%s:%s>\n","id",yytext);}
#define tokenInteger	{LIST; printf("<%s:%s>\n","integer",yytext);}
#define tokenReal	{LIST; printf("<%s:%s>\n","real", yytext);}
#define tokenBoolean	{LIST; printf("<%s:%s>\n","boolean",yytext);}
#define tokenString(t,s){LIST; printf("<%s:%s>\n","string",s);}
#define capitals(t)	{ for(int i = 0; i < strlen(t); i++){t[i] = toupper(t[i]);};printf("<%s>\n", t); }
#define keyword(t)	{LIST; capitals(t)}
#define MAX_LENGTH	256
int 	line_num = 1;
char 	buf[MAX_LENGTH];
char 	str[1000];
char 	Symbol_Table[MAX_LENGTH][MAX_LENGTH];

int Symbol_index = -1;

int insert(char s[]){
	for (int i = 0; i <= Symbol_index; i++)
	{
		if (strcmp(Symbol_Table[i] , s) == 0)
			{
				return i;
			}
				}
				Symbol_index++;
				
				strcpy(Symbol_Table[Symbol_index],s);
				
	return Symbol_index ;
}

int lookup(char s[]){
	for (int i = 0; i <= Symbol_index; i++)
	{
		if (strcmp(Symbol_Table[i] , s)==0)
		{
			printf("%d\n", i);
			return i;
		}
	}
	printf("%s\n", "Null");
	return 0;
}

int dump(){
	for (int i = 0; i <= Symbol_index; i++)
	{
		if (Symbol_Table[i] != '\0')
		{
			printf("%s\n", Symbol_Table[i] );
		}
	}
	return 0 ;
}

%}

%x	STATE_string
%x 	COMMET_Single
%x	COMMET_Multi
digital      [0-9]
integer      {digital}+
real         -?(([0-9]+)([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
letter       [a-zA-Z]
identifier   {letter}+
whitespace   [ \t]+
%%
"bool"				|
"break"				|
"char"				|
"continue"			|
"do"				|
"else"				|
"enum"				|
"extern"			|
"float"				|
"for"				|
"fn"				|
"if"				|
"in"				|
"int"				|
"let"				|
"loop"				|
"match"				|
"mut"				|
"print"				|
"println"			|
"pub"				|
"return"			|
"self"				|
"static"			|
"str"				|
"struct"			|
"use"				|
"where"				|
"while"				{keyword(yytext);}
"false"				{tokenBoolean;}
"true"				{tokenBoolean;}

","				{token(",");}
":"				{token(":");}
";"				{token(";");}
"("				{token("(");}
")"				{token(")");}
"["				{token("[");}
"]"				{token("]");}
"{"				{token("{");}
"}"				{token("}");}

"+"				{token("+");}
"-"				{token("-");}
"*"				{token("*");}
"/"				{token("/");}
"++"				{token("++");}
"--"				{token("--");}
"%"				{token("%");}
"<"				{token("<");}
"<="				{token("<=");}
">="				{token(">=");}
">"				{token(">");}
"=="				{token("==");}
"!="				{token("!=");}
"&&"				{token("&&");}
"||"				{token("||");}
"!"				{token("!");}
"="				{token("=");}
"+="				{token("+=");}
"-="				{token("-=");}
"*="				{token("*=");}
"/="				{token("/=");}
{identifier}  			{tokenId;}
{integer}     			{tokenInteger;}
{real}        			{tokenReal;}
\"		{
                    LIST;
                    BEGIN STATE_string;
                  }

<STATE_string>\"  {
                      char c = input();
                      if(c=='\"')
                    {
                      LIST;
                      strcat(buf,"\"");
                      strcat(str,yytext);
                    }
                      else
                    {
                      tokenString("string",str);
                      unput(c);
                      str[0] = '\0';
                      BEGIN 0;
                    }
                    }
<STATE_string>.     {
                      LIST;
                      strcat(str,yytext);
                    }
"//"          		{
               		LIST;
                	BEGIN COMMET_Single;
            		}
<COMMET_Single>\n 	{
                      LIST;
                      printf("%d: %s", line_num++, buf);
                      buf[0] = '\0';
                      BEGIN 0;
                    }
<COMMET_Single>.    {
                      LIST;
                    }
"/*"               {
                      LIST;
                      BEGIN COMMET_Multi;
                    }
<COMMET_Multi>\n {
                      LIST;
                      printf("%d: %s", line_num++, buf);
                      buf[0] = '\0';
                     	}
<COMMET_Multi>"*/"	{
                      		LIST;
                      		BEGIN 0;
                    	}
<COMMET_Multi>.     {
                      		LIST;
                    	}
\n 			  		{
        			LIST;
        			printf("%d: %s", line_num++, buf);
        			buf[0] = '\0';
        			}
[ \t]*  		{LIST;}
%%

int main(){
yylex();
if (buf[0] != '\0')
{
	printf("%d: %s", line_num++, buf);
}
printf("\n%s\n", "Symbol Table:");
dump();
}
int yywrap()
{
return 1;
}
