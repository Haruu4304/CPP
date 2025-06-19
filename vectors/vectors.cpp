// vectors are like arrays but are arrays is like a fixed size the size cannot varies
// but the vectors are like a dynamic size of arrays and one more similarities between vector and array is that
// both are use contigenous memeory allocation.

//Runtime errors in vectors- 
// limit on a locally vector is - 10^5
// and gloabal vector - 10^9

#include <bits/stdc++.h>
using namespace std;

void printVec(vector <int> v){
    // v.size() -> it is used to give current size of vector and it takes O(1)
    cout << "size : " << v.size() << endl;
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    //array declaration
    int arr[10]; // now the current size of array is 10
    //vectors declaration 
    vector <int> v; //current size of vector is 0
    //take input of int data type
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x); // tc -> O(1)
    }

    //for printing the vector
    printVec(v);


    //we can also create an vector by giving some size : 
    vector <int> v1; //here this 3 will be settled on the replace of 0
    //now we can change the size of array that means we can increment the size 
    v1.push_back(7);
    v1.push_back(5);
    printVec(v1);

    //we can remove it 
    v1.pop_back(); // this pop_back it is used to remove the last element from vector - tc => O(1)

    //we can directly copy from 1 vector to another : 
    //here are ony coping the vector the changes will not reflect on any one 
    vector <int> v2 = v1; // tc -> O(n) 
    // here insted of copying you can also use the references so the values will directly redirect their
    cout << "printing the v2 vector " <<endl;
    v2.push_back(5);
    printVec(v2);

    cout << "printing v1" <<endl;
    printVec(v1);
}