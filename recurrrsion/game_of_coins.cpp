#include <bits/stdc++.h>
using namespace std;
int best_score=0;

int recur(vector<int> v, int i, int j, int n){
    if(i>j){
        return 0;
    }
    //choice 1 = number u chose + number the opponent chooses for u which is min 
    int choice1 = v[i]+ min(recur(v, i+2, j, n), recur(v, i+1, j-1, n));
    int choice2 = v[j]+ min(recur(v, i+1, j-1, n), recur(v, i, j-2, n));

    return max(choice2, choice1);

}

int MaxValue(int n, vector<int> v){

    int sum=0;
    best_score = recur(v, 0, n-1, n);
    cout<<best_score<<"\n";
        for(int x:v) sum+=x;
        if(best_score>=sum-best_score){
            return true; // best>opponent's score
        }
        else return false;

}

int main(){
    int n=5;
    vector<int> v = {5, 3, 6, 10, 7};
    cout << MaxValue(n, v) <<"\n";
}
