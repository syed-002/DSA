#include<cstring>
#include<iostream>
using namespace std;

void replace_space(char *str){
	int spaces =0;
	for(int i=0; i<strlen(str); i++){
		if(str[i]==' ') spaces++;
	}
	int ind= strlen(str)+ 2*spaces;
	str[ind]='\0'; //end char
	for(int i=strlen(str)-1; i>=0; i--){
		if(str[i]==' '){
			str[ind-1]='0';
			str[ind-2]='2';
			str[ind-3]='%';
			ind=ind-3;
			//going from backwards --> -ve
		}
		else{
			str[ind-1]=str[i]; //i=last char b4 end char
			//ind-1 is also last char b4 end char
			// we are just copying
			ind--;
		}
	}
	
}

int main(){
	char input[10000];
	cin.getline(input, 10000); //here 10k is the max length input can be
	replace_space(input);
	cout<<input<<"\n";

}