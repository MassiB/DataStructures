#ifndef NODE_HPP_
#define NODE_HPP_

template < typename T > 
struct Node final {
    Node<T>(const T _data, Node<T> *_next, Node<T> *_prev) : 
        data(_data),
        next(_next),
        prev(_prev) {}
    T data{T(0)};
    Node<T> *next{nullptr}, *prev{nullptr};
};

template < typename T >
struct TreeNode final {
    TreeNode (const T _data, TreeNode<T> *_left, TreeNode<T> *_right) :
        data(_data),
        left(_left),
        right(_right) {}
    T data{T(0)};
    int level{0};
    TreeNode<T> *left{nullptr}, *right{nullptr};
};

template < typename T > auto createNewNode(const T data, Node<T> *next = nullptr, Node<T> *prev = nullptr) -> Node<T>* {
    return new Node<T>(data, next, prev);
}

template < typename T > void removeNodes(Node<T> *node) {
    auto n = node;
    while (nullptr != n){
        auto curr = n;
        n = n->next;
        if (nullptr != n)
            n->prev = nullptr;
        delete curr;
    }
}

template < typename T > auto createNewTreeNode(const T data, TreeNode<T> left = nullptr, TreeNode<T> *right = nullptr) -> TreeNode<T>* {
    return new TreeNode<T>(data, left, right);
}



#endif