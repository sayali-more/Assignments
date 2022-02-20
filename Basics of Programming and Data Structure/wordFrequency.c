#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 50

struct list {   
	char data[20];
	int count;
};

struct list *hashArray[SIZE]; 
int key;

int search(char data[20]) {
	int i=0;
	for(i = 0; i<key; i++) {
		if(strcmp(hashArray[i]->data,data)==0)
			return (i);
	}
	return (0);
}

void insert(char data[20]) {
	struct list *t = (struct list*) malloc(sizeof(struct list));
     	int i;
	strcpy(t->data,data);
      	t->count=1;	
	i=search(data);
     	if(i!=0){
		hashArray[i]->count++;
		return;
      	}
     	if( hashArray[key]==NULL){
		hashArray[key]=t;
		key++;
	}
}

void display() {
     	int i = 0;
	printf("Frequency of words: ");
     	for(i = 0; i<key; i++) {
	  	if(hashArray[i] != NULL)
			printf(" (%s,%d)",hashArray[i]->data,hashArray[i]->count);
	   	else
			printf(" ~~ ");
     	}
     	printf("\n");
}

int main(){
	FILE *filePointer ;
	char data[20];
	filePointer = fopen("data.txt", "r") ;
	if ( filePointer == NULL )
	{
		printf( "data.txt file failed to open." ) ;
	}
	else
	{
		
		while (fscanf(filePointer, "%s", data) != EOF)
        	{
           		 insert(data);
        	}
  	
		fclose(filePointer) ;
		display();

	}
	return 0;
}
