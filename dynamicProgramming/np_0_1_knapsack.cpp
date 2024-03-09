#include <bits/stdc++.h>
using namespace std;

int dp[105][100001];
bool visited[1001];

int answer(int weights[], int values[], int i, int bag_weight)
{

    if (i < 0)
    {
        return 0;
    }

    int op1 = INT_MIN, op2 = INT_MIN;
    if (dp[i][bag_weight] != -1)
    {

        return dp[i][bag_weight];
    }
    if (bag_weight >= weights[i])
    {
        op1 = answer(weights, values, i - 1, bag_weight - weights[i]) + values[i];
    }
    op2 = answer(weights, values, i - 1, bag_weight) + 0;
    if (op1 > op2)
    {
        visited[i] = true;
    }
    else
    {
        visited[i] = false;
    }
    return dp[i][bag_weight] = max(op1, op2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 1001; i++)
    {
        visited[i] = false;
    }

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    int bag_weight;
    cin >> bag_weight;
    int weights[n];
    int values[n];
    int Vmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
        if (Vmax < values[i])
        {
            Vmax = values[i];
        }
    }
    int main_ans;
    main_ans = answer(weights, values, n - 1, bag_weight);
    int max_weight = 0;
    cout << "Original Instances : " << endl;
    cout << "Answer : " << main_ans << endl;

    cout << "Indices : ";
    int used_weights = 0;
    int remaining_weight = bag_weight;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (dp[0][remaining_weight] != 0)
            {
                cout << i + 1 << " "; // Print the index of the item included in the knapsack
                remaining_weight -= weights[i];
                used_weights += weights[i];
            }
        }
        else
        {
            if (dp[i][remaining_weight] != dp[i - 1][remaining_weight])
            {
                cout << i + 1 << " "; // Print the index of the item included in the knapsack
                remaining_weight -= weights[i];
                used_weights += weights[i];
            }
        }
    }
    cout << endl;
    cout << "Used Weight : " << used_weights << endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    double Eps[] = {0.5, 0.2, 0.1, 0.05};
    for (int i = 0; i < 4; i++)
    {

        double theta = (((double)Vmax) * Eps[i]) / (2 * ((double)(n)));

        cout << "Rounded Instance With : " << Eps[i] << endl;
        cout << "Theta : " << theta << endl;
        int reduced_values[n];
        int Vmax2 = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            reduced_values[j] = ceil((long double)values[j] / theta);
            if (reduced_values[j] > Vmax2)
            {
                Vmax2 = reduced_values[j];
            }
        }

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < 105; i++)
        {
            dp[i][0] = 0;
        }

        long long result = answer(weights, reduced_values, n-1, bag_weight);
        cout << "Answer of reduced instance :" << i + 1<< endl;
        cout << "Answer of reduced instance multiplied by theta: " << ((double)result * (double)theta) << endl;
        cout << "Indices :";
        int remaining_weight2 =  bag_weight,used_weights2 = 0;
        int new_values = 0;
        for (int k = n - 1; k >= 0; k--)
        {
            if (k == 0)
            {
                if (dp[0][remaining_weight2] != 0)
                {
                    cout << k + 1 << " "; // Print the index of the item included in the knapsack
                    remaining_weight2 -= weights[k];
                    used_weights2 += weights[k];
                    new_values+=reduced_values[k];
                }
            }
            else
            {
                if (dp[k][remaining_weight2] != dp[k - 1][remaining_weight2])
                {
                    cout << k + 1 << " "; // Print the index of the item included in the knapsack
                    remaining_weight2 -= weights[k];
                    used_weights2 += weights[k];
                    new_values+=reduced_values[k];
                }
            }
        }
        cout<<endl;
        cout << "Used weight :" << result << endl;
        //cout<<main_ans<<" "<<new_values<<endl;
        cout << "Ratio: " << fixed << setprecision(10) << ((double)main_ans / ((double)new_values * theta)) << endl;
        cout << endl;
        cout << endl;
    }

    return 0;
}