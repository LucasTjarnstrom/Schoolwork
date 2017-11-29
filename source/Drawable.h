/*
 * Drawable.h
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <string>

class Drawable
{
public:
    Drawable() = default;                       // default constructor
    virtual ~Drawable() = default;              // destructor
    Drawable(double,double,double,double,std::string);      // constructor 
    //Drawable(Drawable const & dr)               // copy constructor
    //Drawable(Drawable && dr);                   // move constructor
    //Drawable& operator= (Drawable const & it);  // copy assignment
    //Drawable& operator= (Drawable && it);       // move assignment
    
    // Position
    virtual double get_x_pos() const;
    virtual void set_x_pos(double);
    virtual double get_y_pos() const;
    virtual void set_y_pos(double);
    // Velocity, acceleration
    virtual double get_x_velocity() const;
    virtual void set_x_velocity(double);
    virtual double get_y_velocity() const;
    virtual void set_y_velocity(double);
    virtual double get_y_acc() const;
    virtual void set_y_acc(double);
    // Size
    virtual double get_x_size() const;
    virtual void set_x_size(double);
    virtual double get_y_size() const;
    virtual void set_y_size(double);

    virtual sf::Sprite& get_sprite();

    //virtual void draw_this(canvas) = 0;

protected:
    double x_pos {};
    double y_pos {};
    double x_velocity {0};
    double y_velocity {0};
    double y_acc {0.05}; // där g ska vara tyngdkonstanten av något slag i negativ y, fys. kord.p.
    double x_size {};
    double y_size {};
    sf::Texture texture {};
    sf::Sprite sprite {}; // en datamedlem av typen sprite som heter sprite
};

#endif
