// what is iterators ? -> Sometimes we are not able to access the elements from contains directly like we 
// do in array and other way by using indexing but in this scenario we can't use indexing to access the 
// elements from containers. So here we use 'Iteratoers'. 
//Iterators are also contigenous
// It just same like pointer where pointers are used to point the memeory address of any variable here
// we use (*) to access the data.
// in this iterators we have 2 functions - i) begin and ii) end
// i) v.begin() -> it is used to point the element of any vector.
// ii) v.end() -> it is used to point the next to the last element of the vector.

//what is difference between ++it and it+1 ; 
//so ++it -> it is used to point on the next iterator of the vector
// and it+1 -> it is used to point on the next location
// now in our case of vector we can use both ++it and it+1 because our vector are contigenous right
// but we are considering that we can use these iterators over the container like maps and set right ?
// so in these map and set the allocation of elements are not in contigenous manner their the elements can 
// be store anywhere so here we can't directly use the it+1 because it is used to point the next location
// thats why we use ++it it will point on next iterator.

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }

    //iterator declaration - 
    vector <int> :: iterator it = v.begin();
    //now print the vector through iterator
    for(it=v.begin(); it!= v.end(); ++it){
        cout << (*it) << endl;
    }

    //now initializing the iterators with pairs
    vector<pair<int, int>> v_p = {{1,2} , {2,3} , {4,5}};
    //create now iterator
    vector<pair<int, int>> :: iterator it_p;
    for(it_p = v_p.begin(); it_p!= v_p.end(); ++it_p){
        cout << (it_p->first) << " " << (it_p->second) << endl;
    }
}