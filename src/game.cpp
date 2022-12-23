#include <SFML/Graphics.hpp>
#include <game.hpp>

using namespace sf;

namespace mr
{
    float Game::getX()
    {
        return m_x;
    }

    float Game::getY()
    {
        return m_y;
    }

    float Game::getSpeed()
    {
        return m_speed;
    }

    float Game::getAngle()
    {
        return m_angle;
    }

    void Game::setSpeed(float speed)
    {
        m_speed = speed;
    }

    void Game::setAngle(float angle)
    {
        m_angle = angle;
    }
}
