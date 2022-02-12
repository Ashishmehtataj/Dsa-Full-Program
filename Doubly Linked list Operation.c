#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node* head;
void Traversing(){
	struct node* ptr;
	if(head == NULL){
		printf("Empty List :");
	}else{
		ptr = head;
		printf("All data is : ");
		while(ptr->next !=NULL){
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
	}
}
void search(){
	struct node* ptr;
	int data,i=0;
	ptr = head;
	if(ptr ==NULL){
		printf("\nUnable to search\n");
	}else{
		printf("Enter data you went to insert : ");
		scanf("%d",&data);
		while(ptr->next!=NULL){
			if(ptr->data == data){
				printf("Item founded at %d\n",i+1);
				i++;
				break;
			}else{
				ptr = ptr->next;
			}
			if(ptr==NULL){
				printf("Item not founded\n");
				break;
			}	
		}
		
	}
}
void insert_at_first(){
	struct node* newnode;
	int data;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Overflow\n");
	}else{
		printf("Enter data you went to insert : ");
		scanf("%d",&data);
		if(head==NULL){
			newnode->next = NULL;
			newnode->prev = NULL;
			newnode->data = data;
			head = newnode;
		}else{
			newnode->data  =data;
			newnode->prev = NULL;
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		printf("Node insert successfully\n");
	}
}
void insert_at_index(){
	struct node* newnode,*temp;
	int item,i,index;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Overflow\n");
	}else{
		newnode = head;
		printf("Enter index you went to insert data : ");
		scanf("%d",&index);
		for(int i=0;i<index;i++){
			temp = temp->next;
			if(temp==NULL){
				printf("There are less than element : ",index);				
			}
			return ;
		}
	}
	printf("Enter data you went to insert : ");
	scanf("%d",&item);
	newnode->data = item;
	newnode->next = temp->next ;
	newnode->prev = temp;
	temp->next  = newnode;
	temp->next->prev = newnode;
	printf("Node insert successfully\n");
}
void insert_at_end(){
	struct node *newnode,*temp;
	int item;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("\nOverflow\n");
	}else{
		printf("Enter data you went to insert : ");
		scanf("%d",&item);
		newnode->data = item;
		if(head==NULL){
			newnode->next = NULL;
			newnode->prev = NULL;
			head = newnode;
		}else{
			temp = head;
			while(temp->next !=NULL){
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->next = NULL;
			newnode->prev = temp;
		}
	printf("Node insert successfully\n");
	}
}
void delete_at_first(){
	struct node* temp;
	if(head==NULL){
		printf("\nOverflow\n");
	}else if(head->next == NULL){
		head = NULL;
		free(head);
		printf("Node delete successfully\n");
	}else{
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		printf("Node delete successfully\n");
	}
}
void delete_at_index(){
	struct node* temp,*temp1;
	int data;
	printf("Enter data you went to delete : ");
	scanf("%d",&data);
	temp = head;
	while(temp->data != data){
		temp = temp->next;
		if(temp->next ==NULL){
			printf("Unable to delete node\n");
		}else if(temp->next->next==NULL){
			temp->next = NULL;
		}else{
			temp1 = temp->next;
			temp->next = temp1->next;
			temp1->next->prev = temp;
			free(temp);
			printf("Node delete successfully\n");
		}
	}
}
void delete_at_end(){
	struct node* temp;
	if(head==NULL){
		printf("Underflow\n");
	}else if(head->next ==NULL){
		head=NULL;
		free(head);
		printf("Node delete successfully\n");
	}else{
		temp = head;
		if(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next->prev = NULL;
		free(temp);
		printf("node delete successfully\n");
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
