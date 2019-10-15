#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define min(a,b) (a<b? a : b)


void setdp(int r, int c, int **dp)
{
	printf("in Setdp\n");
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			dp[i][j]=-1;
}



//mask keeps track of which chities have been visited and which ones haven't
/*pos is from which citiy are we going to the next city, so that we can add appropriate cost, pos can have values from 1 to n, where n is no. of cities*/
int tsp(int mask, int pos, int VISITED_ALL,int n, int **w, int **dp) 
{
	if(mask==VISITED_ALL) //base cases
		return w[pos][0]; //distance of going back from the current city to the starting point. 

/*Else visit all other unvisited cities that have not been visited.*/
//iterate over all cities.

	if(dp[mask][pos]!=-1)
		return dp[mask][pos];

	int ans=INT_MAX;
	for(int city=0;city<n;city++)
	{
		/*check if new city is visited, by bitwise and of 1<<city and mask, if resultant is non zero, city has been visited, else it hasn't been visited. We're checking the ith bit in the mask whether it is set or not set*/
		if((mask&(1<<city))==0)
		{
			int newAns=w[pos][city]+tsp((mask|(1<<city)),city, VISITED_ALL,n, w, dp);
			/*recursive call, bitwise or of mask and (1<<city) will make the current city visited. city argument is the current city we're in. */
			ans=min(ans,newAns);
		}	
	}
	dp[mask][pos]=ans;
	return ans;
}

int main()
{
	FILE *fp;
	
	int n, **w, len=0, **dp;
	
	if((fp = fopen("input_tsp.txt", "r"))== NULL)
	{
		printf("File not found!\n");
		exit(1);
	}
	
	fscanf(fp,"%d", &n);
	//taking input for weight matrix
	w = (int **)malloc(n * sizeof(int *)); 
    for (int i=0; i<n; i++) 
         w[i] = (int *)malloc(n * sizeof(int)); 
	
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fscanf(fp, "%d", &w[i][j]);			
			
	int r=(int)pow(2,n);
	int c=n;
	int VISITED_ALL = (1<<n)-1;//sets all last n bits=1;
	
	
	//Allocate 2D array dp[r][c]
	dp = (int **)malloc(r * sizeof(int *)); 
    for (int i=0; i<r; i++) 
         dp[i] = (int *)malloc(c * sizeof(int)); 
	setdp(r,c,dp);
	printf("The optimal cost of the TSP tour is: %d\n", tsp(1,0,VISITED_ALL,n,w,dp)); //pos==0 as we're starting from the first city. mask==1 as we have visited the first city
	

	fclose(fp);
	return 0;

}
