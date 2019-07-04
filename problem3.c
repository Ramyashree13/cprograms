#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str
{
	int len;
	char *s;
};
void palin(int begin,int middle,int end,char s[]);
void input(int n,struct str string1[n])
{
	int i,a;
	for(i=0;i<n;i++)
	{
		printf("enter the length of string\n");
		scanf("%d",&string1[i].len);
		string1[i].s=(char *)malloc(string1[i].len * sizeof(char));
		printf("enter the string\n");
		scanf("%s",string1[i].s);
	}

}		
void compute(int n,struct str string1[n])
{
	int middle,begin,end,p,k;
	char s1[5];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<string1[i].len;j++)
		{
			p=j;
			for(k=1;k<string1[i].len;k++)
			{	
				middle=((p)+(k)) / 2;
			//	printf("m=%d\n",middle);
				begin=p;	
				end=k;
				palin(begin,middle,end,string1[i].s);
//				printf("%s",s1);
			}
		}
	}
}
void palin(int begin,int middle,int end,char s[])
{
//	printf("%d\n",middle);
	for(int i=begin;i<end;i++)
	{
	//	printf("%s",s[i]);
		if(s[i] != s[end])
		{
			break;
		}
		end--;
	}
	//if(begin==middle)
		printf("string is a palindrome\n");
	
}
	
int main()
{
	int n;
	printf("enter the number of strings\n");
	scanf("%d",&n);
	struct str string1[n];
	input(n,string1);
	compute(n,string1);
	return 0;
}














