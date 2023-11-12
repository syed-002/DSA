#include<bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string s) {
    bool flag = true;
    int n=s.size();
    
    if(n==1) return true;

    for(int i=0; i<n; i++){
        if(s[i]>= 'A' and s[i]<= 'Z') {
            //cout<<"pass\n";
            continue;
        }
        else{
            //cout<<s[i]<<"\n";
            flag = false;
            break;
        }
    }
    if(flag == true) return true;
    else{
        flag=true; //reinitializing to true
        for(int i=0; i<n; i++){
            if(s[i]>= 'a' and s[i]<= 'z') {
                
                continue;
            }
            else{
                //cout<<s[i]<<"\n";
                flag = false;
                break;
             }

        }
        if(flag== true){
            cout<<"gettin re\n";
            return true;
        } 
        else{
            flag= true;
            if(s[0]>= 'A' and s[0]<= 'Z'){
              for(int i=1; i<n; i++){
                    if(s[i]>= 'a' and s[i]<= 'z') continue;
                    else{
                        flag = false;
                        break;
                     }
                }  
            }
            else flag = false;
        }
    }
    return flag;
}

int main(){
    string s = "AleX";
    cout<< detectCapitalUse(s) << "\n";
}