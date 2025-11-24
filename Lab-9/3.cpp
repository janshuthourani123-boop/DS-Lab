#include <iostream>
using namespace std;

class Node {
public:
    int price;
    Node* left;
    Node* right;
    int height;

    Node(int p) {
        price = p;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    Node* root;

    int height(Node* n) {
        return (n == nullptr) ? 0 : n->height;
    }

    int getBalance(Node* n) {
        return (n == nullptr) ? 0 : height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insertNode(Node* node, int price) {
        if (node == nullptr)
            return new Node(price);

        if (price < node->price)
            node->left = insertNode(node->left, price);
        else if (price > node->price)
            node->right = insertNode(node->right, price);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && price < node->left->price)
            return rightRotate(node);

        if (balance < -1 && price > node->right->price)
            return leftRotate(node);

        if (balance > 1 && price > node->left->price) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && price < node->right->price) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void rangeQuery(Node* node, int X, int Y) {
        if (!node) return;

        if (X < node->price)
            rangeQuery(node->left, X, Y);

        if (node->price >= X && node->price <= Y)
            cout << node->price << " ";

        if (Y > node->price)
            rangeQuery(node->right, X, Y);
    }

public:
    AVL() { root = nullptr; }

    void insert(int price) {
        root = insertNode(root, price);
    }

    void printRange(int X, int Y) {
        cout << "Prices between " << X << " and " << Y << ": ";
        rangeQuery(root, X, Y);
        cout << endl;
    }
};

int main() {
    AVL tree;

    tree.insert(100);
    tree.insert(40);
    tree.insert(200);
    tree.insert(10);
    tree.insert(50);
    tree.insert(150);

    tree.printRange(30, 160);

    return 0;
}
