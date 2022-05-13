#ifndef TIME_H
#define TIME_H

#include <string>


// DONE: operator+ and operator- should produce a *new* Time
// object. Not a std::string. They should also not modify the existing
// time object, but instead (as mentioned before) produce a *new* Time
// object.

// DONE: The comparison operators contain a lot of code duplication.
// Hint: a < b is the same thing as b > a. Can you use this somehow to
// only implement *two* operators and then call those two in all other
// comparisons?

// DONE: formatTime does not work in all circumstances. What happens
// if we do this:
//
// t + 86400
// or:
// t - 86400
//
// i.e. what happens if we add a full day to a time? It should give
// back the exact same time right? Note that this should work no
// matter how many seconds we add to the clock. Even if we add a full
// year worth of seconds it should still give us the correct time.

// Make sure to include these types of tests in your tests.

// Comment: Strictly speaking you don't actually need the
// constructors. Thanks to aggregate initialization of structs you get
// the same behaviour if you just don't implement them.

// Comment: Why is the 'clock' parameter to to_string an int? There
// are only two options, 12-hour or 24-hour clock. Do you know of a
// data type that only allows for two values? This is helpful since
// now the programmer can't use the function incorrectly (for example
// by calling to_string(t, 17)).

/**
 * Struct called 'Time' defined sorted to organize and store each time
 * in hours, minutes and seconds.
 */

struct Time{
    int hour{};
    int min{};
    int sec{};
    
    //Constructor with parameters
    Time (int Hour, int Min, int Sec){
        hour = Hour;
        min = Min;
        sec = Sec;
    }

    //Constructor without parameters
    Time (){
    }
};

/**
 * Operator + with the parameters below overloaded. What this operator
 * does is to sum 'sec' unit(s) of second(s) to the chosen time.
 * @param time
 * @param sec
 */

Time operator +(Time& time, int sec);

/**
 * Operator - with the parameters below overloaded. What this operator
 * does is to subtract 'sec' unit(s) of second(s) to the chosen time.
 * @param time
 * @param sec
 */

Time operator -(Time& time, int sec);

/**
 * Operator ++ with the parameters below overloaded. What this operator
 * does is to increment 1 unit of second to the chosen time (prefix version).
 * @param time
 * @param sec
 */

Time& operator ++(Time& time);

/**
 * Operator ++ with the parameters below overloaded. What this operator
 * does is to increment 1 unit of second to the chosen time (postfix version).
 * @param time
  * @param int It does not mean nothing. It just to clarify that it is postfix.
 */

Time operator ++(Time& time, int);

/**
 * Operator -- with the parameters below overloaded. What this operator
 * does is to decrement 1 unit of second to the chosen time (postfix version).
 * @param time
 * @param int It does not mean nothing. It just to clarify that it is postfix.
 */

Time operator --(Time& time, int);

/**
 * Operator -- with the parameters below overloaded. What this operator
 * does is to decrement 1 unit of second to the chosen time (prefix version).
 * @param time
 */

Time& operator --(Time& time);

/**
 * Operator == with the parameters below overloaded. What this operator
 * does is to return true in case of first and second time are the same.
 * @param time1
 * @return
 */

bool operator ==(Time const& time1, Time const& time2);

/**
 * Operator != with the parameters below overloaded. What this operator
 * does is to return true in case of first and second time are different.
 * @param time1
 * @param time2
 * @return
 */

bool operator != (Time const& time1, Time const& time2);

/**
 * Operator > with the parameters below overloaded. What this operator
 * does is to return true in case of first time is higher than the
 * second one.
 * @param time1
 * @param time2
 * @return
 */

bool operator >(Time const& time1, Time const& time2);

/**
 * Operator >= with the parameters below overloaded. What this operator
 * does is to return true in case of first time is higher than the
 * second one OR if the first and second time are the same.
 * @param time1
 * @param time2
 * @return
 */

bool operator >=(Time const& time1, Time const& time2);

/**
 * Operator < with the parameters below overloaded. What this operator
 * does is to return true in case of first time is lower than the
 * second one.
 * @param time1
 * @param time2
 * @return
 */

bool operator <(Time const& time1, Time const& time2);

/**
 * Operator <= with the parameters below overloaded. What this operator
 * does is to return true in case of first time is lower than the
 * second one OR if the first and second time are the same.
 * @param time1
 * @param time2
 * @return
 */

bool operator <=(Time const& time1, Time const& time2);

/**
 * Operator << with the parameters below overloaded. What this operator
 * does is to output the time in format HH:MM:SS.
 * @param os
 * @param time
 * @return
 */

std::ostream& operator<<(std::ostream& os, Time const& time);

/**
 * Operator >> with the parameters below overloaded. What this operator
 * does is to input the time: firstly hours, then minutes, and finally seconds.
 * @param os
 * @param time
 * @return
 */

std::istream& operator>>(std::istream& in, Time& time);

/**
 * Checks if time is valid or not.
 * @return true if it is valid and vice versa.
 */
bool isValid(Time const& time);

/**
 * Checks if the time is before or after noon (am or pm).
 * @return true in case of AM or false in case of PM.
 */

bool is_am(Time const& time);

/**
 * Converts time into a string in 12 or 24 format
 * @param time
 * @param isTwelveClock Can be 'true' in case of 12 clock or 'false' in case of 24 clock
 * @return A string with time formatted
 */

std::string to_string(Time& time, bool isTwelveClock);

/**
 * Prints the time in a readable format
 * @param time
 * @return
 */

std::string printTime(Time const& time);

/**
 * In case of adding / subtracting a second with functions "+"
 * and "-", and these seconds affect to the minutes and/or
 * hours, then time is formatted properly
 * @param time
 * @return
 */

Time formatTime (Time& time);

#endif
