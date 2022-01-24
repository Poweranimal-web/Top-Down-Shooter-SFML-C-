#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class bullet
{
private:
    /* data */
public:
    Image image_bullet[1000];
    Texture texture_bullet[1000];
    Sprite sprite_bullet[1000];
    
    void draw(){
       image_bullet[click].loadFromFile("D:/C++/texture/bullet.png");
       image_bullet[click].createMaskFromColor(sf::Color(0, 0, 0));
       texture_bullet[click].loadFromImage(image_bullet[click]);
       sprite_bullet[click].setTexture(texture_bullet[click]);
       sprite_bullet[click].setOrigin(16/2,16/2);
       distance_patron[click] = sqrt(pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x- sprite_bullet[click].getPosition().x,2)+pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y - sprite_bullet[click].getPosition().y,2));

    }    
};

