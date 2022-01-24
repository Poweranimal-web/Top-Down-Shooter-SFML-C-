#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
using namespace sf;
using namespace std;
class word
{
private:
    /* data */
public:
Font font;
Font font2;
Font font3;
Font font4;
Text text;
Text text2;
Text text3;
Text text4;
void draw_codinate_player_x(){ 
     font.loadFromFile("D:/C++/texture/sfns-display-bold.ttf");
     text.setFont(font);
     text.setCharacterSize(10);
     text.setFillColor(Color::Black);
     text.setStyle(Text::Bold);
}
void draw_codinate_player_y(){ 
     font2.loadFromFile("D:/C++/texture/sfns-display-bold.ttf");
     text2.setFont(font2);
     text2.setCharacterSize(10);
     text2.setFillColor(Color::Black);
     text2.setStyle(Text::Bold);
}
void draw_FPS(){
     font3.loadFromFile("D:/C++/texture/sfns-display-bold.ttf");
     text3.setFont(font3);
     text3.setCharacterSize(10);
     text3.setFillColor(Color::Black);
     text3.setStyle(Text::Bold);
}
void draw_Rotate(){
     font4.loadFromFile("D:/C++/texture/sfns-display-bold.ttf");
     text4.setFont(font4);
     text4.setCharacterSize(10);
     text4.setFillColor(Color::Black);
     text4.setStyle(Text::Bold);
}
};


