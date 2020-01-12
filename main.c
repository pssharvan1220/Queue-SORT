#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXQUEUE 200

typedef enum{TRUE,FALSE} Boolean;

typedef struct Queue{
    int front;      //Starting position of Queue
    int rear;       //End Position of Queue
    int count;      //No.of Elements in Queue
    int QUE[MAXQUEUE];
}queue;

void createqueue(queue *q)
{
    q->count=0;
    q->front=0;
    q->rear=-1;
}

Boolean IsQueueEmpty(queue *q)
{
    return(q->count==0);
}

Boolean IsQueueFull(queue *q)
{
    return(q->count==MAXQUEUE);
}

void InsertQueue(queue *q,int x)
{
    if(IsQueueFull(q))
    {
        printf("Queue is FULL !!!");
    }
    else
    {
        q->QUE[q->count]=x;
        q->rear++;
        q->count++;
    }
}
void RemoveQueue(queue *q,int *x)
{
    if(IsQueueEmpty(q))
    {
        printf("Queue Is Empty!!!");
    }
    else{
        *x=q->QUE[q->front];
        printf("removed: %d\n",*x);
        q->count--;     //when removes an element the number will decrease
        q->front++;     //This is how to remove an element [ First IN First OUT ]
    }
}

void DisplayQueue(queue *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d\n",q->QUE[i]);
    }
}

void Swap(int *xp,int *yp)
{
    int swap=*xp;
    *xp=*yp;
    *yp=swap;
}


void SortQueue(queue *q)
{
    int i,j,min_idx,arr[q->count],n=0;
    for(i=0;i<q->count;i++){
        //Save current queue to an array
        arr[i]=q->QUE[q->front+i];
        n++;
    }

    //Sort the array USING Selection Sort Method
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j; //Finding the smallest value
            }
        }
        Swap(&arr[min_idx], &arr[i]); //Assigning the smallest value to the i_th value
    }

    //Display The Sorted Array
    for(i=0;i<q->count;i++){
        printf("\n%d",arr[i]);
    }

}

int main()
{
    queue q;
    createqueue(&q);
    int x,size,i,add,del;
    printf("Enter Queue Size: "); scanf("%d",&size);
    printf("\nEnter Elements into the Queue:\n");
    for(i=1;i<=size;i++){
        scanf("%d",&add);
        InsertQueue(&q,add);
    }
    printf("\nHowmany Elements do you want to remove from Queue: "); scanf("%d",&del);
    printf("\n");

    if(size==del){
            for(i=1;i<=del;i++)
                RemoveQueue(&q,&x);
            printf("\nAfter operations Queue is empty");
    }
    else if(size<del)
        printf("Queue only have %d elements\nBut you are trying to delete %d Elements",size,del);
    else
    {
        for(i=1;i<=del;i++)
            RemoveQueue(&q,&x);
    }
    printf("\n");
    printf("\nQueue Is:\n");
    DisplayQueue(&q);
    printf("\nSorted Queue Is: \n");
    SortQueue(&q);
    printf("\n\n");

}
