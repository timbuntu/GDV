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
{}

//Drohne auf einmal Bewegen
void Drone::move(Vector movement) {
    position += movement;
}

//Bewegungsimpuls geben
void Drone::addImpulse(Vector impulse) {
    this->impulse += impulse;
}

//Drohne zeichnen
void Drone::draw() const {
    
    glPushMatrix();
    
    //Translation an aktuelle Position
    glTranslatef(position.getX(), position.getY(), position.getZ());
    
    //Körper der Drohne Zeichnen
    glColor4f(0.9, 0, 0, 1);                    //Rote Farbe
    glutSolidSphere(DRONE_RADIUS, 25, 25);      //Kugel zeichnen
    
    //Rotor
    glRotatef(rotorRotation, 0, 1, 0);          //Rotation
    glTranslatef(0.1, DRONE_RADIUS, 0);         //Position auf dem Körper
    glColor4f(0, 0.7, 0, 1);                    //Grüne Farbe
    
    glPushMatrix();
    
    //Rotorblatt 1
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
    
    //Rotorblatt 2
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

//Werte für nächsten Animationsschritt berechnen
void Drone::step() {
    //Neue Position berechnen
    position += impulse;
    //Nicht in den Boden bewegen
    if(position.getY() < DRONE_RADIUS)
        position.setY(DRONE_RADIUS);
    
    //Neuen Rotationswinkel des Rotors berechnen
    rotorRotation -= rotorRotationSpeed;
    if(rotorRotation <= 0)
        rotorRotation += 360;
}

//Getter für Rotationsgeschwindigkeit
float Drone::getRotorRotationSpeed() const {
    return rotorRotationSpeed;
}

//Setter für Rotationsgeschwindigkeit
void Drone::setRotorRotationSpeed(float speed) {
    rotorRotationSpeed = speed;
}
