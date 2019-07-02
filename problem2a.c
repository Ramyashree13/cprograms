#include<stdio.h>
struct egyptionfraction
{
	int num;
	int den;
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
	printf("enter the numbers\n");
	for(int i=0;i<n;i++)
		scanf("%d",&f[i].den);
}
void compute(int n,struct egyptionfraction f[n],struct egyptionfraction *sum)
{
	int product,i,up,g1,n1;
	for(i=0;i<n;i++)
	{
		product = product * f[i].den;
	}
	for(i=0;i<n;i++)
	{
		n1=product / f[i].den;
		up=up + n1;
	}
	g1=gcd(up,product);
	sum->num= up/g1;
	sum->den=product/g1;
}

void output(int n,struct egyptionfraction f[n],struct egyptionfraction sum)
{
	for(int i=0;i<n;i++)
		f[i].num=1;
        for (int i=0;i<n;i++)
	{
                printf(" %d/%d",f[i].num,f[i].den);
		printf("+");
	}
        printf("=%d/%d",sum.num,sum.den);
}


int main()
{
        int n;
        struct egyptionfraction sum,*s;
	s=&sum;
        printf("enter the array size");
        scanf("%d",&n);
        struct egyptionfraction a[n];
        input(n,a);
        compute(n,a,s);
        output(n,a,sum);
        return 0;

}
