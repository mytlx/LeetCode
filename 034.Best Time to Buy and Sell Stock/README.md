# [Best Time to Buy and Sell Stock][1]
> Say you have an array for which the i th element is the price of a given stock on day i.  
> 
> If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.  
> 
> **Example 1:**
> ``` 
> Input: [7, 1, 5, 3, 6, 4]
> Output: 5
>	
> max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
> ```
> **Example 2:**
> ```cpp 
> Input: [7, 6, 4, 3, 1]
> Output: 0
>
> In this case, no transaction is done, i.e. max profit = 0.
> ```

数组中第i个元素代表第i天股票价格，只能买入一股，卖出一股，求最大利润。  
循环遍历一遍数组，遇到比最小价格小的就设置成最小价格，同时计算利润，如果利润比最大利润大就保存到最大利润中。
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(minPrice > prices[i])            
                minPrice = prices[i];
            else if(prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;            
        }
        return maxProfit;
    }
};
```
[1]:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
