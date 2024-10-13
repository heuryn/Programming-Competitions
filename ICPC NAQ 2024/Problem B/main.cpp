#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double distance(double x, double y) {
    return sqrt(x * x + y * y);
}

bool intersectsYAxis(int a, int b, int c, int d) {
    return (a <= 0 && c >= 0) || (a >= 0 && c <= 0);
}

int main() {
    int n;
    cin >> n;

    double minDistance = numeric_limits<double>::max();
    bool foundBarricade = false;

    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (intersectsYAxis(a, b, c, d)) {
            double t = (0.0 - a) / (c - a);
            double y = b + t * (d - b);

            if (y > 0) {
                foundBarricade = true;
                minDistance = min(minDistance, y);
            }
        }
    }

    if (foundBarricade) {
        cout.precision(10);
        cout << fixed << minDistance << endl;
    } else {
        cout << "-1.0" << endl;
    }

    return 0;
}