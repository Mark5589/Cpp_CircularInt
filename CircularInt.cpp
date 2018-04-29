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

CircularInt& CircularInt::operator-=(int val) { // CHECKED - WORKING FINE
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
    return(*this);
}

CircularInt CircularInt::operator-() {  // CHECKED - WORKING FINE
    CircularInt res(*this);
    int ans = this->get_upper_bound() - this->get_current();
    res.set_current(ans);
    return res;



}



CircularInt &CircularInt::operator*=(int val) { // CHECKED - WORKING FINE


    int tmp= val * this->get_current();
    (*this) += (tmp) ;
    ( *this)++;
    return *this;
}

//CircularInt &CircularInt::operator+(CircularInt other) { // CHECKED - WORKING FINE
//    (*this).operator+=(other.get_current());
//    return (*this);
//}

CircularInt& CircularInt::operator/=(int val) {
    int total = (*this).get_current() * val;
    (*this) -= total;
    return (*this);
}

CircularInt CircularInt::operator/(int num) {
    CircularInt ans(*this);
    int total = num * this->get_current();
    ans -= total;
    return ans;
}

CircularInt::CircularInt(const CircularInt &other): low_bound(other.low_bound), upper_bound(other.upper_bound), current_num(other.current_num) {}

//CircularInt CircularInt::operator-(const CircularInt &other) {
////    (*this)-=other.current_num;
////    return (*this);
//    CircularInt ans(*this);
//    ans -= other.current_num;
//    return ans;
//}



