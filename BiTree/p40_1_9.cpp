/*
����ʱ��:2019/10/10 23:14
���ʱ��: 2019/10/10 24:00
ps:����ʧ�ܣ��������㷨����ȷ��. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9
#define Maxsize 20

typedef struct lklist
{
	int data;
	lklist *next;
}lklist;

void fprintList(lklist *L)
{
	lklist *q;
	q = L->next;
	while(q)
	{
		printf("%d\n ",q->data);
		q = q->next;
	}
		
}

void func(lklist *&A,lklist *&B)//ʵ����������A�����У�ż���ŵ�B������. 
{
	lklist *r,*q,*q1;
	r = B;
//	r->next = NULL;
	q = A;
//	q1 = q->next;
	while(q->next!=NULL)
	{	
		if((q1->next->data)%2 == NULL)//��2�������ŵ�B��.  
		{	
			/*b = (lklist*)malloc(sizeof(lklist));
			b->next = NULL;
			b->data = q1->data;
			r->next = b;
			r = r->next;//above  all of those are right about B-linklist;
			p = q1;
			q->next = p->next;
			q1 = q1->next;	
			free(p);
			*/
			q1 = q->next;
			q->next = q1->next;
			q1->next = NULL;
			r->next = q1;
			r = q1;
						
		}
		else//���ܱ�2����������A��. 		
		q = q->next;

		
	}
	


}
int main()	
{	
	srand((unsigned)time(NULL));
	lklist *A,*q,*B;
	lklist *r;
	A = (lklist*)malloc(sizeof(lklist));
	B = (lklist*)malloc(sizeof(lklist));
	B->next = NULL;
	B->data = NULL;
	A->next = NULL;
	A->data = NULL;
	r = A;
	for(int i=0;i<N;i++)
	{	
		q = (lklist*)malloc(sizeof(lklist));
		q->data = rand()%(Maxsize);
		r->next = q;
		r = r->next; 
	}
	r->next = NULL;
	fprintList(A);
	printf("********************\n");
	func(A,B);
//	fprintList(A);
	fprintList(B);
	return 0;	
}
