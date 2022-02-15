#include <stdio.h>
#include <stdlib.h>

//declar struct
struct data{
  char name[30];
  int age;
  struct data *next; //next pointer to the next node
};

//add the information function
struct data* addStudentInfo(struct data *head){
  if(head == NULL){ // base case 
    head=(struct data*)malloc(sizeof(struct data)); //add node 
    printf("\nEnter student name: ");
    scanf("\n");
    scanf("%[^\n]",head->name); // sacn the name from the user 
    printf("Enter student age: ");
    scanf("%d",&head->age); //scan the age from the user
    head->next=NULL; // the next of the node==NULL
    return head; // return the adress of the node 
  }
  head->next=addStudentInfo(head->next); //recall the function(recursion)
  return head; //return the adress of the node to function
}

//print the information function
void seeStudentInfo(struct data *head){
  printf("\n-------------\n");
  while(head != NULL){
    printf("Name: %s\n",head->name);
    printf("Payment: %d",head->age);
    printf("\n-------------\n");
    head=head->next;
  }
}

int main() {
  struct data *head=NULL;
  int *choice=(int*)malloc(sizeof(int)/2);  
  tryAgain:
  printf("\n1) add student information\n");
  printf("2) see student information\n");
  printf("choose a number: ");
  scanf("%d",choice);
  if(*choice == 1){
    head=addStudentInfo(head); //call the add function
  }
  else if(*choice == 2){
    seeStudentInfo(head); // call print function
  }
  else{
    printf("Please try again\n"); // if choice != 1 && choice != 2 
    goto tryAgain;
  }
  goto tryAgain;
}
