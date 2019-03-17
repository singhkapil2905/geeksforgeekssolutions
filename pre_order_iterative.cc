void preorder(Node* root)
{
    if (!root) {
        return;
    }
    
    auto s = std::stack<Node*>{};
    s.push(root);
    
    while (!s.empty()) {
        auto tp = s.top();
        s.pop();
        std::cout << tp->data << " ";
        if (tp->right) {
            s.push(tp->right);
        }
        
        if (tp->left) {
            s.push(tp->left);
        }
    }
}
