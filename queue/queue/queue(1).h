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

//初始化
void InitQueue(SqQueue* pq);

//判满
bool isQueueFull(SqQueue *pq);

//判空
bool isQueueEmpty(SqQueue* pq);

//进队
int EnQueue(SqQueue* pq, QElemType e);

//出队
int DeQueue(SqQueue* pq, QElemType e);

//取队头
QElemType GetHead(SqQueue* pq,QElemType x);

//清除
void clearQueue(SqQueue* pq);

//队长度
int LenQueue(SqQueue* pq);

void QueueTest1();

void PrintQueue(SqQueue* pq);