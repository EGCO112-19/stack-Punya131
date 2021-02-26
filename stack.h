
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

void push(StackPtr s,char value)
{
Node * newnode = (Node *)malloc(sizeof(Node));
if(newnode)
{
  newnode -> data = value;
  newnode -> nextPtr = s->top;
  s->top = newnode;
  s->size += 1;
}
}
char pop(StackPtr s)
{
  NodePtr t = s->top;
  char value;
  if(s->top != NULL)
  {
  value = t->data;
  s->top = t->nextPtr;
  free(t);
  s->size -= 1;
  return  value;
  }
}

void pop_all(StackPtr s)
{
  NodePtr t = s->top;
  char value;
  while(s->top !=NULL)
  {
    value = t->data;
    s->top = t->nextPtr;
    printf("Popping %c\n",value);
    free(t);
    t = s->top;
    

  }
  s->size =0;
}
#endif
