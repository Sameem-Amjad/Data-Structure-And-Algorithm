#include <iostream>
using namespace std;

// Define the structure of a Node for the binary search tree
struct Node
{
    int key;
    Node *right = NULL;
    Node *left = NULL;
};

// Function to create a new Node and take user input for its key
Node *createNode()
{
    Node *current = new Node();
    cout << "\nEnter a number: ";
    cin >> current->key;
    cout << endl;
    return current;
}

// Function to calculate the height of a node
int height(Node *p)
{
    if (p == NULL)
        return -1;
    else
    {
        int leftHeight = height(p->left);
        int rightHeight = height(p->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// Function to calculate the balance factor of a node
int getBalanceFactor(Node *p)
{
    if (p == NULL)
        return 0;
    return (height(p->left) - height(p->right));
}

// Right rotation of a subtree rooted with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

// Left rotation of a subtree rooted with x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

// Function to balance a node during insertion
Node *balance(Node *r, Node *newNode)
{
    int balanceFactor = getBalanceFactor(r);

    // Left Left rotation
    if (balanceFactor > 1 && newNode->key < r->left->key)
        return rightRotate(r);

    // Right Right Rotation
    if (balanceFactor < -1 && newNode->key > r->right->key)
        return leftRotate(r);

    // Left Right Rotation
    if (balanceFactor > 1 && newNode->key > r->left->key)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Left Rotation
    if (balanceFactor < -1 && newNode->key < r->right->key)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

// Find the node with the minimum value in a subtree
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given key
Node *deleteNode(Node *r, int v)
{
    if (r == NULL)
    {
        return NULL;
    }
    else if (v < r->key)
    {
        r->left = deleteNode(r->left, v);
    }
    else if (v > r->key)
    {
        r->right = deleteNode(r->right, v);
    }
    else
    {
        // Node with only one child or no child
        if (r->left == NULL)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == NULL)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            // Node with two children: Get the inorder successor
            Node *temp = minValueNode(r->right);
            r->key = temp->key;
            r->right = deleteNode(r->right, temp->key);
        }
    }

    int bf = getBalanceFactor(r);

    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && getBalanceFactor(r->left) >= 0)
        return rightRotate(r);

    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && getBalanceFactor(r->left) == -1)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && getBalanceFactor(r->right) <= -0)
        return leftRotate(r);

    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && getBalanceFactor(r->right) == 1)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

// Function to insert a new node with a given key
Node *insert(Node *r, Node *newNode)
{
    if (r == NULL)
    {
        r = newNode;
        cout << "\nNode Inserted successfully\n";
        return r;
    }
    if (newNode->key > r->key)
        r->right = insert(r->right, newNode);
    else if (newNode->key < r->key)
        r->left = insert(r->left, newNode);
    else
    {
        cout << "Duplicate key can't be inserted\n";
        return r;
    }
    r = balance(r, newNode);
    return r;
}

// Function to perform pre-order traversal of the tree
void preOrder(Node *p)
{
    if (p == NULL)
        return;
    cout << p->key << " ";
    preOrder(p->left);
    preOrder(p->right);
}

int main()
{
    Node *r = NULL;
    int option;

    do
    {
        cout << "\n1.Insertion\n2.Deletion\n3.Pre-order\n4.Exit\nEnter your choice : ";
        cin >> option;
        switch (option)
        {
        case 1:
            r = insert(r, createNode());
            break;
        case 2:
            int key;
            cout << "\nEnter key to Delete: ";
            cin >> key;
            deleteNode(r, key);
            break;
        case 3:
            cout << "\nPre-order Traversal: ";
            preOrder(r);
            cout << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid option\n";
            break;
        }
    } while (option != 0);
    return 0;
}
