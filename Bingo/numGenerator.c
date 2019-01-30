/*
	Dima Ivanov's C Programs:
	
	Bingo Number Generator
	
	This program generates a sequence of numbers from 1-99 in random order upon the user's request.
	Some code which changes the font size was taken from an online source.
*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int GetFontSize(HANDLE windowHandle, COORD *size)
{
CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
    {
    return 0;
    }

*size = font.dwFontSize;

return 1;
}

int SetFontSize(HANDLE windowHandle, COORD size)
{
CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
    {
    return 0;
    }

font.dwFontSize = size;

if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
    {
    return 0;
    }

return 1;
}

int main(void)
{
    int i,j;
    char input;
    int numGened;
    int numsGenerated[99];
    int numMatches;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;

    if (GetFontSize(h, &size))
    {
    /* Grow by 50% */
    size.X += (SHORT)(size.X * 1);
    size.Y += (SHORT)(size.Y * 1);
    SetFontSize(h, size);
}

    srand((unsigned int) time(NULL));
    while(1==1)
    {
        numGened=0;
        for(i=0;i<99;i++)
        {
            numsGenerated[i]=0;
        }
        do
        {
            system("cls");
            printf("\n\n\tPress any key to generate the next number\n\tPress the Escape Key to reset the generator\n\tNumbers that have currently been generated: %2i\n\n\t",numGened);
            if(numGened!=0)
            {
                printf("Here is your number: %2i\n\n\tAll Numbers that have been generated:",numsGenerated[numGened-1]);
                for(i=0;i<numGened;i++)
                {
                    if(i%20==0)
                    {
                        printf("\n\t");
                    }
                    printf("%2i ",numsGenerated[i]);
                }
            }
            input=getch();
            if(input!=27)
            {
                if(numGened==99)
                {
                    system("cls");
                    printf("\n\n\tAll possible numbers have been generated, reseting...");
                    getch();
                    break;
                }
                else
                {
                    do
                    {
                        numsGenerated[numGened]=rand()%99+1;
                        numMatches=0;
                        for(i=0;i<numGened;i++)
                        {
                            if(numsGenerated[i]==numsGenerated[numGened])
                            {
                                numMatches=1;
                                break;
                            }
                        }
                    }
                    while(numMatches==1);
                    numGened++;
                }
            }
        }
        while(input!=27);
    }
}
