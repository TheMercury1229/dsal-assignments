/*Write program to implement a priority queue in C++ using
an order list/array to store the items in the queue. Create a
class that includes the data items (which should be template)
and the priority (which should be int). The order list/array
should contain these objects, with operator <= overloaded so
that the items with highest priority appear at the beginning of
the list/array (which will make it relatively easy to retrieve the
highest item.)*/

#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    string *arr;
    int *priority;
    int front, rear, maxSize;

public:
    PriorityQueue(int size)
    {
        maxSize = size;
        arr = new string[maxSize];
        priority = new int[maxSize];
        front = 0;
        rear = -1;
    }

    bool isFull()
    {
        return rear >= maxSize - 1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    void add(string ele, int p)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        rear++;
        arr[rear] = ele;
        priority[rear] = p;

        int j = rear - 1;
        while (j >= front && priority[j] < p)
        {
            arr[j + 1] = arr[j];
            priority[j + 1] = priority[j];
            j--;
        }
        arr[j + 1] = ele;
        priority[j + 1] = p;
    }

    string pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return "/0";
        }

        string ele = arr[front];
        front++;
        return ele;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue (Element, Priority): \n";
        for (int i = front; i <= rear; i++)
        {
            cout << "(" << arr[i] << ", " << priority[i] << ") ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the priority queue: ";
    cin >> size;

    PriorityQueue pq(size);

    int choice;
    string element;
    int priority;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add element to queue\n";
        cout << "2. Pop element from queue\n";
        cout << "3. Print queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            cout << "Enter priority: ";
            cin >> priority;
            pq.add(element, priority);
            break;
        case 2:
            cout << "Popped element: " << pq.pop() << endl;
            break;
        case 3:
            pq.print();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
