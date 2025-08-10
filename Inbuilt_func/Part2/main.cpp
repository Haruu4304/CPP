/*
this is part 2 :
and here we will learn lambda function 
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    auto sum = [](int x){ // this is syntax of lambda function
        return x+2;
    };
    cout << sum(4) << endl;
}