CircularInt CircularInt::operator*(int n) {
    CircularInt ans(*this);
    return ans*=n;
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

CircularInt CircularInt::operator++(int) { // postfix
    CircularInt ans(*this);
    ++(*this);
    return ans;
}

CircularInt &CircularInt::operator++() { // prefix
    (*this)+=1;
    return (*this);
}

CircularInt &CircularInt::operator+=(int val) {
    ///// Version 1.0
//    int total_n = (*this).get_current() + val;
//    int mod_range = this->get_range();
//    int ans = total_n % mod_range;
//    this->set_current(ans);
//    return (*this);

    ///// Version 1.1
    int modNum = val % (upper_bound - low_bound + 1);
    current_num += modNum;
    if (current_num > upper_bound)
        current_num = low_bound + (current_num - upper_bound) - 1;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const CircularInt &n) {
    int ans = n.get_current();
    return os << std::to_string(ans);
}

bool CircularInt::operator==(int val) {
    return (this->get_current()) == val;
}

bool CircularInt::operator!=(int val) {
    return (this->get_current()) != val;
}

bool CircularInt::operator<(int val) {
    return (this->get_current()) < val;
}

bool CircularInt::operator>(int val) {
    return (this->get_current()) > val;
}

bool CircularInt::operator<=(int val) {
    return (this->get_current())==val || (this->get_current()) < val;
}

bool CircularInt::operator>=(int val) {
    return (this->get_current())==val || (this->get_current()) >val;
}

CircularInt CircularInt::operator-(int n) {
    CircularInt ans(*this);
    return ans-= n;
}

CircularInt CircularInt::operator+(int n) {
    CircularInt ans(*this);
    return ans += n;
}

CircularInt::CircularInt(int low, int high, int curr) {
    this->low_bound = low;
    this->upper_bound = high;
    this->current_num = curr;
}

CircularInt& CircularInt::operator-=(const CircularInt &other) {
    return (*this) -= other.get_current();
}

CircularInt &CircularInt::operator/=(const CircularInt &other) {
    return (*this) /= other.get_current();
}

CircularInt &CircularInt::operator*=(const CircularInt &other) {
    return (*this) *= other.get_current();
}

CircularInt &CircularInt::operator=(const CircularInt &other) {
     (*this).upper_bound = other.get_upper_bound();
    (*this).low_bound = other.get_low_bound();
    (*this).current_num = other.get_current();
    return (*this);

}

CircularInt CircularInt::operator--(int) {
    CircularInt res(*this);
    --(*this);
    return res;
}

CircularInt &CircularInt::operator--() {
    (*this) -= 1;
    return (*this);
}

CircularInt &CircularInt::operator+=(const CircularInt &other) {
    return (*this) += other.get_current();
}


CircularInt operator-(int num,const CircularInt  &other) { // 11 == 1- hour(2) because 11 is 2 hours before 1 // CHECKED - WORKING FINE
//   int ans;
//    CircularInt result{other.get_low_bound(), other.get_upper_bound()};
//    result.set_current(num);
//
//    result -= other.get_current();
//    return result;
    CircularInt ans(other);
    ans.set_current(num);
    ans -= other.get_current();
    return  ans;


}

 bool operator==(const  CircularInt &current,const   CircularInt &other) {
    if((current).get_current() == other.get_current() &&
       (current).get_upper_bound() == other.get_upper_bound()&&
       (current).get_low_bound() == other.get_low_bound())
        return true;

    return false;
}

bool operator!=(const CircularInt &current,const  CircularInt &other) {
    return !(current == other);
}

bool operator<(const CircularInt &current,const  CircularInt &other) {
    if(current.get_low_bound() == other.get_low_bound() && current.get_upper_bound() == other.get_upper_bound() &&
            current.get_current() < other.get_current())return true;

    return false;
}

bool operator>(const CircularInt &current,const  CircularInt &other) {
    if(current < other)return false;
    return true;
}

bool operator<=(const CircularInt &current,const  CircularInt &other) {
    if(current < other || current == other)return true;
    return false;
}

bool operator>=(const CircularInt &current,const  CircularInt &other) {
    if(current > other || current == other) return true;
    return false;
}

CircularInt operator-(const CircularInt &a, const CircularInt &b) {
    CircularInt ans(a);
    ans-=b.get_current();
    return ans;
}

CircularInt operator+(const CircularInt &a, const CircularInt &b) {
    CircularInt ans(a);
    ans+=b.get_current();
    return ans;
}

CircularInt operator/(const CircularInt &a, const CircularInt &b) {
    CircularInt ans(a);
    ans /= b.get_current();
    return ans;
}

CircularInt operator*(const CircularInt &a, const CircularInt &b) {
    CircularInt ans(a);
    ans *= b.get_current();
    return ans;
}

CircularInt operator+(int num, const CircularInt &b) {
    CircularInt res(b.get_low_bound(), b.get_upper_bound(), num);
    res += b.get_current();
    return res;
}

CircularInt operator/(int num, const CircularInt &b) {
    CircularInt res(b.get_low_bound(), b.get_upper_bound(), num);    res /= b.get_current();
    return res;
}

CircularInt operator*(int num, const CircularInt &b) {
    CircularInt res(b.get_low_bound(), b.get_upper_bound(), num);    res *= b.get_current();
    return res;
}


bool operator>=(int val,const CircularInt &other) {
    return val > other || val == other;
}

bool operator==(int val,const  CircularInt &other) {
    return val == other.get_current();
}

bool operator!=(int val,const  CircularInt &other) {
    return val != other.get_current();
}

bool operator<(int val,const  CircularInt &other) {
    return val < other.get_current();
}

bool operator>(int val,const  CircularInt &other) {
    return val > other.get_current();
}

bool operator<=(int val,const  CircularInt &other) {
    return val < other || val == other;
}

// bool operator==(CircularInt &current, int val) {
//    return current.get_current() == val;
//}
//
//inline bool operator!=(CircularInt &current, int val) {
//    return current.get_current() != val;
//}
//
//inline bool operator<(CircularInt &current, int val) {
//    return current.get_current() < val;
//}
//
//inline bool operator>(CircularInt &current, int val) {
//    return current.get_current() > val;
//}
//
//inline bool operator<=(CircularInt &current, int val) {
//    return current.get_current() < val || current.get_current() == val;
//}
//
//inline bool operator>=(CircularInt &current, int val) {
//    return current.get_current() > val || current.get_current() == val;
//}




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

// ###################GARBAGE COD#########################################

//CircularInt& CircularInt::operator-(int start_point) { // 2 hours before 1 == 1 - hour
//    int old_current = this->get_current();
//    this->set_current(start_point);
//    *this -= old_current;
//    return *this;
//}

