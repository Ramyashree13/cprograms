#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int palindrome(int begin,int end,char d[],struct str string,int n,char *resstr);
struct str
{
	int len;
	char *s;
	int pos;
	int a[10];
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
}
void compute(int n,struct str string[n])
{
	int p,begin,end,c=0,m;
	char d[10],*resstr[10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<string[i].len;j++)
		{
			p=j;
			for(int k=j+1;k<(string[i].len);k++)
			{
				begin=p;
				end=k;
				for( m=begin;m<=end;m++)
				{
					d[c]=string[i].s[m];
					c++;
				}
				d[c]=NULL;
				palindrome(begin,end,d,string,n,resstr);
				printf("%s",resstr);
				c=0;
				d[c]='\0';
			}
		}
	}
}
int palindrome(int begin,int end,char d[],struct str string,int n,char *resstr)
{
	char a[10],res[20];
	int i,n;
	/*for( i=begin;i<=end;i++)
	{
		d[c]=s[i];
		c++;
	}
	d[c]=NULL;*/
	n=strlen(d);
	for(int i=0;i<n;i++)
	{
		a[(n-1)-i]=d[i];
	}
	a[n]=NULL;
	if(strcmp(a,d)==0)
	{
		if(strlen(a)>=3)
		{
			printf("%d\t",begin+1);
			strcpy(resstr,a);
			printf("%s\n",resstr);
			return resstr;

		}
	}
	return 0;
}
/*void output()
{
	printf("%d\t %s\n",)
}*/
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

