
#ifndef DRONE_H
#define DRONE_H

#include <GL/freeglut.h> 
#include "Vector.h"

#define DRONE_RADIUS 0.5

class Drone {
public:
    
    Drone();
    
    //Drohne auf einmal Bewegen
    void move(Vector movement);
    //Bewegungsimpuls geben
    void addImpulse(Vector impulse);
    //Drohne zeichnen
    void draw() const;
    //Werte für nächsten Animationsschritt berechnen
    void step();
    
    //Setter und Getter für Rotationsgeschwindigkeit des Rotors
    void setRotorRotationSpeed(float speed);
    float getRotorRotationSpeed() const;
private:
    //Position der Drohne
    Vector position;
    //Aktueller Bewegungsimpuls
    Vector impulse;
    //Rotation des Rotors
    float rotorRotation;
    //Rotationsgeschwindigkeit des Rotors
    float rotorRotationSpeed;

};

#endif /* DRONE_H */

