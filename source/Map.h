/*
 * IDENTIFICATION 
 * File: Map.h 
 * Module: Environment
 * 
 * DESCRIPTION
 * This class handles, aggregates, all environment objects
 * that exist on a map. 
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "Environment.h"

class Map
{
public:
    Map() = default;
    Map(std::vector<std::unique_ptr<Environment>>&);

    void create_environment(std::string type, int xp, int yp, int xs, int ys);
    std::vector<std::unique_ptr<Environment>>& get_environments();
    void set_environments(std::vector<std::unique_ptr<Environment>>&);
    void add_environment(std::unique_ptr<Environment>);
    
private:
    std::vector<std::unique_ptr<Environment>> environments {};

};

#endif
