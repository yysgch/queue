#include"Queue.h"
//队列的初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

//队列的销毁
void QueueDestroy(Queue* pq)
{
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = pq->head;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//入队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL) {
		assert(pq->head == NULL);
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	//头删 - 只有一种个结点的情况时tail会成野指针
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//判断队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

//队列中数据的个数
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

//队头的数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//队尾的数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}

//测试
void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("按1是顺序输出，按2是长度:\n");
	int x;
	scanf_s("%d", &x);
	switch (x)
	{
	case 1:
		while (!QueueEmpty(&q))
		{
			printf("%d ", QueueFront(&q));
			QueuePop(&q);
		}
		break;
	case 2:
	{
		int n = 0;
		n = QueueSize(&q);
		printf("%d", n);
		break;
	}
	default:
		break;
	}
	printf("\n");
}