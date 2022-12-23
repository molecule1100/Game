#include <SFML/Graphics.hpp>
#include <game.hpp>

using namespace sf;

struct Car
{
    float x, y, speed, angle;

    Car()
    {
        x = 0; y = 0;
        speed = 2; angle = 0;
    }

    void move()
    {
        x += sin(angle) * speed;
        y -= cos(angle) * speed;
    }
};

