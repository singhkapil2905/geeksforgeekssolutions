void postOrder(Node* root)
{
    if (!root) {
        return;
    }
    
    auto s = std::stack<Node*>{};
    Node* cur = root;
    
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        
        if (s.top()->right) {
            cur = s.top()->right;
        } else {
            Node* tp = nullptr;
            do {
                tp = s.top();
                s.pop();
                std::cout << tp->data << " ";
            } while (!s.empty() && s.top()->right && (tp == s.top()->right));
        }
    }
}
