#include <iostream>
using namespace std;

int knapsack (int profits[], int weights[], int pw[], int m, int n)
{
    float x[] = {0, 0, 0, 0}, max_profit = 0, prod;
    for (int i=0; i<n; i++) {
        if (weights[i] <= m) 
        {
            x[i] = 1.0;
            m = m - weights[i];
        }
        else 
        {
            x[i] = (float)m/weights[i];
            m = 0;
        }
    }

    for(int i=0; i<n; i++) {
        prod = (float)x[i]*profits[i];
        max_profit += prod;
    }        

    return max_profit;
}

int main()
{
    int profits[] = {100, 60, 120},
        weights[] = {20, 10, 30},
        pw[] = {5, 6, 4},
        m = 50, n =3; 
    int i, j, temp1, temp2, temp3;
    
    //sorting
        for (i=0; i<n-1; i++) {
            for (j=0; j<n-1-i; j++) {
                if (pw[j] < pw[j+1]) {
                    temp1 = pw[j];
                    temp2 = profits[j];
                    temp3 = weights[j];

                    pw[j] = pw[j+1];
                    profits[j] = profits[j+1];
                    weights[j] = weights[j+1];

                    pw[j+1] = temp1;
                    profits[j+1] = temp2;
                    weights[j+1] = temp3;
                }
            }
        }

    int result = knapsack(profits, weights, pw, m, n);
    cout<<"The maximum profit obtained is "<<result;
    return 0;
}

// class input
//     int profits[] = {40, 42, 25, 12},
//         weights[] = {4, 7, 5, 3},
//         pw[] = {10, 6, 5, 4},
//         m = 10, n =4; 