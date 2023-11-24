#include <iostream>
using namespace std;

struct node
{
    int key;
    node *right;
    node *left;
    int height;
};

node *root = NULL;

// Function to get the height of a node
int getHeight(node *p)
{
    if (p == NULL)
        return 0;
    return p->height;
}

// Function to create a new node
node *createNode(int key)
{
    node *root = new node();
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    return root;
}

// Function to get the balance factor of a node
int getBalanceFactor(node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    return getHeight(p->left) - getHeight(p->right);
}

// Right rotation of a node
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}

// Left rotation of a node
node *leftRotation(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return y;
}

// Function to insert a node into the AVL tree
node *insert(node *p, int key)
{
    if (p == NULL)
    {
        node *ptr = createNode(key);
        p = ptr;
        return p;
    }
    if (key < p->key)
    {
        p->left = insert(p->left, key);
    }
    else if (key > p->key)
    {
        p->right = insert(p->right, key);
    }

    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

    int balanceFactor = getBalanceFactor(p);

    // Left-Left case
    if (balanceFactor > 1 && key < p->left->key)
    {
        p = rightRotate(p);
    }
    // Right-Right case
    if (balanceFactor < -1 && key > p->right->key)
    {
        p = leftRotation(p);
    }
    // Left-Right case
    if (balanceFactor > 1 && key > p->left->key)
    {
        p->left = leftRotation(p->left);
        p = rightRotate(p);
    }
    // Right-Left case
    if (balanceFactor < -1 && key > p->right->key)
    {
        p->right = rightRotate(p->right);
        p = leftRotation(p);
    }

    return p;
}

// Preorder traversal of the AVL tree
void preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->key << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

int main()
{
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    return 0;
}

