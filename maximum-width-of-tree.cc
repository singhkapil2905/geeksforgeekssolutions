https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/
using li = long int;

li GetTreeHeight(const Node * const p) {
    if (!p) {
        return 0;
    }
    
    const auto l_height = GetTreeHeight(p->left);
    const auto r_height = GetTreeHeight(p->right);
    
    return std::max(l_height, r_height) + 1;
}

void FillNodeCount(const Node* const p, std::vector<li>& node_count, li level) {
    if (!p) {
        return;
    }
    
    ++(node_count.at(level));
    
    FillNodeCount(p->left, node_count, level + 1);
    FillNodeCount(p->right, node_count, level + 1);
}

int getMaxWidth(Node* root)
{
   if (!root) {
       return 0;
   }
   
   const auto tree_height = GetTreeHeight(root);
   
   auto node_count = std::vector<li>(tree_height, 0);
   
   FillNodeCount(root, node_count, 0);
   
   return *(std::max_element(std::begin(node_count), std::end(node_count)));
}
