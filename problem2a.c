#include<stdio.h>
#include<stdlib.h>
//int *p=(int *)malloc(100 * sizeof(int));
struct sum
{
	int num;
	int den;
};
struct egyptionfraction
{
	int m;
	int den[100];
	struct sum s;
};
int gcd(int a,int b)
{
        int c;
        while(c=a%b)
        {
                a=b;
                b=c;
        }
        return b;
}
void input(int n,struct egyptionfraction f[n])
{
	for(int i=0;i<n;i++)
	{
		printf("enter the number of series of unit frcations\n");
		scanf("%d",&f[i].m);
		for(int j=0;j<f[i].m;j++)
		{
			printf("enter the %d egyption fraction\n",j+1);
			scanf("%d",&f[i].den[j]);
		}
	}
}
void compute(int n,int num1[],int num2[],struct egyptionfraction f[n])
{
/*	int product[10],i,up[10],g1[n],n1[10];
	for(i=0;i<n;i++)
	{
		for(int j=0;j<f[i].m;j++)
		{
			product[i] = (product[j]) * (f[i].den[j]);
			printf("%d\n",product[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(int j=0;j<f[i].m;j++)
		{
			n1[j]=product[i] / f[i].den[j];
			up[i]=up[i] + n1[j];
		}
	}
	for(int i=0;i<n;i++)
	{
		g1[i]=gcd(up[i],product[i]);
		num1[i]= up[i]/g1[i];
		num2[i]=product[i]/g1[i];
	}*/

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<f[i].m;j++)
		{
			product=product * f[i].den[j];
			n1=product/f[i].den[j];
			up=up + n1;
			g1=gcd(up,product);
			f[i].s.num=up/g1;
			f[i].s.den=product/g1;
		}
	}
}

void output(int n,int num1[],int num2[],struct egyptionfraction f[n])
{
	int num[10];
	//for(int i=0;i<n;i++)
		//num[i]=1;
        for (int i=0;i<n;i++)
	{
		for(int j=0;j<f[i].m;j++)
		{
                	printf(" 1/%d+",f[i].den[j]);
		}
	        printf("=%d/%d",num1[i],num2[i]);
	
	}
}


int main()
{
        int n,num1[10],num2[10];
        printf("enter the array size");
        scanf("%d",&n);
        struct egyptionfraction a[n];
        input(n,a);
	printf("goto compute\n");
        compute(n,num1,num2,a);
        output(n,num1,num2,a);
        return 0;

}
