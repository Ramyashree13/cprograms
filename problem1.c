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
void input(int n,struct rectangle a[n])
{
	printf("enter the coordinates of rectangles\n");
	for(int i=0;i<n;i++)
		scanf("%f%f%f%f%f%f",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].x3,&a[i].y3);
	for(int i=0;i<n;i++)
		printf("%f%f",a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[i].x3,a[i].y3);
}
void compute(int n,struct rectangle a[n])
{

	int len1[n],len2[n],len3[n],len4[n],p1[n],p2[n];
	for(int i=0;i<n;i++)
		len1[i]= (a[i].x2) - (a[i].x1);
	for(int i=0;i<n;i++)
		len2[i]= (a[i].x3) - (a[i].x2);
	
	for(int i=0;i<n;i++)
		len3[i]=(a[i].y2) - (a[i].y1);
	for(int i=0;i<n;i++)
		len4[i]=(a[i].y3) - (a[i].y2);
	for(i=0;i<n;i++)
		p1[i]=sqrt((len1[i] * len1[i]) + (len3[i] * len3[i]));
	for(i=0;i<n;i++)
		p2[i]=sqrt((len2[i] * len2[i]) + (len4[i] * len4[i]));




}
int main()
{
	int n;
	printf("enter the number of rectangles you need to claculate the area\n");
	scanf("%d",&n);
	struct rectangle a[n];
	input(n,a);
	return 0;
}


