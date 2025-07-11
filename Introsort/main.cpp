/*
lets first understand what is sort function in cpp - 
in cpp we have inbuild sort func - sort() : it is used to sort the element 
and this function takes 2 parameter i) from where it start that index or address or pointer
                                    ii) end of element + 1 (jaha tk sorting karna hai uska next element 
                                    ka address);
lets some learn about introsort concept - 
introsort is a combination of 3 type of sort - i) insertion sort
                                               ii) heap sort
                                               iii) quick sort
it is best sorting algorithm
how it works -> first it applies quick sort then heap and when the no of elements are lesser then
                it applies insertion sort
time complexity of this introsort is - O(NlogN)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());

    for(int i=0; i<n; i++){
        cout << a[i] << endl;
    }

}