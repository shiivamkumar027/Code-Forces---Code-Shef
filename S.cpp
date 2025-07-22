// Author : Shivam
#include <iostream>
using namespace std;

long long count_good(long long N) {
    if (N == 0) return 0;

    int primes[] = {2, 3, 5, 7};
    int num_primes = 4;
    long long bad = 0;

    for (int i = 1; i < (1 << num_primes); ++i) {
        long long prod = 1;
        int bits = 0;

        for (int j = 0; j < num_primes; ++j) {
            if ((i >> j) & 1) {
                prod *= primes[j];
                bits++;
            }
        }

        if (bits % 2 == 1) bad += N / prod;
        else bad -= N / prod;
    }

    return N - bad;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << count_good(r) - count_good(l - 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
