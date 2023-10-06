#include <stdio.h> 
#include <conio.h> 
#include <string.h> 
 
void main(){
    char username[20]; 
    char userpwd[8]; // for storing password 
    int i; 

    printf("Enter your username : "); 
    //gets(username); 
    scanf("%s",username);
    printf("Enter your password : "); 
    scanf("%s",userpwd);
    /* accept password */ 
    // for(i=0;i<8;i++){ 
    //     userpwd[i]=getch(); 
    //     printf("*");   	 
    // } 
    // userpwd[i]='\0'; 

    // printf("\n\nPress any key to continue"); 
    // getch(); 

    if(!strcmp(username,"shaidsk")){
        if (!strcmp(userpwd,"shaidskk")) 
            printf("\n\nLogged In Successful"); 
        else 
            printf("\n\nIncorrect password");
        return;
    } else printf("User not exits\n");
} 





















// InfoMenu.cpp : main project file.

#include <stdafx.h>
#include <iostream>
#include <string>

using namespace std;

//define function prototypes
void MyMenu();

int main()
{
int test=1;//test conditio that user want to continue{1=Yes, 0=no}
if(test==1){
	MyMenu();
}
else{
	return 0;
}
  
}

void MyMenu(){
	
	  int loop=1;
	  int choice;
	  string getinput;

	  while(loop==1)
	{
		cout << "Type 'exit' to leave at any time\n"
			 << "Type 'login' to begin\n";
		cin >> getinput;
		if(getinput=="exit") // Exit Code
		{
			exit(0);
		}
		if(getinput=="login") // Login Code
		cout << "Username:"; // Username Code
		cin >> getinput;
		if (getinput=="Test")
		{
			cout << "Password:"; // Password Code
			cin >> getinput;
			if(getinput=="Pass")
			cout << "Welcome...";
			
		}
	}
  }
	
}