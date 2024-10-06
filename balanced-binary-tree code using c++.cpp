#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

int height(Node* node) {
    return node ? node->height : 0;
}

int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
    node->height = max(height(node->left), height(node->right)) + 1;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    updateHeight(node);

    if (balanceFactor(node) > 1 && key < node->left->key)
        return rightRotate(node);
    
    if (balanceFactor(node) < -1 && key > node->right->key)
        return leftRotate(node);
    
    if (balanceFactor(node) > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balanceFactor(node) < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    int keys[] = {10, 20, 30, 40, 50};
    
    for (int i = 0; i < 5; ++i)
        root = insert(root, keys[i]);

    cout << "Preorder Traversal: ";
    preOrder(root);
    
    return 0;
}
