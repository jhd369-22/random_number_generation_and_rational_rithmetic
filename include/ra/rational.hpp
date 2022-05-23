

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

        // two parameter constructor
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
        rational(const rational &other){
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;
        }

        // copy assignment operator
        rational &operator=(const rational &other){
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;

            return *this;
        }

        // move constructor
        rational(rational &&other){
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;

            other.numerator_ = 0;
            other.denominator_ = 1;
        }

        // move assignment operator
        rational &operator=(rational &&other){
            numerator_ = other.numerator_;
            denominator_ = other.denominator_;

            other.numerator_ = 0;
            other.denominator_ = 1;

            return *this;
        }

        // destructor
        ~rational() {}

        // return numerator
        int_type numerator() const {
            return numerator_;
        }

        // return denominator
        int_type denominator() const {
            return denominator_;
        }

        // arithmetic assignment operators
        rational &operator+=(const rational &other) {
            int_type n = numerator_ * other.denominator_ + other.numerator_ * denominator_;
            int_type d = denominator_ * other.denominator_;
            int_type gcd = std::gcd(n, d);

            numerator_ = n / gcd;
            denominator_ = d / gcd;
            
            return *this;
        }

        rational &operator-=(const rational &other) {
            int_type n = numerator_ * other.denominator_ - other.numerator_ * denominator_;
            int_type d = denominator_ * other.denominator_;
            int_type gcd = std::gcd(n, d);

            numerator_ = n / gcd;
            denominator_ = d / gcd;
            
            return *this;
        }

        rational &operator*=(const rational &other){
            numerator_ *= other.numerator_;
            denominator_ *= other.denominator_;

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return *this;
        }

        rational &operator/=(const rational &other){

            if(other.numerator_ < 0){
                numerator_ *= (-other.denominator_);
                denominator_ *= (- other.numerator_);
            } else {
                numerator_ *= other.denominator_;
                denominator_ *= other.numerator_;
            }

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return *this;
        }

        // truncate
        int_type truncate() const {
            return numerator_ / denominator_;
        }

        // is_integer
        bool is_integer() const {
            return numerator_ % denominator_ == 0;
        }

        // test if a rational number is zero
        bool operator!() const {
            return numerator_ == 0;
        }

        // comparison operators
        bool operator==(const rational &other) const {
            return numerator_ == other.numerator_ && denominator_ == other.denominator_;
        }

        bool operator!=(const rational &other) const {
            return numerator_ != other.numerator_ || denominator_ != other.denominator_;
        }

        bool operator<(const rational &other) const{
            return numerator_ * other.denominator_ < other.numerator_ * denominator_;
        }

        bool operator>(const rational &other) const{
            return numerator_ * other.denominator_ > other.numerator_ * denominator_;
        }

        bool operator<=(const rational &other) const{
            return numerator_ * other.denominator_ <= other.numerator_ * denominator_;
        }

        bool operator>=(const rational &other) const{
            return numerator_ * other.denominator_ >= other.numerator_ * denominator_;
        }

        // prefix and postfix increment
        rational operator++() {
            numerator_ += denominator_;

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return *this;
        }

        rational operator++(int) {
            rational tmp(*this);
            numerator_ += denominator_;

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return tmp;
        }

        // prefix and postfix decrement
        rational operator--() {
            numerator_ -= denominator_;

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return *this;
        }

        rational operator--(int) {
            rational tmp(*this);
            numerator_ -= denominator_;

            int_type gcd = std::gcd(numerator_, denominator_);
            numerator_ /= gcd;
            denominator_ /= gcd;

            return tmp;
        }
}; 

}  // namespace ra::math