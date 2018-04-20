//
// Created by mark  gurin on 16/04/2018.
//

//links for prefix , postfix ++ operator : https://stackoverflow.com/questions/3846296/how-to-overload-the-operator-in-two-different-ways-for-postfix-a-and-prefix

#ifndef CIRCULAR_INT_CIRCULARINT_H
#define CIRCULAR_INT_CIRCULARINT_H

//#include <cmath>
#include <stdlib.h>
#include <string>
#include <iostream>


class CircularInt {
    int low_bound, upper_bound, current_num;
    bool parameters_check(int, int);



public:
    CircularInt(int , int );
    int get_low_bound(){return low_bound;}
    int get_upper_bound(){ return  upper_bound;}
    int get_current(){return current_num;}
    int set_current(int val){this->current_num = val;}
    std::string to_string(){return std::to_string(get_current());}
    int get_range(){return get_upper_bound()-get_low_bound()+1;}


    //operator overloading:


    friend std::ostream& operator<<(std::ostream& os,  CircularInt& s){
        os<<std::to_string(s.get_current()) ;
        return os;
    }

    CircularInt operator+=(int val){
        int total_n = this->get_current() + val;
        int mod_range = this->get_upper_bound() - this->get_low_bound() +1;
        int ans = total_n % mod_range;
        this->set_current(ans);

    }

//    CircularInt& operator++(){ //prefix operator
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
    CircularInt operator++(int){
        this->operator+=(1);
        return *this;
    }

    CircularInt operator-=(int);
    CircularInt& operator-();
    CircularInt& operator-(int);
//    CircularInt operator-(int,CircularInt); //### BUG
    CircularInt&operator*=(int);

};


#endif //CIRCULAR_INT_CIRCULARINT_H
