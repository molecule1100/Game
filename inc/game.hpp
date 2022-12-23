#pragma once

#include <SFML/Graphics.hpp>


namespace mr
{
    class Game
    {
    private:
        float m_x = 0, m_y = 0, m_angle = 0, m_speed = 2;

    public:
        Game(float x, float y, float angle, float speed)
        {
            m_x = x;
            m_y = y;
            m_angle = angle;
            m_speed = speed;
        }
        ~Game()
        {

        }

        float getX();

        float getY();

        float getSpeed();

        float getAngle();

        void setSpeed(float speed);

        void setAngle(float angle);
    };
}