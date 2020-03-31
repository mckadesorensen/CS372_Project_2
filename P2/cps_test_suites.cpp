//
//  cps_test_suites.cpp
//  P2
//
//  Created by Chenyi Ling on 3/24/20.
//  Copyright © 2020 Chenyi Ling. All rights reserved.
//

#include "cps.h"
#include "cps.h"

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework
#include <string>
using std::string;
#include <iomanip>


// *****************
// Test Cases (in progress)
// *****************

TEST_CASE("TEST 1: Shape setup")
{
    Shape s1;
    s1.setHeight(1);
    s1.setWidth(2);
    INFO("Shape height");
    REQUIRE( s1.getHeight() == 1);

    INFO("Shape width");
    REQUIRE( s1.getWidth() == 2);
}

TEST_CASE("TEST 2: Cirle")
{
    Circle c1(2);
    c1.setHeight();
    c1.setWidth();
    
    INFO("Circle height");
    REQUIRE( c1.getHeight() == 4);
    
    INFO("Circle width");
    REQUIRE( c1.getWidth() == 4);

    INFO("Circle radius");
    REQUIRE( c1._radius == 2);
}


TEST_CASE("TEST 3: Polygon")
{
    Polygon p1(5,6);
    p1.setHeight();
    
    INFO("Polygon number of sides");
    REQUIRE(p1._numSides == 5);

    INFO("Polygon side length");
    REQUIRE(p1._sideLength == 6);
    
    INFO("Polygon height: number of side is odd");
    REQUIRE( p1.getHeight() == 4.18);

}
