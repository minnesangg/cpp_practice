#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void findClosestFraction(double x) {
    double sqrt_x = sqrt(x);  
    double min_diff = numeric_limits<double>::infinity(); 
    int best_n = 0, best_m = 0;  

    for (int m = 1; m < 100; ++m) {
        int n = round(m * sqrt_x);
        double diff = abs(sqrt_x - (n / static_cast<double>(m)));

        if (diff < min_diff) {
            min_diff = diff;
            best_n = n;
            best_m = m;
        }
    }
    cout << "Closest fraction: " << best_n << "/" << best_m << endl;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;

    findClosestFraction(x);
    return 0;
}
