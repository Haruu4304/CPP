/*
it allows multiple set to decalre
time complexity is -> O(log n)
it uses red black trees
it allows dublicates
it use to replce the priority queues
*/

#include <bits/stdc++.h>
using namespace std; 

int main(){
    multiset<string> s;
    s.insert("abc"); //O(log n)
    s.insert("bfd");
    s.insert("sgsdg");
    s.insert("abe");

    auto it = s.find("abc"); // this find will send the 1st value if that values dubilcates are presetn
    if(it!=s.end()){
        s.erase(it); //that value only will get deleted
    }

    for(auto value : s){
        cout << value << endl;
    }

    s.erase("abc"); // all the values will be deleted if duplicates are their then both will delete

    for(auto value : s){
        cout << value << endl;
    }
}