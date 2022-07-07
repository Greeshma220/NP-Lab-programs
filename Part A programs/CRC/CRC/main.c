#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
int rem(int,int);
int main()
{
    int dil,dl,i,j,k;
    int data[10],div[5],newdata[15],crc[5],datacrc[15],revdata[15],remdata[5];
    printf("Enter the length of data:\n");
    scanf("%d",&dl);
    printf("Enter the length of divisor:\n");
    scanf("%d",&dil);
    printf("Enter the data:\n");
    for(i=0;i<dl;i++)
    {
        scanf("%d",&data[i]);
    }
     printf("Enter the divisor:\n");
    for(i=0;i<dil;i++)
    {
        scanf("%d",&div[i]);
    }
    printf("Newdata is:\n");
    for(i=0;i<(dl+dil-1);i++)
    {
        if(i<dl)
            newdata[i]=data[i];
        else
            newdata[i]=0;
            printf("%d",newdata[i]);
    }
    for(j=0;j<=dl;j++)
    {
        for(i=0;i<dil;i++)
        {
            crc[i]=newdata[i+j];
            if(crc[0]==1)
                newdata[i+j]=rem(newdata[i+j],div[i]);
            else
                newdata[i+j]=rem(newdata[i+j],0);

        }
        printf("\nCrc is:\n");
        for(i=0;i<dil-1;i++)
            printf("%d",crc[i]);
    }
    printf("The data to be sent is:\n ");
    for(i=0;i<(dl+dil-1);i++)
    {
        if(i<dl)
            datacrc[i]=data[i];
        else
            datacrc[i]=crc[i-dl];
            printf("%d",datacrc[i]);
    }
    printf("Enter receiver data: \n");
     for(i=0;i<(dl+dil-1);i++)
    { scanf("%d",&revdata[i]);}
    for(j=0;j<=dl;j++)
    {
        for(i=0;i<dil;i++)
        {
            remdata[i]=revdata[i+j];
            if(remdata[0]==1)
                revdata[i+j]=rem(revdata[i+j],div[i]);
            else
                revdata[i+j]=rem(revdata[i+j],0);
        }
         printf("Remainder is:\n");
         k=0;
        for(i=0;i<dil-1;i++)
        {
            printf("%d",remdata[i]);
            if(remdata[i]==0)
                k++;
        }
    }
    if(k==dil-1)
        printf("No error\n");
    else
        printf("Error found\n");

}
int rem(int x,int y)
{
    if(x==y)
        return 0;
    else
        return 1;
}
