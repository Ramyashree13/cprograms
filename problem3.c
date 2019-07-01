#include<stdio.h>
void input(int n,char s[],int len[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("enter the length of the string");
		scanf("%d",&len[i]);
		s[len[i]];
		scanf("%s",s);
	}
	printf("strings\n");
	for(i=0;i<n;i++)
		printf("%s",s[i]);
}
	
int main()
{
	int n,i;
	printf("enter the number of strings\n");
	scanf("%d",&n);
	char str[10];
	int len[n];
	//s=str;
	input(n,str,len);
/*	printf("strings\n");
	for(i=0;i<n;i++)
		printf("%s",s);*/
	return 0;
}














