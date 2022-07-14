#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
};

class Queue
{
private:
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
            cout << "Queue is empty";
        else if (front == rear)
            front = rear = NULL;
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    int getFront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }

    void display()
    {
        if (isEmpty())
            cout << "Queue is empty";
        else
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }
        }
    }

    int count()
    {
        int counter = 0;
        Node *temp = front;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        cout<< endl;
        return counter;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.display();
}