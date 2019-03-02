//To implement insertion and deletion in a doubly linked list using menu driven flow of control
//28.02.19

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>

//Macro for easy use of malloc for memory allocation
#define Malloc(a) (a*)(malloc(sizeof(a)))

//Self referential structure for node creation in linked list

typedef struct nodeStructure{
      int data;//data storage
      struct nodeStructure *next;//points to next node in list
      struct nodeStructure *previous;//points to previous node in list
};

//Declaration of a pointer data type on the linked list structure

typedef struct nodeStructure *listPointer;

//Declaration of first and last node pointers 

struct nodeStructure *firstNode;
struct nodeStructure *lastNode;

//Function prototype and declaration for operations

//For inserting the nodes
void insertInList();
      void putNodeAtStart();
      void putNodeAtEnd();
      void putNodeAtPosition();

//For deleting the nodes
void deleteFromList();
      void removeNodeFromStart();
      void removeNodeFromEnd();
      void removeNodeAtPosition();

//Get values to store in the node
int getNodeValue();

//To display the nodes in the list
void getNodes();

//Searching for a user input data value in nodes of the linked list
struct nodeStructure* searchInNodes(); 


//main() opens
void main(){
      int answer;
      
      //For continuous display of switch-case menu

      while(1){
            system("cls");  //Clears the screen before each run of menu
            printf("\nDouble(y) Linked List Operations\n");
            printf("01. Insertion in linked list\n");
            printf("02. Deletion from linked list\n");
            printf("03. Display the linked list\n");
            printf("04. Exit\n");
            scanf("%d", &answer);

            //Switch-case for the user choice

            switch (answer)
            {
                  case 1:     //For insertion in the linked list
                        insertInList();
                        break;

                  case 2:     //For deletion from the linked list
                        deleteFromList();
                        break;

                  case 3:     //For displaying the nodes in list
                        getNodes();
                        break; 

                  default:    //Default case for exiting the program
                        exit(0);
                        break;
            }

      }
      getch();
}//main() closes

//Function definition for operations 

struct nodeStructure* searchInNodes(){
      struct nodeStructure *searchNode;
      int valueFound = 0, searchValue;

      //Get value to search from user
      printf("Enter value to search \n");
      scanf("%d", &searchValue);

      //Declare new node for traversing the list
      struct nodeStructure *scanNode; 
      scanNode = firstNode;

      //Traverse the list till NULL of lastNode is encountered

      searchNode = NULL;

      while(scanNode != NULL){
            if(scanNode->data == searchValue){  //If value is found in a node
                  valueFound = 1;
                  searchNode = scanNode;
            }
            scanNode = scanNode->next;
      }

      //Check if value is found or not

      if(valueFound){
            printf("Value is found \n");
      }
      else{
            printf("Value not found\n");
      }
      return searchNode;
}

int getNodeValue(){     //Gets data to be stored in node from the user
      int value;
      printf("Enter value in node\n");
      scanf("%d", &value);
      return value;
}

void insertInList(){
      struct nodeStructure *newNode;
      int insertAnswer;

      //Allocate memory for a node and pass it's address to newNode
      newNode = Malloc(struct nodeStructure);

      if (!firstNode){   //If the list doesn't exist

            //Get value for node
            newNode->data = getNodeValue();

            //Initialize newNode as the first and last nodes
            firstNode = newNode;
            lastNode = firstNode;

            //Initialize the node pointers to NULL
            newNode->next = NULL;
            newNode->previous = NULL;
      }
      else{       //If the list exists

            //Menu to display for insertion
            system("cls");
            printf("Insertion In Linked List\n");
            printf("01. At the beginning\n");
            printf("02. At the end\n");
            printf("03. At a position\n");
            scanf("%d", &insertAnswer);

            //Switch case for user choice to insert node

            switch (insertAnswer){
            case 1:     //Inserts a node at the beginning of the list
                  putNodeAtStart();
                  break;
            case 2:     //Inserts a node at the end of the list
                  putNodeAtEnd();
                  break;
            case 3:     //Inserts a node at a position given by the user 
                  putNodeAtPosition();
                  break;
            default:
                  break;
            }
      }
      getch();
}

void putNodeAtStart(){
      struct nodeStructure *newNode;

      //Allocate memory for a node and pass it's address to newNode
      newNode = Malloc(struct nodeStructure);
      //Get value for node
      newNode->data = getNodeValue();

      //Placing the node in the doubly linked list at first position
      newNode->next = firstNode;
      firstNode->previous = newNode;
      newNode->previous = NULL;
      firstNode = newNode;
}

