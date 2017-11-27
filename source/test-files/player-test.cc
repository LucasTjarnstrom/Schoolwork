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
    
    CHECK(c.get_x_pos() == 0);
    CHECK(c.get_y_pos() == 0);
    CHECK(c.get_x_size() == 0);
    CHECK(c.get_y_size() == 0);
    
    Player p (12,13,14,15);
    CHECK(p.get_x_pos() == 12);
    CHECK(p.get_y_pos() == 13);
    CHECK(p.get_x_size() == 14);
    CHECK(p.get_y_size() == 15);
    
}
