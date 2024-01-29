#include <iostream>
#include <climits>
#include <cmath>

int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

    long long dvd = labs(dividend);
    long long dvs = labs(divisor);

    long long quotient = 0;
    long long temp = 0;

    for (int i = 31; i >= 0; i--) {
        if (temp + (dvs << i) <= dvd) {
            std::cout << "i:" << i << "dvs << i" << (dvs << i) << std::endl;
            temp += (dvs << i);
            quotient |= (1LL << i);
        }
    }

    return sign * quotient;
}

int main()
{

    int dividend = 0;
    int divisor = 3;

    std::cout << "Result of division" << divide(dividend, divisor) << std::endl;

    return 0;
}
