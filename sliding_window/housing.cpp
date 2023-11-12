#include <bits/stdc++.h>
using namespace std;

// int subarraySum(vector<int>& a, int k) {
    

//     //only for positive integered array
//     vector<pair<int, int>> ind;
    
//     int i=0, j=0, cs = 0;//current_sum

//     while(j<a.size()){

//         cs+= a[j];
//         j++;

//         while(cs>k){
//             cs-=a[i];
//             i++;
//         }

//         if(cs==k){
//             cout<< i<< " " <<j-1 << "\n";
//             ind.push_back(make_pair(i, j));
//         }

//     }
//     return ind.size();
// }

int subarraySum(vector<int>& a, int k) {
    
    //for -ve integered array
    //use hashmap

    //it doesnt store if the cur sum repeats for more than once since we are storing it in the index vector
    //to handle that, we are creating another fucntion where they keep a count that how many times current sum
    // repeats while addint the elements


    unordered_map<int, int> hmap;
    int cs=0, start;

    //for storing those indices
    vector<pair<int, int>> ind;

    for(int i=0; i<=a.size(); i++){
        cs+=a[i];

        //if the subarray is from the index 0, then obviously its nnot stored in hashmap
        if(cs==k){
            ind.push_back(make_pair(0,i));
        }

        //if end pointer is not returned then the cs-k is present in the hashmap
        if(hmap.find(cs-k) != hmap.end()){

            start=hmap[cs-k]+1;
            ind.push_back(make_pair(start, i));
        }
        hmap.insert(make_pair(cs, i));



    }


    for(auto i:ind){
        cout<< i.first<< " " << i.second<<"\n";
    }

    return ind.size();

}

//new optimzied

int final(vector<int> a, int k){

    int cs = 0;
    int ans=0;
    unordered_map<int, int> map;
    for(int i=0; i<a.size(); i++){

        cs+= a[i];
        //found at the beginning of the array
        if(cs==k){
            ans++;
        }

        //the other cs which is not k and also repeats such that 
        //those repeated times should also be recorded

        if(map.find(cs-k)!= map.end()){
            ans+= map[cs-k];
        }
        map[cs]++;

    }
    return ans;
//hashmap after every iteratoin for the given testcase
// 10 1

// 12 1
// 10 1

// 12 1
// 10 2

// -10 1
// 12 1
// 10 2

// 0 1
// -10 1
// 12 1
// 10 2

// 0 1
// -10 1
// 12 1
// 10 3

// 0 2
// -10 1
// 12 1
// 10 3

// 40 1
// 0 2
// -10 1
// 12 1
// 10 3

// 40 1
// 0 2
// -10 2
// 12 1
// 10 3

// -70 1
// 40 1
// 0 2
// -10 2
// 12 1
// 10 3

// 30 1
// -70 1
// 40 1
// 0 2
// -10 2
// 12 1
// 10 3

// 30 1
// -70 1
// 40 1
// 0 3
// -10 2
// 12 1
// 10 3

// 30 1
// -70 1
// 40 1
// 0 3
// -10 3
// 12 1
// 10 3

// 17    

}

    
int main() {
	// your code goes here
	// vector<int> a = {1,3,2,1,4,1,3,2,1,1,2};
	// int k=8;
    // vector<int> a = {-1, 1, -1, 2, -1};
    // int k=0;
    // vector<int> a ={-1, -1 ,1};
    // int k=0;
    //  vector<int> a ={10, 15, -5, 15, -10, 5};
    // int k=5;
     // vector<int> a = {10, 2, -2, -20, 10};
     // int k=-10;
    vector<int> a = {10,2,-2,-20,10,10,-10,40,-50,-60,100,-30,-10};
    int k = -10;
	cout<< final(a,k);
	return 0;
}
