#include<stdio.h>
#include<math.h>
void smallest(float len1,float len2,float len3,float *smallest1,float *smallest2);
struct rectangle distance(int n,struct rectangle a[n]);
struct point
{
	float x;
	float y;
};
struct rectangle
{
	float dis[6];
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
void compute(int n,struct rectangle a[n],float *res)
{

	int i,j;
	float smallest1=0,smallest2=0;
	distance(n,a);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i].len[j]= ((a[i].dis[0]) * (a[i].dis[0])) + ((a[i].dis[3]) * (a[i].dis[3]));
			a[i].len[j]= ((a[i].dis[1]) * (a[i].dis[1])) + ((a[i].dis[4]) * (a[i].dis[4]));
			a[i].len[j]= ((a[i].dis[2]) * (a[i].dis[2])) + ((a[i].dis[5]) * (a[i].dis[5]));
		}
	}
	for(i=0;i<n;i++)
	{
	       	smallest(a[i].len[0],a[i].len[1],a[i].len[2],&smallest1,&smallest2);
		res[i] = (smallest1) * (smallest2);
	}
	
}
struct rectangle distance(int n,struct rectangle a[n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			a[i].dis[j]=( a[i].p[3].x) - (a[i].p[1].x);
			a[i].dis[j]= (a[i].p[3].x) - (a[i].p[2].x);
			a[i].dis[j]= (a[i].p[3].x) - (a[i].p[1].x);
			a[i].dis[j]=(a[i].p[2].y)  - (a[i].p[1].y);
			a[i].dis[j]=(a[i].p[3].y) - (a[i].p[2].y);
			a[i].dis[j]=(a[i].p[3].y) - (a[i].p[1].y);
		}
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

void output(int n,float area[])
{
	printf("the area of the %d rectangle/s are:\n",n);
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


