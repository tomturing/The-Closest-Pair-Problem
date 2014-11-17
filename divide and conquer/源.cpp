#define _CRT_SECURE_NO_WARNINGS
#define min(x,y)(x>y?x:y)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct  points												//为什么要加类型说明Points
{
	int x;
	int y;
}P[1000],P1[1];
void getpoints()
{
	int i;
	srand((unsigned)time(NULL));
	for (i=0;i<1000;i++)
	{
		P[i].x=rand()%1000;
		P[i].y=rand()%1000;
	}
}
int partition(struct points *P,int low,int high)
{
	P1[0]=P[low];
	while (low<high)
	{
		while(low<high&&P[high].x>=P1[0].x)				   //自己没弄明白循环的是什么
		{
			high--;
		}
		P[low]=P[high];
		while(low<high&&P[low].x<=P1[0].x)
		{
			low++;
		}
		P[high]=P[low];
	}
	P[low]=P1[0];
	return low;
}
void  sortxofpoints(struct points *P,int low,int high)	   //为什么运行到这步数据的丢了？
{
	if (low>=high)
	return;
	int pivot=0;
	pivot=partition(P,low,high);
	sortxofpoints(P,low,pivot-1);
	sortxofpoints(P,pivot+1,high);
}
int d;
void dividepoints(struct points *P,int l,int r)
{
	int dl=0,dr=0;
	d=0;
	if (r-l>2)
	{
		dividepoints(P,l,r/2);
		dividepoints(P,r/2+1,r);
		dl=sqrt(((P[l].x-P[r/2].x)*(P[l].x-P[r/2].x)+(P[l].y-P[r/2].y)*(P[l].y-P[r/2].y))*1.0);
		dr=sqrt(((P[r/2+1].x-P[r].x)*(P[r/2].x-P[r].x)+(P[r/2+1].y-P[r].y)*(P[r/2+1].y-P[r].y))*1.0);
		d=min(dl,dr);
		if((P[r/2].x+d)>P[r/2+1].x)
		{
			if (P[r/2].y-d<P[r/2+1].y&&P[r/2].y+d>P[r/2+1].y)
			{
				d=sqrt(((P[r/2].x-P[r/2+1].x)*(P[r/2].x-P[r/2+1].x)+(P[r/2].y-P[r/2+1].y)*(P[r/2].y-P[r/2+1].y))*1.0);
			} 
		}
	}
}
void main()
{
	getpoints();
	sortxofpoints(P,0,999);
	/*FILE *fp=fopen("sortpoints.txt","w");
	for (int j=0;j<1000;j++)
	{
		fprintf(fp,"(%d,%d)\t",P[j].x,P[j].y);
		if ((j+1)/5==0)
		{
			fprintf(fp,"\n");
		}
	}
	fclose(fp);*/
	dividepoints(P,0,999);
	printf("%d",d);
}