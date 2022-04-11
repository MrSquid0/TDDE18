#include "Time.h"
#include <string>
#include <iostream>

using namespace std;

void operator +(Time& time, int sec){
    time.sec += sec;
}

void operator -(Time& time, int sec){
    time.sec -= sec;
}

Time& operator ++(Time& time){
    time.sec++;
}

Time operator ++(Time time, int){
    ++time.sec;
}

Time& operator --(Time& time){
    time.sec--;
}

Time operator --(Time time, int){
    --time.sec;
}

bool operator ==(Time time1, Time time2){
    if ((time1.hour == time2.hour) && (time1.min == time2.min) &&
        (time1.sec == time2.sec)) {
        return true;
    } else {
        return false;
    }
}

bool operator != (Time time1, Time time2){
    if (time1 == time2){
        return false;
    } else {
        return true;
    }
}

bool operator >(Time time1, Time time2){
    if (time1.hour > time2.hour) {
        return true;
    } else if (time1.hour == time2.hour){
        if (time1.min > time2.min){
            return true;
        } else if (time1.min == time2.min){
            if (time1.sec > time2.sec){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator >=(Time time1, Time time2){
    if (time1 == time2){
        return true;
    } else if (time1 > time2){
        return true;
    } else {
        return false;
    }
}

bool operator <(Time time1, Time time2){
    if (time1.hour < time2.hour) {
        return true;
    } else if (time1.hour == time2.hour){
        if (time1.min < time2.min){
            return true;
        } else if (time1.min == time2.min){
            if (time1.sec < time2.sec){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator <=(Time time1, Time time2){
    if (time1 == time2){
        return true;
    } else if (time1 < time2){
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, Time time){
    cout << time.hour << ":" << time.min << ":" << time.sec;
}

istream& operator>>(istream& in, Time time){
    cout << "Write the hours: ";
    cin >> time.hour;
    cout << "Write the minutes: ";
    cin >> time.min;
    cout << "Write the seconds: ";
    cin >> time.sec;
    if(isValid(time)){
        cin.setstate(ios_base::goodbit);
    } else {
        cin.setstate(ios_base::failbit);
    }
}


bool isValid (Time time){

    if (((time.hour >=0) && (time.hour <=23)) &&
        ((time.min >=1) && (time.min <=59)) &&
        ((time.sec >=1) && (time.sec <=59))){
        return true;
    } else {
        return false;
    }
}

bool is_am(Time time) {
    if (time.hour >= 0 && time.hour <= 11) {
        return true;
    } else {
        return false;
    }
}

string to_string(Time time, int clock) {
    string timeFormatted{};
    if (isValid(time)) {
        if (clock == 12){
            if (time.hour >= 0 && time.hour <= 11) {
                return printTime(time) + " am";
            } else {
                if (time.hour == 12){
                    timeFormatted = printTime(time) + " pm";
                } else {
                    time.hour -= 12;
                    timeFormatted = printTime(time) + " pm";
                    time.hour += 12;
                }
                return timeFormatted;
            }
        } else if (clock == 24){
            return printTime(time);
        } else {
            return R"(Clock format invalid. Valid formats: "12" or "24".)";
        }

    } else {
        return "Time is not valid.";
    }
}

string printTime(Time time){
    string timeFormatted{};
    if ((time.hour == 0) || (time.hour >= 1 && time.hour <= 9)) {
        timeFormatted =  "0" + to_string(time.hour) + ":";
    } else {
        timeFormatted = to_string(time.hour) + ":";
    }
    if (time.min >= 1 && time.min <= 9) {
        timeFormatted += "0" + to_string(time.min) + ":";
    } else {
        timeFormatted += to_string(time.min) + ":";
    }
    if (time.sec >= 1 && time.sec <= 9) {
        timeFormatted += "0" + to_string(time.sec);
    } else {
        timeFormatted += to_string(time.sec);
    }
    return timeFormatted;
}