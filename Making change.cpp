#include <stdio.h>
 
int coins[] = {1,2,3};
int numberOFCoins = 3, sum = 4;
 
int solve(int s, int i){
    if(numberOFCoins == 0 || s > sum || i>=numberOFCoins)
        return 0;
    else if(s == sum)
        return 1;
   
    return solve(s+coins[i],i) + solve(s,i+1) ;
}
 
int main()
{
    printf("Total solutions: %d",solve(0,0));
    return 0;
}

