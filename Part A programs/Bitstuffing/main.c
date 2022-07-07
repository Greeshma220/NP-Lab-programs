#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void sender();
void receiver(int *message,int l2);
int main(void)
{
    sender();
}
   void sender()
   {
    int n,msg[50],result[50],i,j;
    int zerocounter=0,count=0,zero=0;
    printf("Enter the number of bits:\n");
    scanf("%d",&n);
    printf("Enter the data:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&msg[i]);
    }
    result[0]=0;
    result[1]=1;
    result[2]=1;
    result[3]=1;
    result[4]=1;
    result[5]=1;
    result[6]=1;
    result[7]=0;
    j=8;
    for(int i=0;i<n;i++)
    {
        if(msg[i]==0)
        {
            result[j]=msg[i];
            j++;
            zero=1;
            count=0;
        }
        else
        {
            if((count==5)&&(zero==1))
            {
                result[j]=0;
                j++;
                zerocounter++;
                result[j]=msg[i];
                j++;
                count=0;
            }
            else
            {
              result[j]=msg[i];
                j++;
                count++;
            }
        }
    }
    result[j++]=0;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=1;
    result[j++]=0;
    int l1=16+n+zerocounter;
    printf("\nLength of the frame is %d:\n",l1);
    printf("The frame is :");
    for(int i=0;i<j;i++)
    {
        printf("%d",result[i]);
    }
    receiver(result,l1);
   }
   void receiver(int *result,int l2)
   {
       int count,mesg[50];
       int l3=l2-8;
       int j=0;
       for(int i=8;i<l3;i++)
       {
           if(result[i]==0)
           {
               if(count==5)
               {
                   i++;
                   mesg[j]=result[i];
                   j++;
                   count=0;
               }
               else
               {
                   mesg[j]=result[i];
                   j++;
                   count=0;
               }
           }
           else
           {
                mesg[j]=result[i];
                j++;
                count++;
           }

       }
       printf("\nReceiver side data is:");
       for(int i=0;i<j;i++)
       {
           printf("%d",mesg[i]);
       }
   }
