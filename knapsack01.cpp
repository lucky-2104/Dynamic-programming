#include <bits/stdc++.h> 

//MEMOIZATION

// int f(int ind , int bag ,vector<int> weight , vector<int> value , vector<vector<int>> & dp)
// {
// 	if(ind == 0)
// 	{
// 		if(weight[0] < bag)
// 		return value[0];
// 		else
// 		return 0;
// 	}
// 	if(dp[ind][bag] != -1)
// 	return dp[ind][bag];

// 	int notpick = 0+f(ind -1 , bag , weight , value ,dp);
// 	int pick = -1e9;
// 	if(weight[ind] < bag)
// 	{
// 		pick = value[ind] + f(ind -1 , bag - weight[ind],weight , value , dp);
// 	}
// 	return dp[ind][bag] = max(pick,notpick);
// }
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>> dp(n , vector<int>(maxWeight+1 , -1));

	vector<vector<int>> dp(n , vector<int>(maxWeight+1 ,0));

	for(int W = weight[0] ; W <= maxWeight ; W++)
	{
		dp[0][W] = value[0];
	}


	for(int i = 1 ; i < n ; i++)
	{
		for(int W = 0 ; W <= maxWeight ; W++ )
		{
			int notpick = 0+dp[i-1][W];
			int pick = INT_MIN;
			if(weight[i] <= W)
			pick = value[i]+dp[i-1][W-weight[i]];

			dp[i][W] = max(notpick ,pick);
		}
	}
	return dp[n-1][maxWeight];

	// return f(n , maxWeight , weight , value , dp);  FOR MEMOIZATION
}