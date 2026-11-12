#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<long long> P(n + 1, 0);
    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + x[i];
    }
    multiset<long long> valid_prefix_sums;
    long long max_sum = P[a] - P[0];
    for (int i = a; i <= n; i++) {
        valid_prefix_sums.insert(P[i - a]);
        if (i - b - 1 >= 0) {
            valid_prefix_sums.erase(valid_prefix_sums.find(P[i - b - 1]));
        }
        long long min_start_prefix = *valid_prefix_sums.begin();
        long long current_max_sum = P[i] - min_start_prefix;
        max_sum = max(max_sum, current_max_sum);
    }
    cout << max_sum << endl;
    return 0;
}
