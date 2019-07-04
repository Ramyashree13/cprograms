#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void palin(int begin,int end,char s[]);
struct str
{
	int len;
	char *s;
};
void input(int n,struct str string[n])
{
	
	for(int i=0;i<n;i++)
	{
		printf("enter the lengt of string\n");
		scanf("%d",&string[i].len);
		string[i].s=(char *)malloc(string[i].len * sizeof(char));
		printf("enter the string\n");
		scanf("%s",string[i].s);
	}
	for(int i=0;i<n;i++)
		//for(int j=0;j<string[i].len;j++)
			printf("%s",string[i].s);


}
void compute(int n,struct str string[n])
{
	int p,begin,end;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<string[i].len;j++)
		{
			p=j;
			for(int k=1;k<string[i].len;k++)
			{
				begin=p;
				end=k;
				palin(begin,end,string[i].s);
			}
		}
	}
}
void palin(int begin,int end,char s[])
{
	char d[10],a[10],n;
	int c=0;
	for(int i=begin;i<end;i++)
	{
		d[c]=s[i];
		c++;
	}
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		a[n-i]=s[i];
	}
	if(strcmp(a,d)==0)
		printf("palindrome");
	
	printf("%s\n",d);
}

int main()
{
	int n;
	printf("enter the number of strings\n");
	scanf("%d",&n);
	struct str string[n];
	input(n,string);
	compute(n,string);
	return 0;
}