void putNodeAtEnd(){
      struct nodeStructure *newNode;

      //Allocate memory for a node and pass it's address to newNode
      newNode = Malloc(struct nodeStructure);
      //Get value for node
      newNode->data = getNodeValue();

      //Placing the node in the doubly linked list at the end position
      lastNode->next = newNode;
      newNode->previous = lastNode;
      newNode->next = NULL;
      lastNode = newNode;
}

void putNodeAtPosition(){
      struct nodeStructure *newNode, *searchNode;

      //Get the node with the given search value
      searchNode = searchInNodes();

      if(searchNode != NULL){   //if search value is found

            if(searchNode->next == NULL){ //If the searched value is found in the last node
                  putNodeAtEnd();
            }

            else{
                  //Allocate memory for a node and pass it's address to newNode
                  newNode = Malloc(struct nodeStructure);
                  //Get value for node
                  newNode->data = getNodeValue();

                  //Attaches the new node after the search node
                  newNode->next = searchNode->next;
                  searchNode->next = newNode;
                  newNode->previous = searchNode;

                  //Traverse both the nodes forward to create reverse linkage to the newNode by the node after the searched node
                  searchNode = searchNode->next;
                  newNode = newNode->next;
                  newNode->previous = searchNode;
            }
      }
      else{       //if search value isn't found exit the current function
            return;
      }
}

void deleteFromList(){
      int insertAnswer;

      if (!firstNode){  //If the list doesn't exist
            printf("No nodes exist underflow\n");
      }

      else{   //If the list exists

            //Menu to display for insertion
            system("cls");
            printf("Deletion In Linked List\n");
            printf("01. At the beginning\n");
            printf("02. At the end\n");
            printf("03. At a position\n");
            scanf("%d", &insertAnswer);

            //Switch case for user choice to insert node

            switch (insertAnswer){
            case 1:     //Remove the first node in linked list
                  removeNodeFromStart();
                  break;
            case 2:     //Removes last node from linked list
                  removeNodeFromEnd();
                  break;
            case 3:     //Removes node at a position given by the user
                  removeNodeAtPosition();
                  break;
            default:
                  break;
            }
      }
      getch();
}

void removeNodeFromStart(){
      //initialize a new node to store address of node to be deleted
      struct nodeStructure *deleteNode;

      deleteNode = firstNode;

      //Make the second node the first node and delete the original first node
      firstNode = firstNode->next;
      firstNode->previous = NULL;
      free(deleteNode);       //frees the memory space
      printf("Node deleted successfully\n");
}

void removeNodeFromEnd(){
      //initialize a new node to store address of node to be deleted
      struct nodeStructure *deleteNode;

      //Makes the second last node as the last node and deletes the original last node
      deleteNode = lastNode;
      lastNode = lastNode->previous;
      lastNode->next =NULL;
      free(deleteNode); //frees the memory space
      printf("Node deleted successfully\n");
}

void removeNodeAtPosition(){
      //initialize a new node to store address of node to be deleted, the node before it and after it
      struct nodeStructure *deleteNode, *previousNode, *nextNode;

      //Get the node with the search value
      deleteNode = searchInNodes();

      if(deleteNode != NULL){       //If the search value is found
            if(deleteNode->next == NULL){
                  removeNodeFromEnd();
                  return;
            }
            else if(deleteNode == firstNode){
                  removeNodeFromStart();
                  return;
            }
            else{
                  previousNode = deleteNode->previous; //initialize the previous node

                  //Break connections from the node to be deleted
                  previousNode->next = deleteNode->next;
                  nextNode = deleteNode->next;
                  nextNode->previous = previousNode;

                  free(deleteNode); //frees the memory space
                  printf("Node deleted successfully\n");
            }
      }
      else{
            return;
      }
}

void getNodes(){        //Displays the list using double arrow connections
      struct nodeStructure *scanNode;
      scanNode = firstNode;

      if(firstNode){
            printf("The linked list is \n");
            printf("HEAD");
            while (scanNode != NULL){
                  printf(" < -- > %d",scanNode->data);
                  scanNode = scanNode->next;
            }
            printf(" -- > NULL");   //Last node points to NULL
      }
      else{
            printf("List is empty, No nodes found\n");
      }
      getch();

}

//Written in ANSI C for the GNU-GCC compiler
//Elit Altum
