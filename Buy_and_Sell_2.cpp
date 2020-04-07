/**
Best Time to Buy and Sell Stock II
Solution
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int profit = 0;
		int buy = 0;
		int sell = 0;
		int n = prices.size();
		
		if (n < 2) {
			return 0;
		}
		int i = 0;
		buy = prices[0];
		sell = prices[1];
		
		for (i =1;i < n-1;i++)
		{
			if (buy > sell) {
				buy = prices[i]; 
				sell = prices[i+1];
				continue;
			}
			
			if (sell <= prices[i]){
				sell = prices[i];
			}else if(sell >= prices[i]){
				profit += (sell - buy);
				buy = prices[i];
				sell = prices[i+1];
			}

		}
		
		if (sell < prices[i]){
			sell = prices[i];
		}
		
		if (i == n-1 && buy < sell){
			profit += (sell - buy);
		}
        return profit;
    }
};

int main()
{
	vector<int> v{7,1,5,3,6,4};
	vector<int> v1{1,2,3,4,5};
	vector<int> v2{7,6,4,3,1};
	vector<int> v3{1,2};
	vector<int> v4{2,1,4};
	vector<int> v5{2,2,5};
	vector<int> v6{2,1,2,0,1};
	vector<int> v7{2,1,2,1,0,1,2};
	
	Solution s;
	cout<<"Solution "<< s.maxProfit(v)<<endl;
	cout<<"Solution "<< s.maxProfit(v1)<<endl;
	cout<<"Solution "<< s.maxProfit(v2)<<endl;
	cout<<"Solution "<< s.maxProfit(v3)<<endl;
	cout<<"Solution "<< s.maxProfit(v4)<<endl;
	cout<<"Solution "<< s.maxProfit(v5)<<endl;
	cout<<"Solution "<< s.maxProfit(v6)<<endl;
	cout<<"Solution "<< s.maxProfit(v7)<<endl;
	
	return 0;
}
