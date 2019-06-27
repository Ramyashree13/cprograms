#include<stdio.h>
#include<math.h>
struct coordinates
{
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
};
struct rectangle
{
	float point1;
	float point2;
	float point3;
	struct coordinates p;
};
void input(int n,struct rectangle a[n])
{
	printf("enter the coordinates of rectangles\n");
	for(int i=0;i<n;i++)
		scanf("%f%f%f%f%f%f",&a[i].p.x1,&a[i].p.y1,&a[i].p.x2,&a[i].p.y2,&a[i].p.x3,&a[i].p.y3);
	for(int i=0;i<n;i++)
		printf("%f\n%f\n%f\n%f\n%f\n%f\n",a[i].p.x1,a[i].p.y1,a[i].p.x2,a[i].p.y2,a[i].p.x3,a[i].p.y3);
}
void compute(int n,struct rectangle a[n])
{

	float len1[n],len2[n],len3[n],len4[n],p1[n],p2[n],area[n];
	for(int i=0;i<n;i++)
		len1[i]= (a[i].p.x2) - (a[i].p.x1);
	for(int i=0;i<n;i++)
		len2[i]= (a[i].p.x3) - (a[i].p.x2);
	
	for(int i=0;i<n;i++)
		len3[i]=(a[i].p.y2) - (a[i].p.y1);
	for(int i=0;i<n;i++)
		len4[i]=(a[i].p.y3) - (a[i].p.y2);
	for(int i=0;i<n;i++)
		p1[i]=sqrt((len1[i] * len1[i]) + (len3[i] * len3[i]));
	for(int i=0;i<n;i++)
		p2[i]=sqrt((len2[i] * len2[i]) + (len4[i] * len4[i]));
	for(int i=0;i<n;i++)
		area[i]= p1[i] * p2[i];
	for(int i=0;i<n;i++)
		printf("%f",area[i]);
}
int main()
{
	int n;
	printf("enter the number of rectangles you need to claculate the area\n");
	scanf("%d",&n);
	struct rectangle a[n];
	input(n,a);
	compute(n,a);
	return 0;
}


