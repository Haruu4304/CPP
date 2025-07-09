/*
Nesting - 
in map - it is a collection of key and value
the elements are inserted in comparision manner - 
if we are considering nesting inside the map we can use pairs, vectors
and sets because they are comparable.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // map<pair<int,int> , int> m;
    //pairs are comparable - lets check
    // pair<int,int> p1, p2;
    // p1 = {1,2};
    // p2 = {2,3};
    // cout << (p1 >  p2);

    //lets see how to insert, access and further operations 
    map<pair<string, string> , vector<int> > m;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string fn , ln;
        int ct;
        cin >> fn >> ln >> ct;
        for(int j=0; j<ct; ++j){
            int x;
            cin >> x;
            m[{fn,ln}].push_back(x);
        }
    }

    for(auto &pr:m){
        auto &full_name = pr.first;
        //pr.first.first = fn 
        //pr.first.second = ln

        //pr.second = vector
        auto &list = pr.second;
        //pr.second[0] = 0th value of vector
        cout << full_name.first<< " " << full_name.second << endl;
        cout << list.size() << endl;
        for(auto &element : list){
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}