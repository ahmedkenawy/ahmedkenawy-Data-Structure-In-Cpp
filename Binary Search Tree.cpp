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
        root = insert(root, item);
    }

    void preOrderTraverse(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->data << "  ";
        preOrder(r->left);
        preOrder(r->right);
    }

    void inOrderTraverse(Node *r)
    {
        if (r == NULL)
            return;
        preOrder(r->left);
        cout << r->data << "  ";
        preOrder(r->right);
    }

    void postOrderTraverse(Node *r)
    {
        if (r == NULL)
            return;
        preOrder(r->left);
        preOrder(r->right);
        cout << r->data << "  ";
    }

    Node *search(Node *r, int key)
    {
        if (r == NULL)
            return NULL;
        else if (r->data == key)
            return r;
        else if (kew < r->data)
            search(r->left, key);
        else
            search(r->right, key);
    }

    bool search(int key)
    {
        Node *result = search(root, key);

        if (result == NULL)
            return false;
        else
            return true;
    }

    Node *findMinimum(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->left == NULL)
            return r;
        else
            findMinimum(r->left);
    }

    Node *findMaximum(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->right == NULL)
            return r;
        else
            findMaximum(r->right);
    }

    Node *Delete(Node *r,int key){
        
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