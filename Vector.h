/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VEctor.h
 * Author: tim
 *
 * Created on 3. Mai 2017, 14:16
 */

#ifndef VECTOR_H
#define VECTOR_H

//Simple Vektor-Klasse
class Vector {
public:
    Vector();
    Vector(float x, float y, float z);
    Vector(const Vector& orig);
    Vector operator+(Vector& other);
    Vector& operator+=(Vector& other);
    
    float getX() const;
    float getY() const;
    float getZ() const;
    
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    void set(float x, float y, float z);
private:
    float x, y, z;

};

#endif /* VECTOR_H */

