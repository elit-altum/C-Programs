//To count the number of nodes in a linked list and reverse it's order of arrangement
//11.03.19

#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>

//Macro for easy use of malloc for memory allocation
#define Malloc(a) (a *)(malloc(sizeof(a)))

//Self referential structure for node creation in linked list

typedef struct nodeStructure{
      int data;                       //data storage
      struct nodeStructure *next;     //points to next node in list
};

//Declaration of first and last node pointers

struct nodeStructure *firstNode;
struct nodeStructure *lastNode;

//Function prototype and declaration for operations

void countNodes(); 
    
void reverseTheLinkedList();
void makeNewLinkedList();

int getNodeData();
void getNodes();

//main() opens

void main(){

      makeNewLinkedList();    //Get user to enter the linked list
      getNodes(); //Display the original linked list    
      countNodes();     //Display the number of nodes in the list    
      reverseTheLinkedList();       //Reverse the order of the linked list
      getNodes();       //Display the reversed linked list

      getch();    //Holds the screen

}//main() closes


int getNodeData(){
      int value;
      printf("Enter value in Node \n");
      scanf("%d", &value);
      return value;
}

void makeNewLinkedList(){
      //Declare new node in local scope and allocate memory for it
      struct nodeStructure *newNode;       
      char answer = 'y';
      while(answer == 'y'){
            if (firstNode){ //If the first node exists

                  newNode = Malloc(struct nodeStructure);

                  //Get data for new node and attach it to the end of the list
                  newNode->data = getNodeData();
                  newNode->next = NULL;

                  lastNode->next = newNode;
                  lastNode = newNode;
            }
            else{ //If the list doesn't exist

                  newNode = Malloc(struct nodeStructure);

                  //Get data for new node and initialize it as the first and last nodes
                  newNode->data = getNodeData();
                  newNode->next = NULL;

                  firstNode = newNode;
                  lastNode = firstNode;
            }
            printf("Want more nodes y/n \n");
            scanf("%s", &answer);
      }
      system("cls"); //Clears the screen
}

void countNodes(){
      int nodeCounter = 0;    //Initialize number of nodes as 0

      //Declare new node in local scope
      struct nodeStructure *scanNode;
      scanNode = firstNode;

      //Scan the list till scanNode reaches end of list and count the number of nodes encountered
      while(scanNode != NULL){      
            nodeCounter++;
            scanNode = scanNode->next;
      }

      printf("Number of nodes in the list : %d \n", nodeCounter); //Prints the number of nodes
}
void reverseTheLinkedList(){
      //Declare three pointers in local scope for traversal
      struct nodeStructure *previousNode;       
      struct nodeStructure *currentNode;       
      struct nodeStructure *nextNode;
      
      //Initialize the local nodes in scope
      currentNode = firstNode;
      previousNode = NULL;    
      nextNode = currentNode->next;

      //Till the current node takes the value of NULL
      while(currentNode != NULL){

            //Create the reverse links in the linked list
            currentNode->next = previousNode;

            //Re-initialise all the pointers to one node ahead
            previousNode = currentNode;
            currentNode = nextNode;

            if(nextNode){
                  nextNode = currentNode->next;
            }
            else{
                  nextNode = NULL;
            }
      }
      firstNode = previousNode;
}

//For displaying the nodes
void getNodes(){

      //Declare new node in local scope
      struct nodeStructure *scanNode;
      scanNode = firstNode;

      printf("The linked list is : \n");

      printf("HEAD -> ");
      //Scan the list till scanNode reaches end of list and print the values
      while (scanNode != NULL){
           printf("%d -> ", scanNode->data);
           scanNode = scanNode->next;
      }
      printf("NULL\n");
}

//Written in ANSI C for the GNU-GCC compiler
//Elit Altum