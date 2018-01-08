/*
 * IDENTIFICATION 
 * File: Environment.h 
 * Module: Environment
 * 
 * DESCRIPTION
 * This class acts as an pure virtual superclass to
 * all other, realizable, environment classes.
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include "Drawable.h"

class Environment : public Drawable
{
public:
    Environment(double,double,double,double, std::string);

};

#endif
