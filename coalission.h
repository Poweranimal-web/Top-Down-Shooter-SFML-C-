#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class coalission
{
private:
    /* data */
public:
sf::RectangleShape rectangle;
sf::RectangleShape rectangle2;
sf::RectangleShape rectangle3;
sf::RectangleShape rectangle4;
sf::RectangleShape rectangle5;
sf::RectangleShape rectangle6;
void draw_colission(){
    rectangle.setSize(sf::Vector2f(274, 10));
    rectangle.setFillColor(Color::Transparent);
    rectangle.setPosition(400,501);
    rectangle2.setSize(sf::Vector2f(10,334));
    rectangle2.setFillColor(Color::Transparent);
    rectangle2.setPosition(400,511);
    rectangle3.setSize(sf::Vector2f(10,334));
    rectangle3.setFillColor(Color::Transparent);
    rectangle3.setPosition(664,511);
    rectangle4.setSize(sf::Vector2f(90,10));
    rectangle4.setFillColor(Color::Transparent);
    rectangle4.setPosition(400,845);
    rectangle5.setSize(sf::Vector2f(80,10));
    rectangle5.setFillColor(Color::Transparent);
    rectangle5.setPosition(594,845);
    rectangle6.setSize(sf::Vector2f(254, 10));
    rectangle6.setFillColor(Color::Transparent);
    rectangle6.setPosition(410,800);
}

};

