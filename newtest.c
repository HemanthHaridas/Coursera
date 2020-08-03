/* Code to sort a LL containing 100 random integers*/

/* The nodes of the LL are constructed using createnode() which 
 * returns a node that contains a randomly generated integer value.
 * It is placed into the LL by insert() which will place it at the
 * head of the list, pushing the rest of the nodes down by one unit.
 * The nodes are then sorted using sort(), which takes two adjacent
 * nodes and swaps their contents, if they are out of order
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
 // struct node *prev;
  struct node *next;
};

void swap(struct node* u, struct node* v)
{
  int temp  = u->data;
  u->data = v->data;
  v->data = temp;
}

void print(struct node* T)
{
  struct node* tr = T;
  int counter = 0;
  while(tr!=NULL)
  {
    printf("%d\t",tr->data);
    tr  = tr->next;
    counter++;
    if(counter%5==0) printf("\n");
  }
  printf("\n");
}

struct node* createnode(int data)
{
  struct node* t = (struct node*)malloc(sizeof(struct node));
  t->data = data;
//  t->prev = NULL;
  t->next = NULL;
  return t;
}

struct node* insert(int data, struct node* T)
{
  if(T==NULL) return createnode(data);
  else T->next = insert(data,T->next);
  return T;
}

struct node* sort(struct node* T)
	{
  struct node * trav  = T;
  while(trav->next!=NULL)
  {
    if(trav->data > trav->next->data)
    {
      swap(trav,trav->next);
      //print(T);
    }
    trav  = trav->next;
  }
}

int main(void)
{
  struct node* head = createnode(rand());
  for(int i=0;i<99;i++) insert(rand(),head);
  for(int i=0;i<99;i++) sort(head);
  print(head);
  return 0;
}
