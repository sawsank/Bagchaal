#include <stdio.h>
char isPiece(char s[], int pos);
int nor_mcheck(int old,int news);
int capture_move(int old , int news);
char game_win(int *capt_goats, char s[]);


int main()
{
	char s[25];
	int i,on=1;
	int mid;
	int diff;
	int extra_goats=20;
	int captured_goats=0;
	_Bool player=0;
	int oldPos,newPos;
	for (i=0;i<25;i++)
	{
		s[i]=32;
	}
	s[0]=s[4]=s[20]=s[24]=84;
	while( on )
	{
		printf(" %c-----%c-----%c-----%c-----%c \n",s[0],s[1],s[2],s[3],s[4]);
		printf(" | \\   |   / | \\   |   / |\n");
		printf(" |   \\ | /   |   \\ | /   |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[5],s[6],s[7],s[8],s[9]);
		printf(" |   / | \\   |    /| \\   |\n");
		printf(" | /   |   \\ |  /  |   \\ |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[10],s[11],s[12],s[13],s[14]);
		printf(" | \\   |   / | \\   |   / |\n");
		printf(" |   \\ | /   |   \\ | /   |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[15],s[16],s[17],s[18],s[19]);
		printf(" |   / | \\   |   / | \\   |\n");
		printf(" | /   |   \\ | /   |   \\ |\n");
		printf(" %c-----%c-----%c-----%c-----%c: %d,%d\n\n",s[20],s[21],s[22],s[23],s[24],extra_goats,captured_goats);

		if (player==0)
		{
			//goats turn
			if (extra_goats)
			{	//if there are spare goats
				printf("Enter your move:Goat(5) ");
				scanf("%d",&newPos);
				newPos=newPos-1;
				if (newPos>25)
				{
					on=1;
				}
				while (getchar()!='\n');

				if (isPiece(s,newPos)==32)
				{
					s[newPos]=71;
					extra_goats=extra_goats-1;

					player=1;
				}
				else
				{
					printf("\nNot valid\n");
				}

			}
			else
			{	//if there arent spare goats
				printf("Enter your move,Goat:(5,10) ");
				scanf("%d %d",&oldPos,&newPos);
				newPos=newPos-1;
				oldPos=oldPos-1;
				if (newPos>25)
				{
					on=1;
				}
				while (getchar()!='\n');
				if ((isPiece(s,newPos)==32) && nor_mcheck(oldPos,newPos) && s[oldPos]==71)
				{
					s[newPos]=71;
					s[oldPos]=32;

					player=1;
				}
				else
				{
					printf("\nNot valid\n");
				}
			}
		}

		else
		{
			//tiger turn
			printf("Enter your move:Tiger(5,10)");
			scanf("%d %d",&oldPos,&newPos);
			newPos=newPos-1;
			oldPos=oldPos-1;
			diff=oldPos-newPos;


			if (newPos>25)
				{
					on=1;
				}
			while (getchar()!='\n');

                   // printf("\nDifference: %d\n",diff);
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
                        printf("\nnot valid in capture 2");
                    }
                }
                else
                {
                    printf("\nNot valid in capture\n");
                   // printf("capture : %d",capture_move(oldPos,newPos));
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
                    printf("\nNot valid in normal tiger move\n");
                }
            }
		}


	}
	return 0;
}


int nor_mcheck(int old,int news)
{
	unsigned char pos[25];
	int mod_new=0;
	int flag=0;
	//storing positions
	pos[0]=034;
	pos[1]=025;
	pos[2]=037;
	pos[3]=025;
	pos[4]=007;
	pos[5]=0124;
	pos[6]=0377;
	pos[7]=0125;
	pos[8]=0377;
	pos[9]=0105;
	pos[10]=0174;
	pos[11]=0125;
	pos[12]=0377;
	pos[13]=0125;
	pos[14]=0307;
	pos[15]=0124;
	pos[16]=0377;
	pos[17]=0125;
	pos[18]=0377;
	pos[19]=0105;
	pos[20]=0160;
	pos[21]=0121;
	pos[22]=0361;
	pos[23]=0121;
	pos[24]=0301;


	//modifying new value
	switch (old-news)
	{
		case 6:
		{
			mod_new=1;
			return (pos[old] & 128?1:0);
			break;
		}
		case 5:
		{
			mod_new=2;
			return (pos[old] & 64?1:0);
			break;
		}
		case 4:
		{
			mod_new=3;
			return (pos[old] & 32?1:0);
			break;
		}
		case -1:
		{
			mod_new=4;
			return (pos[old] & 16?1:0);
			break;
		}
		case -6:
		{
			mod_new=5;
			return (pos[old] & 8?1:0);
			break;
		}
		case -5:
		{
			mod_new=6;
			return (pos[old] & 4?1:0);
			break;
		}
		case -4:
		{
			mod_new=7;
			return (pos[old] & 2?1:0);
			break;
		}
		case 1:
		{
			mod_new=8;
			return (pos[old] & 1?1:0);
			break;
		}

		default:
			{
			return 0;
			break;
			}
	}
}



char isPiece(char s[], int pos)
{
	if (s[pos]=='G')
	{
		return 'G';
	}
	else if (s[pos]=='T')
	{
		return 'T';
	}
	else
	{
		return ' ';
	}
}

int capture_move(int old , int news)
{
	unsigned char pos[25];
	int mod_new=0;
	int flag=0;
	//storing positions
	pos[0]=034;
	pos[1]=025;
	pos[2]=037;
	pos[3]=025;
	pos[4]=007;
	pos[5]=0124;
	pos[6]=0377;
	pos[7]=0125;
	pos[8]=0377;
	pos[9]=0105;
	pos[10]=0174;
	pos[11]=0125;
	pos[12]=0377;
	pos[13]=0125;
	pos[14]=0307;
	pos[15]=0124;
	pos[16]=0377;
	pos[17]=0125;
	pos[18]=0377;
	pos[19]=0105;
	pos[20]=0160;
	pos[21]=0121;
	pos[22]=0361;
	pos[23]=0121;
	pos[24]=0301;


	//modifying new value
	switch (old-news)
	{
		case 6*2:
		{
			mod_new=1;
			return (pos[old] & 128?1:0);
			break;
		}
		case 5*2:
		{
			mod_new=2;
			return (pos[old] & 64?1:0);
			break;
		}
		case 4*2:
		{
			mod_new=3;
			return (pos[old] & 32?1:0);
			break;
		}
		case -1*2:
		{
			mod_new=4;
			return (pos[old] & 16?1:0);
			break;
		}
		case -6*2:
		{
			mod_new=5;
			return (pos[old] & 8?1:0);
			break;
		}
		case -5*2:
		{
			mod_new=6;
			return (pos[old] & 4?1:0);
			break;
		}
		case -4*2:
		{
			mod_new=7;
			return (pos[old] & 2?1:0);
			break;
		}
		case 1*2:
		{
			mod_new=8;
			return (pos[old] & 1?1:0);
			break;
		}

		default:
			{
			return 0;
			break;
			}
	}


}

char game_win(int *capt_goats,char s[])
{
    int t[5],i,j,k;
    char result;
    int flag=0;
	if (*capt_goats >=5)
        result='G';
    else
    {
        for (i=0;i<24;i++)
        {
        if (s[i]=='T')
        {
            t[j]=i;
            j++;
        }
        }
        for (k=0;k<4;k++)
        {
            for (i=0;i<24;i++)
            {
                if (nor_mcheck(t[k],i))
                    flag=1;
                if (capture_move(t[k],i))
                    flag=1;
            }
        }
        if (flag==1)
            result='G';

    }
    return result;
}
