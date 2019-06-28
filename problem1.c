#include<stdio.h>
#include<math.h>
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
	for(int i=0;i<n;i++)
	{	
		for(int j=1;j<=3;j++)
		{
			printf("%f\n%f\n",a[i].p[j].x,a[i].p[j].y);
		}
	}
}
void compute(int n,struct rectangle a[n],float *res)
{

	float len1[n],len2[n],len3[n],len4[n],p1[n],p2[n];

	for(int i=0;i<n;i++)
		len1[i]= (a[i].p[2].x) - (a[i].p[1].x);
	for(int i=0;i<n;i++)
		len2[i]= (a[i].p[3].x) - (a[i].p[2].x);
	
	for(int i=0;i<n;i++)
		len3[i]=(a[i].p[2].y) - (a[i].p[1].y);
	for(int i=0;i<n;i++)
		len4[i]=(a[i].p[3].y) - (a[i].p[2].y);
	for(int i=0;i<n;i++)
		p1[i]=sqrt((len1[i] * len1[i]) + (len3[i] * len3[i]));
	for(int i=0;i<n;i++)
		p2[i]=sqrt((len2[i] * len2[i]) + (len4[i] * len4[i]));
	for(int i=0;i<n;i++)
		res[i]= p1[i] * p2[i];
	for(int i=0;i<n;i++)
		printf("%f",res[i]);
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
	struct rectangle rect[n];
	float area[n],*res;
	res=area;
	input(n,rect);
	compute(n,rect,res);
	output(n,area);
	return 0;
}


