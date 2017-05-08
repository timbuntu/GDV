/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drone.h
 * Author: tim
 *
 * Created on 3. Mai 2017, 13:07
 */

#ifndef DRONE_H
#define DRONE_H

#include <GL/freeglut.h> 
#include "Vector.h"

class Drone {
public:
    Drone();
    virtual ~Drone();
    
    void move(Vector movement);
    void addImpulse(Vector impulse);
    void draw() const;
    void step();
private:
    Vector position;
    Vector impulse;
    float rotorRotation;

};

#endif /* DRONE_H */
