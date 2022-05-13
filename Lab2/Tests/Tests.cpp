#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Time.h"

// DONE: Testing of + and - are still insufficient. You only ever test
// what happens when we add or subtract 1 second. What happens if we
// add more (way more)? See comment in Time.h for more details.

#include <iostream>

Time t0{41,43,45};
Time t2{41,43,45};
Time t3{3,23,45};
Time t4{6,34,12};
Time t5{24,34,42};
Time t6{24,34,42};
Time t7{15, 23, 48};
Time t8{23, 59, 59};
Time t9{0, 0, 0};
Time t10{1,1,1};
Time t12{19,12,56};

TEST_CASE("All Tests") {
    std::stringstream os;

    SECTION ("Time 3 should not be changed ")
    {
        os << t3;
        CHECK(os.str() == "03:23:45");
        os.str("");
        os << t3 + 0;
        CHECK(os.str() == "03:23:45");
    }

    SECTION ("Time 4 should not be changed adding a whole day in seconds")
    {
        os << t4;
        CHECK(os.str() == "06:34:12");
        os.str("");
        os << t4 + 86400;
        CHECK(os.str() == "06:34:12");
    }

    SECTION ("Time 4 should not be changed subtracting a whole day in seconds")
    {
        os << t4;
        CHECK(os.str() == "06:34:12");
        os.str("");
        os << t4 - 86400;
        CHECK(os.str() == "06:34:12");
    }
    SECTION ("Time 4 should be changed adding 70 seconds")
    {
        os << t4;
        CHECK(os.str() == "06:34:12");
        os.str("");
        os << t4 + 70;
        CHECK(os.str() == "06:35:22");
    }
    SECTION ("Time 4 should be changed subtracting 90 seconds")
    {
        os << t4;
        CHECK(os.str() == "06:35:22");
        os.str("");
        os << t4 - 90;
        CHECK(os.str() == "06:33:52");
    }
    SECTION ("Second 45 should be 46")
    {
        ++t0;
        CHECK(t0.sec == 46);
    }

    SECTION("Second 45 should be 44")
    {
        --t2;
        CHECK(t2.sec == 44);
    }

    SECTION ("Adding a second to time 8, it should be formatted "
             "to 00:00:00")
    {
        ++t8;
        CHECK (t8.hour == 0);
        CHECK (t8.min == 0);
        CHECK (t8.sec == 0);
    }

    SECTION ("Subtracting a second to time 9, it should be formatted "
             "to 23:59:59")
    {
        --t9;
        CHECK (t9.hour == 23);
        CHECK (t9.min == 59);
        CHECK (t9.sec == 59);
    }

    SECTION("Time 3 and time 4 should be not equal")
    {
        CHECK_FALSE(t3 == t4);
    }

    SECTION("Time 1 and time 2 should be equal")
    {
        CHECK(t5 == t6);
    }

    SECTION("Time 3 and time 4 should be different")
    {
        CHECK(t3 != t4);
    }

    SECTION("Time 5 and time 6 should not be different")
    {
        CHECK_FALSE(t5 != t6);
    }

    SECTION ("Time 4 should be higher that time 3")
    {
        CHECK (t4 > t3);
    }

    SECTION("Time 3 should be lower than time 4")
    {
        CHECK(t3 < t4);
    }

    SECTION("Time 3 should neither be higher nor equal than time 4")
    {
        CHECK_FALSE(t3 >= t4);
    }

    SECTION("Time 4 should be higher than time 3")
    {
        CHECK(t3 < t4);
    }

    SECTION("Time 5 should be the same as time 6")
    {
        CHECK(t5 <= t6);
    }

    SECTION("Hour 24 should not be valid")
    {
        CHECK_FALSE(isValid(t5));
    }

    SECTION("Hour 41 should not be valid")
    {
        CHECK_FALSE(isValid(t0));
    }

    SECTION("Hour 6 should be valid")
    {
        CHECK(isValid(t4));
    }

    SECTION("Time '15:23:48' should be '03:23:48 pm' in 12 clock format")
    {
        CHECK(to_string(t7, 12) == "03:23:48 pm");
    }

    SECTION("Time '41:43:45' should be not valid if we try to convert it "
            "into 12 clock format")
    {
        CHECK (to_string(t0, 12) == "Time is not valid.");
    }

    SECTION("Time '15:23:48' should not be AM")
    {
        CHECK_FALSE(is_am(t7));
    }

    SECTION("Time '6:34:12' should be AM")
    {
        CHECK(is_am(t4));
    }

    SECTION ("Time 12 should be outputted properly")
    {
        os.str("");
        os << t12;
        CHECK (os.str() == "19:12:56");
    }

    SECTION ("Time 11 should have the proper inputted time")
    {
        Time t11{};
        std::istringstream is("13 45 21");
        std::cin.rdbuf(is.rdbuf());

        std::cin >> t11;
        os << t11;

        CHECK ((os.str()) == "13:45:21");
    }
}
