// Pair is a class what is used to store 2 values.

#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<int,string> p;
    //to make paris we use this - make_pair
    p = make_pair(3, "harsha");
    //another way to create a pairs is -
    p = {3, "Harsha"};
    cout << p.first << " " << p.second << endl;

    //we have 2 arrays a and b and if we changed one pattern the the alternate one should also changed
    int a[3] = {1,2,3};
    int b[3] = {3,4,5};

    pair<int,int> p1_array[3];
    p1_array[0] = {1,3};
    p1_array[1] = {2,4};
    p1_array[2] = {3,5};
    swap(p1_array[0] , p1_array[2]);
    for(int i=0; i<3; i++){
        cout << p1_array[i].first << " " << p1_array[i].second <<endl;
    }

    //if you want to take input in pairs
    pair <int,string> pp;
    cin >> pp.first;
    cout << pp.first<< endl;
}