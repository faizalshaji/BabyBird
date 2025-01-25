#pragma once

struct VelocityComponent {
    float dx;
    float dy;

    VelocityComponent(float x = 0.f, float y = 0.f) : dx(x), dy(y) {}
};
