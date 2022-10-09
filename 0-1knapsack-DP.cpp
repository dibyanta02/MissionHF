//Given an array of items with their {weight, value, and a knapsack with weight W}. Find the maximum value of items that can be stolen and put into knapsack.
//Note: We either have to pick full item (i) or no item (0)

//Idea
//We iterate from left to right in items array. For each item we have 2 choices
//(i) Take it = remaining capacity of Knapsack
//(ii) Not take it = Capacity remains same

//Let, f(n, w) = denotes the maximum value of items we can pick till item n and current capacity of knapsack w.
//Therefore, f(n, w) = max(f(n=1, w), f(n-1, w-weight[n]+value[n]))

//Since we can represent it as a recurrance relation

//It follows optimal substructure property

//Optimal Solutions (using Dynamic Programming)

//Approach 1 (Memoization)
//1. Write the recursive solution
//2. Memoize it

//Approach 2 (Tabulation)
//1. For every items, compute the answer for every weight from 0-W
//2. Use the recurrence of taking and not taking.
//      dp[n][w] = max (dp[n-1][w], dp[n-1][w-wt[n]] + val[n])
//T.C. = O(n * w)

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

//Below soln is working but wont work for larger values

// const int N = 1e5+2, MOD = 1e9+7;
// int val[N], wt[N];

// int knapSack(int n, int w) {
//     if (w <= 0)
//         return 0;
    
//     if (n <= 0)
//         return 0;
    
//     if (wt[n-1] > w)
//         return knapSack(n-1, w);
    
//     return max(knapSack(n-1, w), knapSack(n-1, w-wt[n-1]) + val[n-1]);
// }

// int main(){
//     int n;
//     cin >> n;
//     loop (i, 0, n) 
//         cin >> wt[i];
//     loop (i, 0, n)
//         cin >> val[i];
    
//     int w;
//     cin >> w;

//     cout << knapSack(n ,w) << endl;
//     return 0;
// }

//Tabulation Used

const int N = 1e3+2, MOD = 1e9+7;
int val[N], wt[N];

int dp[N][N];

int knapSack(int n, int w) {
    if (w <= 0)
        return 0;
    
    if (n <= 0)
        return 0;

    if (dp[n][w] != -1) 
        return dp[n][w];
    
    if (wt[n-1] > w)
        dp[n][w] = knapSack(n-1, w);
    else
        dp[n][w] = max(knapSack(n-1, w), knapSack(n-1, w-wt[n-1]) + val[n-1]);
    
    return dp[n][w];
}

int main(){

    loop (i, 0, N) {
        loop (j, 0, N)
            dp[i][j] = -1;
    }

    int n;
    cin >> n;
    loop (i, 0, n) 
        cin >> wt[i];
    loop (i, 0, n)
        cin >> val[i];
    
    int w;
    cin >> w;

    cout << knapSack(n ,w) << endl;
    return 0;
}
