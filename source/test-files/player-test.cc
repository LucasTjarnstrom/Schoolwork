/*
 * player-test.cc
 */

#include "catch.hpp"
#include "../Player.h"

using namespace std;

TEST_CASE("Constructing Player")
{
    Player c {};
    Player c1 (12);
    
    CHECK(c.get_vitality() == 0);
    CHECK(c1.get_vitality() == 12);
    CHECK(c.get_current_health() == 0);
    CHECK(c1.get_current_health() == 0);

    c.set_vitality(99);

    CHECK(c.get_vitality() == 99);    
}
