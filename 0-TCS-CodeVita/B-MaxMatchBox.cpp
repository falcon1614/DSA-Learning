#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    area = abs(area) / 2.0;

    double perimeter = 0.0;
    double min_edge = 1e9;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double dx = abs(points[i].x - points[j].x);
        double dy = abs(points[i].y - points[j].y);
        double len = dx + dy;
        perimeter += len;
        if (len < min_edge) {
            min_edge = len;
        }
    }

    double H_max = (min_edge - 0.1) / 2.0;
    double max_volume = 0.0;
    double step = 0.1;

    for (double H = step; H <= H_max + 1e-5; H += step) {
        double base_area = area - perimeter * H + 4 * H * H;
        double volume = base_area * H;
        if (volume > max_volume) {
            max_volume = volume;
        }
    }

    cout << fixed << setprecision(2) << max_volume << endl;

    return 0;
}
