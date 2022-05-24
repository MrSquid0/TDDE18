#include "Time.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Time operator +(Time& time, int sec){
    time.sec += sec;
    formatTime(time);
    return time;
}

Time operator -(Time& time, int sec){
    time.sec -= sec;
    formatTime(time);
    return time;
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
    }
    return false;
}

bool operator != (Time const& time1, Time const& time2){
    if (time1 == time2){
        return false;
    }
    return true;
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
    }
    return false;
}

bool operator >=(Time const& time1, Time const& time2){
    if (time1 == time2){
        return true;
    } else if (time1 > time2){
        return true;
    }
    return false;
}

bool operator <(Time const& time1, Time const& time2){
    if (time2 > time1){
        return true;
    }
    return false;
}

bool operator <=(Time const& time1, Time const& time2){
    if (time1 == time2){
        return true;
    } else if (time1 < time2){
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, Time const& time){
    os << printTime(time);
}

std::istream& operator>>(std::istream& in, Time& time){
    std::cout << "Enter the hour:" ;
    in >> time.hour;
    std::cout << "\nEnter the minute:" ;
    in >> time.min;
    std::cout << "\nEnter the second:" ;
    in >> time.sec;
    if(isValid(time)){
        std::cin.setstate(std::ios_base::goodbit);
    } else {
        std::cin.setstate(std::ios_base::failbit);
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
std::string to_string(Time& time, bool isTwelveClock) {
    std::string timeFormatted{};
    if (isValid(time)) {
        if (isTwelveClock == true){
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
        } else{
            return printTime(time);
        }

    } else {
        return "Time is not valid.";
    }
}

std::string printTime(Time const& time){
    std::string timeFormatted{};
    if ((time.hour == 0) || (time.hour >= 1 && time.hour <= 9)) {
        timeFormatted = "0";
    }
    timeFormatted += std::to_string(time.hour) + ":";

    if (time.min >= 0 && time.min <= 9) {
        timeFormatted += "0";
    }
    timeFormatted += std::to_string(time.min) + ":";

    if (time.sec >= 0 && time.sec <= 9) {
        timeFormatted += "0";
    }
    timeFormatted += std::to_string(time.sec);
    return timeFormatted;
}

Time formatTime(Time& time) {
    while(time.sec >= 60){
        time.sec -= 60;
        time.min += 1;
        while(time.min >= 60){
            time.min -= 60;
            time.hour += 1;
            if(time.hour >= 24){
                time.hour -= 24;
            }
        }
    }

    while(time.sec < 0){
        time.sec += 60;
        time.min -= 1;
        while(time.min < 0){
            time.min += 60;
            time.hour -= 1;
            if(time.hour < 0){
                time.hour += 24;
            }
        }
    }
}