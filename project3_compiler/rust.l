%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "union.h"
#include "rust.tab.h"
#define LIST		strcat(buf,yytext)
#define token(t)	{LIST; printf("<'%s'>\n",yytext);}
#define tokenId		{LIST; printf("<%s:%s>\n","id",yytext);}
#define tokenInteger	{LIST; printf("<%s:%s>\n","int",yytext);}
#define tokenFloat(t)   {LIST; printf("<%s:%s>\n","float",yytext);}
#define tokenBoolean	{LIST; printf("<%s:%s>\n","boolean",yytext);}
#define tokenString(s)  {LIST; printf("<%s:%s>\n","string",str);}
#define capitals(t)	{ for(int i = 0; i < strlen(t); i++){t[i] = toupper(t[i]);};printf("<%s>\n", t);}
#define keyword(t)	{LIST; capitals(t);}
#define MAX_LENGTH	256
int 	line_num = 1;
char 	buf[MAX_LENGTH];
char 	str[1000];

int yywarp(void);
int yylex(void);

%}

%x	STATE_string
%x 	COMMET_Single
%x	COMMET_Multi
digital      [0-9]
integer      {digital}+
float         -?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
letter       [a-zA-Z]
identifier   {letter}+([a-zA-Z]|{digital})*
whitespace   [ \t]+
%%
"bool"		{keyword(yytext);return BOOL;}
"break"		{keyword(yytext);return BREAK;}
"char"		{keyword(yytext);return CHAR;}
"continue"	{keyword(yytext);return CONTINUE;}
"do"		{keyword(yytext);return DO;}
"else"		{keyword(yytext);return ELSE;}
"enum"		{keyword(yytext);return ENUM;}
"extern"	{keyword(yytext);return EXTERN;}
"float"		{keyword(yytext);return FLOAT;}
"for"		{keyword(yytext);return FOR;}
"fn"		{keyword(yytext);return FN;}
"if"		{keyword(yytext);return IF;}
"in"		{keyword(yytext);return IN;}
"int"		{keyword(yytext);return INT;}
"let"		{keyword(yytext);return LET;}
"loop"		{keyword(yytext);return LOOP;}
"match"		{keyword(yytext);return MATCH;}
"mut"		{keyword(yytext);return MUT;}
"print"		{keyword(yytext);return PRINT;}
"println"	{keyword(yytext);return PRINTLN;}
"pub"		{keyword(yytext);return PUB;}
"return"	{keyword(yytext);return RETURN;}
"self"		{keyword(yytext);return SELF;}
"static"	{keyword(yytext);return STATIC;}
"str"		{keyword(yytext);return STR;}
"struct"	{keyword(yytext);return STRUCT;}
"use"		{keyword(yytext);return USE;}
"where"		{keyword(yytext);return WHERE;}
"while"		{keyword(yytext);return WHILE;}
"false"		{tokenBoolean; yylval.m_nInt = 0; return FALSEVAL;}
"true"		{tokenBoolean; yylval.m_nInt = 1;return TRUEVAL;}

","       {token(",");return COMMA;}
":"       {token(":");return COLON;}
";"       {token(";");return SEMICOLON;}
"("       {token("(");return LP;}
")"       {token(")");return RP;}
"["       {token("[");return LSB;}
"]"       {token("]");return RSB;}
"{"       {token("{");return LCB;}
"}"       {token("}");return RCB;}

"+"       {token("+");return PLUS;}
"-"       {token("-");return MINUS;}
"*"       {token("*");return MULTIPLY;}
"/"       {token("/");return DIVIDE;}
"++"      {token("++");return INCREMENT;}
"--"      {token("--");return DECREMENT;}
"%"       {token("%");return MODULUS;}
"<"       {token("<");return LT;}
"<="      {token("<=");return LE;}
">="      {token(">=");return GE;}
">"       {token(">");return GT;}
"=="      {token("==");return EQ;}
"!="      {token("!=");return NE;}
"&&"      {token("&&");return AND;}
"||"      {token("||");return OR;}
"!"       {token("!");return NOR;}
"="       {token("=");return EQUALS;}
"+="      {token("+=");return PLUSEQUALS;}
"-="      {token("-=");return MINUSEQUALS;}
"*="      {token("*=");return MULTIPLYEQUALS;}
"/="      {token("/=");return DIVIDEEQUALS;}
{identifier}  {
              strcpy(yylval.m_sId , yytext);
              tokenId(yylval.m_sId);
              return IDENTIFIER;
              }
{integer} 	{
              yylval.m_nInt=atoi(yytext);
              tokenInteger(yylval.m_nInt);
              
              return INTEGERVAL;
              }
{float}       {
              yylval.m_float=atof(yytext);
              tokenFloat(yylval.m_float);
              return FLOATVAL;
              }
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
                      tokenString(str);
                      unput(c);
                      str[0] = '\0';
                      BEGIN 0;
		      return STRINGVAL;
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


int yywrap(void)
{
    puts("-----the file is end");
    return 1;
}
