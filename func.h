#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED



#endif // FUNC_H_INCLUDED
#include <stdio.h>
#include <conio.h>
#include <string.h>
void menu();
int nor_mcheck(int old,int news);
void disp(char s[],char p[][2],int ext,int capt);
char isPiece(char s[], int pos);
char game_win(int capt_goats,char s[]);
void getpos(int * oldp, int * newp,int player,char p[][2],char s[],int ext,int capt);
void getp(int * newp,char p[][2],char s[],int ext,int capt,char username[],char password[]);
void save(char username[],char password[],char s[],int ext_goats,int capt_goats);
void menu(int chc[]);
void cls();

void cls()
{
    system("cls");
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

char game_win(int capt_goats,char s[])
{
    int t[5],i,j=0,k;
    char result;
    int counter=0;
    int flag=0;
	if (capt_goats >=5)
        return 'T';
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
            for (i=0;i<=24;i++)
            {
                if ( (nor_mcheck(t[k],i)) && s[i]==' ' )
                {
                    counter ++;
                    //printf("\nk=%d--i=%d--chk=%d",t[k],i,nor_mcheck(t[k],i));
                }
                if ( (capture_move(t[k],i)) && s[i]==' ')
                {
                    counter++;
                    //printf("\nk=%d--i=%d--chk=%d",t[k],i,capture_move(t[k],i));
                }
            }
        }
        }
        if (counter==0)
            result='G';
        else
            result='N';
        //printf("\nThe counter : %d\n",counter);
    return result;
}
void getpos(int * oldp, int * newp,int player,char p[][2],char s[],int ext,int capt)
{
    char ch;
    int newPos,oldPos;
    /**
        For first old input */
    //Initializing current selection to 1st position
    int cur_pos=0;
    //clearing the selection mark
    for (int i=0;i<=24;i++)
    {
        p[i][0]=' ';
        p[i][1]=' ';
    }
    //putting selection mark in first
    p[cur_pos][0]=712;
    p[cur_pos][1]=700;

    //clearing screen and Displaying the
    cls();
    disp(s,p,ext,capt);
    printf("\nPress 'F' or 'f' to select");
    printf("\nTurn:%s",(player==0)?"Goat":"Tiger");
    printf("\nOldPos:%d",cur_pos+1);
    //Taking input
    while((ch=getch())!='c')
    {
        if ( (ch=='w') )
        {
            if ((cur_pos-5)>=0) cur_pos-=5;
        }
        else if ( (ch=='s'))
        {
            if ( (cur_pos+5)<=24) cur_pos+=5;
        }
        else if ( (ch=='a'))
        {
            if ( (cur_pos-1)>=0) cur_pos-=1;
        }
        else if ( (ch=='d'))
        {
            if ( (cur_pos+1)<=24)
            cur_pos+=1;
        }
        else
        {
            break;
        }
        //changing selection mark
        for (int i=0;i<=24;i++)
        {
        p[i][0]=' ';
        p[i][1]=' ';
        }

        p[cur_pos][0]=712;
        p[cur_pos][1]=700;
        //displaying updated field.
        cls();
        disp(s,p,ext,capt);
        printf("\nPress 'F' or 'f' to select");
        printf("\nTurn:%s",(player==0)?"Goat":"Tiger");
        printf("\nOldPos:%d",cur_pos+1);

    }
    oldPos=cur_pos+1;

    /**
        For second output*/
    //initializing selection mark
    cur_pos=oldPos-1;
    //clearing selection mark
    for (int i=0;i<=24;i++)
    {
        p[i][0]=' ';
        p[i][1]=' ';
    }
    //putting selection mark
    p[cur_pos][0]='|';
    p[cur_pos][1]='|';
    p[oldPos-1][0]='[';
    p[oldPos-1][1]=']';
    cls();
    disp(s,p,ext,capt);
    printf("\nPress 'F' or 'f' to select");
    printf("\nTurn:%s",(player=0)?"Goat":"Tiger");
    printf("\nOld Selection:%d",oldPos);
    printf("\nNew Selectin: %d",cur_pos+1);
    //taking input
    while((ch=getch())!='c')
    {
        if ( (ch=='w') )
        {
            if ((cur_pos-5)>=0) cur_pos-=5;
        }
        else if ( (ch=='s'))
        {
            if ( (cur_pos+5)<=24) cur_pos+=5;
        }
        else if ( (ch=='a'))
        {
            if ( (cur_pos-1)>=0) cur_pos-=1;
        }
        else if ( (ch=='d'))
        {
            if ( (cur_pos+1)<=24) cur_pos+=1;
        }
        else
        {
            break;
        }
        //updating selection mark
        for (int i=0;i<=24;i++)
        {
        p[i][0]=' ';
        p[i][1]=' ';
        }
        p[cur_pos][0]=712;
        p[cur_pos][1]=700;
        p[oldPos-1][0]=455;
        p[oldPos-1][1]=438;
        cls();
        disp(s,p,ext,capt);
        printf("\nPress 'F' or 'f' to select");
        printf("\nTurn:%s",(player=0)?"Goat":"Tiger");
        printf("\nOld Selection:%d",oldPos);
        printf("\nNew Selectin: %d",cur_pos+1);
    }
    newPos=cur_pos+1;
    *oldp=oldPos;
    *newp=newPos;
}

