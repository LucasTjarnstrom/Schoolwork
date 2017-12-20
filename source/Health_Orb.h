/*
 * Health_Orb.h
 */

#ifndef HEALTH_ORB_H
#define HEALTH_ORB_H

#include <string>
#include "Environment.h"

class Health_Orb : public Environment
{
public:
    Health_Orb(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;

    void set_health(int);
    int get_health() const;

private:
    int health {};
};

#endif
