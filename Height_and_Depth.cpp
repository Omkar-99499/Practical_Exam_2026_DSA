
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Insert node
Node* insert(Node* root, int x)
{
    if (root == NULL)
    {
        Node* n = new Node{x, NULL, NULL};
        return n;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find height of BST
int height(Node* root)
{
    if (root == NULL)
        return -1;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + (l > r ? l : r);
}

// Find depth of node
int depth(Node* root, int x, int d = 0)
{
    if (root == NULL)
        return -1;

    if (root->data == x)
        return d;

    if (x < root->data)
        return depth(root->left, x, d + 1);

    return depth(root->right, x, d + 1);
}

int main()
{
    Node* root = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Height of BST: " << height(root);

    cout << "\nEnter node to find depth: ";
    cin >> key;

    int d = depth(root, key);

    if (d == -1)
        cout << "Node not found";
    else
        cout << "Depth of node: " << d;

    return 0;
}
