
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        root = new Node{x, NULL, NULL};
        return root;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* r) {
    if (r) {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

void preorder(Node* r) {
    if (r) {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node* r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}

int main() {
    Node* root = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nEnter name/number to search: ";
    cin >> key;

    Node* p = root;

    while (p && p->data != key)
        p = (key < p->data) ? p->left : p->right;

    cout << (p ? "Found" : "Not Found");

    return 0;
}
