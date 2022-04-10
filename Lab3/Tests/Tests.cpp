// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../sortedList.h"

sortedList getList(){
    sortedList list{};
    list.insert(5);
    list.insert(3);
    return list;
};

//=======================================================================
// Test cases
//=======================================================================


TEST_CASE( "Create an empty list" ) {
    sortedList list{};

    SECTION("List should be empty")
    {
        REQUIRE(list.isEmpty() == true);
    }

    SECTION("Constructor should work well")
    {
        REQUIRE(list.getSize() == 0);
    }

    SECTION("isEmpty and getSize should work well")
    {
        REQUIRE(list.isEmpty());
        list.insert(3);
        list.insert(6);
        list.insert(1);
        list.insert(8);
        list.remove(0);
        list.remove(0);
        list.remove(0);
        CHECK_FALSE(list.isEmpty());
        CHECK(list.getSize() == 1);
    }

    SECTION("insert and printList should work well")
    {
        REQUIRE(list.isEmpty());
        list.insert(3);
        list.insert(6);
        list.insert(1);
        list.insert(8);
        CHECK(list.printList() == "1 -> 3 -> 6 -> 8 -> NULL.");
    }

    SECTION("insert, remove and printList should work well")
    {
        REQUIRE(list.isEmpty());
        list.insert(3);
        list.insert(6);
        list.insert(1);
        list.insert(8);
        CHECK(list.printList() == "1 -> 3 -> 6 -> 8 -> NULL.");
        list.remove(2); //Deleting number 6 (position 2)
        CHECK(list.printList() == "1 -> 3 -> 8 -> NULL.");
    }

    SECTION("printList should work well")
    {
        CHECK ((list.printList()) == "NULL.");
    }

    SECTION("Function 'at' should work as it is supposed")
    {
        list.insert(4);
        CHECK_FALSE(list.at(0) == 1);
        list.insert(1);
        CHECK(list.at(0) == 1);
        CHECK(list.at(1) == 4);
    }

    SECTION("Function 'at' should return -1 when the list is empty")
    {
        CHECK(list.at(1) == -1);
        CHECK(list.at(0) == -1);
    }

    SECTION("Function 'at' should return the first element of the list"
            " when the index does not exist and the list is not empty")
    {
        list.insert(4);
        list.insert(1);
        CHECK(list.at(3) == 1);
    }

    SECTION("Copy constructor should work well")
    {
        list.insert(7);
        list.insert(3);
        sortedList listTwo{list};
        CHECK ((listTwo.printList()) == "3 -> 7 -> NULL.");
    }

    SECTION("Copy assignment operator should work well")
    {
        list.insert(3);
        list.insert(5);
        sortedList listTwo {};
        listTwo = list;
        CHECK ((listTwo.printList()) == "3 -> 5 -> NULL.");
    }

    SECTION("Move constructor should work well")
    {
        sortedList listTwo{getList()};
        CHECK ((listTwo.printList()) == "3 -> 5 -> NULL.");
    }

    SECTION("Move assignment operator should work well")
    {
        sortedList listTwo {};
        listTwo = getList();
        CHECK ((listTwo.printList()) == "3 -> 5 -> NULL.");
    }
}