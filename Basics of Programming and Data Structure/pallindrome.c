#include<stdio.h>
#include <string.h>
char string[30];
int isPallindrome(){
	int i,length;
	int ret=1;
	length = strlen(string);               
	for(i=0;i < length ;i++){  		
		if(string[i] != string[length-i-1]){                           
			ret = 0;                                                        
			break;                                                        
		}                   
	}
	return(ret);
}
int main(){
	printf("Enter a string:");
	scanf("%s", string);	
 	if (isPallindrome()==0) {
		printf("%s is not a palindrome\n", string);
	}    
	else {
		printf("%s is a palindrome\n", string);
	}
	return 0;
}
