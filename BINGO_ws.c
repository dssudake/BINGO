#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<time.h>

void start_game();
void play(char PL[5][20] , int no);
int random(int y[25]);
void player_ip(char PL[5][20] , int no , int P[5][25]);

//MAIN FUNCTION
int main()
{
    int ch,i;
    //GAME OPTIONS
    start:
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t1 . START GAME\n\t\t\t\t\t\t\t\t\t2 . END\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\tEnter choice : ");
    scanf(" %d",&ch);
    system("cls");  //cls's screen
    switch(ch)
    {
      case 1 :  //START GAME
                start_game();
                break;

      case 2 :  //END GAME
                printf("\n\n\n\n\n\n\n\n\n\n\n");
                printf("\t\t\t\t\t\t\t\t\t\tEnding");
                for(i=0 ; i<=5 ; i++)
                {
                    sleep(1);
                    printf(".");
                }
                system("cls");
                exit(1);

      default :
                printf("\n\n\n\n\n\n\n\n\n\n\n");
                printf("\n\t\t\t\t\t\t\t\t\tEnter correct choice.");
                sleep(3);
                system("cls");
                goto start;  //Again take input goto star
                break;
    }
}


//CASE 1 : START GAME
void start_game()
{
    int i,f,no;
    char PL[5][20];

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tLoading");
    for(i=0 ; i<=6 ; i++)
    {
      sleep(1);
      printf(".");
    }
  	system("cls");

    printf("\n\n\n\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\tNo of player(<5) : ");
    scanf("%d",&no);
    system("cls");

    //Input players name
    printf("\n\n\n\n\n\n\n\n");
    for(i=0 ; i<no ; i++)
    {
      printf("\n\t\t\t\t\t\t\t\t\tPlayer %d : ",i+1);
      scanf(" %[^\t\n]s",PL[i]);
    }
    system("cls");

    //Dispaly palyers name
    printf("\n\n\n\n\n\n\n");
    for(i=0 ; i<no ; i++)
    {
      printf("\n\n\t\t\t\t\t\t\t\t\tPlayer %d : %s",i+1,PL[i]);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to start. ");
    scanf(" %d",&f);
    system("cls");

    //Game starting timer
    for(i=5 ; i>=0 ; i--)
    {
      printf("\n\n\n\n\n\n\n\n\n\n\n");
      printf("\n\n\t\t\t\t\t\t\t\t\tGame starts in %d sec ", i);
      sleep(1);
      system("cls");
    }

    play(PL,no);
}


void play(char PL[5][20] , int no)
{
    int i,j,k,temp;
    int P[5][25]={
                  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25},
                  {2,3,4,5,6,11,12,7,8,9,10,1,13,14,15,21,22,23,24,25,16,17,18,19,20},
                  {11,21,1,3,23,13,2,22,12,10,20,25,5,15,7,17,9,19,4,24,14,6,16,8,18},
                  {1,25,2,24,3,23,4,22,5,21,6,20,19,18,7,9,8,10,15,12,17,16,11,13,14},
                  {2,3,4,5,6,11,12,7,8,9,10,1,13,14,15,21,22,23,24,25,16,17,18,19,20},
                 };

   for(i=0 ; i<no ; i++)
   {
	     printf("\n\n\n\n\n\n\n\n");
       printf("\n\t\t\t\t\t\t\t\t\t\tPlayer %d : ",i+1);
	     puts(PL[i]);
       srand(time(NULL));
       for(k=0;k<25;k++)
       {
         j= (rand() % 25) ;
         temp=P[i][k];
         P[i][k]=P[i][j];
         P[i][j]=temp;
       }
   }
   system("cls");
   player_ip(PL , no , P);
}


