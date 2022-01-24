#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class cursor
{
private:
    /* data */
public:
    Image image_cursor;
    Texture texture_cursor;
    Sprite sprite_cursor;
    const char *way_to_cursor;
    float position_x,position_y,width_cursor,height_cursor;
    cursor(const char *way,float x,float y,float width,float height){
        way_to_cursor = way;
        position_x = x;
        position_y = y;
        width_cursor = width;
        height_cursor = height;

    };
    void draw(){
        image_cursor.loadFromFile(way_to_cursor);
        texture_cursor.loadFromImage(image_cursor);
        sprite_cursor.setTexture(texture_cursor);
        sprite_cursor.setOrigin(width_cursor / 2, height_cursor/ 2);
        // sprite_cursor.setPosition(position_x,position_y);

    }
    
};
