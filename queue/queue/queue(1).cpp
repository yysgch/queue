#include"queue(1).h"

void InitQueue(SqQueue* pq)
{
	pq->front = pq->rear = 0;
}
bool isQueueEmpty(SqQueue* pq)
{
	if (pq->front == pq->rear) 
		return true;
	else
		return false;
}
bool isQueueFull(SqQueue* pq)
{
	if ((pq->rear + 1) % maxsize == pq->front)
		return true;
	else
		return false;
}
int EnQueue(SqQueue* pq, QElemType e)
{
	if (isQueueFull(pq)){
		return 0;
	}
	pq->rear = (pq->rear + 1) % maxsize;
	pq->data[pq->rear] = e;	// 先移动指针再存入元素
	return e;
}
int DeQueue(SqQueue* pq, QElemType e)
{
	if (isQueueEmpty(pq)) {
		return 0;
	}
	pq->front = (pq->front+1) % maxsize;
	e = pq->data[pq->front];	
	return e;
}	
QElemType GetHead(SqQueue* pq,QElemType x)
{
	if (isQueueEmpty(pq)) {
		return 0;
	}
	pq->front = (pq->front + 1) % maxsize;
	int n = pq->data[pq->front];
	return n;
}
void PrintQueue(SqQueue* pq)
{
	int i = pq->front + 1;
	if (isQueueEmpty(pq)) {
		printf("队列已空\n");
	}
	else if (pq->front < pq->rear) {
		for (i; i <= pq->rear; i++) {
			printf("%d ", pq->data[i]);
		}
	}
	else {
		for (i; i <= pq->front+maxsize; i++) {
			printf("%d ", pq->data[i]);
		}
	}
	printf("\n");
}
void clearQueue(SqQueue* pq)
{
	pq->front = pq->rear = 0;
}
int LenQueue(SqQueue* pq)
{
	int i = pq->front;
	int size = 0;
	for (i; i < pq->rear; i++) {
		size++;
	}
	printf("队长为：%d\n", size);
	return size;
}
void QueueTest1()
{
	SqQueue pq;
	InitQueue(&pq);
	EnQueue(&pq, 1);
	EnQueue(&pq, 2);
	EnQueue(&pq, 3);
	EnQueue(&pq, 4);
	DeQueue(&pq, 1);
	printf("按1是顺序输出,按2也是顺序输出,按3清除队列,按4为队伍的长度:\n");
	int x;
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		while (!isQueueEmpty(&pq))
		{	
			int m = 0;
			int n;//用于储存队头
			n = GetHead(&pq, m);
			printf("%d ", n);
		}
		break;
	case 2:
		PrintQueue(&pq);
		break;
	case 3:
		clearQueue(&pq);
		PrintQueue(&pq);
		break;
	case 4:
		LenQueue(&pq);
		break;
	}
	printf("\n");
}