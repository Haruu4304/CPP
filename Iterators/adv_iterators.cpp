// today we are goint to learn about the range based loops which will reduced your no of lines of code 
// as you can see in iterator we have to write a big line but we can use it simple
// but remember the int value : v -> here the value it takes as copy if you make any changes it will not 
// reflect. so u can use references
// these range based loops can be used int everywhere. 

// Auto keyword - 
// it is used to assume the data type dynamically.

#include <bits/stdc++.h>
using namespace std;

int main(){
//     vector<int> v;
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++){
//         int x;
//         cin >> x;
//         v.push_back(x);
//     }

//     // for(int i=0; i<v.size(); ++i){
//     //     cout << v[i] << endl;
//     // }
// //with range based of loops
//     for(int &value : v){ //here it is taking the value like copy
//         value++;
//     }

//     //now lets do it with references
//     for(int value : v){ 
//         cout << value << endl;
//     }

    //lets use range based with pairs
    vector<pair<int, int>> v_p = {{1,2},{2,3},{4,5}};
    // for(pair<int,int> &value : v_p){
    //     cout << value.first << " " << value.second << endl;
    // }
    for(auto &value : v_p){
        cout << value.first << " " << value.second << endl;
    }

    auto a = 10;
    cout << a << endl;

    
}