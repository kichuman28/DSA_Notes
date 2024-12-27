class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};


//Step 1: I know price of the stock for the next n days. I need to find the day where the price of the stock is min.
//Step 2: Next from that day onwards, I check when the price of the stock has reached the max price. I find it.
//Step 3: Now I have the highest and lowest price, I subtract it and return the answer.4

//Step 1: I need to find the min price for each day and from there onwards I check the highest price. 
//Step 2: After that I store it in the maxProfit variable. 
//Step 3: If I find a minPrice later on then I use that and then try to do the same thing and find a bigger profit than 
//maxProfit.

//Based on the fact that we have to sell after we buy and we are trying to maximize profit, we can iterate through the prices and only need to consider two things:
// 1.) Is this price cheaper than any other price I've seen before?
// 2.) If I subtract current price by the cheapest price I've found, does this yield a greater profit than what I've seen so far?

// A fun thing to note is if #1 is true, then #2 cannot be true as well so there isn't a need to check

// Let's consider an example of [4,1,5,2,7]

// 4 is the cheapest price we see to start, and we can't sell on the first day so maxProfit is 0
// 1 is now the cheapest price we've seen. Selling now would lose us money, so we can't update maxProfit
// 5 is not cheaper than 1, but if we sell now we get a maxProfit of 4! Better save that for later
// 2 is not cheaper than 1 and if we sell, we only get a profit of 1, no need to do anything here
// 7 is not cheaper than 1, but if we sell here, we'll increase maxProfit to 6, making this the best profit to return.
// Hope this helps someone else!

//TL:DR: I try to buy and sell everyday, while keeping track of the minPrice. a