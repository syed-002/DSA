#include<bits/stdc++.h>
using namespace std;


void merge(int l, int r, int mid, vector<int>a){

	int i=l, j = mid+1, k =0;
	vector<int> temp(r-l+1, 0);
	while(i<= mid and j<=r){
		if(a[i]< a[j]){
			temp[k] = a[i];
			i++;
			k++;
		}
		else{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		temp[k]= a[i];
		i++;
		k++;
	}
	while(j<=r){
		temp[k] = a[j];
		j++;
		k++;
	}
	//copying them to array

	for(int i=l; i <= r; i++){
		a[i] = temp[i-l];
 	}

 	temp.clear();

}


void mergesort(int l, int r, vector<int> a){

	if(l!=r){
		int mid = l+ (r-l)/2;
		mergesort(l, mid, a);
		mergesort(mid+1, r, a);
		merge( l, r,  mid, a);
	}
}

int largestArea(vector<int> a1, int N, vector<int> a2, int M){

	mergesort(0, N, a1);
	for(auto i:a1){
    	cout<< i << " ";
    }
	mergesort(0, M, a2);
    cout<< endl;
    for(auto i:a2){
    	cout<< i << " ";
    }
    cout<< endl;
    int s=0, e=0, i=0, j=0;
    while(i<N and j<M){
    	if(a1[i] == a2[j]){
    		if(s==0){ //to recognize the starting poitn
    			s = a1[i];
    		}
    		else{
    			e = a1[i]; //updating max point everytime
    		}
    		
    		i++, j++;
    	}
    	else if(a1[i]>a2[j]){
    		j++;
    	}
    	else{
    		i++;
    	}
    	cout<< "s : " << s << endl;
    	cout<< "e : " << e << endl;

    }
    cout<< "s : " << s << endl;
    cout<< "e : " << e << endl;
    if(s==0 or e==0){
    	return 0;
    }
    else{
    	return e-s;
    }
}


int main()
{
    // Given point
    vector<int> arr1 = {1,3,5};
 
    // Given length
    int N = arr1.size();
 
    // Given points
    vector<int> arr2= {4,2,10};
 
    // Given length
    int M =arr2.size();
 
    // Function Call

    cout << largestArea(arr1, N, arr2, M);
 
    return 0;
}