//Function to take player input
void player_ip(char PL[5][20] , int no , int P[5][25])
{
    int i,j,k,m,l;
    int x,y;
    int con[5]={0,0,0,0,0};
    int f[5][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0}
                };

    for(m=0 ; m<25 ; m++)
    {
      for(i=0 ; i<no ;i++)
      {
      //ROW CHECK
      if(P[i][0]==0 && P[i][1]==0 && P[i][2]==0 && P[i][3]==0 && P[i][4]==0 && f[i][0]==0 )
      {
       con[i]++;
       f[i][0]++;
      }
      if(P[i][5]==0 && P[i][6]==0 && P[i][7]==0 && P[i][8]==0 && P[i][9]==0 && f[i][1]==0)
      {
        con[i]++;
       f[i][1]++;
      }
      if(P[i][10]==0 && P[i][11]==0 && P[i][12]==0 && P[i][13]==0 && P[i][14]==0 && f[i][2]==0)
      {
        con[i]++;
        f[i][2]++;
      }
      if(P[i][15]==0 && P[i][16]==0 && P[i][17]==0 && P[i][18]==0 && P[i][19]==0 && f[i][3]==0)
      {
        con[i]++;
        f[i][3]++;
      }
      if(P[i][20]==0 &&P[i][22]==0 &&P[i][23]==0 &&P[i][24]==0 && P[i][21]==0 && f[i][4]==0)
      {
        con[i]++;
        f[i][4]++;
      }

      //COLOUMN CHECK
      if(P[i][0]==0 &&P[i][5]==0 &&P[i][10]==0 &&P[i][15]==0 &&P[i][20]==0 && f[i][5]==0 )
      {
       con[i]++;
       f[i][5]++;
      }
      if(P[i][1]==0 &&P[i][6]==0 &&P[i][11]==0 &&P[i][16]==0 &&P[i][21]==0 && f[i][6]==0)
      {
        con[i]++;
        f[i][6]++;
      }
      if(P[i][2]==0 &&P[i][7]==0 &&P[i][12]==0 &&P[i][17]==0 &&P[i][22]==0&& f[i][7]==0 )
      {
        con[i]++;
        f[i][7]++;
      }
      if(P[i][3]==0 &&P[i][8]==0 &&P[i][13]==0 &&P[i][18]==0 && P[i][23]==0 && f[i][8]==0)
      {
        con[i]++;
        f[i][8]++;
      }
      if(P[i][4]==0 &&P[i][9]==0 &&P[i][14]==0 &&P[i][24]==0 &&P[i][19]==0 && f[i][9]==0)
      {
        con[i]++;
        f[i][9]++;
      }

      //DIAGONAL CHECK
      if(P[i][0]==0 &&P[i][6]==0 &&P[i][12]==0 &&P[i][18]==0 &&P[i][24]==0 && f[i][10]==0)
      {
        con[i]++;
        f[i][10]++;
      }
      if(P[i][4]==0 &&P[i][8]==0 &&P[i][12]==0 &&P[i][16]==0 &&P[i][20]==0 && f[i][11]==0)
      {
        con[i]++;
        f[i][11]++;
      }

      //WINNER CHECK
      if(con[i]==5)
      {
        for(k=0;k<=7;k++)
        {
          printf("\n\n\n\n\n\n\n\n\n\n\n");
          printf("\n\t\t\t\t\t\t\t\t *  *   *    * * * *  * *   * *  * *\n");
          printf("\n\t\t\t\t\t\t\t\t              B  I  N  G  O          ");
          printf("\n\t\t\t\t\t\t\t\t    !!! PLAYER %d i.e %s WON !!!",i+1,PL[i]);
          printf("\n\t\t\t\t\t\t\t\t * *   *   *  *  * *  *  * *  *  * *\n");
          sleep(1);
          system("cls");
          sleep(1);
        }
        printf("\n\n\t\t\t\t\t\t\t\t\tPress any key to end. ");
        scanf(" %d",&l);
        exit(1);
        system("cls");
      }

      //PLAYER INPUT
      printf("\n\n\n\n\n\n\n\n");
      printf("\n\t\t\t\t\t\t\t\t\tPlayer %d : ",i+1);
      puts(PL[i]);
      printf("\n\t\t\t\t\t\t\t\tB\tI\tN\tG\tO  :  %d\n",con[i]);
      printf("\n\t\t\t\t\t\t\t\t");
      for(k=0;k<25;k++)
      {
          printf("%d\t",P[i][k]);
          if(k%5==4)
          printf("\n\n\t\t\t\t\t\t\t\t");
      }
      printf("\n\n\t\t\t\t\t\t\t\tEnter no (P%d : %s) : ",i+1,PL[i]);
      scanf(" %d",&x);
      for(k=0 ; k<no ; k++ )
      {
        for(j=0;j<25;j++)
        {
          if(P[k][j]==x)
          {
            P[k][j]=0;
          }
        }
      }
      system("cls");
    }
  }
}