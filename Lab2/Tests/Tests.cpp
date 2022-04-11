#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../Time.h"

Time t0{41,43,45};
Time t2{41,43,45};
Time t3{3,23,45};
Time t4{6,34,12};
Time t5{24,34,42};
Time t6{24,34,42};
Time t7{15, 23, 48};

TEST_CASE("All Testss") {
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

    SECTION("Time 3 should be lower than time 4")
    {
        CHECK_FALSE(t3 > t4);
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
}