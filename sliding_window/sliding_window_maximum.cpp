#include<bits/stdc++.h>
using namespace std;

void slid_wind_max(vector<int>a, int k){

    deque<int> Q(k); //deque of size k
    int i;
    for(i=0; i<k; i++){

        while(!Q.empty() and a[i]> Q.back()){
            Q.pop_back();
        }
        Q.push_back(i);

    }

    for( ; i<a.size(); i++){
        
        cout<< a[Q.front()] << " ";
        //for removing the elements out of the window
        //contracting from left
        while(!Q.empty() and Q.front()<= i-k){
            Q.pop_front();
        }

        
        //for popping the smaller elemt indices 

         while(!Q.empty() and a[i]>=a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);


    }

    while(!Q.empty()){
        cout<<a[Q.front()] << " ";
        Q.pop_front();
    }

}

int main(){

    vector<int>a = {1,2,3,1,4,5,2,3,5};
    //op = 3,3,4,5,5,5,5
    int k = 3;

    slid_wind_max(a, k);
    return 0;

}