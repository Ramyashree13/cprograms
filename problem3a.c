#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void palindrome(int begin,int end,char s[]);
//int memoryalloc(int m,int n,char *resultstr);
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
}
void compute(int n,struct str string[n])
{
	int p,begin,end;
//	char *resultstr;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<string[i].len;j++)
		{
			p=j;
			for(int k=j+1;k<(string[i].len);k++)
			{
				begin=p;
				end=k;
				palindrome(begin,end,string[i].s);
			}
		}
	}
}
void palindrome(int begin,int end,char s[])
{
	char d[10],a[10],res[20];
	int c=0,i,n;
	for( i=begin;i<=end;i++)
	{
		d[c]=s[i];
		c++;
	}
	d[c]=NULL;
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
			/*memoryalloc(strlen(s),strlen(a),resultstr);
			strcpy(*resultstr,a);
			printf("%s",*resultstr);*/
			printf("%d\t",begin+1);
			strcpy(res,a);
			printf("%s\n",res);

		}
	}
}
/*int memoryalloc(int m,int n,char *resultstr)
{

	resultstr=(char *)malloc(m * sizeof(char));
	for(int i=0;i<m;i++)
		resultstr=(char *) malloc(n * sizeof(char));
	return *resultstr;
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

