#include <stdint.h>

#include <iostream>

namespace ra::random {

class linear_congruential_generator {
        using int_type = uint64_t;

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
        int_type min();

        // max
        int_type max();
};

// constructor
linear_congruential_generator::linear_congruential_generator(int_type a, int_type c, int_type m, int_type s) {
    // set the a, c, m, and s values of the generator
    this->a_ = a;
    this->c_ = c;
    this->m_ = m;
    this->s_ = s;

    // set the initial state of the generator
    if ((c % m) == 0 && (s % m) == 0) {
        this->x_ = 1;
    } else {
        this->x_ = s;
    }
}

// copy constructor
linear_congruential_generator::linear_congruential_generator(const linear_congruential_generator &other) {
    // copy the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // copy the initial state of the other generator
    this->x_ = other.x_;
}

// copy assignment operator
linear_congruential_generator &linear_congruential_generator::operator=(const linear_congruential_generator &other) {
    // copy the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // copy the initial state of the other generator
    this->x_ = other.x_;

    return *this;
}

// move constructor
linear_congruential_generator::linear_congruential_generator(linear_congruential_generator &&other) {
    // move the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // move the initial state of the other generator
    this->x_ = other.x_;
}

// move assignment operator
linear_congruential_generator &linear_congruential_generator::operator=(linear_congruential_generator &&other) {
    // move the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // move the initial state of the other generator
    this->x_ = other.x_;

    return *this;
}

// return destructor
linear_congruential_generator::~linear_congruential_generator() {}

// return multiplier
int_type linear_congruential_generator::multiplier() const {
    return this->a_;
}

// return increment
int_type linear_congruential_generator::increment() const {
    return this->c_;
}

// return modulus
int_type linear_congruential_generator::modulus() const {
    return this->m_;
}

// default_seed
int_type linear_congruential_generator::default_seed() {
    return 1;
}

// return current x
int_type linear_congruential_generator::get_x() const {
    return this->x_;
}

// set a new seed value
void linear_congruential_generator::seed(int_type s) {
    if ((this->c_ % this->m_) == 0 && (s % this->m_) == 0) {
        this->x_ = 1;
    } else {
        this->x_ = s;
    }
}

// return current seed
int_type linear_congruential_generator::get_seed() const {
    return this->s_;
}

// operator()
int_type linear_congruential_generator::operator()() {
    // calculate the next state of the generator
    this->x_ = (this->a_ * this->x_ + this->c_) % this->m_;

    // return the next state of the generator
    return this->x_;
}

// operator==
bool linear_congruential_generator::operator==(const linear_congruential_generator &other) const {
    // return true if the a, c, m, and s values of the two generators are equal
    return (this->a_ == other.a_ && this->c_ == other.c_ && this->m_ == other.m_ && this->x_ == other.x_);
}

// operator!=
bool linear_congruential_generator::operator!=(const linear_congruential_generator &other) const {
    // return true if the a, c, m, and s values of the two generators are not equal
    return (this->a_ != other.a_ || this->c_ != other.c_ || this->m_ != other.m_ || this->x_ != other.x_);
}

// discard
void linear_congruential_generator::discard(unsigned long long n) {
    // discard next n numbers
    for (unsigned long long i = 0; i < n; i++) {
        this->operator()();
    }
}

// min
int_type linear_congruential_generator::min() {
    return this->c_ == 0 ? 1 : 0;
}

// max
int_type linear_congruential_generator::max() {
    return this->m_ - 1;
}

}  // namespace ra::random