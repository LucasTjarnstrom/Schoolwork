/*
 * Map.cc
 */

#include "Map.h"
#include "Floor.h"
#include "Wall.h"
#include "Ceiling.h"
#include "Coin.h"
#include "Weapon.h"
#include <vector>
#include <memory>

using namespace std;

Map::Map(vector<std::unique_ptr<Environment>>& ve)
    : environments {move(ve)}
{
} 

void Map::create_environment(std::string type, int xp, int yp, int xs, int ys)
{
    if (type == "floor")
    {
	unique_ptr<Floor> temp = make_unique<Floor> (xp,yp,xs,ys,"resources/floor2.png");
	add_environment(move(temp));
    }
    else if (type == "floor_100px")
    {
	unique_ptr<Floor> temp = make_unique<Floor> (xp,yp,xs,ys,"resources/floor_100px.png");
	add_environment(move(temp));
    }
    else if (type == "floor_1280px")
    {
	unique_ptr<Floor> temp = make_unique<Floor> (xp,yp,xs,ys,"resources/floor_1280px.png");
	add_environment(move(temp));
    }
    else if (type == "floor_filler")
    {
	unique_ptr<Floor> temp = make_unique<Floor> (xp,yp,xs,ys,"resources/floor_filler.png");
	add_environment(move(temp));
    }
    else if (type == "wall")
    {
	unique_ptr<Wall> temp = make_unique<Wall> (xp,yp,xs,ys,"resources/wall2.png");
	add_environment(move(temp));
    }
    else if (type == "wall_100px")
    {
	unique_ptr<Wall> temp = make_unique<Wall> (xp,yp,xs,ys,"resources/wall_100px.png");
	add_environment(move(temp));
    }
    else if (type == "wall_20px")
    {
	unique_ptr<Wall> temp = make_unique<Wall> (xp,yp,xs,ys,"resources/wall_20px.png");
	add_environment(move(temp));
    }
    else if (type == "ceiling")
    {
	unique_ptr<Ceiling> temp = make_unique<Ceiling> (xp,yp,xs,ys,"resources/floor2.png");
	add_environment(move(temp)); 
    }
    else if (type == "coin")
    {
	unique_ptr<Coin> temp = make_unique<Coin> (xp,yp,xs,ys,"resources/coin.png");
	add_environment(move(temp));  
    }
    else if (type == "weapon")
    {
	unique_ptr<Weapon> temp = make_unique<Weapon> (xp,yp,xs,ys,"resources/weapon.png");
	add_environment(move(temp));  
    }
    else
    {
	throw logic_error("Trying to create environment of invalid type");
    }
}

vector<std::unique_ptr<Environment>>& Map::get_environments()
{
    return environments;
}

void Map::set_environments(std::vector<std::unique_ptr<Environment>>& other)
{
    environments = move(other);
}
void Map::add_environment(std::unique_ptr<Environment> e)
{
    environments.push_back(move(e));
}

