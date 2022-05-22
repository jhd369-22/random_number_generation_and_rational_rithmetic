#include<iostream>

// int_type. This type member is the unsigned integer type used by the linear_congruential_generator class. This type must be at least 64 bits in size.
using int_type = unsigned long;

class linear_congruential_generator{

    private:
        int_type a_;
        int_type c_;
        int_type m_;
        int_type s_;
        int_type x0_;

    public:
        // constructor
        linear_congruential_generator(int_type a, int_type c, int_type m, int_type s = default_seed());

        // copy constructor
        linear_congruential_generator(const linear_congruential_generator& other);

        // copy assignment operator
        linear_congruential_generator& operator=(const linear_congruential_generator& other);

        // move constructor
        linear_congruential_generator(linear_congruential_generator&& other);

        // move assignment operator
        linear_congruential_generator& operator=(linear_congruential_generator&& other);

        // destructor
        ~linear_congruential_generator();

        // default seed
        static int_type default_seed();


};

// constructor
linear_congruential_generator::linear_congruential_generator(int_type a, int_type c, int_type m, int_type s = default_seed()){

    // set the a, c, m, and s values of the generator
    this->a_ = a;
    this->c_ = c;
    this->m_ = m;
    this->s_ = s;

    // set the initial state of the generator
    if( (c % m) == 0 && (s % m) == 0 ){
        this->x0_ = 1;
    }
    else{
        this->x0_ = s;
    }
}

// copy constructor
linear_congruential_generator::linear_congruential_generator(const linear_congruential_generator& other){

    // copy the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // copy the initial state of the other generator
    this->x0_ = other.x0_;
}

// copy assignment operator
linear_congruential_generator& linear_congruential_generator::operator=(const linear_congruential_generator& other){

    // copy the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // copy the initial state of the other generator
    this->x0_ = other.x0_;

    return *this;
}


// move constructor
linear_congruential_generator::linear_congruential_generator(linear_congruential_generator&& other){

    // move the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // move the initial state of the other generator
    this->x0_ = other.x0_;
}

// move assignment operator
linear_congruential_generator& linear_congruential_generator::operator=(linear_congruential_generator&& other){

    // move the a, c, m, and s values of the other generator
    this->a_ = other.a_;
    this->c_ = other.c_;
    this->m_ = other.m_;
    this->s_ = other.s_;

    // move the initial state of the other generator
    this->x0_ = other.x0_;

    return *this;
}

// default_seed. This static member function returns the default seed value, which is the value returned by the default constructor.
int_type linear_congruential_generator::default_seed(){
    return 1;
}

// destructor
linear_congruential_generator::~linear_congruential_generator(){}