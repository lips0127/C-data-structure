/*
������Ĵ��������ң�ɾ�����Լ�����;
���α�����;
����ʱ��:2019/10/02. 
���ʱ��:2019/10/03. 
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
	//TODO:ʹ��β�巨:
	lklist *s,*r;
	L = (lklist*)malloc(sizeof(lklist));
	L->date = NULL;
	L->next = NULL;//ͷ���;
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
	//TODO ʹ��ͷ�巨:
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
	printf("��ǰ����date�����:\n");
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
	printf("�������.\n");
}

void deleteElem(lklist *&L)
{	
	lklist *r0;
	int num;
	int flag1 = 0;
	printf("��������ɾ��������.\n");
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
	printf("����Ҫɾ�������ֲ�����.\n");
	
	
}
void insertNum(lklist *&L)
{
	//TODO:	
	lklist *s0,*n;
	int num;
	printf("����������Ҫ���������:\n");
	scanf("%d",&num);
	srand((unsigned)time(NULL));
	int i = rand()%10;
	printf("Ϊ���������һ������λ��%d���ڲ���:\n",i);
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
	printf("��������ɾ��������.\n");
	scanf("%d",&denum);	
	if(findElem(q,denum) == 0)
	printf("����Ҫɾ�������ֲ�����.\n");
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
	printf("******����Ĵ���ɾ���Լ�����*******\n");
	srand((unsigned)time(NULL));
	printf("�������������£�\n");
	for(int i=0;i<m;i++)
	{	a[i] = rand()%101;//�������0-100;
		if(i != 9)
		printf("%d,",a[i]);	
		else
		printf("%d.",a[i]);	
	}
	printf("\n");
	
	printf("����ʹ�����ַ�����������,β�巨����1,ͷ�巨����2:\n");
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































