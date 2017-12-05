#include "Level.h"
#include <vector>

Level::Level(std::vector<Drawable*>& dr)
    : drawables {dr}
{
}

void Level::draw_all() const
{
    for(auto const& dr : drawables)
    {
	dr->draw_this();
    }
}