void getp(int * newp,char p[][2],char s[],int ext,int capt,char username[],char password[])
{
    char ch;
    int cur_pos;
    int newPos;
    /**
        For second output*/
    //initializing selection mark
    cur_pos=0;
    //clearing selection mark
    for (int i=0;i<=24;i++)
    {
        p[i][0]=' ';
        p[i][1]=' ';
    }
    //putting selection mark
        p[cur_pos][0]=712;
        p[cur_pos][1]=700;
    cls();
    disp(s,p,ext,capt);
    printf("\nPress 'F' or 'f' to select");
    printf("\nTurn: Goat");
    printf("\nNew Selectin: %d",cur_pos+1);
    //taking input
    while((ch=getch())!='f')
    {
        if ( (ch=='w') && (cur_pos-5)>=0)
        {
            cur_pos-=5;
        }
        else if ( (ch=='s') && (cur_pos+5)<=24)
        {
            cur_pos+=5;
        }
        else if ( (ch=='a') && (cur_pos-1)>=0)
        {
            cur_pos-=1;
        }
        else if ( (ch=='d') && (cur_pos+1)<=24)
        {
            cur_pos+=1;
        }
        else if ( ch=='o')
        {
            save(username,password,s,ext,capt);
        }
        else
        {
            if (ch!='a' || ch!='w' || ch!='s' || ch!='d') break;
        }
        //updating selection mark
        for (int i=0;i<=24;i++)
        {
        p[i][0]=' ';
        p[i][1]=' ';
        }
        p[cur_pos][0]=712;
        p[cur_pos][1]=700;

        cls();
        disp(s,p,ext,capt);
        printf("\nPress 'F' or 'f' to select");
        printf("\nNew Selectin: %d",cur_pos+1);
    }
    newPos=cur_pos+1;
    *newp=newPos;
}

