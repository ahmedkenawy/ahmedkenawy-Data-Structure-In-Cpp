#include <iostream>
using namespace std;

class Array
{
private:
    int size;
    int length;
    int *items;

public:
    Array(int arraySize)
    {
        size = arraySize;
        length = 0;
        items = new int[arraySize];
    }

    void fill()
    {
        int no_of_items;
        cout << "How many items you want to fill?\n";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cout << "number you entered is greater than array Size\n";
            return;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                cout << "Enter element #" << i;
                cin >> items[i];
            }
        }
    }

    void Display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    int getLength()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == size;
    }

    void insertAt(int index, int value)
    {
        if (isFull())
        {
            cout << "Array is Full\n";
        }
        else if (isEmpty())
        {
            cout << "Array is Empty\n";
            items[length] = value;
            length++;
        }
        else
        {
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
            }
            items[index] = value;
            length++;
        }
    }

    void deleteIndex(int index)
    {
        if (isEmpty())
        {
            cout << "Array is Empty\n";
        }
        else
        {
            for (int i = index; i < length; i++)
            {
                items[i] = items[i + 1];
            }
            length--;
        }
    }

    void enlargeArray(int newSize)
    {
        if (newSize <= size)
        {
            cout << "new size must be larger than current size \n";
        }
        else
        {
            int *old = items;
            items = new int[newSize];
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[] old;
        }
    }

    void mergeArray(int newArray[])
    {
    }
};

int main()
{
    int sizeOfArray;
    cout << "Enter the size of array :";
    cin >> sizeOfArray;
    cout << endl;
    Array myArray(sizeOfArray);

    myArray.fill();
    myArray.Display();
}