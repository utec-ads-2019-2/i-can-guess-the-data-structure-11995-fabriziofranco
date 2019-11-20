#include <stack>
#include <queue>
#include <iostream>
using namespace std;


void print(bool STACK, bool QUEUE, bool PRIORITY);

void popAndCompare(stack<int> &myStack, queue<int> &myQueue, priority_queue<int> &myPriority, int number, bool &STACK,
                   bool &QUEUE, bool &PRIORITY);

void pushInStructures(bool STACK, bool QUEUE, bool PRIORITY, stack<int> &myStack, queue<int> &myQueue,
                      priority_queue<int> &myPriority, int number);

int main(){
    int input;
    while (cin >>input){
        bool STACK = true, QUEUE = true, PRIORITY = true;
        stack<int> myStack;queue<int> myQueue; priority_queue<int> myPriority;
        for(auto i=0;i<input;i++){
            int behavior, number;
            cin >> behavior >> number;
            if (behavior==1) {
                pushInStructures(STACK, QUEUE, PRIORITY, myStack, myQueue, myPriority, number);
            }
            else{
                popAndCompare(myStack, myQueue, myPriority, number, STACK, QUEUE, PRIORITY);
            }
        }
        print(STACK, QUEUE, PRIORITY);
    }
}

void pushInStructures(bool STACK, bool QUEUE, bool PRIORITY, stack<int> &myStack, queue<int> &myQueue,
                      priority_queue<int> &myPriority, int number) {
    if (STACK)
        myStack.push(number);
    if (QUEUE)
        myQueue.push(number);
    if (PRIORITY)
        myPriority.push(number);
}

void popAndCompare(stack<int> &myStack, queue<int> &myQueue, priority_queue<int> &myPriority, int number, bool &STACK,
                   bool &QUEUE, bool &PRIORITY) {
    if (STACK){
        if (myStack.empty() or myStack.top() != number)
            STACK = false;
        else
            myStack.pop();
    }
    if (QUEUE){
        if (myQueue.empty() or myQueue.front() != number)
            QUEUE = false;
        else
            myQueue.pop();
    }
    if (PRIORITY){
        if (myPriority.empty() or myPriority.top() != number)
            PRIORITY = false;
        else
            myPriority.pop();
    }
}

void print(bool STACK, bool QUEUE, bool PRIORITY) {
    if (!STACK and !QUEUE and !PRIORITY)
        cout << "impossible\n";
    else if ((STACK and QUEUE) or (STACK and PRIORITY) or (QUEUE and PRIORITY))
        cout << "not sure\n";
    else if (STACK)
        cout << "stack\n";
    else if (QUEUE)
        cout << "queue\n";
    else
        cout << "priority queue\n";
}
