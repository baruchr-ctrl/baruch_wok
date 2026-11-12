#include <bits/stdc++.h>
using namespace std;

bool canAchieveMedian(const vector<long long>& a, long long k, long long target) {
    int n = a.size();
    long long ops = 0;
    for (int i = n / 2; i < n; ++i) {
        if (a[i] < target) {
            ops += target - a[i];
            if (ops > k) return false;
        }
    }
    return true;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    long long low = a[n / 2], high = a[n / 2] + k, ans = low;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canAchieveMedian(a, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
