 

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

int add(int a, int b) {
    return (a + b);
}

TEST_CASE( "add two integers", "[sum]" ) {
    
    REQUIRE(add(2, 2) == 4);
    REQUIRE(add(0,1) == 1);
    
}

