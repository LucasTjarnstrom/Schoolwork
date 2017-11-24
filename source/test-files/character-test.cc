/*
 * character-test.cc
 */

#include "catch.hpp"
#include "../Character.h"

using namespace std;

TEST_CASE("Constructing Character")
{
    Character c {};
    Character c1(12);

    CHECK(c.get_vitality() == 0);
    CHECK(c1.get_vitality() == 12);
    CHECK(c.get_current_health() == 0);
    CHECK(c1.get_current_health() == 0);
    
}
