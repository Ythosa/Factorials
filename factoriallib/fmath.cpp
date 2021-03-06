#include <vector>
#include <exception>
#include <cstring>
#include "fmath.h"

#define ll long long

namespace fmath {
    /* prime_range() function returns range of prime numbers.
     * The function returns an array with the first
     * element >= f and the last element <= l. */
    std::vector<ll> prime_range(ll f, ll l) {
        std::vector<int> sieve;
        std::vector<ll> primes;

        for (int i = 1; i < l + 1; ++i)
            sieve.push_back(i);

        sieve[0] = 0;
        for (int i = 2; i < l + 1; ++i) {
            if (sieve[i - 1] != 0) {
                primes.push_back(sieve[i - 1]);
                for (int j = 2 * sieve[i - 1]; j < l + 1; j += sieve[i - 1]) {
                    sieve[j - 1] = 0;
                }
            }
        }

        std::vector<ll> filtered_primes;
        for (auto & prime : primes) {
            if (prime >= f) {
                filtered_primes.push_back(prime);
            }
        }

        return filtered_primes;
    }

    /* range() function returns vector where
     * first element >= f and last element < l. */
    std::vector<ll> range(ll f, ll l) {
        std::vector<ll> r;
        while (f < l) {
            r.push_back(f);
            f++;
        }

        return r;
    }

    /* isqrt() function is used to get the integer square root of
     * the given non - negative integer value n. This method returns
     * the floor value of the exact square root of n or equivalently
     * the greatest integer a such that a2 <= n. */
    ll isqrt(ll remainder) {
        if (remainder < 0) {
            throw NegativeArgumentPassed("remainder");
        }

        ll place = (unsigned ll)1 << (sizeof(ll) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000
        while (place > remainder)
            place /= 4; // optimized by compiler as place >>= 2

        ll root = 0;
        while (place)
        {
            if (remainder >= root + place)
            {
                remainder -= root + place;
                root += place * 2;
            }
            root /= 2;
            place /= 4;
        }
        return root;
    }

    /* bisect_left() function returns the index where to insert item x
     * in list a, assuming a is sorted. The return value i is such that
     * all e in a[:i] have e < x, and all e in a[i:] have e >= x.
     * So if x already appears in the list, a.insert(i, x) will insert just
     * before the leftmost x already there. Optional args lo (default 0) and
     * hi (default len(a)) bound the slice of a to be searched. */
    ll bisect_left(std::vector<ll> a, ll x, ll lo, ll hi) {
        if (lo < 0) {
            throw NegativeArgumentPassed("lo");
        }

        if (hi == -1) {
            hi = a.size();
        }

        ll mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (a[mid] < x)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }

    /* bit_counter() function returns the number of
     * units in the binary representation of a number. */
    ll bit_counter(ll n) {
        ll count = 0;
        for (; n; count++)
            n &= (n - 1);

        return count;
    }

    ll pow(ll base, ll exp) {
        ll result = 1;
        for (;;)
        {
            if ((unsigned ll)exp & 1u)
                result *= base;
            exp >>= 1u;
            if (!exp)
                break;
            base *= base;
        }

        return result;
    }
}
