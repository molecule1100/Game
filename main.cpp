#include <SFML/Graphics.hpp>
#include <game.hpp>


using namespace sf;
using namespace mr;
using namespace std;


int main()
{
    setlocale(LC_ALL, "Ru");

    // создаем окно игры
    RenderWindow game(VideoMode(640, 480), "Game");
    game.setFramerateLimit(60);

    // задаем текстуры
    Texture t1, t2;
    t1.loadFromFile("C:\\213\\images\\back.png");
    t2.loadFromFile("C:\\213\\images\\car.png");
    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite spriteBackground(t1), spriteCar(t2);
    spriteBackground.scale(2, 2);
    spriteCar.setOrigin(-1, -1);

    // создаем машинку и ее характеристики
    Game car(0, 0, 0, 2);

    float x = car.getX();
    float y = car.getY();
    float speed = car.getSpeed();
    float angle = car.getAngle();

    float maxSpeed = 12.0;
    float accel = 0.2, decel = 0.3;
    float turnSpeed = 0.065;

    // смещение по X и Y
    int offsetX = 0, offsetY = 0;

    while (game.isOpen())
    {
        Event event;
        while (game.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                game.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    game.close();
                break;
            }
        }

        // задаем кнопки управления машинкой (стрелочки)

        bool Up = 0, Right = 0, Down = 0, Left = 0;

        if (Keyboard::isKeyPressed(Keyboard::Up))
            Up = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right))
            Right = 1;
        if (Keyboard::isKeyPressed(Keyboard::Down))
            Down = 1;
        if (Keyboard::isKeyPressed(Keyboard::Left))
            Left = 1;


        // движение вперед
        if (Up && speed < maxSpeed)
        {
            if (speed < 0)
                speed += decel;
            else
                speed += accel;
        }

        // движение назад
        if (Down && speed > -maxSpeed)
        {
            if (speed > 0)
                speed -= decel;
            else
                speed -= accel;
        }

        // неподвижное стояние
        if (!Up && !Down)
        {
            if (speed - decel > 0)
                speed -= decel;
            else if (speed + decel < 0)
                speed += decel;
            else
                speed = 0;
        }

        // движение направо или налево
        if (Right && speed != 0)
            angle += turnSpeed * speed / maxSpeed;
        if (Left && speed != 0)
            angle -= turnSpeed * speed / maxSpeed;

        // движение машинки

        car.setSpeed(speed);
        car.setAngle(angle);

        x += sin(angle) * speed;
        y -= cos(angle) * speed;

        game.clear(Color::White);
        game.draw(spriteBackground);

        // бекграунд передивагается зависимо от положения машинки
        if (x > 320)
            offsetX = x - 320;
        if (y > 240)
            offsetY = y - 240;

        spriteBackground.setPosition(-offsetX, -offsetY);
        game.draw(spriteBackground);

        spriteCar.setPosition(x - offsetX, y - offsetY);

        // перевод из радиан в градусы
        spriteCar.setRotation(angle * 180 / 3.141593);
        spriteCar.setColor(Color::Green);
        game.draw(spriteCar);

        game.display();

    }

    return 0;
}