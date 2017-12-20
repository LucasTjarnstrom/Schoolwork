/*
 * Coin.h
 */

#ifndef COIN_H
#define COIN_H

#include <string>
#include "Environment.h"

class Coin : public Environment
{
public:
    Coin(double,double,double,double, std::string);

    sf::Sprite draw_this() override;
    void is_colliding(std::string) override;

    void set_score(int);
    int get_score() const;

private:
    int score {};
};

#endif
