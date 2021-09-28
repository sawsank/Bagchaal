#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void gotoxy(int, int);
void display(int arr[][3],int, int);
int check(int arr[][3],int,int);

int nine ()
{
    char key;
    int row=2,col=2,move=0;
    int arr[][3]={1,5,6,8,3,2,4,7,9};

    char name[100];
    printf("Enter your name: ");
    scanf("%[^\n]",name);

    FILE *fptr;

    fptr=fopen("info.txt","r+");
    if (fptr==NULL)
    {
        fptr=fopen("info.txt","w+");

        if (fptr==NULL)
        {
            fprintf(stderr,"File cannot be opened");
        }
    }

    fseek(fptr, 0, SEEK_END);
    fprintf(fptr,"\n%-20s",name);

    display(arr,3,3);

    gotoxy(20,6);



    row=6;
    col=6;
    printf("\n\n\n");
    gotoxy(row,col);


    do
    {
        key=getch();

        if (key=='w')
        {
            move++;
            if (col>3)
            {

                int temp;
                temp=arr[col/2-1][row/2-1];
                arr[col/2-1][row/2-1]=arr[col/2-2][row/2-1];
                arr[col/2-2][row/2-1]=temp;
                system("cls");
                display(arr,3,3);

                col=col-2;
                gotoxy(row,col);

                if (check(arr,3,3)==0)
                {
                    system("cls");
                    printf("CONGRATULATIONS\nYou finally did it.");
                    fseek(fptr,5,SEEK_CUR);
                    fprintf(fptr,"Completed");
                    fseek(fptr, 4, SEEK_CUR);
                    fprintf(fptr,"%d\n",move);
                }

            }
        }

        if (key=='s')
        {
            move++;
            if (col<5)
            {

                int temp;
                temp=arr[col/2-1][row/2-1];
                arr[col/2-1][row/2-1]=arr[col/2][row/2-1];
                arr[col/2][row/2-1]=temp;
                system("cls");
                display(arr,3,3);

                col=col+2;
                gotoxy(row,col);

                if (check(arr,3,3)==0)
                {
                    system("cls");
                    printf("CONGRATULATIONS\nYou did it.");
                    fseek(fptr,5,SEEK_CUR);
                    fprintf(fptr,"Completed");
                    fseek(fptr, 4, SEEK_CUR);
                    fprintf(fptr,"%d\n",move);
                }
            }
        }

        if (key=='d')
        {
            move++;
            if (row<5)
            {

                int temp;
                temp=arr[col/2-1][row/2-1];
                arr[col/2-1][row/2-1]=arr[col/2-1][row/2];
                arr[col/2-1][row/2]=temp;
                system("cls");
                display(arr,3,3);

                row=row+2;
                gotoxy(row,col);

                if (check(arr,3,3)==0)
                {
                    system("cls");
                    printf("CONGRATULATIONS\nYou did it.");
                    fseek(fptr,5,SEEK_CUR);
                    fprintf(fptr,"Completed");
                    fseek(fptr, 4, SEEK_CUR);
                    fprintf(fptr,"%d\n",move);
                }
            }
        }

        if (key=='a')
        {
            move++;
            if (row>3)
            {

                int temp;
                temp=arr[col/2-1][row/2-1];
                arr[col/2-1][row/2-1]=arr[col/2-1][row/2-2];
                arr[col/2-1][row/2-2]=temp;
                system("cls");
                display(arr,3,3);

                row=row-2;
                gotoxy(row,col);

                if (check(arr,3,3)==0)
                {
                    system("cls");
                    printf("CONGRATULATIONS\nYou did it.");
                    fseek(fptr,5,SEEK_CUR);
                    fprintf(fptr,"Completed");
                    fseek(fptr, 4, SEEK_CUR);
                    fprintf(fptr,"%d",move);
                }

            }
        }
        gotoxy(20,2);
        printf("Moves: %d",move);

        gotoxy(row,col);


    }
    while (key!=13);

    if (key==13)
    {
        system("cls");
        printf("Its over");
        getch();
    }

}

void gotoxy(int x,int y)
{
    HANDLE hStdout = GetStdHandle (STD_OUTPUT_HANDLE);
    COORD position={x,y};
    SetConsoleCursorPosition(hStdout,position);

}

void display(int arr[][3],int l,int m)
{
    int row=2,col=2;
    for (int i=0; i<l; i++)
    {
        row=2;
        for (int j=0; j<m; j++)
        {
            gotoxy(row,col);
            printf("%d ",arr[i][j]);
            row=row+2;
        }
        col=col+2;
    }

}

int check(int arr[][3],int row,int col)
{
    int flag=0,a=1;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if (arr[i][j]!=a)
            {
                flag=1;
            }
            a++;

        }
    }
    return flag;

}

