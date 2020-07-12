#include <iostream>

#define ull unsigned long long

ull const simple_values[] = { 1,1,1,3 };

template <typename type>
type isqrt(type remainder)
{
    if (remainder < 0) // if type is unsigned this will be ignored = no runtime  
        return 0; // negative number ERROR  

    type place = (type)1 << (sizeof(type) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000  
    while (place > remainder)
        place /= 4; // optimized by complier as place >>= 2  

    type root = 0;
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

/*  Return the index where to insert item x in list a, assuming a is sorted.
    The return value i is such that all e in a[:i] have e < x, and all e in
    a[i:] have e >= x.  So if x already appears in the list, a.insert(i, x) will
    insert just before the leftmost x already there.
    Optional args lo (default 0) and hi (default len(a)) bound the
    slice of a to be searched. */
ull bisect_left(ull a[], ull x, ull lo = 0, ull hi = -1) {
    if (lo < 0) {
        throw "lo must be non-negative";
    }

    if (hi == -1) {
        hi = sizeof(a) / sizeof(*a);
    }

    ull mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (a[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }

    return lo;
}

ull product(ull s[], ull n, ull m) {
    if (n > m) {
        return 1;
    }
    
    if (n == m) {
        return s[n];
    }

    ull k = (n + m) / 2;

    return product(s, n, k) * product(s, k + 1, m);
}

int main() {
    std::cout << "Hello World!\n";
}

