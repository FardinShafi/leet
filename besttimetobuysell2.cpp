#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L = prices[0];
        int P = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < L) {
                L = prices[i];
                cout<<"resetting L: "<<L<<endl;
            }
            if (prices[i] > L) {
                cout<<"adding: "<<prices[i] - L<<endl;
                P = P + (prices[i] - L);
                L=prices[i];
            }
        }
        return P;
    }
}
;

int main(int argc, char const *argv[])
{
    vector<int> prices={7,1,5,4,3,6,4};
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}
