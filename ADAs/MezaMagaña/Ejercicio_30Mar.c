/*
    Author Joshua Immanuel Meza Magaña
    Version 1.0.0
    Date 30/03/2020
    Program who makes operations with two rational numbers
*/
#include <stdio.h>
#include <math.h>

struct rational{
    int num;
    int den;
};

void readNum(struct rational *,struct rational *,int);
void readDen(struct rational *,struct rational *,int);
void addRational(struct rational,struct rational,int res[][2]);
void subRational(struct rational,struct rational,int res[][2]);
void mulRational(struct rational,struct rational,int res[][2]);
void divRational(struct rational,struct rational,int res[][2]);
void simpRational(int res[][2],int);
void printRes(int res[][2]);

int main(){
    /* Input */
    struct rational r1, r2;
    int res[4][2],insFlag=0;
    while(insFlag<=1){
        readNum(&r1,&r2,insFlag);
        readDen(&r1,&r2,insFlag); 
        insFlag++;   
    }

    /* Process */
    addRational(r1,r2,res);
    subRational(r1,r2,res);
    mulRational(r1,r2,res);
    divRational(r1,r2,res);

    /* Output */
    printRes(res);

    return 0;
}

/* Functions */

void readNum(struct rational *r1,struct rational *r2, int insFlag){
    /*
    It reads the numerators
    Args:
        r1 (structure): First rational
        r2 (structure): Second rational
        insFlag (int): Flag to know which rational is 
    Returns:
        The numerators
    */
    if(insFlag==0){
        printf("Insert the first numerator: ");
        scanf("%d",&r1 -> num);
    }else{
        printf("Insert the second numerator: ");
        scanf("%d",&r2 -> num);
    }
}

void readDen(struct rational *r1,struct rational *r2, int insFlag){
    /*
    It reads the numerators
    Args:
        r1 (structure): First rational
        r2 (structure): Second rational
        insFlag (int): Flag to know which rational is 
    Returns:
        The numerators
    */
    if(insFlag==0){
        printf("Insert the first denominator: ");
        scanf("%d",&r1 -> den);
        while(r1 -> den ==0){
            printf("ERROR, TRY AGAIN: ");
            scanf("%d",&r1 -> den);
        }
    }else{
        printf("Insert the second numerator: ");
        scanf("%d",&r2 -> den);
         while(r2 -> den ==0){
            printf("ERROR, TRY AGAIN: ");
            scanf("%d",&r2 -> den);
        }
    }
}

void addRational(struct rational r1,struct rational r2,int res[][2]){
    /*
    Do the sum of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The sum of fractions 
    */
    res[0][0]=r1.num*r2.den+r1.den*r2.num;
    res[0][1]=r1.den*r2.den;

    simpRational(res,0);
}

void subRational(struct rational r1,struct rational r2,int res[][2]){
    /*
    Do the substraction of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The substraction of fractions 
    */
    res[1][0]=r1.num*r2.den-r1.den*r2.num;
    res[1][1]=r1.den*r2.den;

    simpRational(res,1);
}

void mulRational(struct rational r1,struct rational r2,int res[][2]){
    /*
    Do the multiplication of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The multiplication of fractions 
    */
    res[2][0]=r1.num*r2.num;
    res[2][1]=r1.den*r2.den;

    simpRational(res,2);
}

void divRational(struct rational r1,struct rational r2,int res[][2]){
    /*
    Do the division of fractions
    Args:
        res (array): contains the results of the operations
        r1 (structure): First rational
        r2 (structure): Second rational
    Returns:
        The division of fractions 
    */
    res[3][0]=r1.num*r2.den;
    res[3][1]=r1.den*r2.num;

    simpRational(res,3);
}

void simpRational(int res[][2],int position){
    /*
    It simplifies the result
    Args:
        res (array): contains the results of the operations
        position (int): describes which operation is simplifying
        N (int): spaces for the array
        prime (array): list of prime numbers in the domain
        i (int): counter
        j (int): counter
    Returns:
        The final result
    */
    int N,i,j;

    /* Length of the array of prime numbers */
    if(res[position][0]>res[position][1]){
        N=res[position][0];
    }else{
        N=res[position][1];
    }

    if(N<0){
        N*=-1;
    }

    int prime[N];
    
    /* Sieve of Eratosthenes */
    for(i=0;i<N;i++){
        prime[i]=i+2;
    }
    
    for(i=0;i<sqrt(N);i++){
        if(prime[i]!=0){
            j=i+1;
            while(j<N){
                if(prime[j]%prime[i]==0){
                    prime[j]=0;
                }
                j++;
            }
        }
    }

    /* Reduction */
    i=0;
    while(i<N){
        if(prime[i]==0){
            i++;
        }else{
            if(res[position][0]%prime[i]==0 && res[position][1]%prime[i]==0){
                res[position][0]=res[position][0]/prime[i];
                res[position][1]=res[position][1]/prime[i];
            }else{
            i++;
            }
        }
    }
}

