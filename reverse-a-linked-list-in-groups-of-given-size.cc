// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

{
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     cin>>t;
     while(t--)
     {
     insert();
     cin>>k;
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/
node* Reverse(node* p) {
    if (!p || !p->next) {
        return p;
    }
    
    node* prev{nullptr};
    node* cur{p};
    node* nxt{nullptr};
    
    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    
    return prev;
}

struct node *reverse (struct node *head, int k)
{ 
  if (!head) {
      return head;
  }
  
  if (k < 2) {
      return head;
  }
  
  node* new_head{nullptr};
  node* cur_head{head};
  node* next_head{nullptr};
  node* temp{nullptr};
  node* last_tail{nullptr};
  head = nullptr;
  do {
      temp = cur_head;
      auto temp_k = k;
      while (temp && temp_k > 1) {
          temp = temp->next;
          temp_k--;
      }
      
      next_head = temp ? temp->next : nullptr;
      if (temp) {
        temp->next = nullptr;
      }
      
      if (!new_head) {
          new_head = Reverse(cur_head);
      } else {
          last_tail->next = Reverse(cur_head);
      }
      
      last_tail = cur_head;
      cur_head = next_head;
  } while (cur_head);
  
  return new_head;
}
