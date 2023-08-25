#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>

#pragma once

typedef int QDataType;

//���еĻ�������(����)
typedef struct QueueNode {
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* head;
	QNode* tail;
}Queue;



//���еĳ�ʼ��
void QueueInit(Queue* pq);

//���е�����
void QueueDestroy(Queue* pq);

//���
void QueuePush(Queue* pq, QDataType x);

//����
void QueuePop(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���������ݵĸ���
int QueueSize(Queue* pq);

//��ͷ������
QDataType QueueFront(Queue* pq);

//��β������
QDataType QueueBack(Queue* pq);

//����
void QueueTest();