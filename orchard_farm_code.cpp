#include<bits/stdc++.h>
using namespace std;

int maxPercentage = 40;
int appleDays = 10;
int appleTreeIncome = 12000;
int orangeDays = 6;
int orangeTreeIncome = 10000;
int mangoDays = 15;
int mangoTreeIncome = 27500;
int lemonDays = 5;
int lemonTreeIncome = 7500;
int coconutDays = 15;
int coconutTreeIncome = 8000;

int main() {
    freopen("TOF_large.txt", "r", stdin);
    freopen("output_TOF_large.txt", "w", stdout);
    int t;
    cin >> t;
    int a = 1;
    while(t--) {
        int tree,days;
        cin >> tree >> days;
        int maxTree = (tree * maxPercentage) / 100;
        int income[5];
        int totalIncome = 0;
        income[0] = (days / appleDays) * appleTreeIncome;
        income[1] = (days / orangeDays) * orangeTreeIncome;
        income[2] = (days / mangoDays) * mangoTreeIncome;
        income[3] = (days / lemonDays) * lemonTreeIncome;
        income[4] = (days / coconutDays) * coconutTreeIncome;
        for(auto x : income) totalIncome += x;
        tree -= 5;
        sort(income, income + 5, greater<int>());
        int i = 0;
        while(tree > 0 && i < 5) {
            int temp = min(tree, maxTree - 1);
            totalIncome += (income[i] * temp);
            tree -= temp;
            i++;
        }
        cout << "Case #" << a << ": ";
        cout << totalIncome << "\n";
        a++;
    }
    return 0;
}
