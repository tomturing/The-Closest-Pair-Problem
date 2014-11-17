#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>
/*void getpoints()
{
	int i;
	struct point
	{
		int x;
		int y;
	}P[1000];
	srand((unsigned)time(NULL));
	for (i=0;i<1000;i++)
	{
		P[i].x=rand()%1000+99;
		P[i].y=rand()%1000+99;
	}
	for (i=0;i<1000;i++)
	{
		printf("(%d,%d)\t",P[i].x,P[i].y);
		if ((i+1)%5==0)
		{
			printf("\n");
		}
	}
}*/
struct points
{
	int x;
	int y;
}P[1000];
int i;
FILE *fp=fopen("result.txt","w");
void getpoints()
{
	srand((unsigned)time(NULL));
	for (i=0;i<1000;i++)
	{
		P[i].x=rand()%1000+99;
		P[i].y=rand()%1000+99;
	}
	for (i=0;i<1000;i++)
	{
		fprintf(fp,"(%d,%d)\t",P[i].x,P[i].y);
		if ((i+1)%5==0)
		{
			fprintf(fp,"\n");
		}
	}
}
	/*int dmin=INT_MAX,d=0;
	int j;
	int index1=0,index2=0;
	for (j=0;j<999;j++)
	{
		for (i=j+1;i<1000;i++)
		{
			d=sqrt(((P[i].x-P[j].x)^2+(P[i].y-P[j].y)^2)*1.0);
			if(d<dmin)
			{
				dmin=d;
				index1=i,
				index2=j;
			}
		}
	}
	fprintf(fp,"%d\n",d);
	fprintf(fp,"%d\n",dmin);
	fprintf(fp,"i=%d,j=%d\n",index1,index2);
	fprintf(fp,"(%d,%d),(%d,%d)\n",P[i].x,P[i].y,P[j].x,P[j].y);
	*/
void bruteforceclosetspoints(struct points *P)											  //P[1000]怎么引用在另一个函数中？
{
	int dmin=INT_MAX,d=0;
	int j;
	int index1=0,index2=0;
	for (j=0;j<999;j++)																	  //j 必须要溢出一位才能跳出循环
	{
		for (i=j+1;i<1000;i++)															  //
		{
			d=sqrt(((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y))*1.0);//平方怎么表示？
			if(d<dmin)
			{
				dmin=d;
				index1=i,
					index2=j;
			}
		}
	}
	fprintf(fp,"最后两点的距离：%d\n",d);																 //最后两个点的距离
	fprintf(fp,"最短距离：%d\n",dmin);
	fprintf(fp,"点在数组中的位置：i=%d,j=%d\n",index1,index2);
	fprintf(fp,"点的坐标：(%d,%d),(%d,%d)\n",P[index1].x,P[index1].y,P[index2].x,P[index2].y);	 //注意变量的不同，明确自己想要什么
	//fprintf(fp,"(%d,%d),(%d,%d)\n",P[i].x,P[i].y,P[j].x,P[j].y);						 也正是因为i=1000,j=999才分别跳出自己的循环
}
void main()
{
	getpoints();
	bruteforceclosetspoints(P);
}