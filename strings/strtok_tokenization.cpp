#include<iostream>
#include<cstring>

using namespace std;

int main(){

	//strtok works on char array
	char input[1000];
	cin.getline(input, 1000);

	//cout<<strtok(input, " "); //gets first token..first word
	//strats from strarting of funtion,should update everytime

	//cout<<strtok(NULL, " ");
	//internally maintains the state ofhte string in last function
	//by making a static variable

	char *token = strtok(input, " ");
	cout<<token<<"\n";
	while(token){
		token= strtok(NULL, " ");
		cout<<token<<"\n";
	}


}