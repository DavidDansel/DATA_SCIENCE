#include<stdio.h>
#define STACK_SIZE 100
int STACK[STACK_SIZE];
int stack_ptr=-1;

int push(int n){
  if(stack_ptr+1==STACK_SIZE){
     printf("Stack is full\n");
     return 0;
  }
  STACK[++stack_ptr]=n;
  return 1;
}

int pop(int *n){
  if(stack_ptr>=0){
    printf("%d",STACK[stack_ptr]);
    *n=STACK[stack_ptr];
    stack_ptr--;
    return 1;
  }
 printf("Stack is empty\n");
 return 0;
}
