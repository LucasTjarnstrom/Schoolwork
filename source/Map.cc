/*
 * Map.cc
 */

#include "Map.h"
#include <vector>
#include <memory>

using namespace std;

Map::Map(vector<std::unique_ptr<Environment>>& ve)
    : environments {move(ve)}
{
} 

vector<std::unique_ptr<Environment>>& Map::get_environments()
{
    return environments;
}

void Map::set_environments(std::vector<std::unique_ptr<Environment>>& other)
{
    environments = move(other);
}
void Map::add_environment(std::unique_ptr<Environment> & e)
{
    environments.push_back(move(e));
}

