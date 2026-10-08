#include "RoboticArm.h"

RoboticArm::RoboticArm(double x, double y, double z, bool sujetando)
    : x(x), y(y), z(z), sujetando(sujetando) {
}

double RoboticArm::getX() {
    return x;
}

double RoboticArm::getY() {
    return y;
}

double RoboticArm::getZ() {
    return z;
}

bool RoboticArm::getSujetando() {
    return sujetando;
}

void RoboticArm::grab() {
    sujetando = true;
}

void RoboticArm::release() {
    sujetando = false;
}

void RoboticArm::move(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
