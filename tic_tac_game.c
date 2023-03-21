#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool updatingBoard(char* newRow, unsigned input, char lInput);

int main(void){
  printf("Tic Tac Toe Game\n\n");

//defining the scoring rows
  char row1[3] = {'1','2','3',};
  char row2[3] = {'4','5','6',};
  char row3[3] = {'7','8','9',};

  bool state = true;
  bool turn = true;
  unsigned counter = 0;

  while (state){
   
//printing the board
   printf(" %c | %c | %c  \n",row1[0],row1[1],row1[2]);
   printf("-----------\n");
   printf(" %c | %c | %c  \n",row2[0],row2[1],row2[2]);
   puts("-----------");
   printf(" %c | %c | %c  \n\n",row3[0],row3[1],row3[2]);

//determining player turn
   char player = {0};
   if (turn){
    player = 'X';
    turn = false;
   }
   else{
    player = 'O';
    turn = true;
   }
   bool validInput = true;
   unsigned i = 0;

//checking if the input is valid
  while (validInput){
   printf("Player %c please select a position on the board\n\n",player);
   scanf("%u",&i);
   printf(" \n");

//updating the board
   if (i > 0 && i < 4){
    i = i - 1;
    validInput = updatingBoard(row1,i,player);
   } else if (i > 3 && i < 7){
      i = i -4;
      validInput = updatingBoard(row2,i,player);
   } else if (i > 6 && i < 10){
      i = i - 7;
      validInput = updatingBoard(row3,i,player);
   } else
      printf("invalid\n");
}
//incrementing the counter variable that triggers checking if the game is won
   counter += 1;
   if (counter > 4){
//checking if the game is won with horizontal pattern
    if (row1[0] == row1[1] && row1[1] == row1[2] && state)
     state = false;
    else if (row2[0] == row2[1] && row2[1] == row2[2] && state)
     state = false;
    else if (row3[0] == row3[1] && row3[1] == row3[2] && state)
     state = false;

//checking for vertical winning pattern
    if (state){
     for (size_t i = 0;i < 3;++i)
      if (row1[i] == row2[i] && row2[i] == row3[i]){
       state = false;
       i = 3;
      }
    }
//checking for diagonal winning pattern
    if (state){
     if (row1[0] == row2[1] && row2[1] == row3[2])
      state = false;
     else if (row1[2] == row2[1] && row2[1] == row3[0])
      state = false;
    }
  
   }

//printing the winning message and board
   if (!state){
    printf("Player %c wins the game!!!!\n\n",player);
    printf(" %c | %c | %c  \n",row1[0],row1[1],row1[2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n",row2[0],row2[1],row2[2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n\n",row3[0],row3[1],row3[2]);
   }

 //chekcing if the game is a draw
   if (counter == 9 && state){
    printf("The game is a draw\n\n");
    printf(" %c | %c | %c  \n",row1[0],row1[1],row1[2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n",row2[0],row2[1],row2[2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n\n",row3[0],row3[1],row3[2]);
    state = false;
   }   
  }

  return EXIT_SUCCESS;
}

bool updatingBoard(char* newRow, unsigned input, char lInput){
  bool state = true;

  if (newRow[input] == 'X' || newRow[input] == 'O'){
      puts("Invalid");
      return state;
  } else{
      newRow[input] = lInput;
      state = false;
      return state;   
  }
}    

