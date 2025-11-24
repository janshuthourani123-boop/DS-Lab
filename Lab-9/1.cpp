#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
private:
    Node* root;
    string lastRotation;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int balanceFactor(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        lastRotation = "Right Rotation (LL Case)";
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        lastRotation = "Left Rotation (RR Case)";
        return y;
    }

    Node* insertNode(Node* node, int key) {
        if (!node) return new Node(key);

        if (key < node->data)
            node->left = insertNode(node->left, key);
        else if (key > node->data)
            node->right = insertNode(node->right, key);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int bf = balanceFactor(node);

        if (bf > 1 && key < node->left->data) {
            return rightRotate(node);
        }
        if (bf < -1 && key > node->right->data) {
            return leftRotate(node);
        }
        if (bf > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            lastRotation = "Left-Right Rotation (LR Case)";
            return rightRotate(node);
        }
        if (bf < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            lastRotation = "Right-Left Rotation (RL Case)";
            return leftRotate(node);
        }

        lastRotation = "No rotation";
        return node;
    }

    Node* minValueNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }
                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (!root) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int bf = balanceFactor(root);

        if (bf > 1 && balanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        if (bf > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            lastRotation = "Left-Right Rotation (LR Case)";
            return rightRotate(root);
        }
        if (bf < -1 && balanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        if (bf < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            lastRotation = "Right-Left Rotation (RL Case)";
            return leftRotate(root);
        }

        lastRotation = "No rotation";
        return root;
    }

public:
    AVL() {
        root = nullptr;
        lastRotation = "None";
    }

    void insert(int key) {
        cout << "\nINSERT: " << key;
        root = insertNode(root, key);
        printStatus();
    }

    void remove(int key) {
        cout << "\nDELETE: " << key;
        root = deleteNode(root, key);
        printStatus();
    }

    void printStatus() {
        cout << "\nTree Height: " << height(root);
        cout << "\nRotation Performed: " << lastRotation;
        cout << "\nRoot Balance Factor: " << balanceFactor(root);
        cout << "\n-----------------------------------\n";
    }
};

int main() {
    AVL tree;


    tree.insert(50);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(70);
    tree.insert(80);


    tree.remove(20);
    tree.remove(10);
    tree.remove(70);

    return 0;
}