void printRes(int res[][2]){
    /* Print the results */
    if(res[0][0]==res[0][1]){
        printf("Sum of fractions: 1\n");
    }else if(res[0][1]==1){
        printf("Sum of fractions: %d\n",res[0][0]);
    }else if(res[0][1]==-1){
        printf("Sum of fractions: %d\n",res[0][0]*-1);
    }else if(res[0][0]==0){
        printf("Sum of fractions: 0\n");
    }else if(res[0][0]<0 && res[0][1]<0){
        printf("Sum of fractions: %d/%d\n",res[0][0]*-1,res[0][1]*-1);
    }else if(res[0][0]<0 || res[0][1]<0){
        if(res[0][0]<0){
            printf("Sum of fractions: %d/%d\n",res[0][0],res[0][1]);
        }else{
            printf("Sum of fractions: -%d/%d\n",res[0][0],res[0][1]*-1);
        }
    }else{
        printf("Sum of fractions: %d/%d\n",res[0][0],res[0][1]);
    }

    if(res[1][0]==res[1][1]){
        printf("Substraction of fractions: 1\n");
    }else if(res[1][1]==1){
        printf("Substraction of fractions: %d\n",res[1][0]);
    }else if(res[1][1]==-1){
        printf("Substraction of fractions: %d\n",res[1][0]*-1);
    }else if(res[1][0]==0){
        printf("Substraction of fractions: 0\n");
    }else if(res[1][0]<0 && res[1][1]<0){
        printf("Substraction of fractions: %d/%d\n",res[1][0]*-1,res[1][1]*-1);
    }else if(res[1][0]<0 || res[1][1]<0){
        if(res[1][0]<0){
            printf("Substraction of fractions: %d/%d\n",res[1][0],res[1][1]);
        }else{
            printf("Substraction of fractions: -%d/%d\n",res[1][0],res[1][1]*-1);
        }
    }else{
        printf("Substraction of fractions: %d/%d\n",res[1][0],res[1][1]);  
    }
    
    if(res[2][0]==res[2][1]){
        printf("Multiplication of fractions: 1\n");
    }else if(res[2][1]==1){
        printf("Multiplication of fractions: %d\n",res[2][0]);
    }else if(res[2][1]==-1){
        printf("Multiplication of fractions: %d\n",res[2][0]*-1);
    }else if(res[2][0]==0){
        printf("Multiplication of fractions: 0\n");
    }else if(res[2][0]<0 && res[2][1]<0){
        printf("Multiplication of fractions: %d/%d\n",res[2][0]*-1,res[2][1]*-1);
    }else if(res[2][0]<0 || res[2][1]<0){
         if(res[2][0]<0){
            printf("Multiplication of fractions: %d/%d\n",res[2][0],res[2][1]);
        }else{
            printf("Multiplication of fractions: -%d/%d\n",res[2][0],res[2][1]*-1);
        }
    }else{
        printf("Multiplication of fractions: %d/%d\n",res[2][0],res[2][1]);  
    }
    
    if(res[3][1]==0){
        printf("Division of fractions: Undefined");
    }else if(res[3][0]==res[3][1]){
        printf("Division of fractions: 1\n");
    }else if(res[3][1]==1){
        printf("Division of fractions: %d\n",res[3][0]);
    }else if(res[3][1]==-1){
        printf("Division of fractions: %d\n",res[3][0]*-1);
    }else if(res[3][0]==0){
        printf("Division of fractions: 0\n");
    }else if(res[3][0]<0 && res[3][1]<0){
        printf("Division of fractions: %d/%d\n",res[3][0]*-1,res[3][1]*-1);
    }else if(res[3][0]<0 || res[3][1]<0){
         if(res[3][0]<0){
            printf("Division of fractions: %d/%d\n",res[3][0],res[3][1]);
        }else{
            printf("Division of fractions: -%d/%d\n",res[3][0],res[3][1]*-1);
        }
    }else{
        printf("Division of fractions: %d/%d\n",res[3][0],res[3][1]);  
    }  
}
