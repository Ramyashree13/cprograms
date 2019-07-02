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
	float area;
	float len[3];
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
void compute(int n,struct rectangle a[n])
{

	int i,j;
	float smallest1=0,smallest2=0;
	for(i=0;i<n;i++)
	{
		a[i].len[0]= sqrt(((a[i].p[2].x) - (a[i].p[1].x)) * ((a[i].p[2].x) - (a[i].p[1].x)) + ((a[i].p[2].y)-(a[i].p[1].y)) * ((a[i].p[2].y) - (a[i].p[1].y)));
		a[i].len[1]= sqrt(((a[i].p[3].x) - (a[i].p[2].x)) * ((a[i].p[3].x) - (a[i].p[2].x)) + ((a[i].p[3].y)-(a[i].p[2].y)) * ((a[i].p[3].y) - (a[i].p[2].y)));
		a[i].len[2]= sqrt(((a[i].p[3].x) - (a[i].p[1].x)) * ((a[i].p[3].x) - (a[i].p[1].x)) + ((a[i].p[3].y)-(a[i].p[1].y)) * ((a[i].p[3].y) - (a[i].p[1].y)));
	}
	for(i=0;i<n;i++)
	{
	       	smallest(a[i].len[0],a[i].len[1],a[i].len[2],&smallest1,&smallest2);
		a[i].area = (smallest1) * (smallest2);
	}
	
}
void smallest(float len1,float len2,float len3,float *smallest1,float *smallest2)
{
	if(len1>len2 && len1>len3)
	{
		*smallest1=len2;
		*smallest2=len3;
	}
	else if(len2>len1 && len2>len3)
	{
		*smallest1=len1;
		*smallest2=len3;
	}
	else 
	{
		*smallest1=len1;
		*smallest2=len2;
	}
	
}

void output(int n,struct rectangle a[n])
{
	printf("the area of the %d rectangle/s are:\n",n);
	for(int i=0;i<n;i++)
		printf("%f\n",a[i].area);

}
int main()
{
	int n;
	printf("enter the number of rectangles you need to claculate the area\n");
	scanf("%d",&n);
	struct rectangle a[n];
	input(n,a);
	compute(n,a);
	output(n,a);
	return 0;
}


