#include <iostream>
using namespace std;

class Node {
private:
    string data;
    Node* prev;
    Node* next;
    bool isBooked;
    string bookedBy; 

public:
    Node(string d) : data(d), prev(nullptr), next(nullptr), isBooked(false), bookedBy("") {}

    string getData() { return data; }
    bool getIsBooked() { return isBooked; }
    string getBookedBy() { return bookedBy; }

    void book(string name) { 
        isBooked = true; 
        bookedBy = name; 
    }

    void cancel() { 
        isBooked = false; 
        bookedBy = ""; 
    }

    Node* getPrev() { return prev; }
    Node* getNext() { return next; }
    void setPrev(Node* p) { prev = p; }
    void setNext(Node* n) { next = n; }
};

class Row {
private:
    Node* head;
    int seatCount;

public:
    Row() : head(nullptr), seatCount(0) {}

    ~Row() {
        if (head) {
            Node* current = head;
            do {
                Node* temp = current;
                current = current->getNext();
                delete temp;
            } while (current != head);
        }
    }

    void addSeat(char rowLetter, int seatNumber) {
        string seatName = string(1, rowLetter) + to_string(seatNumber);
        Node* newNode = new Node(seatName);
        if (!head) {
            head = newNode;
            head->setNext(head);
            head->setPrev(head);
        } else {
            Node* tail = head->getPrev();
            tail->setNext(newNode);
            newNode->setPrev(tail);
            newNode->setNext(head);
            head->setPrev(newNode);
        }
        seatCount++;
    }

    void freeSlotsDisplay() {
        if (!head) return;
        Node* current = head;
        do {
            cout << current->getData() 
                 << (current->getIsBooked() ? " (Booked)" : " (Available)") 
                 << " ";
            current = current->getNext();
        } while (current != head);
        cout << endl; 
    }

    void bookASeat(string seatName, string name) {
        Node* current = head;
        do {
            if (current->getData() == seatName) {
                if (!current->getIsBooked()) {
                    current->book(name);
                    cout << "Seat " << seatName << " booked successfully by " << name << "." << endl;
                } else {
                    cout << "Seat " << seatName << " is already booked by " << current->getBookedBy() << "." << endl;
                }
                return;
            }
            current = current->getNext();
        } while (current != head);
        cout << "Seat " << seatName << " not found." << endl;
    }

    void cancelASeat(string seatName, string name) {
        Node* current = head;
        do {
            if (current->getData() == seatName) {
                if (current->getIsBooked()) {
                    if (current->getBookedBy() == name) {
                        current->cancel();
                        cout << "Seat " << seatName << " booking cancelled for " << name << "." << endl;
                    } else {
                        cout << "Seat " << seatName << " is booked by " << current->getBookedBy() << ", cannot cancel." << endl;
                    }
                } else {
                    cout << "Seat " << seatName << " is not booked." << endl;
                }
                return;
            }
            current = current->getNext();
        } while (current != head);
        cout << "Seat " << seatName << " not found." << endl;
    }
};

int main() {
    Row* rows[10];
    for (int i = 0; i < 10; ++i) {
        rows[i] = new Row();
        char rowLetter = 'A' + i;
        for (int seat = 0; seat < 7; ++seat) {
            rows[i]->addSeat(rowLetter, seat);
        }
    }

    string name;
    string sName;
    int no, no1;
    int choice;
    do {
        cout << "Enter your choice\n1->Display Free Seats\n2->Book A Seat\n3->Cancel A Seat\n4->Exit the program" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            for (int i = 0; i < 10; ++i) {
                cout << "Row " << char('A' + i) << ": ";
                rows[i]->freeSlotsDisplay(); 
            }  
            break;
        case 2:
            cout << "Enter Your Name: ";
            cin >> name;
            cout << "Enter The Seat Name to be booked (e.g., A0): ";
            cin >> sName;
            no = sName[0] - 'A'; // Row number
            rows[no]->bookASeat(sName, name);
            break;
        case 3:
            cout << "Enter Your Name: ";
            cin >> name;
            cout << "Enter The Seat Name to be canceled (e.g., A0): ";
            cin >> sName;
            no1 = sName[0] - 'A'; // Row number
            rows[no1]->cancelASeat(sName, name);
            break;
        case 4:
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);

    for (int i = 0; i < 10; ++i) {
        delete rows[i];
    }

    return 0;
}
