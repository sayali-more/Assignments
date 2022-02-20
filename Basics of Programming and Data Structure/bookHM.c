#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 10

struct list {   
	int book_id;
	char book_name[20];
	struct list *next;
};

struct list *hashArray[SIZE]; 
int key,count;

struct list* search(int bid) {
	key=bid%10;
	struct list *f;
     	for(f=hashArray[key];f!=NULL;f=f->next){
		if(f->book_id==bid)
			return(f);
	}
	return(NULL);
}

void insert(int bid,char book[20]) {
	struct list *f,*t = (struct list*) malloc(sizeof(struct list));
	f=search(bid);	
	if(f!=NULL){
		while(f!=NULL){
			printf("%d is already present..!!!!\nPlease enter another book id: ",bid);
			scanf("%d",&bid);
			f=search(bid);
		}
	}
	t->next=NULL;
	strcpy(t->book_name,book);
      	t->book_id=bid;
	count++;
	key=bid%10;
     	if(hashArray[key]==NULL){
		hashArray[key]=t;
		return;
      	}
     	for(f=hashArray[key];f->next!=NULL;f=f->next);
	f->next=t;
}

void display() {
     	int i = 0;
	struct list *f;
     	for(i = 0; i<SIZE; i++) {
		for(f=hashArray[i];f!=NULL;f=f->next){
	  		printf("%d : %s\n",f->book_id,f->book_name);
	   	}
     	}
}

void delete(int bid) {
	struct list *f,*t;
     	f=search(bid);
	key=bid%10;
	if(f==NULL){
		printf("No such Book found..!!!");
		return;
	}
	if(f->next==NULL){
		for(t=hashArray[key];t->next!=f;t=t->next);
		t->next=NULL;
		free(f);
		return;
	}
	t=f->next;
	f->book_id=t->book_id;
	strcpy(f->book_name,t->book_name);
	f->next=t->next;
	t->next=NULL;
	free(t);
}

int main(){
	char book[20];
	int input,bid;
	struct list *f;
	while (input != 5) {

		printf("\n\n************Please select option************\n");
		printf("1. Add book information\n2. Display book information book information\n3. Delete book informatiom\n4. Search book\n5. Quit");
		printf("\nEnter one of the above: ");
		scanf("%d", &input);
		switch (input) {
		case 1: printf("Enter book id: ");
			scanf("%d",&bid);
			printf("Enter name of books : ");
			scanf("%s", book);
			insert(bid,book);
			break;

		case 2: if(count==0){
				printf("There is no information to display..!\n");
			}
			else{
				printf("List of books: \n");
				display();
			}
			break;

		case 3:	if (count==0)
				printf("No book to delete..!\n");
			else{
				printf("Enter book id: ");
				scanf("%d",&bid);
				delete(bid);
				printf("Book information deleted..!");
			}
			break;

		case 4:	printf("Enter book id: ");
			scanf("%d",&bid);
			f=search(bid);
			if(f!=NULL)
				printf("Book is present..!\n");
			else
				printf("Book is not present..!\n");
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}
