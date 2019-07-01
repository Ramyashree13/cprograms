#include<stdio.h>
struct str
{
	int len;
	char s[10];
};
void input(int n,struct str string1[n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("enter the length of string\n");
		scanf("%d",&string1[i].len);
		printf("enter the string\n");
		scanf("%s",string1[i].s);
	}
}
void compute()
{

}
	
int main()
{
	int n,i;
	printf("enter the number of strings\n");
	scanf("%d",&n);
	struct str string1[n];
	input(n,string1);
	return 0;
}














