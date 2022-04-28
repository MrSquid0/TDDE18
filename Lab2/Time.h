#ifndef TIME_H
#define TIME_H

#include <string>

//DONE: You have to use header-guards in your .h-files to not cause
//problems for the programs including your functions.

//DONE: Use const & for parameters of class type (for example time)
//whenever passing them to a function where they should not be
//changed, to avoid creating copies. If the value should be changed
//use references.

//DONE: Your + and - functions does not work as intended, they should
//not just add the seconds, they have to make sure that minutes and
//hours are increased if necessary.

//DONE: The comparison operators all function in a very similar
//way. To avoid code duplication you should implement them using the
//ones you have already implemented. You should only implement a
//maximum of 3 comparison operators, and the rest should be
//implemented by calling the ones already implemented.

//DONE: Your output operator does not always follow the correct
//format, for example when the values are less than 10. Fix that.

//DONE: Your input operator should read from the stream that you
//passed in, and not only cin. You also have warnings from this
//function that is relevant to the implementation.

//DONE: There is too much code duplication in your printTime
//function. Remove the similar code. Look at for example stringstreams
//that can help you here and also in the testing program.

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

std::string operator +(Time& time, int sec);

/**
 * Operator - with the parameters below overloaded. What this operator
 * does is to subtract 'sec' unit(s) of second(s) to the chosen time.
 * @param time
 * @param sec
 */

std::string operator -(Time& time, int sec);

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
 * @param clock Can be "12" or "24" format
 * @return A string with time formatted
 */

std::string to_string(Time& time, int clock);

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