/*
 * Drawable.h
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

//#include<canvas>
//#include<sprite>

class Drawable
{
public:
    Drawable() = default;                       // default constructor
    virtual ~Drawable() = default;              // destructor
    Drawable(int,int,int,int,sprite);           // constructor
    Drawable(Drawable const & dr)               // copy constructor
    Drawable(Drawable && dr);                   // move constructor
    Drawable& operator= (Drawable const & it);  // copy assignment
    Drawable& operator= (Drawable && it);       // move assignment

    int get_x_pos() const;
    void set_x_pos(int);
    int get_y_pos() const;
    void set_y_pos(int);
    int get_x_velocity() const;
    void set_x_velocity(int);
    int get_y_velocity() const;
    void set_y_velocity();
    // int get_y_acc() const;
    void set_y_acc(int);
    int get_x_size() const;
    void set_x_size(int);
    int get_y_size() const;
    void set_y_size(int);

    virtual void draw_this(canvas) = 0;

protected:
    int x_pos {};
    int y_post {};
    int x_velocity {0};
    int y_velocity {0};
    int y_acc {g}; // där g ska vara tyngdkonstanten av något slag i negativ y, fys. kord.p.
    int x_size {};
    int y_size {};
    sprite sprite; // en datamedlem av typen sprite som heter sprite
}

#endif
