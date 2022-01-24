#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
const int Height_map = 50;
const int Width_map = 25;
sf::String Tilemap[Height_map]={
    "0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",

};
class maps
{
private:
	/* data */
public:
Image image_map;
Texture texture_map;
sf::Sprite sprite_map;
void draw(){
image_map.loadFromFile("D:/C++/texture/1625487354_18-kartinkin-com-p-kamen-piksel-art-art-krasivo-211.jpg");
texture_map.loadFromImage(image_map);
sprite_map.setTexture(texture_map);
}
};
class home
{
private:
	/* data */
public:
Image image_home;
Texture texture_home;
Sprite sprite_home;
void draw(){
image_home.loadFromFile("D:/C++/texture/my_sweet_home 2.png");
texture_home.loadFromImage(image_home);
sprite_home.setTexture(texture_home);
}
};


