#include <SFML/Graphics.hpp>
#include <iostream>
#include <box2d/box2d.h>
using namespace sf;
using namespace std;
class player
{
private:

public:
    Image image_player;
    Texture texture_player;
    Sprite sprite_player;
    const char *way_to_sprite;
    float position_x,position_y,width_charcter,height_charcter;
    float x = sprite_player.getPosition().x;
    float y = sprite_player.getPosition().y;
    float position_player_x; 
    float position_player_y;
    player(const char *way,float x,float y,float width,float height,float pos_x,float pos_y){
        position_x = x;
        position_y = y;
        width_charcter = width;
        height_charcter = height;
        way_to_sprite = way;
        position_player_x = pos_x;
        position_player_y = pos_y;
    }
    void draw(){
        image_player.loadFromFile(way_to_sprite);
        texture_player.loadFromImage(image_player);
        sprite_player.setTexture(texture_player);
        // sprite_player.setTextureRect(IntRect(0,0,width_charcter,height_charcter)); // ширина - 716 высота - 1065 716/5 = 143.2 1065 / 7 = 152.14
        sprite_player.setOrigin(width_charcter / 2, height_charcter/ 2);
        sprite_player.setPosition(position_player_x,position_player_y);

    }
};