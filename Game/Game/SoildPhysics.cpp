#include "SoildPhysics.h"


SoildPhysics::SoildPhysics()
{
}


SoildPhysics::~SoildPhysics()
{
}
glm::vec3 SoildPhysics::Velocity() {
    //Do some maths here
    return answer;
}

float SoildPhysics::Gravity(float mass1, float mass2, float distance) {
    newtons = (6.67408 × 10-11)*((mass1* mass2)/distance^2);
    return newtons;   
}
