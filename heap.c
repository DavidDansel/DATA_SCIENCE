#include<stdio.h>
#include<stdlib.h>
#define HEAP_SIZE 100
int HEAP[HEAP_SIZE];
int N=0;


int heap_empty(){
  return N==0;
}

void fixUp(int val){
int k=N;
int temp;
   while(k>1 && HEAP[k]>HEAP[k/2]){
      temp=HEAP[k];
      HEAP[k]=HEAP[k/2];
      HEAP[k/2]=temp;
      k/=2;
   }
}

int insert(int val){
 if(N==HEAP_SIZE){
   printf("heap is full\n");
   return 0;
 }
 HEAP[++N]=val;
 fixUp(val);
 return 1;
}

void fixDown(){
int k=1;
int j;
int temp;
   //while the element at position k has a child or children
   while(2*k<=N-1){
     j=2*k;
     if(j<N-1 && (HEAP[j]<HEAP[j+1]))
        j++;
     if(!(HEAP[k]<HEAP[j]))
       break;
      temp=HEAP[k];
      HEAP[k]=HEAP[j];
      HEAP[j]=temp;
      k=j;
   }
}


int del_max(int *ret){
 if(heap_empty())
   return 0;
 //exchange the maximum element at the top with the last element in the heap
 int temp=HEAP[1];
 HEAP[1]=HEAP[N];
 HEAP[N]=temp;
 fixDown();
 *ret=HEAP[N];
 N--;
 return 1;
}
