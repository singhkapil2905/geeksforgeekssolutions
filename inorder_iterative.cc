void inOrder(Node* root)
{
    if (!root) {
        return;
    }
    
    auto s = std::stack<Node*>{};
    auto cur = root;
    
    do {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        
        auto tp = s.top();
        s.pop();
        std::cout << tp->data << " ";
        if (tp->right) {
            s.push(tp->right);
            cur = tp->right->left;
        }
    } while (!s.empty());
}
