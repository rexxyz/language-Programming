#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>


#define NROFTHROWS 10

int main(){
  int diceValue = 0;
  int nrOfThrows = 0;

  srand(time(NULL)); 

  printf("DiceStats 1.0\n\n\n");

  printf("Dice value: ");
    scanf(" %d", &diceValue);
  printf("Number of throws: ");
    scanf(" %d", &nrOfThrows);


  int dice = 0;
  int result[diceValue];
  float percentage[diceValue];

  for(int i = 0; i < diceValue; i++){
    result[i] = 0;
    percentage[i] = 0;
  }

  for(int i = 0; i < nrOfThrows; i++){
    dice = ((rand()%diceValue+1));
    result[dice - 1] = result[dice - 1] + 1;
  }

  for(int i = 0; i < diceValue; i++){
    percentage[i] = ((float)(result[i]/(float)nrOfThrows)*100);
  }

  printf("\nResults: \n\n  Value\t\tdiceCount\tdicePercentage\n\n");

  for(int i = 0; i < diceValue; i++){
    printf("  %d:\t\t%d\t\t%0.3f\n", i+1, result[i], percentage[i]);
  }

   return 0;
}
