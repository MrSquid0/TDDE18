#include "Time.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string operator +(Time& time, int sec){
    Time timeChanged{time};
    timeChanged.sec += sec;
    formatTime(timeChanged);
    return printTime(timeChanged);
}

string operator -(Time& time, int sec){
    Time timeChanged{time};
    timeChanged.sec -= sec;
    formatTime(timeChanged);
    return printTime(timeChanged);
}

Time& operator ++(Time& time){
    time.sec++;
    formatTime(time);
}

Time operator ++(Time& time, int){
    ++time.sec;
    formatTime(time);
}

Time& operator --(Time& time){
    time.sec--;
    formatTime(time);
}

Time operator --(Time& time, int){
    --time.sec;
    formatTime(time);
}

bool operator ==(Time const& time1, Time const& time2){
    if ((time1.hour == time2.hour) && (time1.min == time2.min) &&
        (time1.sec == time2.sec)) {
        return true;
    } else {
        return false;
    }
}

bool operator != (Time const& time1, Time const& time2){
    if (time1 == time2){
        return false;
    } else {
        return true;
    }
}

bool operator >(Time const& time1, Time const& time2){
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

bool operator >=(Time const& time1, Time const& time2){
    if (time1 == time2){
        return true;
    } else if (time1 > time2){
        return true;
    } else {
        return false;
    }
}

bool operator <(Time const& time1, Time const& time2){
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

bool operator <=(Time const& time1, Time const& time2){
    if (time1 == time2){
        return true;
    } else if (time1 < time2){
        return true;
    } else {
        return false;
    }
}

ostream& operator<<(ostream& os, Time const& time){
    os << printTime(time);
}

istream& operator>>(istream& in, Time& time){
    in >> time.hour;
    in >> time.min;
    in >> time.sec;
    if(isValid(time)){
        cin.setstate(ios_base::goodbit);
    } else {
        cin.setstate(ios_base::failbit);
    }
    return in;
}


bool isValid (Time const& time){

    if (((time.hour >=0) && (time.hour <=23)) &&
        ((time.min >=0) && (time.min <=59)) &&
        ((time.sec >=0) && (time.sec <=59))){
        return true;
    } else {
        return false;
    }
}

bool is_am(Time const& time) {
    if (time.hour >= 0 && time.hour <= 11) {
        return true;
    } else {
        return false;
    }
}

//Comment: Nice that you reuse printTime!
string to_string(Time& time, int clock) {
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

string printTime(Time const& time){
    string timeFormatted{};
    if ((time.hour == 0) || (time.hour >= 1 && time.hour <= 9)) {
        timeFormatted = "0";
    }
    timeFormatted += to_string(time.hour) + ":";

    if (time.min >= 0 && time.min <= 9) {
        timeFormatted += "0";
    }
    timeFormatted += to_string(time.min) + ":";

    if (time.sec >= 0 && time.sec <= 9) {
        timeFormatted += "0";
    }
    timeFormatted += to_string(time.sec);
    return timeFormatted;
}

Time formatTime(Time& time) {
        if (time.sec == 60){
            time.sec = 0;
            time.min++;
            if (time.min == 60){
                time.min = 0;
                time.hour++;
                if (time.hour == 24){
                    time.hour = 0;
                }
            }
        }
        else if (time.sec == -1)
        {
            time.sec = 59;
            time.min--;
            if (time.min == -1){
                time.min = 59;
                time.hour--;
                if (time.hour == -1){
                    time.hour = 23;
                }
            }
        }
}