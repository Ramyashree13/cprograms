#include<stdio.h>
#include<stdlib.h>
struct sum
{
	int num1;
	int num2;
};
struct egyptionfraction
{
	int m;
	int *den;
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

	//f->den=(int *)malloc(100 *(sizeof(int)));
	for(int i=0;i<n;i++)
	{
		printf("enter the number of series of unit frcations\n");
		scanf("%d",&f[i].m);
		f[i].den=(int *)malloc(100 *(sizeof(int)));
		for(int j=0;j<f[i].m;j++)
		{
			printf("enter the %d egyption fraction\n",j+1);
			scanf("%d",&f[i].den[j]);
		}
	}

}
void compute(int n,struct egyptionfraction f[n])
{
	int i,product,up,g1,n1;
	for( i=0;i<n;i++)
	{
		product=1;
		up=0;
		n1=0;
		for(int j=0;j<f[i].m;j++)
		{
			product=(product) * (f[i].den[j]);
		}
		for(int j=0;j<f[i].m;j++)
		{
			n1=product/(f[i].den[j]);
			up=up + n1;
		}
		g1=gcd(up,product);
		f[i].s.num1=up/g1;
		f[i].s.num2=product/g1;
	}

}

void output(int n,struct egyptionfraction f[n])
{
        for (int i=0;i<n;i++)
	{
		for(int j=0;j<f[i].m;j++)
		{
                	printf(" 1/%d",f[i].den[j]);
			if(j==(f[i].m-1))
				break;
			printf("+");
		}
	        printf("=%d/%d\n",f[i].s.num1,f[i].s.num2);
		printf("\n");
	}
}


int main()
{
        int n;
        printf("enter the array size");
        scanf("%d",&n);
        struct egyptionfraction a[n];
        input(n,a);
        compute(n,a);
        output(n,a);
        return 0;

}
