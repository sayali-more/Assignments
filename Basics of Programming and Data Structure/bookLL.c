#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEWNODE (struct book*)malloc(sizeof(struct book))
int count=0;
struct book {
	char bname[20];
	int bid;
	struct book *next;
};

struct book* create(int n){
	int i;
	struct book *f=NULL,*l=NULL,*t=NULL;
	f=NEWNODE;
	printf("Enter book name: ");
	scanf("%s",f->bname);
	printf("Enter book id: ");
	scanf("%d",&f->bid);
	f->next=NULL;
	l=f;
	count++;
	for(i=2;i<=n;i++){
		t=NEWNODE;
		printf("Enter book name: ");
		scanf("%s",t->bname);
		printf("Enter book id: ");
		scanf("%d",&t->bid);
		t->next=NULL;
		l->next=t;
		l=l->next;
		count++;
	}
	return(f);
}

struct book* add(struct book *f,int n){
	struct book *t=NEWNODE,*l;
	int i=1;
	printf("Enter book name: ");
	scanf("%s",t->bname);
	printf("Enter book id: ");
	scanf("%d",&t->bid);
	t->next=NULL;
	if(n==1){
		t->next=f;
		f=t;
		return(f);
	}
	for(l=f;i!=n-1;i++,l=l->next);
	t->next=l->next;
	l->next=t;
	return(f);

}

void disp(struct book *f){
	struct book *t;
	for(t=f;t!=NULL;t=t->next){
		printf("%d : %s\n",t->bid,t->bname);
	}
}

struct book* delete(struct book *f,int n){
	struct book *t,*l;
	int i=1;
	if(n==1){
		t=f;
		f=f->next;
		free(t);
		count--;
		return(f);
	}
	for(t=f;i!=n;i++,t=t->next);
	if(t->next!=NULL){
		l=t;
		t=t->next;
		strcpy(l->bname,t->bname);
		l->bid=t->bid;
		l->next=t->next;
	}
	free(t);
	count--;
	return(f);
}

int search(struct book *f,int n){
	struct book *t;
	for(t=f;t!=NULL;t=t->next){
		if(t->bid==n){
			return(1);
		}
	}
	return(0);
}


int main(){

	int n,input;
	struct book *head=NULL;
	while (input != 5) {

		printf("\n\n************Please select option************\n");
		printf("1. Add book information\n2. Display book information book information\n3. Delete book informatiom\n4. Search book\n5. Quit");
		printf("\nEnter one of the above: ");
		scanf("%d", &input);
		switch (input) {
		case 1: if(count == 0){
				printf("Enter how many number of books : ");
				scanf("%d", &n);
				head=create(n);
			}
			else{
				printf("Enter position = ");
				scanf("%d", &n);
				if(n>count+1)
					printf("Invalid position..!\n");
				else
					head=add(head,n);
			}
			break;

		case 2: if(count!=0){
				printf("List of books: \n");
				disp(head);
			}
			else{
				printf("There is no information to display..!\n");
			}
			break;

		case 3:	printf("Enter position: ");
			scanf("%d",&n);
			if (n>count)
				printf("Invalid position..!\n");
			else{
				head=delete(head,n);
				printf("Book information deleted..!");
			}
			break;

		case 4:	printf("Enter book id: ");
			scanf("%d",&n);
			if(search(head,n))
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
