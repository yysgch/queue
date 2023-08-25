#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#pragma once

#define maxsize 5
typedef int QElemType;

typedef struct
{
	int data[maxsize];
	int front;
	int rear;
}SqQueue;

//��ʼ��
void InitQueue(SqQueue* pq);

//����
bool isQueueFull(SqQueue *pq);

//�п�
bool isQueueEmpty(SqQueue* pq);

//����
int EnQueue(SqQueue* pq, QElemType e);

//����
int DeQueue(SqQueue* pq, QElemType e);

//ȡ��ͷ
QElemType GetHead(SqQueue* pq,QElemType x);

//���
void clearQueue(SqQueue* pq);

//�ӳ���
int LenQueue(SqQueue* pq);

void QueueTest1();

void PrintQueue(SqQueue* pq);