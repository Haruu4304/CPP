#include<bits/stdc++.h>
using namespace std;

vector<pair<int , int>> operations = {{100,0}, {75,25}, {50,50}, {25,75}};

//now we will try with memorization: 
vector<vector<double>> t;
double Prob_A_empty(int A, int B){
    if(A <= 0 && B <= 0){
        return 0.5;
    }
    if(A <= 0){
        return 1.0;
    }
    if(B <= 0){
        return 0.0;
    }

    if(t[A][B] != -1.0){
        return t[A][B];
    }

    double prob = 0.0;
    for(auto &p : operations){
        int A_taken = p.first;
        int B_taken = p.second;

        //at the end we have to sum all the P1, P2, P3, P4 (probability)
        prob += Prob_A_empty(A - A_taken, B-B_taken);
    }
    return t[A][B] = 0.25*prob;
}

double soupServing(int n){
    // Optimization: for large enough n, the answer approaches 1
    if(n >= 4800) return 1.0;
    t.resize(n+1, vector<double>(n+1 , -1.0));

    return Prob_A_empty(n, n);
}

int main(){
    int n = 50;
    double result  = soupServing(n);
    cout << "Result : " << result;
}