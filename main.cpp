// working operators : <<  , += , -= , ()++ , ++() , -() , ()- int,  ,*= ,hour+hour,1-hour
// NOT WORKING : #### BUG : int - () #NOT WORKING#
//Should be done :  , hour/2
#include <iostream>
using namespace std;

//#include "CircularInt.hpp"
#include   "CircularInt.hpp"

//void test1(){
//    CircularInt hour {1, 12};                 // <hour is an integer between 1 and 12, like an hour on the clock>
//    cout << hour << endl;                     // 1
//	hour += 4;  cout << hour << endl;         // 5
//	(hour += 2)++;  cout << hour << endl;     // 8
//	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
//	cout << -hour << endl;                    // 10  (2 hours before midnight)
////	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
//	cout << hour+hour << endl;                // 10 (11 hours after 11)
//	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
////	cout << hour/2 << endl;
//}

//void test2(){
//    CircularInt hour {1, 12};// <hour is an integer between 1 and 12, like an hour on the clock>
//    cout << hour<< endl; //1
//    hour++;    cout << hour<< endl; //2
//
//    cout <<"hour is : "<< -hour << endl; //10
////    cout << 5 - hour << endl;
////    hour++; //11
////    cout << hour<< endl;
//    cout << "hour before adding 11 is : "<< hour << endl;
//    hour += 11;
//    cout << "hour after adding 11 is : "<< hour << endl;
//    hour += 22;
//    hour += 4; // 11
//    hour *= 2;
//    cout << hour<< endl; //11
////    hour += 44;
////    cout << hour << endl;
//
//}


int main() {
    CircularInt hour {1, 12};// <hour is an integer between 1 and 12, like an hour on the clock>

//    test2();
//    test1();
    cout << hour << endl;                     // 1
	hour += 4;  cout << hour << endl;         // 5
	(hour += 2)++;  cout << hour << endl;// 8
    cout << hour << endl;
	hour += 18;   cout << hour << endl;       // 2   (18 hours after 8)
	cout << -hour << endl;                    // 10  (2 hours before midnight)
    hour.set_current(2);
	hour = 1 - hour; cout << hour << endl;// 11  (2 hours before 1)
//    hour*=2;
//    cout << "1|hour= "<< hour <<endl;
    CircularInt c{1,12};
    c.set_current(3);
    cout << c << endl;
    cout << hour+c << endl;
    cout << hour-c << endl;
    cout << hour/2<< endl;
    cout << hour * 2 << endl;

//    CircularInt c = hour/2;
    cout << "2|hour= "<< hour <<endl;
    cout << "hour/2 :"<<hour/2 << endl;
    cout <<"|c=" << c << "|hour= "<< hour <<" | c - hour: " <<  c - hour << endl;
    hour =2;
    cout << "hour is :: " << hour << endl;
    cout <<"|c=" << c << "|hour= "<< hour <<" | c/ hour:" <<  c/hour <<" c="<<c << endl;
    cout << c*2 << endl;
    hour =1; cout << hour << endl;
    c=1; cout<< c << endl;


    if(hour!=c) cout << "not equal" << endl;
    else cout << " equal"<<endl;
    if(hour <= c)  cout << "hour <= c" << endl;
    else  cout << "hour > c" << endl;


    hour = 18; cout << hour << endl;
    cout << endl;
    cin >> hour; cout << "hour after input :"<< hour<<endl;



//	try {
//		cout << hour/3;
//	} catch (const string& message) {
//		cout << message << endl;     // "There is no number x in {1,12} such that x*3=10"
//	}

	// RIDDLES (not for submission): 
	//  * when is there exactly one answer to a/b?
	//  * when are there two or more answers to a/b?
	//	* when is there no answer to a/b?
}

