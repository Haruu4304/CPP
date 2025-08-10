/*
so this is part 1 and here we are leraning some basic inbuilt functions - 
all these following function takes O(n) tc.
except count and find in map it takes O(log n) tc
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; //size of vector
    cin >> n; 
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    //we were trying to give full vector we can check or serach from specific index also
    int min = *min_element(v.begin()+3, v.end());
    cout << "min element : " << min << endl;
    //2nd func : 
    int max = *max_element(v.begin(), v.end());
    cout << "max element : " << max << endl;
    //3rd : accumulate : it is used to return sum
    int sum = accumulate(v.begin(), v.end() , 0); //here 0 is initial sum value
    cout << "sum : "<< sum << endl;
    //4th : count  
    int ct = count(v.begin(), v.end(), 6); //here it will check the 6 how many times it came in whole vector
    cout << "count : " << ct << endl;
    //5th : find
    auto it = find(v.begin(), v.end() , 10);
    if(it != v.end()){
        cout << *it << endl;
    }else{
        cout << "Element not find" << endl;
    }
    //6th : reverse the string or array 
    reverse(v.begin()+3, v.end());
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
    //now lets try with string
    string s = "abcdefgh";
    reverse(s.begin() , s.end());
    for(auto &val : s){
        cout << val << " ";
    }
    cout << endl;
}
