//To implement queue in a 1D Array using Menu-Driven flow of control
//12.01.19

#include<stdio.h>
#include<process.h>
#include<conio.h>

main(){
    int Queue[20];
    int QueueRear,QueueFront,i,j,Answer;
    QueueFront = QueueRear = -1;

    //Continuous display of menu

    while(1){
        printf("\n Queue Using Array Operations Menu \n \n");
        printf("1. Insert In Queue \n");
        printf("2. Delete From Queue \n");
        printf("3. Display Queue \n");
        printf("4. Exit\n");
        scanf("%d", &Answer);

        switch (Answer)
        {
            case 1:
                //Inserting in the queue

                if(QueueRear == 19){
                    printf("Queue is full, Overflow\n");
                }
                else if(QueueFront == -1){
                    QueueFront++;
                    QueueRear++;
                    printf("Enter the value\n");
                    scanf("%d",&Queue[QueueRear]);
                }
                else{
                    QueueRear++;
                    printf("Enter the value\n");
                    scanf("%d",&Queue[QueueRear]);
                }
                break;
            case 2:
                //Deletion from the queue using FIFO

                if(QueueFront == -1){
                    printf("Queue is empty, Underflow\n");
                }
                else if(QueueFront == QueueRear){
                    QueueFront = QueueRear = -1;
                    printf("Element deleted\n");
                }
                else{
                    QueueFront++;
                    printf("Element deleted\n");
                }
                break;
            case 3:
                //Display the queue

                if(QueueFront == -1){
                    printf("Queue is empty, enter elements first \n");
                }
                else{
                    printf("Queue is \n");
                    for(i = QueueFront;i <= QueueRear;i++){
                        printf("%d \n", Queue[i]);
                    }
                }
                break;
            default:
                //Default to exit from the program  
                exit(0);
        }
    }
    getch();
}

//Written in ANSI for the GNU-GCC complier
//Elit Altum
