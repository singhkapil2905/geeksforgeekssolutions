// https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
{
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
struct node* NewNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
struct node *correctBST( struct node* root );
void Inorder(struct node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct node *temp,struct node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}
int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct node *root=NULL;
	struct node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	//Inorder(root);
	//cout<<endl;
	root=correctBST(root);
	//Inorder(root);
	//cout<<endl;
	inorder(temp,root);
	//cout<<c<<endl;
	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0
";
	}
	}
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
void PopulateNodes(node* p, node* low, node* high, node*& n1, node*& n2) {
    if (!p) {
        return;
    }
    
    if (low && p->data < low->data) {
        if (!n1) {
            n1 = p;
        } else {
            n2 = p;
        }
    }
    
    if (high && p->data > high->data) {
        if (!n1) {
            n1 = p;
        } else {
            n2 = p;
        }
    }
    
    if (n1 && n2) {
        return;
    }
    
    PopulateNodes(p->left, low, p, n1, n2);
    PopulateNodes(p->right, p, high, n1, n2);
}
struct node *correctBST( struct node* root )
{
    node* node1{nullptr};
    node* node2{nullptr};
    
    if (!root) {
        return root;
    }
    
    PopulateNodes(root, nullptr, nullptr, node1, node2);
    std::swap(node1->data, node2->data);
    
    return root;
}
