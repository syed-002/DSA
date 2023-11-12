#include<bits/stdc++.h>

using namespace std;

//my own tokeniser without using sstream and strtok
char* tokeniser(char *token, char delim){

	static char * input= NULL;
	if(token!= NULL){
		input=token;
	}
	if(input==NULL) return NULL;
	//to return the array we use dynamic array
	//if you use static, it will creatrd locally n will be destroyed
	
	char *string = new char[strlen(input)+1];
	//+1 is for the null char

	int i=0;
	while(input[i]){
		if(input[i]!=delim){
			string[i] = input[i];
			//here we are adding letters one by one
			//until its not equal to space (delim)
			i++;
		}
		else{
			string[i]='\0'; //adding null char to make it token
			input = input+i+1; //pointing to the next word
			//updated the static variable (input)
			return string;
		}
	}

	//out of loop.. last 
	//string[i] = '\0';
	//resset the input to null
	//input = NULL;
	return string;
}

int main(){
	char input[1000];
	cin.getline(input, 1000);
	char delim = ' ';

	char * token =  tokeniser(input, delim);
	while(token){
		cout<<token<<"\n";
		token =  tokeniser(NULL, delim);
	}
	return 0;
}