
#include "Vector.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(const Vector& orig) {
    this->x = orig.x;
    this->y = orig.y;
    this->z = orig.z;
}

Vector Vector::operator+(Vector& other) {
    Vector result(this->x + other.x, this->y + other.y, this->z + other.z);
    return result;
}

Vector& Vector::operator +=(Vector& other) {
    *this = *this + other;
    return *this;
}

float Vector::getX() const {
    return x;
}

float Vector::getY() const {
    return y;
}

float Vector::getZ() const {
    return z;
}

void Vector::setX(float x) {
    this->x = x;
}

void Vector::setY(float y) {
    this->y = y;
}

void Vector::setZ(float z) {
    this->z = z;
}

void Vector::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
