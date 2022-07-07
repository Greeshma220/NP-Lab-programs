#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void receiver();
char frames[1024];
int main()
{
    int len,i,j,n;
    char buffer[256],length[10];
    printf("Enter the number of frames to be sent:\n");
    bzero(buffer,256);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
      printf("Enter the frame:\n");
      scanf("%s",&buffer);
      printf("Length of frame is %d:\n",strlen(buffer));
      len=strlen(buffer);
      len=len+1;
      sprintf(length,"%d",len);
      strcat(frames,length);
      strcat(frames,buffer);
    }
    for(int i=0;frames[i]!='\0';i++)
        printf("%c",frames[i]);
        receiver();
        return 0;
}
void receiver()
{
    int framelen,ipvar,i=0;
    char leninchar;
    printf("\nThis is reciever side:");
    printf("\nData is %s\n",frames);
    while(frames[i]!='\0')
    {
        leninchar=frames[i];
        framelen=(int)leninchar-(int)'0';
        printf("\nLength of the frame is %d \n",framelen);
        printf("\nFrame---->");
        ipvar=i+framelen;
        i=i+1;
        while(i<ipvar)
        {
            printf("%c",frames[i++]);
        }
        printf("\n");
    }
}
