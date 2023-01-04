#include<iostream>
#include<thread>
#include<string.h>
using namespace std;
char str[50];
void input(){
	
	try
    {
        cout << "Enter a string: ";
        cin >> str;
    }
    catch (const exception& ex)
    {
        cout << "Exception " << ex.what() << endl;
    }

	cout<<"Entered string is   "<<str;
	
	
}


void reverse(){
 	for(int i=0;i<strlen(str)/2;i++){
 		swap(str[i],str[strlen(str)-i-1]);
	 }
 
	cout<<"\nReversed   "<<str;
	
	
	
	
	
	
}
void captalize(){
	int flag = 0;
	char i;
	
	while(1){
		if(str[flag]>=97 and str[flag]<=122){
			str[flag] = char(int(str[flag])-32);
		}
//		str[flag] = char(int(str[flag])+2);
		else if(str[flag]>=65 and str[flag]<=90){
			continue;
		}

		
		flag++;				//for going through the char array
		i = str[flag];		// if i == \0 which is always present at the end of a string
		
		if(i=='\0'){
			break;
		}
	}
	cout<<endl<<"Capatalized  "<<str;
	
	
}


void shift(){
	cout<<endl;
	char i;
	int flag = 0;
	while(1){
		str[flag] = char(int(str[flag])+2);
		
		flag++;				//for going through the char array
		i = str[flag];		// if i == \0 which is always present at the end of a string
		
		if(i=='\0'){
			break;
		}
	}
	cout<<"Shifted String   "<<str;
	
}


int main(){
	thread t(&input);
	t.join();
	thread t1(&reverse);
	t1.join();
	thread t2(&captalize);
	t2.join();
	thread t3(&shift);
	t3.join();
	
	
}
