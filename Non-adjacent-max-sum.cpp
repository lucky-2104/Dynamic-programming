#include <bits/stdc++.h>
using namespace std;


// Memoization 
int sums(vector<int>& nums, int i , vector<int>& dp)
{
    if(i == 0) return nums[0];
    if(i < 0) return 0;

    if(dp[i] != -1)
    return dp[i];

    int pick = nums[i] + sums(nums,i-2,dp);
    int notpick = 0+sums(nums,i-1,dp);

    return dp[i] = max(pick,notpick);
}

// Tabulation 


int maximumNonAdjacentSum(vector<int> &nums){
    
    vector<int> dp(nums.size()+1 , 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    int cost = 0;
    for(int i = 2 ; i < nums.size() ;i++)
    {
        int pick = dp[i-2] + nums[i];
        int notpick = dp[i-1]+0;
        dp[i] = dp[i] + max(pick,notpick);
    }
    return dp[nums.size()-1];

    // return sums(nums,nums.size()-1,dp); (For Memoization)

}