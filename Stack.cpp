#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    bool isEmpty() { return top == NULL; }

    void push(int value)
    {

        Node *newNode = new Node();
        newNode->data = value;
        if (isEmpty())
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    void pop()
    {
        Node *temp = top;
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            top = top->next;
            delete temp;
        }
        size--;
    }

    int peek()
    {
        return top->data;
    }

    int count() { return size; }

    bool isFound(int value)
    {
        bool flag = false;
        Node *temp = top;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                flag = true;
            }
            temp = temp->next;
        }
        return flag;
    }

    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.display();
    cout << "*******************************" << endl;
    cout << s.peek() << endl;
    cout << "*******************************" << endl;
    s.pop();
    s.pop();
    s.pop();
    s.display();
    cout<< s.isFound(8);
}