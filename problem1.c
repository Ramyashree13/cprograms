#include<stdio.h>
#include<math.h>
void smallest(float len1,float len2,float len3,float *smallest1,float *smallest2);
struct point
{
	float x;
	float y;
};
struct rectangle
{
	struct point p[3];
};
void input(int n,struct rectangle a[n])
{
	printf("enter the coordinates of rectangles\n");
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%f%f",&a[i].p[j].x,&a[i].p[j].y);
		}
	}
}
void compute(int n,struct rectangle a[n],float *res)
{

	float len1,len2,len3,p1,p2,p3,p4,p5,p6;
	float *smallest1=0,*smallest2=0;
	for(int i=0;i<n;i++)
	{
		p1= (a[i].p[2].x) - (a[i].p[1].x);
		p2= (a[i].p[3].x) - (a[i].p[2].x);
		p3= (a[i].p[3].x) - (a[i].p[1].x);
		p4=(a[i].p[2].y)  - (a[i].p[1].y);
		p5=(a[i].p[3].y) - (a[i].p[2].y);
		p6=(a[i].p[3].y) - (a[i].p[1].y);
		len1=sqrt((p1 * p1) + (p4 * p4));
		len2=sqrt((p2 * p2) + (p5 * p5));
		len3=sqrt((p3 * p3) + (p6 * p6));
		printf("%f\n%f\n%f\n",len1,len2,len3);
		smallest(len1,len2,len3,smallest1,smallest2);
		res[i] = (*smallest1) * (*smallest2);
	}
	printf("rectangles\n");
}
void smallest(float len1,float len2,float len3,float *smallest1,float *smallest2)
{
	if(len1>len2 && len1>len3)
	{
		*smallest1=len2;
		*smallest2=len3;
		printf("%f\n%f\n",*smallest1,*smallest2);
	}
	else if(len2>len1 && len2>len3)
	{
		*smallest1=len1;
		*smallest2=len3;
		printf("%f\n%f\n",*smallest1,*smallest2);
	}
	else 
	{
		*smallest1=len1;
		*smallest2=len2;
		printf("%f\n%f\n",*smallest1,*smallest2);
	}
}

void output(int n,float area[])
{
	printf("the area of the %d rectangles are:\n",n);
	for(int i=0;i<n;i++)
		printf("%f\n",area[i]);

}
int main()
{
	int n;
	printf("enter the number of rectangles you need to claculate the area\n");
	scanf("%d",&n);
	struct rectangle a[n];
	float area[n],*res;
	res=area;
	input(n,a);
	compute(n,a,res);
	output(n,area);
	return 0;
}


