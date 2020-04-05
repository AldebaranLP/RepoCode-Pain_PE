/*
    Author Joshua Immanuel Meza Magaña
    Version 1.0.0
    Date 03/04/2020
    Program who saves total amounts of money per day 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ch 121

typedef struct info{
    char name[ch];
    float money;
    int date;
}INFO;
typedef struct node{
    INFO data;
    struct node *nextNode;
}NODE;
typedef NODE *NodePTR; /* Node Pointer */

void asigStr(char name[ch]);
int askContinue();
int getDate();
float getMoney();
void insertOrganized(NodePTR *,char*,int,float);
void printList(NodePTR);
void cleanString(char name[ch]);

int main(){
    /* Input */
    NodePTR headPTR=NULL;
    int flag=1,i=0,date;
    char name[ch];
    float money;

    /* Process */
    while(flag==1){
        asigStr(name);
        date=getDate();
        money=getMoney();

        insertOrganized(&headPTR,name,date,money);

        flag=askContinue();
        cleanString(name);
    }

    /* Output */
    printList(headPTR);

    return 0;
}

/* Functions */

void cleanString(char name[ch]){
    int i;

    memset(name,'\0',ch);
}

void asigStr(char name[ch]){
    /*
    Get the name
    Args:
        a (char): temporary string
        name (char): dinamic memory for the string
    Returns:
        The name with the correct space of memory
    */
    printf("Insert the name of the person who used the cash register that day: ");
    gets(name);
}

int askContinue(){
    /*
    Check if the user want to register another day
    Args:
        a (int): takes 1 or 0 as True or False
    Returns:
        The decision
    */
    int a;

    printf("Do you want to register another day? (1/0)\nR: ");
    scanf("%d",&a);

    return a;
}

int getDate(){
    /*
    Obtains the correct date
    Args:
        dd (int): days
        mm (int): months
        yyyy (int): years
        ly (int): leap year
        final (int): final date
    Returns:
        The date
    */
    int dd,mm,yyyy,ly=0,final;

    printf("Insert the year (yyyy): ");
    scanf("%d",&yyyy);
    if(yyyy%4==0){
        ly=1;
    }
    printf("Insert the month (mm): ");
    scanf("%d",&mm);
    while(mm<1 || mm>12){
        printf("Select a month between 1 and 12: ");
        scanf("%d",&mm);
    }
    printf("Insert the day (dd): ");
    scanf("%d",&dd);
    if(mm<=6){
        if(mm%2!=0){
            if(dd<0 || dd>31){
                while(dd<0 || dd>31){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
        }else if(mm==2){
            if(ly==1){
                if(dd<0 || dd>29){
                while(dd<0 || dd>29){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
            }else{
                if(dd<0 || dd>28){
                while(dd<0 || dd>28){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
            }
        }else{
            if(dd<0 || dd>30){
                while(dd<0 || dd>30){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
        }
    }else{
        if(mm==9 || mm==11){
            if(dd<0 || dd>30){
                while(dd<0 || dd>30){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
        }else{
            if(dd<0 || dd>31){
                while(dd<0 || dd>31){
                    printf("The day is incorrect, try again: ");
                    scanf("%d",&dd);
                }
            }
        }
    }
    final=yyyy+mm*10000+dd*1000000;

    return final;
}

float getMoney(){
    /*
    It reads the amount of money
    Args:
        money (float): Amount of money
    Returns:
        The amount of money
    */
   float _money;

   printf("Insert the amount of money: ");
   scanf("%f",&_money);

   return _money;
}

void insertOrganized(NodePTR *nptr,char* _name,int _date,float _money){
    NodePTR newNode, actualNode=*nptr, previousNode=NULL;

    newNode=(NODE*)malloc(sizeof(NODE)); 
    
    if(newNode!=NULL){
        strcpy(newNode -> data.name,_name);
        newNode -> data.date=_date;
        newNode -> data.money=_money;
        newNode -> nextNode=NULL;

        while(actualNode!=NULL && _date>actualNode->data.date){
            previousNode=actualNode;
            actualNode=actualNode->nextNode;
        }

        if(previousNode==NULL){
            newNode -> nextNode=*nptr;
            *nptr=newNode;
        }else{
            previousNode -> nextNode=newNode;
            newNode -> nextNode=actualNode;
        }
    }else{
        printf("There is no more memory\n");
    }
}

void printList(NodePTR actualNode){
    if(actualNode==NULL){
        printf("-----------\n");
        printf("Empty list");
        printf("-----------\n");
    }else{
        printf("-----------\n");
        printf("List:\n");

        while(actualNode!=NULL){
            printf("-----------\n");
            printf("Name: %s\n",actualNode->data.name);
            printf("Date: %d\n",actualNode->data.date);
            printf("Money: %.2f\n",actualNode->data.money);

            actualNode=actualNode->nextNode;
        }
        printf("-----------\n");
    }
}
