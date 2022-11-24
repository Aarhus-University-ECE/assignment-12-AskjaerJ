#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("time") {
    duration test;
    duration timeset(10);
    REQUIRE(test.getDuration() == 0);
    REQUIRE(timeset.getDuration() == 10);
}
TEST_CASE("tick+1") {
    duration add;
    add.tick();
    REQUIRE(add.getDuration() == 1);
}
TEST_CASE("tick") {
    duration add0;
    duration add5(0);
    duration add20(0);
    REQUIRE(add0.getDuration() == 0);
    add5.tick(5);
    REQUIRE(add5.getDuration() == 5);
    add20.tick(20);
    REQUIRE(add20.getDuration() == 20);
    duration alarm(10);
    alarm.setAlarm(20);
    REQUIRE(alarm.tick() == false);
    REQUIRE(alarm.tick(12) == true);
    
}