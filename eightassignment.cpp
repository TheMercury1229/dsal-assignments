/*
Write C++ program for storing appointment schedule for day. Appointments
are booked randomly using linked list. Set start and end time and min and
max duration for visit slot. Write functions for- a) Display free slots b) Book
appointment c) Cancel appointment (check validity, time bounds,
availability) d) Sort list based on time e) Sort list based on time using
pointer manipulation
*/
#include <iostream>
using namespace std;

class Node {
public:
    int start, end, min, max;
    bool flag;
    Node *next;
    
    Node(int s, int e, int m, int ma) : start(s), end(e), min(m), max(ma), flag(false), next(nullptr) {}
};

class AppointmentList {
private:
    Node *head;

public:
    AppointmentList() : head(nullptr) {}

    void createSchedule() {
        int size;
        int startTime, endTime, minTime, maxTime;
        cout << "Enter the number of appointment slots: ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout<<"For the slot "<<i+1<<endl;
            cout << "Enter the start time of the appointment: ";
            cin >> startTime;
            cout << "Enter the end time of the appointment: ";
            cin >> endTime;
            cout << "Enter the min time of the appointment: ";
            cin >> minTime;
            cout << "Enter the max time of the appointment: ";
            cin >> maxTime;
            Node *newNode = new Node(startTime, endTime, minTime, maxTime);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node *temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    void displaySchedule() {
        Node *temp = head;
        int cnt = 1;
        cout << "Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus" << endl;
        while (temp) {
            cout << cnt << "\t" << temp->start << "\t" << temp->end << "\t"
                 << temp->min << "\t" << temp->max << "\t"
                 << (temp->flag ? "Booked" : "Not booked") << endl;
            temp = temp->next;
            cnt++;
        }
    }

    void bookAppointment() {
        int start, time;
        cout << "Enter the appointment start time: ";
        cin >> start;
        cout << "Enter the time of appointment needed: ";
        cin >> time;
        
        Node *temp = head;
        while (temp) {
            if (temp->start == start && !temp->flag) {
                if (temp->max >= time) {
                    cout << "The appointment has been booked." << endl;
                    cout << "The start time of the meeting is " << temp->start << endl;
                    cout << "The time allotted to meet is " << time << endl;
                    temp->flag = true;
                } else {
                    cout << "The appointment cannot be booked due to unavailability of time." << endl;
                }
                return; // Exit after booking
            }
            temp = temp->next;
        }
        cout << "Appointment slot not found or already booked." << endl;
    }

    void cancelAppointment() {
        int start;
        cout << "Enter the start time of the appointment to cancel: ";
        cin >> start;

        Node *temp = head;
        while (temp) {
            if (temp->start == start && temp->flag) {
                temp->flag = false;
                cout << "Appointment at " << start << " has been canceled." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No booked appointment found at this start time." << endl;
    }

    void sortList() {
        if (head == nullptr) return;

        bool swapped;
        do {
            swapped = false;
            Node *current = head;
            Node *prev = nullptr;

            while (current->next != nullptr) {
                if (current->start > current->next->start) {
                    
                    Node *nextNode = current->next;
                    current->next = nextNode->next;
                    nextNode->next = current;

                    if (prev == nullptr) {
                        head = nextNode;
                    } else {
                        prev->next = nextNode;
                    }

                    swapped = true;
                    prev = nextNode;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Create Schedule\n";
            cout << "2. Display Schedule\n";
            cout << "3. Book Appointment\n";
            cout << "4. Cancel Appointment\n";
            cout << "5. Sort Appointments\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: createSchedule(); break;
                case 2: displaySchedule(); break;
                case 3: bookAppointment(); break;
                case 4: cancelAppointment(); break;
                case 5: sortList(); displaySchedule(); break;
                case 6: cout << "Exiting..." << endl; break;
                default: cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != 6);
    }
};

int main() {
    AppointmentList appointmentList;
    appointmentList.displayMenu();
    return 0;
}
