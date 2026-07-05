#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> memo(amount + 1, -2);
        return solve(coins, amount, memo);
    }
private:
    int solve(vector<int>& coins, int rem, vector<int>& memo) {
        if (rem < 0) return -1; 
        if (rem == 0) return 0;  
        if (memo[rem] != -2) return memo[rem]; 
        
        int min_count = INT_MAX;
        
        for (int coin : coins) {
            int res = solve(coins, rem - coin, memo);
            if (res >= 0 && res < min_count) {
                min_count = 1 + res;
            }
        }
        
        memo[rem] = (min_count == INT_MAX) ? -1 : min_count;
        return memo[rem];
    }
};

int main() {
    int num_coins;
    cout << "Ingrese el numero de denominaciones de monedas: ";
    cin >> num_coins;

    vector<int> coins(num_coins);
    cout << "Ingrese las denominaciones de las monedas: ";
    for (int i = 0; i < num_coins; ++i) {
        cin >> coins[i];
    }

    int amount;
    cout << "Ingrese el monto: ";
    cin >> amount;

    cout << "\nInput: coins = [";
    for (size_t i = 0; i < coins.size(); ++i) {
        cout << coins[i] << (i == coins.size() - 1 ? "" : ",");
    }
    cout << "], amount = " << amount << endl;

    Solution sol;
    int result = sol.coinChange(coins, amount);
    cout << "Output: " << result << endl;

    return 0;
}