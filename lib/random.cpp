#include <include/ra/random.hpp>

namespace ra::random {
// definition of operator<<
std::ostream &operator<<(std::ostream &os, const linear_congruential_generator &lcg) {
    os << "a: " << lcg.a_ << ", c: " << lcg.c_ << ", m: " << lcg.m_ << ", s: " << lcg.s_ << ", x: " << lcg.x_;
    return os;
}
}  // namespace ra::random