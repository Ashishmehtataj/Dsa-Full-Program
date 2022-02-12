#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* head;
void Traversing(){
	struct node *temp;
	temp = head;
	if(temp==NULL){
		printf("Empty linked list\n");
	}else{
		printf("All data is : ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->link;
		}
	}
}
void insert_at_first(){
	struct node* newnode;
	int data;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("\nOverflow\n");
	}else{
		printf("Enter data you went to insert : ");
		scanf("%d",&data);
		newnode->data = data;
		newnode->link = head;
		head = newnode;
		printf("Node Insert successfully\n");
	}
}
void insert_at_index(){
	int i,position,data;
	struct node* newnode,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("\nOverflow\n");
	}else{
		printf("Enter new data you went to insert : ");
		scanf("%d",&data);
		newnode->data = data;
		printf("Enter position you went to insert : ");
		scanf("%d",&position);
		temp = head;
		for(i = 0;i<position;i++){
			temp = temp->link;
			if(temp==NULL){
				printf("Unable to insertion\n");
			}
		}
		newnode->link = temp->link;
		temp->link = newnode;
		printf("Insert node Successfully\n");
		
	}
}
void insert_at_end(){
	struct node* newnode,*temp;
	int data;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("\nOverflow\n");
	}else{
		printf("Enter data you went to insert : ");
		scanf("%d",&data);
		newnode->data = data;
		if(head==NULL){
			newnode->link  =NULL;
			head = newnode;
		}else{
			temp = head;
			while(temp->link !=NULL){
				temp  = temp->link;
			}
			temp->link = newnode;
			newnode->link = NULL;
		}
		printf("Node Insert successfully\n");
	}
}
void delete_at_first(){
	struct node *temp;
	if(head == NULL){
		printf("\nEmpty Linked list\n");
	}else{
		temp = head;
		head = temp->link;
		free(temp);
		printf("\nNode Delete successfully\n");
	}
}
void delete_at_index(){
	struct node *temp,*temp1;
	int i,position;
	printf("Enter position you went to delete node : ");
	scanf("%d",&position);
	temp = head;
	for(i=0;i<position;i++){
		temp1 = temp;
		temp = temp->link;
		if(temp==NULL){
			printf("Unable to delete\n");
		}
	}
	temp1->link = temp->link;
	free(temp);
	printf("Delete node successfully\n");
}
void delete_at_end(){
	struct node* temp,*temp1;
	if(head==NULL){
		printf("\nOverflow\n");
	}else if(head->link==NULL){
		head = NULL;
		free(head);
		printf("Delete node successfully\n");
	}else{
		temp = head;
		while(temp->link!=NULL){
			temp1 = temp;
			temp = temp->link;
		}
		temp1->link  =NULL;
		free(temp);
		printf("Delete node successfully\n");

	}
}
void search(){
	struct node *temp;
	int item,i=0;
	temp = head;
	if(head == NULL){
		printf("\nEmpty Linked List\n");
	}else{
		printf("Enter data you went to search : ");
		scanf("%d",&item);	
		while(temp!=NULL){
			if(temp->data = item){
				printf("Item founded at location %d\n",i+1);
				i++;
				break;
			}else{
				temp = temp->link;
			}
			if(temp==NULL){
				printf("Item not founded\n");
				break;
			}
			
		}
	}
}

int main(){
	int choice = 0;
	printf("\n------------------------MAIN MENU---------------------------\n");
	printf("\nchoose one operation in this MENU\n");
	printf("Enter 1 for Insert at First\n");
	printf("Enter 2 for Insert at Index\n");
	printf("Enter 3 for Insert at End\n");
	printf("Enter 4 for Delete at First\n");
	printf("Enter 5 for Delete at index\n");
	printf("Enter 6 for Delete at end\n");
	printf("Enter 7 for Traversing\n");
	printf("Enter 8 for Search item in list\n");
	printf("Enter 9 for Exit\n");
	while(choice!=9){
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert_at_first();
				break;
			
			case 2:
				insert_at_index();
				break;
			
			case 3:
				insert_at_end();
				break;
			
			case 4:
				delete_at_first();
				break;
			
			case 5:
				delete_at_index();
				break;
			
			case 6:
				delete_at_end();
				break;
				
			case 7:
				Traversing();
				break;
			
			case 8:
				search();
				break;
				
			case 9:
				exit(0);
				break;
				
			default:
				printf("Invalid choice please select a valid choice\n");
				break;
		}
	}
return 0;
}
