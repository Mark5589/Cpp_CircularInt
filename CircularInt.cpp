//
// Created by mark  gurin on 16/04/2018.
//

#include "CircularInt.hpp"
bool CircularInt::parameters_check(int a, int b) {
    int a_abs = abs(a);
    int b_abs = abs(b);
    return b_abs - a_abs;

}

CircularInt::CircularInt(int lower, int upper){

        if(CircularInt::parameters_check(lower,upper) > 0 ){
            this->low_bound = lower;
            this->upper_bound=upper;
            this->current_num = lower;
        }
        else{
            throw "The lower bound should be smaller then the upper bound!";
        }

}

CircularInt CircularInt::operator-=(int val) {
    int ans;
    if(val >= this->get_current()){
        val = (val - this->get_current()) % this->get_range();
        ans = get_upper_bound() -val;
    }
    else{
        ans = this->get_current() - val;

    }
    if(ans == 0 ) ans = get_upper_bound();

    this->set_current(ans);
}

CircularInt& CircularInt::operator-() {
    int ans = this->get_upper_bound() - this->get_current();
    this->set_current(ans);
    return *this;

}

CircularInt& CircularInt::operator-(int start_point) { // 2 hours before 1 == 1 - hour
    int old_current = this->get_current();
    this->set_current(start_point);
    *this -= old_current;
    return *this;
}

// ### BUG IS HERE , COMPILER MESSAGE : " error: overloaded 'operator-' must be a unary or binary operator (has 3 parameters) "
//CircularInt CircularInt::operator-(int starting, CircularInt currentOne) {
//    CircularInt ans{currentOne.get_low_bound(), currentOne.get_upper_bound()};
//    int tmp = currentOne.get_current();
//    ans.set_current(starting);
//    ans -= tmp;
//    return ans;
//
//
//}

CircularInt &CircularInt::operator*=(int val) {


    int tmp= val * this->get_current();
    (*this) += (tmp) ;
    ( *this)++;
    return *this;
}




