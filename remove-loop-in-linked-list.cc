//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
{
// C program to detect loop in a linked list
#include<bits/stdc++.h>
 using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
 vector<int> _A_;
 void removeLoop(struct Node *, struct Node *);
 void removeTheLoop(Node *);
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node =
          (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_Node->data  = new_data;
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}
void removeTheLoop(struct Node *list);
int __detectloop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
  	bool fA=0;
  	bool fB =0;
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           fA=1;
        }
    }
    
    //Check for valid list
    
    
    
    if(fA)
    return 1;
    else 
    return 0;
}
/* Drier program to test above function*/
int main()
{
	int t,n,c,x,i;
	cin>>t;
	while(t--){
    /* Start with the empty list */
    cin>>n;
    _A_.clear();
    struct Node *head = NULL;
    struct Node* temp;
    struct Node *s;
    cin>>x;
    push(&head,x);
    s=head;
    
   _A_.push_back(x);
    for(i=1;i<n;i++){
		cin>>x;
		
   _A_.push_back(x);
    push(&head,x);}
    
    /* Create a loop for testing */
    cin>>c;
    if(c>0){
    c=c-1;
    temp=head;
    while(c--)
    temp=temp->next;
    s->next=temp;
	}
	removeTheLoop(head);
	
	int g = __detectloop(head);
	Node *test = head;
    int c_=0;
    int fB=0;
  reverse(_A_.begin(),_A_.end());
    while(test!=NULL)
    {
    
    	if(test->data!=_A_[c_]){
    	fB=1;
    
    	break;
    	
    	}
    	test=test->next;
    	c_++;
    }
	
	
    if(g or fB)
    cout<<"0
";
    else
    cout<<"1
";
	}
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
     if (!node || !node->next) {
         return;
     }
     
     Node* p = node;
     Node* pp = node;
     
     while (p) {
         p = p->next;
         if (pp) {
             pp = pp->next;
         }
         if (pp) {
             pp = pp->next;
         }
         
         if (p == pp) {
             break;
         }         
     }
     
     if (!p) {
         return;
     }
     
     p = pp;
     
     while (p->next != pp) {
         p = p->next;
     }
     
     p->next = nullptr;
}
