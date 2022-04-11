#include <string>

/**
 * Struct called 'Time' defined sorted to organize and store each time
 * in hours, minutes and seconds.
 */

struct Time{
    int hour{};
    int min{};
    int sec{};

    Time (int Hour, int Min, int Sec){
        hour = Hour;
        min = Min;
        sec = Sec;
    }
};

/**
 * Operator + with the parameters below overloaded. What this operator
 * does is to sum 'sec' unit(s) of second(s) to the chosen time.
 * @param time
 * @param sec
 */

void operator +(Time& time, int sec);

/**
 * Operator - with the parameters below overloaded. What this operator
 * does is to subtract 'sec' unit(s) of second(s) to the chosen time.
 * @param time
 * @param sec
 */

void operator -(Time& time, int sec);

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

Time operator ++(Time time, int);

/**
 * Operator -- with the parameters below overloaded. What this operator
 * does is to decrement 1 unit of second to the chosen time (postfix version).
 * @param time
 * @param int It does not mean nothing. It just to clarify that it is postfix.
 */

Time operator --(Time time, int);

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

bool operator ==(Time time1, Time time2);

/**
 * Operator != with the parameters below overloaded. What this operator
 * does is to return true in case of first and second time are different.
 * @param time1
 * @param time2
 * @return
 */

bool operator != (Time time1, Time time2);

/**
 * Operator > with the parameters below overloaded. What this operator
 * does is to return true in case of first time is higher than the
 * second one.
 * @param time1
 * @param time2
 * @return
 */

bool operator >(Time time1, Time time2);

/**
 * Operator >= with the parameters below overloaded. What this operator
 * does is to return true in case of first time is higher than the
 * second one OR if the first and second time are the same.
 * @param time1
 * @param time2
 * @return
 */

bool operator >=(Time time1, Time time2);

/**
 * Operator < with the parameters below overloaded. What this operator
 * does is to return true in case of first time is lower than the
 * second one.
 * @param time1
 * @param time2
 * @return
 */

bool operator <(Time time1, Time time2);

/**
 * Operator <= with the parameters below overloaded. What this operator
 * does is to return true in case of first time is lower than the
 * second one OR if the first and second time are the same.
 * @param time1
 * @param time2
 * @return
 */

bool operator <=(Time time1, Time time2);

/**
 * Operator << with the parameters below overloaded. What this operator
 * does is to output the time in format HH:MM:SS.
 * @param os
 * @param time
 * @return
 */

std::ostream& operator<<(std::ostream& os, Time time);

/**
 * Operator >> with the parameters below overloaded. What this operator
 * does is to input the time: firstly hours, then minutes, and finally seconds.
 * @param os
 * @param time
 * @return
 */

std::istream& operator>>(std::istream& in, Time time);

/**
 * Checks if time is valid or not.
 * @return true if it is valid and vice versa.
 */
bool isValid(Time time);

/**
 * Checks if the time is before or after noon (am or pm).
 * @return true in case of AM or false in case of PM.
 */

bool is_am(Time time);

/**
 * Converts time into a string in 12 or 24 format
 * @param time
 * @param clock Can be "12" or "24" format
 * @return A string with time formatted
 */

std::string to_string(Time time, int clock);

/**
 * Prints the time in a readable format
 * @param time
 * @return
 */

std::string printTime(Time time);