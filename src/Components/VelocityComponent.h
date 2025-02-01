#pragma once

struct VelocityComponent {
    float dx;
    float dy;

    VelocityComponent(float dx = 0.f, float dy = 0.f) : dx(dx), dy(dy) {}
};
