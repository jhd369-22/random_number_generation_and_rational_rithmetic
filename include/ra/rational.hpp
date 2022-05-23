

namespace ra::math {
template <typename T>
class rational {
        using int_type = T;

    private:
        int_type numerator_;
        int_type denominator_;

    public:

        //default constructor
        rational() : numerator_(0), denominator_(1) {}

        // two parameter constructor, the numerator n and denominator d are coprime
        rational(int_type n = 0, int_type d = 1): numerator_(n), denominator_(d) {
            if(denominator_ == 0){
                numerator_ = std::numeric_limits<int_type>::max();
                denominator_ = int_type(1);
            }
            
            if(denominator_ < 0){
                numerator_ = -numerator_;
                denominator_ = -denominator_;
            }

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;
        }

        // copy constructor
        rational(const rational &other): numerator_(other.numerator_), denominator_(other.denominator_) {}

        // copy assignment operator
        rational &operator=(const rational &other);

        // move constructor
        rational(rational &&other);

        // move assignment operator
        rational &operator=(rational &&other);

        // destructor
        ~rational();

        // return numerator
        int_type numerator() const;

        // return denominator
        int_type denominator() const;

        // arithmetic assignment operators
        rational &operator+=(const rational &other);
        rational &operator-=(const rational &other);
        rational &operator*=(const rational &other);
        rational &operator/=(const rational &other);

        // truncate
        int_type truncate() const;

        // is_integer
        bool is_integer() const;

        // test if a rational number is zero
        bool operator!() const;

        // comparison operators
        bool operator==(const rational &other) const;
        bool operator!=(const rational &other) const;
        bool operator<(const rational &other) const;
        bool operator>(const rational &other) const;
        bool operator<=(const rational &other) const;
        bool operator>=(const rational &other) const;

        // prefix and postfix increment
        rational operator++();
        rational operator++(int);

        // prefix and postfix decrement
        rational operator--();
        rational operator--(int);
}; 

}  // namespace ra::math