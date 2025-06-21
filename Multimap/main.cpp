/*multimap is very similar to multimap 
here one difference between map and multimap is when we are trying to
store the same key value in map it will not happen it will only update 
the value of value term
but in multimap it will happen.

when you want to store multiple data we can use multimap.
it is also used to ordered manner
*/

#include <bits/stdc++.h>
using namespace std;

void printMM(multimap<int ,string> mm){
    cout << "Size: " << mm.size() << endl;
    for(auto &value : mm){
        cout << value.first << " " << value.second << endl;
    }
}

int main(){
    multimap<int , string> mm;
    mm.insert({3,"asbc"});
    mm.insert({5,"asbc"});
    mm.insert({32,"asbc"});
    mm.insert({1,"asbc"});
    mm.insert({5,"asbc"});

    printMM(mm);
}