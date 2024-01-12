//a program to have lots of queue keeping the fronts and rears of each queue in a stack ptr array.
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELM 10 


//structure to keep each node
struct QueueNode {
	int data;
	struct QueueNode* next;
};

//structure of queue ptr array
struct Queue{
	struct QueueNode* front;
	struct QueueNode* rear;
};

//array of the fronts and rears of each queue
struct Queue *queueArray[MAX_ELM];

//enqueue operation of a certain queue in the array
void enqueue(struct Queue* q, int data) {

	struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if(q->front==NULL && q->rear==NULL){
		q->front = q->rear = newNode;
		return;
	}

	q->rear->next = newNode;
	q->rear = newNode;
}

//function to decide which queue will be enqueued
void EnqCallByIndexOfQueueArr(int index, int data) {

	if (index<0 || index>MAX_ELM) return;

	struct Queue* q = queueArray[index];
	enqueue(q, data);
}

//dequeue operation of a certain queue in the array
void dequeue(struct Queue* q) {

	if (q->front == NULL) return;

	struct QueueNode* toDelete = q->front;
	if (q->front == q->rear) {
		q->front = NULL;
		q->rear = NULL;
		free(toDelete);
		return;
	}

	q->front = q->front->next;
	free(toDelete);
}


//function to decide which queue will be dequeued
void DeqCallByIndexOfQueueArr(int index) {
	if (index<0 || index>MAX_ELM) return;

	struct Queue* q = queueArray[index];
	dequeue(q);
}


void printQueue(struct Queue *qArr[MAX_ELM]) {
	for (int i = 0; i < MAX_ELM; i++) {
		printf("queue %d: ", i);
		struct QueueNode* q = qArr[i]->front;

		while (q) {
			printf("%d\t", q->data);
			q = q->next;
		}
		printf("\n");
	}

	printf("\n\n\n");

}

int main() {

	//initializing the each queue in the array.
	for (int i = 0; i < MAX_ELM; i++) {
		queueArray[i] = (struct Queue*)malloc(sizeof(struct Queue));
		queueArray[i]->front= NULL;
		queueArray[i]->rear = NULL;
	}

	
	EnqCallByIndexOfQueueArr(0, 14);
	EnqCallByIndexOfQueueArr(0, 34);
	EnqCallByIndexOfQueueArr(0, 56);
	EnqCallByIndexOfQueueArr(3, 5);
	EnqCallByIndexOfQueueArr(3, 78);
	EnqCallByIndexOfQueueArr(6, 122);
	EnqCallByIndexOfQueueArr(9, 89);

	printQueue(queueArray);

	DeqCallByIndexOfQueueArr(0);
	DeqCallByIndexOfQueueArr(9);

	printQueue(queueArray);


	return 0;
}