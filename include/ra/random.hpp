#ifndef RA_RANDOM_HPP
#define RA_RANDOM_HPP

#include <stdint.h>
#include <iostream>

namespace ra::random {

using int_type = uint64_t;

class linear_congruential_generator {
    private:
        int_type a_, c_, m_, s_;
        int_type x_;  // integer sequence x_n for n = 0, 1, 2, ...

    public:
        // constructor
        linear_congruential_generator(int_type a, int_type c, int_type m, int_type s = default_seed());

        // copy constructor
        linear_congruential_generator(const linear_congruential_generator &other);

        // copy assignment operator
        linear_congruential_generator &operator=(const linear_congruential_generator &other);

        // move constructor
        linear_congruential_generator(linear_congruential_generator &&other);

        // move assignment operator
        linear_congruential_generator &operator=(linear_congruential_generator &&other);

        // destructor
        ~linear_congruential_generator();

        // return multiplier
        int_type multiplier() const;

        // return increment
        int_type increment() const;

        // return modulus
        int_type modulus() const;

        // default seed
        static int_type default_seed();

        // return x
        int_type get_x() const;

        // set new seed
        void seed(int_type s = default_seed());

        // return current seed
        int_type get_seed() const;

        // operator()
        int_type operator()();

        // operator==
        bool operator==(const linear_congruential_generator &other) const;

        // operator!=
        bool operator!=(const linear_congruential_generator &other) const;

        // operator<<
        friend std::ostream &operator<<(std::ostream &os, const linear_congruential_generator &lcg);

        // discard
        void discard(unsigned long long n);

        // min
        int_type min() const;

        // max
        int_type max() const;
};

std::ostream &operator<<(std::ostream &os, const linear_congruential_generator &lcg);

}  // namespace ra::random

#endif