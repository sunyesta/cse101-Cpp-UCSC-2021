
#include <bits/stdc++.h>
using namespace std;

void myRecursiveFunction(int n){
    if(n>0){
        myRecursiveFunction(n-1);
        cout<<n<<" ";
    }else{
        return;
    }
}

//steps to make a recursive function into a stack
//1) create an obj that holds variables for each changing parameter of the 
//   recursive function. We will call this stackObj
class stackObj{
    public:
        int n;
        stackObj(int n){
            this->n = n;
        }
};

//2) create a stack that holds stackObjs at the beggining of the function

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;

    if(n>0){
        myRecursiveFunction(n-1);
        cout<<n<<" ";
    }else{
        return;
    }
}

//3) create a stackObj that resembles the initial call to the recursive function's
//   parameters and push it onto the stack

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));

    if(n>0){
        myRecursiveFunction(n-1);
        cout<<n<<" ";
    }else{
        return;
    }
}
//4) wrap the rest of a code in a while(stack isn't empty loop)

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));
    
    while(!recurStack.empty()){
        if(n>0){
            myRecursiveFunction(n-1);
            cout<<n<<" ";
        }else{
            return;
        }
    }
}

//5) as the first line of the while loop create a stackObj, call it stackTop,
//   and set it to the top stackObj of the stack. Then pop the top item from
//   the stack

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));
    
    while(!recurStack.empty()){
        stackObj stackTop = recurStack.top();
        recurStack.pop();

        if(n>0){
            myRecursiveFunction(n-1);
            cout<<n<<" ";
        }else{
            return;
        }
    }
}

//6) at the halting case, replace "return" with "continue" if it is present

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));
    
    while(!recurStack.empty()){
        stackObj stackTop = recurStack.top();
        recurStack.pop();

        if(n>0){
            myRecursiveFunction(n-1);
            cout<<n<<" ";
        }else{
            continue;
        }
    }
}

//7) wherever you usually call the function again, replace it with a call that
//   pushes a new stackObj onto the stack with the values that match the
//   parameters of the old recursive call
//

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));
    
    while(!recurStack.empty()){
        stackObj stackTop = recurStack.top();
        recurStack.pop();

        if(n>0){
            recurStack.push(stackObj(n-1));
            cout<<n<<" ";
        }else{
            continue;
        }
    }
}

//8) add stackTop.(your paramter here) wherever a parameter isn't defined anymore

void myStackFunction(int thisn){
    stack<class stackObj>recurStack;
    recurStack.push(stackObj(thisn));
    
    while(!recurStack.empty()){
        stackObj stackTop = recurStack.top();
        recurStack.pop();

        if(stackTop.n>0){
            recurStack.push(stackObj(stackTop.n-1));
            cout<<stackTop.n<<" ";
        }else{
            continue;
        }
    }
}


// all done!


