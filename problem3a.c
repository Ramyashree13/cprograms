#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int main()
{
	int n;
	printf("enter the number of strings\n");
	scanf("%d",&n);
	struct str string[n];
	input(n,string);
	return 0;
}

