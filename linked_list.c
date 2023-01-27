#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
  char *string;
  struct node *next;
}node;

int NUMBER_OF_ITEMS=0;
node* root=NULL;

int set_up(char *s){
  root=(node *)malloc(sizeof(node));
  if(root==NULL)
     return 0;
  root->string=s;
  root->next=NULL;
  NUMBER_OF_ITEMS++;
  return 1;
}

int add_to_list(char *s){
 s=strdup(s);
 if(NUMBER_OF_ITEMS==0){
    if(set_up(s)==0)
        return 0;
    return 1;
 }
 node *temp=root;
 while(temp->next!=NULL)
     temp=temp->next;
  temp->next=(node *)malloc(sizeof(node));
  if(temp->next==NULL)
        return 0;
  temp->next->string=s;
  temp->next->next=NULL;
  NUMBER_OF_ITEMS++;
  return 1;
}

void remove_from_list(char *s){
  node *temp=root;
  if(strcmp(temp->string,s)==0){
      if(root->next!=NULL){
        root=root->next;
        return;
      }
      root=NULL;
      return;
  }
  node *prev=temp;
  temp=temp->next;
  while(temp!=NULL){
    if(strcmp(temp->string,s)==0){
      prev->next=temp->next;
      free(temp);
      NUMBER_OF_ITEMS--;
      return;
     }
     prev=temp;  
     temp=temp->next;
 }
}

void print_list(){
 node *temp=root;
 while(temp!=NULL){
    printf("%s\n",temp->string);
    temp=temp->next;
 }
}
