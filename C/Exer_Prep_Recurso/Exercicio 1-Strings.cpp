#include<stdio.h>

int tamanhostring(char s[])
{
int i;
for(i=0;s[i]!='\0';i++);
return i;
}
int m_t_string(char s[])
{
int i;	
	for(i=0;s[i]!='\0';i++)
	{
		printf("A string tem o Tamanho %d",s[i]);	
	}
	
}

int main()
{
char s;
int i;
	printf("String:\n");
	scanf("%s",&s);
m_t_string;
tamanhostring;
	
}
