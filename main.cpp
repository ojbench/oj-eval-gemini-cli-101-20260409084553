#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // a: seconds per minute
    // b: minutes per hour
    // c: hours per day
    // d: current seconds
    // e: current minutes
    // f: current hours
    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;

    // Total number of seconds in a day
    long long total_seconds = a * b * c;
    
    // Current time in seconds from the start of the day
    long long current_time = f * a * b + e * a + d;

    long long min_s = -1;
    
    // The maximum possible value for the hands to coincide is bounded by the 
    // maximum valid value for seconds, minutes, and hours.
    long long max_k = min({a - 1, b - 1, c - 1});

    // Iterate over all possible times where hour == minute == second == k
    for (long long k = 0; k <= max_k; ++k) {
        // Target time in seconds from the start of the day
        long long target_time = k * a * b + k * a + k;
        
        // Calculate the number of seconds needed to reach the target time
        long long s = (target_time - current_time) % total_seconds;
        if (s < 0) {
            s += total_seconds;
        }
        
        // Update the minimum seconds required
        if (min_s == -1 || s < min_s) {
            min_s = s;
        }
    }

    cout << min_s << "\n";

    return 0;
}