void disp(char s[],char p[][2],int ext,int capt)
{
    printf("                             Bagchal                           \n");
    printf("                      Remaining Goats: %d                      \n",ext);
    printf("                      Captured Goats:  %d                      \n",capt);
    printf("        *****************************************************\n");
    printf("        *        %c%c%c-----%c%c%c-----%c%c%c-----%c%c%c-----%c%c%c        *\n",p[0][0],s[0],p[0][1], p[1][0],s[1],p[1][1], p[2][0],s[2],p[2][1], p[3][0],s[3],p[3][1] ,p[4][0],s[4],p[4][1]);
    printf("        *         | \\     |     / | \\     |     / |         *\n");
    printf("        *         |   \\   |   /   |   \\   |   /   |         *\n");
    printf("        *         |     \\ | /     |     \\ | /     |         *\n");
    printf("        *        %c%c%c-----%c%c%c-----%c%c%c-----%c%c%c-----%c%c%c        *\n",p[5][0],s[5],p[5][1], p[6][0],s[6],p[6][1], p[7][0],s[7],p[7][1], p[8][0],s[8],p[8][1] ,p[9][0],s[9],p[9][1]);
    printf("        *         |     / | \\     |      / | \\    |         *\n");
    printf("        *         |   /   |   \\   |    /   |   \\  |         *\n");
    printf("        *         | /     |     \\ |  /     |     \\|         *\n");
    printf("        *        %c%c%c-----%c%c%c-----%c%c%c-----%c%c%c-----%c%c%c        *\n",p[10][0],s[10],p[10][1], p[11][0],s[11],p[11][1], p[12][0],s[12],p[12][1], p[13][0],s[13],p[13][1] ,p[14][0],s[14],p[14][1]);
    printf("        *         | \\     |     / | \\     |     / |         *\n");
    printf("        *         |   \\   |   /   |   \\   |   /   |         *\n");
    printf("        *         |     \\ | /     |     \\ | /     |         *\n");
    printf("        *        %c%c%c-----%c%c%c-----%c%c%c-----%c%c%c-----%c%c%c        *\n",p[15][0],s[15],p[15][1], p[16][0],s[16],p[16][1], p[17][0],s[17],p[17][1], p[18][0],s[18],p[18][1] ,p[19][0],s[19],p[19][1]);
    printf("        *         |     / | \\     |     /  |\\     |         *\n");
    printf("        *         |   /   |   \\   |   /    |  \\   |         *\n");
    printf("        *         | /     |     \\ | /      |    \\ |         *\n");
    printf("        *        %c%c%c-----%c%c%c-----%c%c%c-----%c%c%c-----%c%c%c        *\n",p[20][0],s[20],p[20][1], p[21][0],s[21],p[21][1], p[22][0],s[22],p[22][1], p[23][0],s[23],p[23][1] ,p[24][0],s[24],p[24][1]);
    printf("        *****************************************************");
}
void menu(int chc[])
{
    printf("***************************************************************\n");
    printf("%c1. Start New Game.\n",chc[0]);
    printf("%c2. Load Old Game.\n",chc[1]);
    printf("%c3. Help\n",chc[2]);
    printf("%c4. About \n",chc[3]);
    printf("%c5. Game of Nine \n",chc[4]);
    printf("***************************************************************");

}
void login(char username[],char pwd[])
{
    char user[30];
    char ast[30];
    char pass[30];
    char temp[100];
    int i;
    for (int i=0;i<24;i++)
    {
        user[i]=' ';
        ast[i]=' ';
    }
    i=0;
    do
    {
        if (user[i-1]=='\b')
        {
            i=i-1;
            user[i]=' ';
        }
        cls();

        printf("                *****************************************************              \n\n");
        printf("                          ***************************\n");
        printf("                Username: *%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",user[0],user[1],user[2],user[3],user[4],user[5],user[6],user[7],user[8],user[9],user[10],user[11],user[12],user[13],user[14],user[15],user[16],user[17],user[18],user[19],user[20],user[21],user[22],user[23]);
    } while (((user[i++]=getch())!='\r') && i<=23);
    user[i-1]='\0';
    i=0;
    fflush(stdin);
    do
    {
        cls();
        if (user[i-1]=='\b')
        {
            i=i-1;
            user[i]=' ';
            ast[i]=' ';
        }
        ast[i+1]='\0';

        printf("                *****************************************************              \n\n");
        printf("                          ***************************\n");
        printf("                Username: *%-24s\n",user);
        printf("                Password: *%-24s\n",ast);
        ast[i]=1447;
        ast[i+1]='\0';
    }while ( ( (pass[i++]=getch())!='\r') && i<=23);
    pass[i-1]='\0';
    strcpy(username,user);
    strcpy(pwd,pass);
}
void save(char username[],char password[],char s[],int ext_goats,int capt_goats)
{
    FILE *fp;
    fp=fopen("rec.txt","w");
    for (int i=0;i<25;i++)
    {
        fprintf(fp,"%d ",s[i]);
    }
    fprintf(fp,"%d %d\n",ext_goats,capt_goats);
    fprintf(fp,"%s\n",username);
    fprintf(fp,"%s\n",password);
    fclose(fp);
}
void load(char username[],char password[],char s[],int *ext_goats,int* capt_goats)
{
    FILE *fp;
    int ext, capt;
    int num;
    fp=fopen("rec.txt","a+");
    //printf("name: %s and %s",username,password);
    for (int i=0;i<25;i++)
    {
        fscanf(fp,"%d",&num);
        s[i]=num;
    }
    fscanf(fp,"%d",&ext);
    fscanf(fp,"%d",&capt);
    //fscanf(fp,"%s,%s",username,password);
    *ext_goats=ext;
    *capt_goats=capt;
    //*ext_goats=ext;
    //*capt_goats=capt;*/
}
