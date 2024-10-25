#include <iostream>
using namespace std;

class Deque
{
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Deque(int s)
    {
        front = -1;
        rear = 0;
        size = s;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void insertFront(int key)
    {
        if (isFull())
        {
            cout << "Overflow: Cannot insert, deque is full\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front = front - 1;
        }

        arr[front] = key;
        cout << "Inserted " << key << " at the front\n";
    }

    void insertRear(int key)
    {
        if (isFull())
        {
            cout << "Overflow: Cannot insert, deque is full\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        arr[rear] = key;
        cout << "Inserted " << key << " at the rear\n";
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow: Cannot delete, deque is empty\n";
            return;
        }

        cout << "Deleted " << arr[front] << " from the front\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow: Cannot delete, deque is empty\n";
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear = rear - 1;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[rear];
    }

    void printDeque()
    {
        if (isEmpty())
        {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    int choice, element, size;
    cout << "Enter the size of the deque: ";
    cin >> size;

    Deque dq(size);

    do
    {
        cout << "\n*** Menu ***\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Get front element\n";
        cout << "6. Get rear element\n";
        cout << "7. Print deque\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert at front: ";
            cin >> element;
            dq.insertFront(element);
            break;
        case 2:
            cout << "Enter element to insert at rear: ";
            cin >> element;
            dq.insertRear(element);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            element = dq.getFront();
            if (element != -1)
                cout << "Front element: " << element << endl;
            break;
        case 6:
            element = dq.getRear();
            if (element != -1)
                cout << "Rear element: " << element << endl;
            break;
        case 7:
            dq.printDeque();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
