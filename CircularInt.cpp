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

CircularInt CircularInt::operator-=(int val) { // CHECKED - WORKING FINE
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

CircularInt& CircularInt::operator-() {  // CHECKED - WORKING FINE
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


CircularInt &CircularInt::operator*=(int val) { // CHECKED - WORKING FINE


    int tmp= val * this->get_current();
    (*this) += (tmp) ;
    ( *this)++;
    return *this;
}

CircularInt &CircularInt::operator+(CircularInt other) { // CHECKED - WORKING FINE
    (*this).operator+=(other.get_current());
    return (*this);
}

CircularInt CircularInt::operator/=(int val) {
    CircularInt result(*this);
    int total = this->get_current() * val;
    result -= total;
    return result;
}

CircularInt& CircularInt::operator/(int num) {
    int total = num * this->get_current();
    *this -= total;
    return (*this);
}

CircularInt::CircularInt(const CircularInt &other): low_bound(other.low_bound), upper_bound(other.upper_bound), current_num(other.current_num) {}

CircularInt &CircularInt::operator-(const CircularInt &other) {
    (*this)-=other.current_num;
    return (*this);
}

CircularInt &CircularInt::operator/(const CircularInt &other) {
    (*this) /= other.current_num;
    return (*this);
}

CircularInt &CircularInt::operator*(int n) {
    return (*this)*=n;
}

CircularInt &CircularInt::operator*(const CircularInt &other) {
    return (*this) *= other.current_num;
}

CircularInt &CircularInt::operator=(int n) {
    if(n > (*this).get_range()){
        (*this).set_current((*this).get_low_bound());
        (*this) += n;
    }
    else{
        (*this).current_num = n;
    }
    return (*this);
}



CircularInt operator-(int num, CircularInt  &other) { // 11 == 1- hour(2) because 11 is 2 hours before 1 // CHECKED - WORKING FINE
   int ans;
    CircularInt result{other.get_low_bound(), other.get_upper_bound()};
    result.set_current(num);

    result -= other.get_current();
    return result;

}

 bool operator==( CircularInt &current,  CircularInt &other) {
    if((current).get_current() == other.get_current() &&
       (current).get_upper_bound() == other.get_upper_bound()&&
       (current).get_low_bound() == other.get_low_bound())
        return true;

    return false;
}


// ####################### CODE BREAKER (Programmer Notes) #####################################
/*COPY - TMP - TESTING
 * CircularInt operator-(int num, CircularInt const &other) {
   int ans;
    CircularInt result(other);
    ans = num - result.get_current();
    result.set_current(ans);
    return result;

}
 */

/*/
 * //    CircularInt operator+=(int val){ // Non Reference (probably wrong way)
//        int total_n = this->get_current() + val;
//        int mod_range = this->get_upper_bound() - this->get_low_bound() +1;
//        int ans = total_n % mod_range;
//        this->set_current(ans);
//
//    }
 */


/*/
 * //    CircularInt& operator++(){ //prefix operator
//        int ans = this->get_current() + 1;
//        this->set_current(ans);
//        return *this;
//    }
//
//    CircularInt operator++(int){// postfix operator
//        CircularInt result(*this);
//        ++(*this);
//        return result;
//    }
 */

// ############################################################

