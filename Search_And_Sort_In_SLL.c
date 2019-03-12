//To implement linear search and selection sort in a singly linked list
//12.03.19

#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>

//Macro for easy use of malloc for memory allocation
#define Malloc(a) (a *)(malloc(sizeof(a)))

//Self referential structure for node creation in linked list

typedef struct nodeStructure{
      int data;                   //data storage
      struct nodeStructure *next; //points to next node in list
};

//Declaration of first and last node pointers

struct nodeStructure *firstNode;
struct nodeStructure *lastNode;

//Function declaration and prototypes for operation

int getNodeData();
void makeNewList();

//To display the nodes on the console
void getNodes();

//Operations on linked list
void selectionSort();
void linearSearch();

//main()opens

void main(){
      makeNewList();    //Gets new list from the user
      system("cls");

      printf("Original list is :\n");
      getNodes();

      //Implements selection sort on the list and displays it
      printf("Sorted list is : \n");
      selectionSort();  
      getNodes();
      getch();

      //Implements linear search on the linked list
      linearSearch();
      getch();

}     //main closes


//Function definitions for operations

int getNodeData(){
      int value;
      printf("Enter value in the node : ");
      scanf("%d", &value);
      return value;
}

void makeNewList(){
      //Declare new node in local scope
      struct nodeStructure *newNode;
      char wantMoreNodes = 'y';

      while(wantMoreNodes == 'y'){

            //Allocate memory for the new node and get it's value
            newNode = Malloc(struct nodeStructure);
            newNode->next = NULL;
            newNode->data = getNodeData();

            //If the list exists attach the new node to the end of the list
            if (firstNode){ 
                  lastNode->next = newNode;
                  lastNode = newNode;
            }
            //If the list doesn't exist initialize the new node as the first and last nodes
            else{
                  firstNode = newNode;
                  lastNode = firstNode;
            }

            //Check if user wants more nodes
            printf("Want more nodes y/n\n");
            scanf("%s", &wantMoreNodes);
      }      
}

void getNodes(){
      //Declare new node in local scope to traverse the list
      struct nodeStructure *scanNode;

      //Initialize scanNode as the first node for traversal
      scanNode = firstNode;

      //Prints the node values along with denoting the start and end of list
      printf("HEAD -> ");
      while(scanNode != NULL){
            printf("%d -> ", scanNode->data);
            scanNode = scanNode->next;
      }
      printf("NULL\n");
}

void selectionSort(){
      int minimumValue, swapNumber;

      //Declare nodes in local scope to traverse the list
      struct nodeStructure *currentNode;
      struct nodeStructure *scanNode;
      struct nodeStructure *leastValueNode;

      currentNode = firstNode;

      while(currentNode->next != NULL){

            minimumValue = currentNode->data;
            scanNode = currentNode->next;

            //Always initializes the node with the least value in the list as NULL
            leastValueNode = NULL;        
           
            while(scanNode){

                  if(scanNode->data < minimumValue){
                        minimumValue = scanNode->data;
                        leastValueNode = scanNode;
                  }

                  scanNode = scanNode->next;
            }

            //Swaps the data value of the nodes if a node with lesser value is found
            if(leastValueNode){
                  swapNumber = currentNode->data;
                  currentNode->data = leastValueNode->data;
                  leastValueNode->data = swapNumber;
            }

            currentNode = currentNode->next;
      }

}

void linearSearch(){
      int valueIsFound = 0;
      int searchValue, searchValuePosition;
      int nodeCounter = 0;

      //Get the value to search from the user
      printf("Enter value to search : ");
      scanf("%d",&searchValue);

      //Declare new node in local scope to traverse the list
      struct nodeStructure *scanNode;

      //Initailize scanNode as the first node for traversal
      scanNode = firstNode;   

      while(scanNode != NULL){
            nodeCounter++;    //Keeps the index of each node

            if(searchValue == scanNode->data){
                  valueIsFound = 1;  
                  searchValuePosition = nodeCounter;  //Stores the index of the node at which search value is found
            }

           scanNode = scanNode->next; 
      }

      //Check if searched value is found or not
      if(valueIsFound){
            printf("The given value is found at %d node.\n", searchValuePosition);
      }
      else{
            printf("Node not found. Search unsuccessful\n");
      }
}

//Written in ANSI C for the GNU-GCC compiler
//Elit Altum