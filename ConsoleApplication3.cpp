#include <iostream>
#include <cmath>
#define PI 3.14159265

int main() {
    float x;
    float y;
    std::cin >> x;
    std::cin >> y;
    float R = std::cos((PI / 4) * x);
    float S = std::sqrt(8) * std::exp(y) * std::pow(5, 1.0f / y);
    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;
    float C = std::max(R, S);
    std::cout << "MAX = " << C << std::endl;
    return 0;
}