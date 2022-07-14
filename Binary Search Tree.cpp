#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int item)
    {
        data = item;
        left = right = NULL;
    }
};

class BST
{

public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    Node *insert(Node *r, int item)
    {
        if (r == NULL)
        {
            Node *newNode = new Node(item);
            r = newNode;
        }
        else if (item < r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right, item);
        }
        return r;
    }

    void insert(int item)
    {
        root=insert(root, item);
    }

    void preOrder(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->data << "  ";
        preOrder(r->left);
        preOrder(r->right);
    }
};

int main()
{
    BST b;
    b.insert(5);
    b.insert(20);
    b.insert(35);
    b.insert(7);
    b.insert(9);
    b.insert(2);
    b.preOrder(b.root);

    return 0;
}