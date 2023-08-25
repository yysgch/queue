#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<stdbool.h>

#pragma once

typedef int QDataType;

//队列的基本操作(链表)
typedef struct QueueNode {
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* head;
	QNode* tail;
}Queue;



//队列的初始化
void QueueInit(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);

//入队
void QueuePush(Queue* pq, QDataType x);

//出队
void QueuePop(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//队列中数据的个数
int QueueSize(Queue* pq);

//队头的数据
QDataType QueueFront(Queue* pq);

//队尾的数据
QDataType QueueBack(Queue* pq);

//测试
void QueueTest();