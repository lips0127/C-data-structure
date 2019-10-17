/*
顺序队的初始化 
判断队空，出队，入队. 
create time:2019/10/17 23:12
end time:2019/10/17 23:34
*/

#include <stdio.h>
#define maxsize 20

typedef struct sqQueue
{
	int data[maxsize];
	int front;
	int rear;
}sqQueue;

int main()
{
	
	


}

int  initQueue(sqQueue Q)
{
	Q.front = Q.rear = 0;
}

int isQueueEmpty(sqQueue Q)
{
	if(Q.front == Q.rear)
		return 1;
	else
		return 0;
}

int  enQueue(sqQueue &Q,int x)
{
	if((Q.rear+1)%maxsize == Q.front)
	return 0;
	Q.rear=(Q.rear+1)%maxsize;//先移动指针，在存入数字. 
	Q.data[Q.rear] = x;
	return 1;
}

int  deQueue(sqQueue &Q,int &x)
{
	if((Q.rear == Q.front))
	return 0;
	Q.front = (Q.front+1)%maxsize;
	x = Q.data[Q.front];//先移动指针，在存入数字.
	return 1;
}
