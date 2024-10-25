/*
In any language program mostly syntax error occurs due to
unbalancing delimiter such as (),{},[]. Write C++ program using
stack to check whether given expression is well parenthesized or
not
*/

#include<iostream>
#define MAXI 1000

using namespace std;
class Stack{
    private:
    char a[MAXI];
    public:
    int top=-1;
    // Checks if the stack is full or not
    bool isStackFull(){
        if(top>=MAXI){
            return true;
        }
        return false;
    }
    // Checks if the stack is empty or not
    bool isStackEmpty(){
        if(top<0){
            return true;
        }
        return false;
    }
    // Adds element to the stack
    void push(char ele){
        if(isStackFull()){
            cout<<"Stack Overflow"<<endl;
        }else{
            top++;
            a[top] = ele;
        }
    }
    // Removes element from the stack
    char pop(){
       if(isStackEmpty()){
       cout<<"Stack is empty "<<endl;
       return -1;
      }
    int x=a[top];
    top--;
    return x;
    }
    // Prints the stack
    void printStack(){
        for(int i=0;i<=top;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
   //Gives the element at top of head
    char peak(){
        return a[top];
    }
};

bool isValidParanthese(string s){
    Stack paranthesis;
    for(int i=0;i<=s.length();i++){
        char ch = s[i];
        switch (ch)
        {
        case '[':
            paranthesis.push(ch);
            break;
        case '(':
            paranthesis.push(ch);
            break;
        case '{':
            paranthesis.push(ch);
            break;
        case ']':
           if(paranthesis.peak()=='['){
            paranthesis.pop();
           }
           else{
            return false;
           }
           break;
        case ')':

           if(paranthesis.peak()=='('){
            paranthesis.pop();
           }
           else{
            return false;
           }
           break;
        case '}':
           if(paranthesis.peak()=='{'){
            paranthesis.pop();
           }
           else{
            return false;
           }
        break;
        default:
            break;
        }
       
    }
if(paranthesis.isStackEmpty()){
return true;
}else{
    return false;
}
}

int main(){
string userInp;
cout<<"Enter the expression"<<endl;
cin>>userInp;
bool result = isValidParanthese(userInp);
if(result){
    cout<<"Valid Parenthesis String"<<endl;
}
else{
    cout<<"Invalid Parenthesis String"<<endl;
}
}