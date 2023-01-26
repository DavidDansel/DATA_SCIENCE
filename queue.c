#include<stdio.h>
#define QUEUE_SIZE 10
int QUEUE[QUEUE_SIZE];
int queue_head_ptr=-1;
int queue_tail_ptr=-1;
int queue_items_N=0; //number of items in queue

int enqueue(int n){
  if(queue_items_N==QUEUE_SIZE){
     printf("queue is full\n");
     return 0;
  }
  QUEUE[++queue_tail_ptr % QUEUE_SIZE]=n;
  queue_items_N++;
  return 1;
}

int dequeue(int *n){
  if(queue_items_N==0){
    printf("queue is empty\n");
    return -1;
  }
  *n=QUEUE[++queue_head_ptr % QUEUE_SIZE];
  queue_items_N--;
  return 1;
}

