#include <iostream>
#include <cmath>
#include <limits>
#include <chrono>

using namespace std;

void findClosestFractionByM(double x) {
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
    cout << "[Перебор по m] Closest fraction: " << best_n << "/" << best_m << endl;
}

void findClosestFractionByN(double x) {
    double sqrt_x = sqrt(x);
    double min_diff = numeric_limits<double>::infinity();
    int best_n = 0, best_m = 0;

    for (int n = 1; n < 100; ++n) {
        int m = round(n / sqrt_x);
        if (m == 0) continue; 
        double diff = abs(sqrt_x - (n / static_cast<double>(m)));

        if (diff < min_diff) {
            min_diff = diff;
            best_n = n;
            best_m = m;
        }
    }
    cout << "[Перебор по n] Closest fraction: " << best_n << "/" << best_m << endl;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;

    auto start1 = chrono::high_resolution_clock::now();
    findClosestFractionByM(x);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time1 = end1 - start1;

    auto start2 = chrono::high_resolution_clock::now();
    findClosestFractionByN(x);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time2 = end2 - start2;

    cout << "\nВремя работы (перебор по m): " << time1.count() << " секунд" << endl;
    cout << "Время работы (перебор по n): " << time2.count() << " секунд" << endl;

    return 0;
}
