//To implement stack and queue operations in a single linked list using menu driven flow of control
//27.2.19

#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<conio.h>

//Declaring linked list structure

typedef struct nodeStructure{
      int data;
      struct nodeStructure *next;
};

//Initializing first and last node pointers

struct nodeStructure *firstNode;
struct nodeStructure *lastNode;

//Function prototype declaration for stack operations

void pushInStack();

//Function prototype declaration for queue operations

void pushInQueue();

//Function prototype declaration for common operations on queues or stacks

void popFromStackOrQueue();
void getNodes();

//main() opens
void main(){
      int firstAnswer = 0, nestedAnswer;
      //For continuous display of menu

      while(1){
            system("cls"); //Clears the screen before each run
            char operationAnswer = 'y';
            printf("\nStacks And Queues Using Singly Linked Lists\n");
            printf("01. Implement Stack Operations \n");
            printf("02. Implement Queue Operations \n");
            scanf("%d", &firstAnswer);
            
            //Switch-case for implementation

            switch (firstAnswer)
            {
                  case 1:
                        //Internal menu for stacks
                        while(operationAnswer == 'y'){
                              system("cls");
                              printf("\nStack Operations In Single Linked List\n");
                              printf("01. Push in the stack \n");
                              printf("02. Pop from the stack \n");
                              printf("03. Display the stack \n");
                              scanf("%d", &nestedAnswer);

                              //Internal switch case for stack operations

                              switch (nestedAnswer)
                              {
                                    case 1://For pushing in stack
                                          pushInStack();
                                          break;
                                    case 2://For deleting from stack
                                          popFromStackOrQueue();
                                          break;
                                    case 3://For displaying the stack
                                          getNodes();
                                          break;                             
                                    default:
                                          break;
                              }

                              //Checking if user wants to stay in stack menu or not

                              printf("Want more operations on stack y/n\n");
                              scanf("%s", &operationAnswer);
                        }//menu for stack closes
                        
                        break;//stack operation case closes

                  case 2:
                        //Internal menu for queues
                        while(operationAnswer == 'y'){
                              system("cls");
                              printf("\nQueue Operations In Single Linked List\n");
                              printf("01. Push in the queue \n");
                              printf("02. Pop from the queue \n");
                              printf("03. Display the queue \n");
                              scanf("%d", &nestedAnswer);

                              //Internal switch case for queue operations

                              switch (nestedAnswer)
                              {
                                    case 1://For pushing in queue
                                          pushInQueue();
                                          break;
                                    case 2://For deleting from queue
                                          popFromStackOrQueue();
                                          break;
                                    case 3://For displaying the queue
                                          getNodes();
                                          break;                             
                                    default:
                                          break;
                              }

                              //Checking if user wants to stay in queue menu or not

                              printf("Want more operations on queue y/n\n");
                              scanf("%s", &operationAnswer);
                        }//menu for queue closes
                        
                        break;//queue operation case closes
            
                  default:
                        exit(0);//For exiting from the program
                        break;
            }         
      }
      getch(); //For holding the screen after responses (not necessary)
}//main() closes


//Common operations for queues or stacks

void popFromStackOrQueue(){
      struct nodeStructure *deleteNode;//Declare a new node in local scope
     if(firstNode){
            deleteNode = firstNode;
            //Moves the first node to the next node in stack and deletes the previous one
            firstNode = firstNode->next;
            free(deleteNode);
            printf("Node popped successfully\n");
     }
     else{ //if no nodes exist print underflow
           printf("No nodes exist Underflow \n");
     }
}


void getNodes(){
      struct nodeStructure *scannerNode;//Declare a new node in local scope
      scannerNode = firstNode;
      if(firstNode){
            printf("\nThe values are\n");
            while(scannerNode){  //loop runs till scannerNode != NULL
                  printf("%d  ", scannerNode->data);
                  scannerNode = scannerNode->next; //sends to the next node for next iteration
            }
      }
      else{//If the queue/stack is empty
            printf("No nodes found \n");
      }
      printf("\n");
}

//Functions for queue operations

void pushInQueue(){
      struct nodeStructure *newNode;//Declare a new node in local scope
      if(firstNode){  //If the first node of the queue exists

            //Allocate memory for new node and connect it to the queue
            newNode = (struct nodeStructure*)(malloc(sizeof(struct nodeStructure)));
            newNode->next = NULL;
            lastNode->next = newNode;
            lastNode = newNode;

            //Get value for new node from user
            printf("Enter value in new node\n");
            scanf("%d", &newNode->data);
      }
      else{  //If the queue doesn't exist

           //Allocate memory for new node and initialize first and last nodes to it
           newNode = (struct nodeStructure*)(malloc(sizeof(struct nodeStructure))); 
           newNode->next = NULL;
           firstNode = newNode;
           lastNode = firstNode;

           //Get value for new node from user
           printf("Enter value in new node\n");
           scanf("%d", &newNode->data);
      }
}

//Functions for stack operations

void pushInStack(){
      struct nodeStructure *newNode;//Declare a new node in local scope

      if(firstNode){  //If the stack exists

            //Allocate memory for new node and connect it to the stack
            newNode = (struct nodeStructure*)(malloc(sizeof(struct nodeStructure)));
            newNode->next = firstNode;
            firstNode = newNode;

            //Get value for new node from user
            printf("Enter value in new node\n");
            scanf("%d", &newNode->data);
      }
      else{  //If the stack doesn't exist

           //Allocate memory for new node and initialize first and last nodes to it
           newNode = (struct nodeStructure*)(malloc(sizeof(struct nodeStructure))); 
           newNode->next = NULL;
           firstNode = newNode;
           lastNode = firstNode;

           //Get value for new node from user
           printf("Enter value in new node\n");
           scanf("%d", &newNode->data);
      }
}

//Written in ANSI C for the GNU-GCC compiler
//Elit Altum
