#include <iostream>
using namespace std;

#define MAXI 1000

class Stack {
private:
    char* a;
    int maxSize;
    int top;

public:
    Stack(int size) {
        maxSize = size;
        a = new char[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] a;
    }

    // Checks if the stack is full or not
    bool isStackFull() {
        return top >= maxSize - 1;
    }

    // Checks if the stack is empty or not
    bool isStackEmpty() {
        return top < 0;
    }

    // Adds an element to the stack
    void push(char ele) {
        if (isStackFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            a[++top] = ele;
        }
    }

    // Removes an element from the stack
    char pop() {
        if (isStackEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return a[top--];
    }

    // Gives the element at the top of the stack
    char peak() {
        if (isStackEmpty()) {
            return -1;
        }
        return a[top];
    }
};


// Utility to check precedence of operator
int givePrecedence(char op) {
    switch (op) {
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

string postfixConverter(const string& infix) {
    string postfix = "";
    Stack operators(infix.length());
    
    for (int i = 0; i < infix.length(); i++) {
        char current = infix[i];
        
        if (isdigit(current)) {
            postfix += current;
        } else if (current == '(') {
            operators.push(current);
        } else if (current == ')') {
            while (!operators.isStackEmpty() && operators.peak() != '(') {
                postfix += operators.pop();
            }
            operators.pop(); // Remove the '(' from stack
        } else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (!operators.isStackEmpty() && givePrecedence(current) <= givePrecedence(operators.peak())) {
                postfix += operators.pop();
            }
            operators.push(current);
        }
    }
    
    while (!operators.isStackEmpty()) {
        postfix += operators.pop();
    }
    
    return postfix;
}

int evaluatePostfix(const string& postfix) {
    Stack operands(postfix.length());
    
    for (int i = 0; i < postfix.length(); i++) { 
        char ch = postfix[i];
        
        if (isdigit(ch)) {
            operands.push(ch);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int A = operands.pop() - '0';
            int B = operands.pop() - '0';
            int result;
            switch (ch) {
            case '+':
               result=B+A;
                break;
            case '-':
                result=B-A;
                break;
            case '*':
                result=B*A;
                break;
            case '/':
                result=B/A;
                break;
            default:
                result = 0;
                break;
            }
            operands.push(result + '0');
        }
    }
    
    return operands.pop() - '0';
}

int main() {
    string infix;
    cout << "Enter the infix operation: ";
    cin >> infix;
    
    string postfix = postfixConverter(infix);
    cout << "Postfix Expression: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Result of Postfix Expression: " << result << endl;
    

    return 0;
}
