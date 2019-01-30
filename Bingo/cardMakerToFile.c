/*
	Dima Ivanov's C Programs:
	
	Bingo Card Maker
	
	This program makes a file which contains 5 different, randomized bingo cards.
	Numbers range from 1-99 and a free space is located in the middle.
*/

#include<stdio.h>

int main(void)
{
    int card[25]={0};
    int i,j,k;
    int numMatches;
    FILE*fp=fopen("bingoCard.txt","w");

    srand((unsigned int) time(NULL));
    for(k=0;k<5;k++)
    {
        for(i=0;i<25;i++)
        {
            do
            {
                card[i]=rand()%99+1;
                numMatches=0;
                for(j=0;j<i;j++)
                {
                    if(card[j]==card[i])
                    {
                        numMatches=1;
                        break;
                    }
                }
            }
            while(numMatches==1);
        }
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(i==2&&j==2)
                {
                    fputc(32,fp);
                    fputc(32,fp);
                }
                else
                {
                    fputc((card[5*i+j]/10)+48,fp);
                    fputc((card[5*i+j]%10)+48,fp);
                }
                fputc(32,fp);
            }
            fputc(10,fp);
        }
        fputc(10,fp);
    }

    fflush(fp);
    fclose(fp);
}
