// working operators : <<  , += , -= , ()++ , ++() , -() , ()- int,  ,*= ,
// NOT WORKING : #### BUG : int - () #NOT WORKING#
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
//	hour = 1 - hour; cout << hour << endl;    // 11  (2 hours before 1)
//	cout << hour+hour << endl;                // 10 (11 hours after 11)
//	hour *= 2;   cout << hour << endl;        // 10 (11*2 = 11+11)
//	cout << hour/2 << endl;
//}

void test2(){
    CircularInt hour {1, 12};// <hour is an integer between 1 and 12, like an hour on the clock>
    cout << hour<< endl; //1
    hour++;    cout << hour<< endl; //2

    cout <<"hour is : "<< -hour << endl; //10
//    cout << 5 - hour << endl;
//    hour++; //11
//    cout << hour<< endl;
    cout << "hour before adding 11 is : "<< hour << endl;
    hour += 11;
    cout << "hour after adding 11 is : "<< hour << endl;
    hour += 22;
    hour += 4; // 11
    hour *= 2;
    cout << hour<< endl; //11
//    hour += 44;
//    cout << hour << endl;




}


int main() {
    CircularInt hour {1, 12};// <hour is an integer between 1 and 12, like an hour on the clock>
    test2();
////    cout << hour.to_string() << endl;

//    cout << hour<< endl;
////    hour.operator+=(4);
//    hour += 4; // 5
////    hour++;
//    cout << hour<< endl;
////    cout<<hour<< endl;
//    (hour += 2)++; // 7
//    hour++;     // 8
//    cout<<hour<<endl;
//    hour-=6; // -1 check, -3 check,
//    hour-=2; // -1 check, -3 check,
//    cout<<hour<<endl;
//    -hour;
//    cout << hour << endl;

//    hour.operator++();
//    hour+=3;
//    cout<< hour<< endl;
//    hour+=18;
//    cout<< hour<< endl;
//    cout<< hour << endl;

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

