#include<stdio.h>
struct str
{
	int len;
	char s[10];
};
void palin(int begin,int middle,int end,char s[]);
void input(int n,struct str string1[n])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the length of string\n");
		scanf("%d",&string1[i].len);
		printf("enter the string\n");
		scanf("%s",string1[i].s);
	}
}
void compute(int n,struct str string1[n])
{
	int middle,begin,end;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<string1[i].len;j++)
		{
			middle=((j)+(j+1)) / 2;
			begin=j;
			end=j+1;
			palin(begin,middle,end,string1[i].s);
		}
	}
}
void palin(int begin,int middle,int end,char s[])
{
	for(int i=begin;i<middle;i++)
	{
		if(s[begin] != s[end])
			break;
		end--;
		if(begin==middle)
			printf("is a palindrome\n");
	}
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














