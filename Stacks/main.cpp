/*
Stacks is a lifo ds (last in first out)
only 2 operations - i) push
                    ii)pop (top element remove)
                    iii)peak
*/

//stack basic operations 
// by using push , pop , isEmpty and isFull

/*
Stack overflow  - when the stack is full and you are trying to push one 
element then stack overflow occurs.
Stack Underflow  - when the stack is empty and still you are trying to pop 
an element from it.
*/

#include<bits/stdc++.h>
using namespace std;

//stack overflow condition - 
void isStackFull(stack<int> &ss, int elem , int n){
    if(ss.size() >= n){
        cout << "stack is overflow" << endl;
    }else{
        ss.push(elem);
    }
}

//stack underflow condition - 
void popTopelement(stack<int> ss){
    if(ss.size() == 0){
        cout << "stack is underflow!!!" << endl;
    }
    ss.pop();
    cout << ss.top() << endl;
}

int main(){
    stack<int> ss;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int elem;
        cout << "enter the element you want to insert" << endl;
        cin >> elem;
        isStackFull(ss, elem, n);
    }
    //to display the elements - 
    if(!ss.empty()){
        cout << ss.top() << endl;
    } 

    //now remove the top element - 
    popTopelement(ss);

    return 0;
}