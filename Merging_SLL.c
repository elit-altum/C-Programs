//To implement linear search and selection sort in a singly linked list
//12.03.19

#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>

//Macro for easy use of malloc for memory allocation
#define Malloc(a) (a *)(malloc(sizeof(a)))

//Self referential structure for node creation in linked list

typedef struct nodeStructure
{
      int data;                   //data storage
      struct nodeStructure *next; //points to next node in list
};

//Declaration of first and last node pointers for both lists

struct nodeStructure *firstNodeOfFirstList;
struct nodeStructure *lastNodeOfFirstList;

struct nodeStructure *firstNodeOfSecondList;
struct nodeStructure *lastNodeOfSecondList;

struct nodeStructure *firstNodeOfSortedList;

//Function declaration and prototypes for operation

int getNodeData();
struct nodeStructure *makeNewNode();

//Implements selection sort on a list to arrange it in ascending order
void selectionSort(struct nodeStructure *firstNode);

//For merging the the two lists
struct nodeStructure *mergeLinkedLists(struct nodeStructure *firstListScanner, struct nodeStructure *secondListScanner);

//To display the nodes on the console
void getNodes(struct nodeStructure *firstNode);

void main(){

      //Get the first list from the user
      printf("Enter the first list\n");
      char wantMoreNodes = 'y';
      while(wantMoreNodes == 'y'){

            if(firstNodeOfFirstList){
                  lastNodeOfFirstList->next = makeNewNode();
                  lastNodeOfFirstList = lastNodeOfFirstList->next;
            }
            else{
                  firstNodeOfFirstList = makeNewNode();
                  lastNodeOfFirstList = firstNodeOfFirstList;
            }

            //Check if user wants more nodes
            printf("Want more nodes y/n\n");
            scanf("%s", &wantMoreNodes);
      }
      system("cls");

      //Get the second list from the user
      printf("Enter the second list\n");
      wantMoreNodes = 'y';
      while (wantMoreNodes == 'y'){

            if (firstNodeOfSecondList){
                  lastNodeOfSecondList->next = makeNewNode();
                  lastNodeOfSecondList = lastNodeOfSecondList->next;
            }
            else{
                  firstNodeOfSecondList = makeNewNode();
                  lastNodeOfSecondList = firstNodeOfSecondList;
            }

            //Check if user wants more nodes
            printf("Want more nodes y/n\n");
            scanf("%s", &wantMoreNodes);
      }
      system("cls");

      //Display the linked lists
      getNodes(firstNodeOfFirstList);
      getNodes(firstNodeOfSecondList);

      //Selection sort the lists
      selectionSort(firstNodeOfFirstList);
      selectionSort(firstNodeOfSecondList);

      printf("\n");
      //Display the sorted linked lists
      printf("Sorted linked lists are\n");
      getNodes(firstNodeOfFirstList);
      getNodes(firstNodeOfSecondList);

      getch();

      printf("\n");
      firstNodeOfSortedList = mergeLinkedLists(firstNodeOfFirstList, firstNodeOfSecondList);
      getNodes(firstNodeOfSortedList);

      getch();
}

int getNodeData(){
      int value;
      printf("Enter value in the node : ");
      scanf("%d", &value);
      return value;
}

struct nodeStructure* makeNewNode(){
      //Declare new node in local scope
      struct nodeStructure *newNode;

      //Allocate memory for the new node and get it's value
      newNode = Malloc(struct nodeStructure);
      newNode->next = NULL;
      newNode->data = getNodeData();

      return newNode;
}

void getNodes(struct nodeStructure *firstNode)
{
      //Declare new node in local scope to traverse the list
      struct nodeStructure *scanNode;

      //Initialize scanNode as the first node for traversal
      scanNode = firstNode;

      //Prints the node values along with denoting the start and end of list
      printf("HEAD -> ");
      while (scanNode != NULL){
            printf("%d -> ", scanNode->data);
            scanNode = scanNode->next;
      }
      printf("NULL\n");
}

void selectionSort(struct nodeStructure *firstNode){
      int minimumValue, swapNumber;

      //Declare nodes in local scope to traverse the list
      struct nodeStructure *currentNode;
      struct nodeStructure *scanNode;
      struct nodeStructure *leastValueNode;

      currentNode = firstNode;

      while (currentNode->next != NULL){

            minimumValue = currentNode->data;
            scanNode = currentNode->next;

            //Always initializes the node with the least value in the list as NULL
            leastValueNode = NULL;

            while (scanNode){

                  if (scanNode->data < minimumValue){
                        minimumValue = scanNode->data;
                        leastValueNode = scanNode;
                  }

                  scanNode = scanNode->next;
            }

            //Swaps the data value of the nodes if a node with lesser value is found
            if (leastValueNode){
                  swapNumber = currentNode->data;
                  currentNode->data = leastValueNode->data;
                  leastValueNode->data = swapNumber;
            }

            currentNode = currentNode->next;
      }
}

struct nodeStructure *mergeLinkedLists(struct nodeStructure *firstListScanner, struct nodeStructure *secondListScanner){

      //Declare nodes in local scope
      struct nodeStructure *firstNodeOfMergedList, *lastNodeOfMergedList;

      //Compares the first nodes of the lists
      if (firstListScanner->data < secondListScanner->data){

            lastNodeOfMergedList = firstNodeOfMergedList = firstListScanner;
            firstListScanner = firstListScanner->next;
            lastNodeOfMergedList->next = NULL;
      }

      else{
            lastNodeOfMergedList = firstNodeOfMergedList = secondListScanner;
            secondListScanner = secondListScanner->next;
            lastNodeOfMergedList->next = NULL;
      }

      //Runs to compare all the other nodes in the list
      while (firstListScanner != NULL || secondListScanner != NULL){    //Till the nodes are encountered
            
            //Breaks out of the loop if the last nodes are found
            if (firstListScanner == NULL){
                  lastNodeOfMergedList->next = secondListScanner;
                  break;
            }

            else if (secondListScanner == NULL){
                  lastNodeOfMergedList->next = firstListScanner;
                  break;
            }

            else{
                  //For all other nodes insert nodes in between the list
                  if (firstListScanner->data < secondListScanner->data){

                        lastNodeOfMergedList->next = firstListScanner;
                        firstListScanner = firstListScanner->next;
                        lastNodeOfMergedList = lastNodeOfMergedList->next;
                        lastNodeOfMergedList->next = NULL;
                  }
                  else{

                        lastNodeOfMergedList->next = secondListScanner;
                        secondListScanner = secondListScanner->next;
                        lastNodeOfMergedList = lastNodeOfMergedList->next;
                        lastNodeOfMergedList->next = NULL;
                  }
            }
      }
      return firstNodeOfMergedList;
}

//Written in ANSI C for the GNU-GCC compiler
//Elit Altum