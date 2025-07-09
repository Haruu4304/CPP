//this topic is divided into 3 sections - 
// 1) vectors of pairs 
// 2) array of vectors and 
// 3) nested vectors

#include <bits/stdc++.h>
using namespace std;

void printVec(vector <int> v){
    cout << "size : " << v.size() <<endl;
    for(int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout<< endl;
}

// 1) vectors of pairs :- 
int main(){
    //here we are creating vectors with each element as pair
    vector<pair<int , int>> v;
    //taking vales as input
    int n;
    cin >> n;
    for(int i=0; i<n ;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    printVec(v);
}

//array of vectors - 
int main(){
    //here the below code containing the value inside the square bracket is not the size of 
    // vector instead it is an no of vector you are 
    // trying to create now in this following declaration we are going to create 10 vectors
    vector <int> v[10];
    int N;
    cin >> N;
    for(int i=0; i<N; ++i){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i=0; i<N; ++i){
        printVec(v[i]);
    }

}

//vectors of vectors - 
int main(){
    int N;
    cin >> N;
    vector <vector<int> > v;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vector <int> temp;
        for(int j=0; j<n ;++j){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    
}