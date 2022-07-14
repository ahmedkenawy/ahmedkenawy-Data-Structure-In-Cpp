#include <iostream>
using namespace std;
class Node
{
public:
    int Data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insertFirst(int value)
    {
        Node *newNode=new Node();
        newNode->Data = value;
        if (isEmpty())
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    };

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->Data << "  ";
            temp = temp->next;
        }
    }

    int count()
    {
        int counter = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int key)
    {
        Node *temp = head;
        bool flag = false;
        while (temp != NULL)
        {
            if (temp->Data == key)
            {
                flag = true;
                break;
            }
            temp = temp->next;
        }
        return flag;
    }

    void insertBefor(int item, int newValue)
    {
        Node *temp = head;
        Node *newNode = new Node();
        newNode->Data = newValue;
        if (isEmpty())
            cout << "List is Empty\n";
        if (isFound(item))
        {
            while (temp->next->Data != item)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = temp->next;
        }
        else
        {
            cout << "item not found in list\n";
        }
    }

    void append(int value)
    {
        Node *temp = head;
        Node *newNode = new Node();
        newNode->Data = value;
        if (isEmpty())
            insertFirst(value);
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void Delete(int item)
    {
        Node *delPtr = head, *prev = NULL;
        if (isEmpty())
            cout << "No items in List\n";
        if (isFound(item))
        {
            if (head->Data == item)
            {
                head = head->next;
                delete delPtr;
            }
            else
            {
                while (delPtr->Data != item)
                {
                    prev = delPtr;
                    delPtr = delPtr->next;
                }
                prev->next = delPtr->next;
                delete delPtr;
            }
        }
        else
        {
            cout << "item not found in  list\n";
        }
    }
};

int main()
{
    LinkedList *l = new LinkedList();
    l->insertFirst(5);
    l->insertFirst(7);
    l->insertFirst(8);
    l->insertFirst(9);
    l->insertFirst(10);
    l->append(18);
    l->display();
} 
