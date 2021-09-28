#include <stdio.h>
#include <func.h>
#include <game.h>
#include <conio.h>
#include <string.h>
int main()
{
    char ch;
    char inp;
    int decision=1;
	int i,on=1;
	int mid;
	int diff;
	int cond=1;
	int extra_goats=1;
	int captured_goats=0;
	char username[30];
	char password[30];
	int chc[5]={711,' ',' ',' ',' '};
	char p[25][2];
	char s[25]={'G','T','G','G','G',
                'G','T','G',' ','G',
                'G','G','T','T','G',
                'G','G','G','G',' ',
                'G','G','G','G','G'};
	_Bool player=0;
	int oldPos,newPos;
    while (cond)
    {
        cls();
        menu(chc);
        while ((inp=getch())!='f')
        {
            if (inp=='w')
            {
                if ( (decision-1)>=1)
                    decision-=1;
            }
            else if (inp=='s')
            {
                if ( (decision+1)<=5)
                    decision+=1;
            }
            else
            {
                break;
            }

            for (int i=0;i<=4;i++)
            {
                chc[i]=' ';
            }
            chc[decision-1]=711;
            cls();
            menu(chc);
        }
        switch (decision)
        {
        case 1:

            for (i=0;i<25;i++)
            {
                s[i]=32;
                p[i][0]=32;
                p[i][1]=32;
            }
            p[0][0]='|';
            p[0][1]='|';
            s[0]=s[4]=s[20]=s[24]=84;
            extra_goats=20;
            cond=0;
            login(username,password);
            break;
        case 2:
            {
                load(username,password,s,&extra_goats,&captured_goats);//take from file
                cond=0;
                break;
            }
        case 3:
            cls();
            printf("Press 'F' or 'f' to select\n");
            printf("Press 'w' ,'a','s','d' to move\n");
            printf("Press 'o' to save game");
            getch();


            //disp_help();
            break;
        case 4:
            cls();
            printf("Bagchal is a traditional nepali two player game. \mThere are 20 goats and 4 tigers. \nTiger wins by capturing 5 goats.");
            printf("\nGoat wins by blocking all moves of Tiger");
            printf("\n\n*********************************");
            printf("\nGame of Nine");
            printf("\nThe Game of Nine is a puzzle played on a square, two-dimensional board with numbered tiles that slide.");
            printf("\nThe goal of this puzzle is to arrange the board�s tiles from smallest to largest, left to right, top to bottom. ");
            printf("\nTiles may not be moved diagonally, though, or forcibly removed from the board.");
            getch();
            //disp_about();
            break;
        case 5:
            cls();
            nine();
            getch();
    }
    }
    //loop until game stops
	while( on )
	{
	    char state;
	    cls();
		disp(s,p,extra_goats,captured_goats);
		disp(s,p,extra_goats,captured_goats);
		if (player==0)
		{
			//goats turn
			if (extra_goats)
			{	//if there are spare goats
			    int cur_pos=0;
				getp(&newPos,p,s,extra_goats,captured_goats,username,password);
				newPos=newPos-1;
				if (isPiece(s,newPos)==32)
				{
					s[newPos]=71;
					extra_goats=extra_goats-1;

					player=1;
				}
				else
				{
					printf("\nGoat cant move there\n");
				}

			}
			else
			{	//if there arent spare goats
                getpos(&oldPos,&newPos,0,p,s,extra_goats,captured_goats);
				newPos=newPos-1;
				oldPos=oldPos-1;
				if ((isPiece(s,newPos)==32) && nor_mcheck(oldPos,newPos) && s[oldPos]==71)
				{
					s[newPos]=71;
					s[oldPos]=32;
					player=1;
				}
				else
				{
					printf("\nNot valid...Press enter to continue\n");
					getch();
				}
			}
		}

		else
		{
			//tiger turn
			getpos(&oldPos,&newPos,1,p,s,extra_goats,captured_goats);
			newPos=newPos-1;
			oldPos=oldPos-1;
			diff=oldPos-newPos;

			if ( (diff==6*2) || (diff==5*2) || (diff ==4*2) || (diff==-1*2) || (diff == -6*2) || (diff==-5*2) || (diff ==-4*2) ||(diff==1*2) )
            {
                if (isPiece(s,newPos)==32 && capture_move(oldPos,newPos) && s[oldPos]==84)
                {
                    if ( (oldPos-diff)>=0 && s[oldPos-diff/2]=='G')
                    {
                    s[newPos]=84;
                    s[oldPos]=32;
                    s[oldPos-diff/2]=32;
                    captured_goats=captured_goats+1;
                    player=0;
                    }
                    else
                    {
                        printf("\nNo Goat to eat");
                    }
                }
                else
                {
                    printf("\nNo tiger or not empty space\n");
                }

			}
			else
            {
                if (isPiece(s,newPos)==32 && nor_mcheck(oldPos,newPos) && s[oldPos]==84)
                {
                    s[newPos]=84;
                    s[oldPos]=32;
                    player=0;
                }
                else
                {
                    printf("\nNot empty or no Tiger\n");
                }
            }
		}

    state=game_win(captured_goats, s);
    if (state!='N')
    {
        if (state=='G')
        {
            printf("\nGoat wins");
        }
        else if (state=='T')
        {
            printf("\nTiger Wins");
        }
        on=0;
    }
	}
	return 0;
}



