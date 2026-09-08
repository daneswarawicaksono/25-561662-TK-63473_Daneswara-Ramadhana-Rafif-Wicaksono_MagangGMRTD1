#include <iostream>

using namespace std;

int min_value(int a, int b) {
    return (a < b) ? a : b;
}

int max_value(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    int n, C, R, K;
    cin >> n >> C >> R >> K;

    int* x = new int[n];

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    int* dp = new int[K + 1];
    int* charge_dp = new int[K + 1];
    int* next_dp = new int[K + 1];

    for (int i = 0; i <= K; i++) {
        dp[i] = -1;
        charge_dp[i] = -1;
        next_dp[i] = -1;
    }

    dp[0] = C;

    int complete = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            charge_dp[j] = dp[j];
        }

        for (int j = 1; j <= K; j++) {
            if (charge_dp[j - 1] != -1) {
                int charged = min_value(C, charge_dp[j - 1] + R);
                charge_dp[j] = max_value(charge_dp[j], charged);
            }
        }

        bool execute = false;
        for (int j = 0; j <= K; j++) {
            next_dp[j] = -1;
            if (charge_dp[j] >= x[i]) {
                next_dp[j] = charge_dp[j] - x[i];
                execute = true;
            }
        }

        if (execute) {
            for (int j = 0; j <= K; j++) {
                dp[j] = next_dp[j];
            }
            complete++;
        } else {
            break;
        }
    }

    cout << complete << "\n";

    // Hapus alokasi memori
    delete[] x;
    delete[] dp;
    delete[] charge_dp;
    delete[] next_dp;

    return 0;
}
