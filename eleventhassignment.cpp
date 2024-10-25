#include<iostream>
using namespace std;
class Queue{
    private:
    string *arr;
    int front,rear,maxSize;
    public:
    Queue(int size){
       maxSize = size;
        arr = new string[maxSize];
        front = 0;
        rear=-1;
    }

    bool isFull(){
        if(rear>maxSize){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front>rear){
            return true;
        }
        return false;
    }
    void add(string ele){
         if(!isFull()){
            rear++;
            arr[rear]=ele;
            return;
         }
        cout<<"Queue is full"<<endl;
    }
    string pop(){
        if(!isEmpty()){
            string ele =arr[front];
            front++;
            return ele;
        }
        cout<<"Queue is empty"<<endl;
        return "/0";
    }
    void print(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        int s = front;
        int e =rear;
        while(s<=e){
            cout<<arr[s]<<" ";
            s++;
        }
        cout<<endl;
    }
};

int main(){
   int no,choice;
   string ch,num;
   cout<<"Enter the number of processes :"<<" ";
   cin>>no;
   Queue q1(no);
   while(true){
    cout<<"Menu:-\n1 -> Add a process \n2 -> Remove the first process \n3 -> Print the queue\n4 -> Exit the loop"<<endl;
    cout<<"Enter your Choice"<<" ";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the name of process:"<<endl;
       cin>>num;
        q1.add(num);
        break;
         case 2:
         ch=q1.pop();
         if(ch!="/0"){
            cout<<ch<<" deleted from the queue"<<endl;    
         }
        break; 
        case 3:
        q1.print();
        break;
        case 4:
        exit(0);
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }
   }  
}