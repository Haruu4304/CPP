/*set is a collection of keys.
these keys are unique.
sets are very much similar to map.
sets are used to store the values in sorting order
*/

#include<bits/stdc++.h>
using namespace std; 

void printSet(set<string> &s){
    for(string value : s){
        cout << value << endl;
    }
}

int main(){
    //decalaration of sets
    set<string> s;
    //to insert any value in set - 
    s.insert("harsha"); //log(n)
    s.insert("Surwase");
    s.insert("bce");
    auto it = s.find("harsha"); // it will return one iterator log(n)
    // printSet(s);

    if(it != s.end()){
        s.erase(it); //it returns iterator and also take log(n)
    }
    printSet(s);
}