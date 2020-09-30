//Implements stack operations in a 1-D Array using Menu-Driven flow of control
//10.01.19


#include<stdio.h>
#include<stdbool.h>
#include<process.h>

main(){
    int stackArray[25];
    int topOfStack = -1;
    int answer,i;

    //For continuous display of the menu

    while (true) {
        printf("\n ************** \n");
        printf("Stack Operations Using Array \n \n");
        printf("1. Push \n2. Pop\n3. Display\n4. Exit\n");

        scanf("%d", &answer);
        switch (answer){

            //Entering values in stack

            case 1:
                if(topOfStack == 24){
                    printf("Stack is full, overflow \n");
                }
                else{
                    topOfStack++;
                    printf("Enter the value to be inserted \n");
                    scanf("%d", &stackArray[topOfStack]);
                }
                break;

            case 2:

            //Getting values from stack using LIFO

                if(topOfStack == -1){
                    printf("Stack is empty, underflow \n");
                }
                else{
                    topOfStack--;
                    printf("Value is deleted \n");
                }
                break;

            case 3:

            //Display all values in stack

                if(topOfStack == -1){
                    printf("Stack is empty add values first \n");
                }
                else{
                    printf("Stack is \n \n");
                    for(i = topOfStack;i >= 0;i--){
                       printf("%d \n", stackArray[i]);
                    }
                }
                break;

            default:
                exit(0);
        }
    }

}

//Written in ANSI for the GNU-GCC compiler
//Elit Altum
