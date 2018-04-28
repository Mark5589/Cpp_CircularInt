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
    CircularInt(int , int , int );
    CircularInt(const CircularInt& other);
    int get_low_bound() const {return low_bound;}
    int get_upper_bound() const{ return  upper_bound;}
    int get_current() const {return current_num;}
    void set_current(int val){this->current_num = val;}
    std::string to_string(){return std::to_string(get_current());}
    int get_range(){return get_upper_bound()-get_low_bound()+1;}


    //operator overloading:


//    friend  std::ostream& operator<<(std::ostream& os,  CircularInt& s){
//        os<<std::to_string(s.get_current()) ;
//        return os;
//    }

    friend std::istream& operator>>(std::istream &is ,CircularInt& s ){
        int i;
        is >> i;
        s =i;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, CircularInt const &n);



    CircularInt&operator+=(int val);



    CircularInt& operator++(); // prefix
    CircularInt operator++(int); // postfix

    CircularInt& operator--(); // prefix
    CircularInt operator--(int); // postfix

    CircularInt operator/(int num);
    CircularInt operator-();
    CircularInt operator*(int n);
    CircularInt operator-(int n);
    CircularInt operator+(int n);


    CircularInt operator-=(int);
    CircularInt& operator/=(int);
    CircularInt&operator*=(int);
    CircularInt&operator=(int n);

    CircularInt operator-=(const CircularInt& other);
    CircularInt& operator/=(const CircularInt& other);
    CircularInt&operator*=(const CircularInt& other);
    CircularInt&operator=(const CircularInt& other);

    bool operator==(int val);
    bool operator!=(int val);
    bool operator<( int val);
    bool operator>( int val);
    bool operator<=(int val);
    bool operator>=(int val);


};
//This is non-member function because its have to deal with 3 members on unary/binary operator (compiling error)
CircularInt operator-(int num, CircularInt  &other);                //num-CircularInt // CHECKED - WORKING FINE //
CircularInt operator+(int num ,const CircularInt&b); // CHECKED - WORKING FINE
CircularInt operator/(int num ,const CircularInt&b);
CircularInt operator*(int num ,const CircularInt&b);



CircularInt operator-(int num               ,CircularInt  &other);
CircularInt operator+(const CircularInt& a ,const CircularInt&b);
CircularInt operator-(const CircularInt& a ,const CircularInt&b);
CircularInt operator/(const CircularInt& a ,const CircularInt&b);
CircularInt operator*(const CircularInt& a ,const CircularInt&b);

 bool operator==( CircularInt &current ,  CircularInt&other);
 bool operator!=( CircularInt &current ,  CircularInt&other);
 bool operator<( CircularInt &current ,  CircularInt&other);
 bool operator>( CircularInt &current ,  CircularInt&other);
 bool operator<=( CircularInt &current ,  CircularInt&other);
 bool operator>=( CircularInt &current ,  CircularInt&other);

bool operator==( CircularInt &current , int val);
bool operator!=( CircularInt &current , int val);
bool operator<( CircularInt &current ,  int val);
bool operator>( CircularInt &current ,  int val);
bool operator<=( CircularInt &current , int val);
bool operator>=( CircularInt &current , int val);
//
bool operator==(int val ,  CircularInt&other);
bool operator!=(int val ,  CircularInt&other);
bool operator<( int val,  CircularInt&other);
bool operator>( int val,  CircularInt&other);
bool operator<=(int val ,  CircularInt&other);
bool operator>=(int val ,  CircularInt&other);



#endif //CIRCULAR_INT_CIRCULARINT_H
