//code for linear search in array in c
//time complexity: O(n)
//space complexity: O(1)

#include <stdio.h>
int main()
{
  int array[100], search, j, n;
  printf("Enter number of elements in array\n");
  scanf("%d", &n);
  
  printf("Enter %d integers \n", n);
  for (j = 0; j < n; j++)
    scanf("%d", &array[j]);
    
  printf("Enter a number to search\n");
  scanf("%d", &search);
  
  for (j = 0; j < n; j++)
  {
    if (array[j] == search)    
    {
      printf("%d is present at location %d.\n", search, j+1);
      break;
    }
  }
  
  if (j == n)
    printf("%d isn't present in the array.\n", search);
  return 0;
}
