#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int generate_randomnumber(int n)
{
   srand(time(NULL));
   return rand() % n;
}


int greater(char c1, char c2)
{
  if ((c1=='r'&&c2=='p'))
  {
     return -1;
  }


  else if ((c1=='r'&&c2=='s'))
  {
     return 1;
  }


  else if ((c1=='r'&&c2=='r'))
  {
     return 0;
  }
  
  else if ((c1=='p'&&c2=='r'))
  {
     return 1;
  }

  else if ((c1=='p'&&c2=='s'))
  {
     return -1;
  }
  
  else if ((c1=='p'&&c2=='p'))
  {
     return 0;
  }

  else if ((c1=='s'&&c2=='r'))
  {
     return -1;
  }

  else if ((c1=='s'&&c2=='p'))
  {
     return 1;
  }

  else
  {
     return 0;
  }
   
}


int main()
{
   char str[50],choice;
   int playerscore=0, compscore=0;
   char playerchoice, compchoice;
   int temp;
   char options[] = {'r', 'p', 's'};

  start: printf("WELCOME TO  ROCK , PAPER & SCISSORS\n");
   printf("Player 1 enter your name\n");
   gets(str);
   printf("%s here are the rules\n", str);
   printf("1.This game consists of 3 rounds\n\n2.You have to enter 1 for Rock , 2 for Paper , 3 for Scissors.\n\n3.You will compete against the computer.\n\n4.The player with the maximum no of points after the 3 rounds will be the winner (OF COURSE !!)");
   for (int i = 0; i < 3; i++)
   {
      //Take player 1's choice
      printf("\n\nROUND %d : %s,it's your turn\n", i + 1,str);
      printf("Enter 1 for Rock , 2 for Paper , 3 for Scissors\n");
      scanf("%d", &temp);
      getchar();
      printf("You chose %d",temp);
      playerchoice = options[temp - 1];

      //Take computer's choice
      printf("\n\nROUND %d : Computer it's your turn\n", i + 1);
      printf("Enter 1 for Rock , 2 for Paper , 3 for Scissors\n");
      temp = generate_randomnumber(3) + 1;
      compchoice = options[temp - 1];
      printf("Computer entered %d\n\n",temp);

      //Comparing the scores
      if (greater(compchoice, playerchoice) == 1)
      {
         compscore += 1;
      }

      else if (greater(compchoice, playerchoice) == 0)
      {
         compscore += 0;
         playerscore += 0;
      }

      else
      {
         playerscore += 1;
      }
   
   printf("SCORE AFTER ROUND %d\n\n",i+1);
   printf("%s : %d point(s)\t",str,playerscore);
   printf("Computer : %d point(s)",compscore);
   }

   if(compscore>playerscore)
   {
      printf("\n\nWINNER:COMPUTER . CONGRATULATIONS.\n\n");
   }

   else
   if(playerscore>compscore)
   {
      printf("\n\nWINNER:%s . CONGRATULATIONS.\n\n",str);
   }

   else
   {
      printf("\n\nMATCH TIED\n\n");
   }
   
  question: printf("Press 1 to play again,2 to exit\n");
   scanf("%c",&choice);
   getchar();
   

   if(choice=='1')
   {
      goto start;
   }

   else if(choice=='2')
   {
      exit(0);
   }

   else
   {
      printf("INVALID CHOICE\n\n");
      goto question;
   }
   
   
   
   return 0;
}
