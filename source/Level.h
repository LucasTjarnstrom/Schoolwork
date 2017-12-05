#include <SFML/Graphics.hpp>
#include <vector>
#include "Drawable.h"

class Level
{
public:
    Level(std::vector<Drawable*>&); // incomplete constructor, should also include map

    void draw_all() const;

private:
    std::vector<Drawable*> drawables {};

};
