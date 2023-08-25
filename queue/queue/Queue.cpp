#include"Queue.h"
//���еĳ�ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

//���е�����
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

//���
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

//����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	//ͷɾ - ֻ��һ�ָ��������ʱtail���Ұָ��
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

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

//���������ݵĸ���
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

//��ͷ������
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

//��β������
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}

//����
void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("��1��˳���������2�ǳ���:\n");
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