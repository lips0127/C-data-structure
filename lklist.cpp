/*
单链表的创建，查找，删除，以及插入;
整形变量版;
创建时间:2019/10/02. 
完成时间:2019/10/03. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


#define m 10

typedef struct lklist
{
	int date;
	struct lklist *next;
}lklist;

void createList1(lklist *&L,int a[],int n)
{
	//TODO:使用尾插法:
	lklist *s,*r;
	L = (lklist*)malloc(sizeof(lklist));
	L->date = NULL;
	L->next = NULL;//头结点;
	r = L;
	for(int i=0;i<n;i++)
	{
		s = (lklist*)malloc(sizeof(lklist));
		s->date = a[i];
		r->next = s;
//		r = r->next;
		r = s;
    }
    r->next = NULL;
    
}

void createList2(lklist *&L,int a[],int)
{
	//TODO 使用头插法:
	lklist *s/*,*h*/;
	L = (lklist*)malloc(sizeof(lklist));
	L->date = NULL;
	L->next = NULL;
//	h = L;
	for(int i=0;i<m;++i)
	{
		s = (lklist*)malloc(sizeof(lklist));
		s->date = a[i];
		s->next = L->next;
		L->next = s;			
	}
}

void outputList(lklist *L)
{	
	printf("当前链表date域情况:\n");
	lklist *r0;
	r0  = L;
	while(L)
	{	if(r0->next != NULL)
		printf("%d,",r0->date);
		
		else 
		{ 
		printf("%d.\n",r0->date);	
		break;
		}	
		r0 = r0->next; 
	}

//	printf("\n");
	printf("输出结束.\n");
}

void deleteElem(lklist *&L)
{	
	lklist *r0;
	int num;
	int flag1 = 0;
	printf("输入你想删除的数字.\n");
	scanf("%d",&num);
	r0 = L;	
	while(r0->next != NULL) 
	{	
	if(r0->next->date  == num)
		{
			r0->next = r0->next->next;
			printf("delete complete.\n");
			flag1 = 1;	
			break;					
		}
		r0 = r0->next;		
	}
	if(flag1 == 0)
	printf("你想要删除的数字不存在.\n");
	
	
}
void insertNum(lklist *&L)
{
	//TODO:	
	lklist *s0,*n;
	int num;
	printf("请输入你想要插入的数字:\n");
	scanf("%d",&num);
	srand((unsigned)time(NULL));
	int i = rand()%10;
	printf("为你随机生成一个链表位置%d用于插入:\n",i);
	s0 = L;
	for(i+1;i>=0;i--)
	{
		s0 = s0->next; 
	}
	n = (lklist*)malloc(sizeof(lklist));
	n->date = num;
	n->next = s0->next;
	s0->next = n;		
}

/*void deleteList(lklist *&L)
{	
	lklist *q;
	q = L;
	int denum;
	printf("输入你想删除的数字.\n");
	scanf("%d",&denum);	
	if(findElem(q,denum) == 0)
	printf("你想要删除的数字不存在.\n");
	else if(findElem(q,denum) == 1)
	{
		lklist *m;
		whlie(q)
		{
			
		}	
	}
	}	
*/	
	
	


int main()
{	

	int a[m];
	int select;
	lklist *q;
	printf("******链表的创建删除以及插入*******\n");
	srand((unsigned)time(NULL));
	printf("随机数组情况如下：\n");
	for(int i=0;i<m;i++)
	{	a[i] = rand()%101;//随机生成0-100;
		if(i != 9)
		printf("%d,",a[i]);	
		else
		printf("%d.",a[i]);	
	}
	printf("\n");
	
	printf("你想使用哪种方法构建链表,尾插法输入1,头插法输入2:\n");
	scanf("%d",&select);
	if(select == 1)
	createList1(q,a,m);
	else if(select ==2)
	createList2(q,a,m);
	outputList(q);
	deleteElem(q);
	outputList(q);
	insertNum(q);
	outputList(q);
	
	return 0;
}































