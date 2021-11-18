/*
快速排序. 
创建时间:2019/10/08
完成时间:2019/10/09 23:10
相关链接: https://www.bilibili.com/video/av38482542
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define m 15
#define maxfanwei 100
typedef struct lklist
{
	int a[m];
	int length;
	
}lklist;
void fprintf(lklist *q);
int Qsort(lklist *&q,int low,int high);
int Partition(lklist *&q,int low,int high);

int main()
{	
	srand((unsigned)time(NULL));
	lklist *L;
	L = (lklist*)malloc(sizeof(lklist));
	printf("生成顺序表:\n");
	L->a[0] = NULL;		
	for(int i=1;i<m;i++)
	{
		L->a[i] = rand()%(maxfanwei);		
	}
	L->length = m;
	printf("%d\n",L->length);
	fprintf(L);
	Qsort(L,1,L->length-1);
	printf("*****************\n");
	fprintf(L);
}

//打印数组元素. 
void fprintf(lklist *q)
{		
	for(int i =0;i<q->length;i++)
	{
		if(i<q->length-1)
		printf("q->a[%d]=%d,",i,q->a[i]);
		else if(i = q->length-1)
		printf("q->a[%d]=%d.\n",i,q->a[i]);	
	}
}

int Qsort(lklist *&q,int low,int high)//low = 1;high = q->length-1;
{	
	int pivoloc;
	if(low<high)
	{ 	
		pivoloc = Partition(q,low,high);
		Qsort(q,low,pivoloc-1);
		Qsort(q,pivoloc+1,high);
	}
//	q->a[0] = NULL;
}

int Partition(lklist *&q,int low,int high)
{

		q->a[0] = q->a[low];//这一步是子表递归的关键
		int pivokey = q->a[low];
		while(low<high)
	{	
		while(low<high && q->a[high] >= pivokey)
		high--;
		q->a[low] = q->a[high];
		while(low<high && q->a[low] <= pivokey)
		low++;
		q->a[high] = q->a[low];
	}
	q->a[low] = q->a[0];
	q->a[0] = NULL;
	return low;
}











































