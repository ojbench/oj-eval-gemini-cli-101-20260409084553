#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;

    long long total_seconds = a * b * c;
    long long current_time = f * a * b + e * a + d;

    long long min_s = -1;
    long long max_k = min({a - 1, b - 1, c - 1});

    for (long long k = 0; k <= max_k; ++k) {
        long long target_time = k * a * b + k * a + k;
        long long s = (target_time - current_time) % total_seconds;
        if (s < 0) {
            s += total_seconds;
        }
        if (min_s == -1 || s < min_s) {
            min_s = s;
        }
    }

    cout << min_s << endl;

    return 0;
}
