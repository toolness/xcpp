#include "sieve.h"
#include <cmath>

namespace
{
bool is_prime(int n)
{
    if (n % 2 == 0) {
        return false;
    }
    const int max_factor = static_cast<int>(std::sqrt(n));
    for (int probe = 2; probe <= max_factor; ++probe) {
        if (n % probe == 0) {
            return false;
        }
    }
    return true;
}
}

namespace sieve
{

std::vector<int> primes(int n)
{
    std::vector<int> result;
    if (n >= 2) {
        result.push_back(2);
    }
    for (int candidate = 3; candidate < n; ++candidate) {
        if (is_prime(candidate)) {
            result.push_back(candidate);
        }
    }
    return result;
}

}
