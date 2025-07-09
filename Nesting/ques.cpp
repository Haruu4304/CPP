/*
Question based on this nesting - 
condition -
i) store in decreasing order 
ii)if same marks are their then store in lexicographical order
i/p                     o/p
eve 78                  bob 90
bob 90                  alice 78
alice 78                eve 78
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,multiset<string>> marks_map;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int marks;
        string name;
        cin >> name >> marks;
        marks_map[-1*marks].insert(name);//creating a negative numbers so they will store in decreasing order only
    }
    //to display it in decreasing order we have to reverse it 
    //to reverse - end() -> it will point on the next element of end
    // auto cur_it = --marks_map.end();
    // while(true){
    //     auto &students = cur_it->second;
    //     int marks = cur_it->first;
    //     for(auto student : students){
    //         cout << student << " " << marks << endl;
    //     }
    //     //how long it will run 
    //     if(cur_it == marks_map.begin()){
    //         break;
    //     }
    //     cur_it--;
    // }

    // now we are going to learn new concept that is negative numbers -97 > -99
    // so here are using the same logic for reverse instead of infinite loop
    for(auto &marks_students_pr : marks_map){
        auto &students = marks_students_pr.second;
        int marks = marks_students_pr.first;
        for(auto student : students){
            cout << student << " " << -1*marks << endl;
        }
    }
}