/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Drone.cpp
 * Author: tim
 * 
 * Created on 3. Mai 2017, 13:07
 */

#include <GL/gl.h>

#include "Drone.h"
#include "Vector.h"

Drone::Drone() 
: position(0, 0, 0), impulse(0, 0, 0), rotorRotation(0), rotorRotationSpeed(25)
{
    
}

Drone::~Drone() {
}

void Drone::move(Vector movement) {
    position += movement;
}

void Drone::addImpulse(Vector impulse) {
    this->impulse += impulse;
}

void Drone::draw() const {
    
    glPushMatrix();
    
    glTranslatef(position.getX(), position.getY(), position.getZ());
    
    glColor4f(0.9, 0, 0, 1);
    glutSolidSphere(DRONE_RADIUS, 25, 25);
    
    glRotatef(rotorRotation, 0, 1, 0);
    glTranslatef(0.1, DRONE_RADIUS, 0);
    glColor4f(0, 0.7, 0, 1);
    
    glPushMatrix();
    
    glRotatef(90, 1, 0, 0);
    glScalef(2, 2, 2);
    
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.1, 0, 0);
    glVertex3f(0, 0, -0.01);
    glVertex3f(0, 0.5, 0);
    glVertex3f(-0.1, 0, 0);
    glEnd();
    
    glPopMatrix();
    
    glTranslatef(-0.2, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 0, 1);
    glScalef(2, 2, 2);
    
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(-0.1, 0, 0);
    glVertex3f(0, 0, -0.01);
    glVertex3f(0, 0.5, 0);
    glVertex3f(-0.1, 0, 0);
    glEnd();
    
    glPopMatrix();
    
}

void Drone::step() {
    position += impulse;
    if(position.getY() < DRONE_RADIUS)
        position.setY(DRONE_RADIUS);
    
    rotorRotation -= rotorRotationSpeed;
    if(rotorRotation <= 0)
        rotorRotation += 360;
}

float Drone::getRotorRotationSpeed() const {
    return rotorRotationSpeed;
}

void Drone::setRotorRotationSpeed(float speed) {
    rotorRotationSpeed = speed;
}
