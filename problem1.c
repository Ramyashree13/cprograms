#include<stdio.h>
struct rectangle
{
	float x;
	float y;
};
void input(int n,struct rectangle a[n])
{
	printf("enter the coordinates of rectangles\n");
	for(int i=0;i<n;i++)
		scanf("%f%f",&a[i].x,&a[i].y);
	for(int i=0;i<n;i++)
		printf("%f%f",a[i].x,a[i].y);
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

