#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <iostream>
#include <D:/C++/Game/player.h>
#include <D:/C++/Game/cursor.h>
#include <D:/C++/Game/map.h>
// #include <D:/C++/C++_code/bullet.h>
#include <D:/C++/Game/text.h>
#include <windows.h>
#include <D:/C++/Game/timer.h>
#include <D:/C++/Game/coalission.h>
#include <sstream>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1280,900),"game");
SoundBuffer buffer;
Sound sound;
Event event;
View view;
Color color(101,67,20);
bool shoot = true;
bool draw_text = true;
float position_player_x = 450;
float position_player_y = 300;
float position_home_x = 400;
float position_home_y = 500;
float width_player = 60;
float height_player = 60;
// 143.2  152.14
float width_cursor = 40;
float height_cursor = 40;
float position_world_mouse_x = 0;
float position_world_mouse_y = 0;
float position_window_mouse_x = 0;
float position_window_mouse_y = 0;
float angel2;
float angel3;
float angel4;
float angel5;
float position_bullet_x = 0;
float position_bullet_y = 0;
float pos_player_x2;
float pos_player_y2;
float distanation;
int direction = 0;
int change = 25;
int change2 = 50;
bool visiable_bullet[1000];
float current_position[1000];
int distance_patron[1000];
int click = -1;
float angel[1000];
int number_bullets = 6;
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

    }    
};
int main(){
maps map;
home home;
player player("D:/Top_Down_Survivor/Top_Down_Survivor/rifle/move/frames.png",position_player_x,position_player_y,106.52,59,position_player_x,position_player_y);
cursor cursor("D:/C++/texture/strela3.png",0,0,width_cursor,height_cursor);
bullet bullet;
coalission coalission;
sf::VertexArray lines(sf::Lines, 4);
word word;
float fps;
float CurrentFrame = 0;
Clock clock;
Time previousTime = clock.getElapsedTime();
Time currentTime;
map.draw();
home.draw();
player.draw();
cursor.draw();
word.draw_codinate_player_x();
word.draw_codinate_player_y();
word.draw_FPS();
word.draw_Rotate();
bullet.draw();
coalission.draw_colission();
while (window.isOpen()){
float time = clock.getElapsedTime().asMicroseconds(); 
clock.restart(); 
time = time / 800;
FloatRect player_pos = player.sprite_player.getGlobalBounds();
FloatRect rect_pos_1 = coalission.rectangle.getGlobalBounds();
FloatRect rect_pos_2 = coalission.rectangle2.getGlobalBounds();
FloatRect rect_pos_3 = coalission.rectangle3.getGlobalBounds();
FloatRect rect_pos_4 = coalission.rectangle4.getGlobalBounds();
FloatRect rect_pos_5 = coalission.rectangle5.getGlobalBounds();
FloatRect rect_pos_6 = coalission.rectangle6.getGlobalBounds();
while (window.pollEvent(event)){ 
     
    switch (event.type){
        case Event::Closed:
            window.close();
            break;
        case Event::MouseMoved:{
            position_world_mouse_x = window.mapPixelToCoords(Mouse::getPosition(window)).x; 
            position_world_mouse_y = window.mapPixelToCoords(Mouse::getPosition(window)).y;
            position_window_mouse_x = Mouse::getPosition().x;
            position_window_mouse_y = Mouse::getPosition().y;
            cursor.sprite_cursor.setPosition(position_world_mouse_x,position_world_mouse_y);
            float deltaX = position_world_mouse_x - player.sprite_player.getPosition().x;
            float deltaY = position_world_mouse_y - player.sprite_player.getPosition().y;
            float deltaX2 =  position_window_mouse_x - player.sprite_player.getPosition().x;
            float deltaY2 = position_window_mouse_y - player.sprite_player.getPosition().y;
			player.sprite_player.setRotation(atan2(deltaY ,deltaX) * 180.f/3.14f);
            angel3 = atan2(deltaY ,deltaX) * 180.f/3.14f;
            angel5 = atan2(deltaY ,deltaX);
            distanation = sqrt(pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x- player.sprite_player.getPosition().x,2)+pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y - player.sprite_player.getPosition().y,2));
            // cout << bullet.sprite_bullet.getPosition().x <<" , " << bullet.sprite_bullet.getPosition().y << "\n";
            lines[0].position = sf::Vector2f(player.sprite_player.getPosition().x-10,player.sprite_player.getPosition().y-10);
            lines[1].position = sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x,window.mapPixelToCoords(sf::Mouse::getPosition(window)).y);
            // bullet.sprite_bullet.setPosition((player.sprite_player.getPosition().x-13)+(change2*cos(angel)),(player.sprite_player.getPosition().y)+(change2*sin(angel)));
            angel2 = atan2(deltaY ,deltaX) * 180.f/3.14f;
            break;
        }
        case Event::MouseButtonPressed:{
            // buffer.loadFromFile("D:/C++/audio/drobovik-27711.wav");
	        // sound.setBuffer(buffer);
	        // sound.play();
            if (number_bullets==0){
               shoot=false;
            }
            if (shoot==true){
                number_bullets--;
                click+=1;
                current_position[click]=0;
                sf::Vector2f bulletOffset(50, 15);
                sf::Transform tansform;
                tansform.rotate(player.sprite_player.getRotation());
                sf::Vector2f newBulletOffset = tansform.transformPoint(bulletOffset);
                sf::Vector2f bulletPosition = player.sprite_player.getPosition() + newBulletOffset;
                bullet.sprite_bullet[click].setPosition(bulletPosition);
                float deltaX3 =  window.mapPixelToCoords(Mouse::getPosition(window)).x - bullet.sprite_bullet[click].getPosition().x;
                float deltaY3 = window.mapPixelToCoords(Mouse::getPosition(window)).y - bullet.sprite_bullet[click].getPosition().y;
                angel4 =  atan2(deltaY3,deltaX3);
                angel[click] = angel4;
                visiable_bullet[click] = true;
                distance_patron[click] = sqrt(pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).x- bullet.sprite_bullet[click].getPosition().x,2)+pow(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y - bullet.sprite_bullet[click].getPosition().y,2));
            }
            break;

        }
        case Event::KeyReleased:{
            // cout << "released" << "\n";
        }
    
    }
  
}
ostringstream cordinate_x;
ostringstream cordinate_y;
ostringstream FPS;
ostringstream Rotate;
Rotate << angel3;
word.text4.setString("Angel: "+Rotate.str());
cordinate_x << player.sprite_player.getPosition().x;
word.text4.setPosition(view.getCenter().x+115,view.getCenter().y-495);
word.text.setString("X:"+cordinate_x.str());//задает строку тексту
word.text.setPosition(view.getCenter().x+215,view.getCenter().y-495);
cordinate_y << player.sprite_player.getPosition().y;
word.text2.setString("Y:"+cordinate_y.str());//задает строку тексту
word.text2.setPosition(view.getCenter().x+315,view.getCenter().y-495);
currentTime = clock.getElapsedTime ();
fps = 1.0f / (currentTime.asSeconds () - previousTime.asSeconds ()); // asSeconds возвращает число с плавающей запятой
previousTime = currentTime;
word.text3.setPosition(view.getCenter().x+415,view.getCenter().y-495);
int time_over = timer(4);
if (time_over==1)
{
  FPS << round(fps);
  word.text3.setString("FPS:"+FPS.str());
}
view.setCenter(player.sprite_player.getPosition().x,player.sprite_player.getPosition().y);
home.sprite_home.setPosition(position_home_x,position_home_y);
if (player_pos.intersects(rect_pos_1)){
   if (direction==0){ 
    // player.sprite_player.move(sf::Vector2f((cos(angel)*-0.3)*time,0));
    // player.sprite_player.move(sf::Vector2f(0,(sin(angel)*-0.3)*time));
     player.sprite_player.move(sf::Vector2f(0,-0.3*time));
   }
   if (direction==1){
       player.sprite_player.move(sf::Vector2f(0,-0.2*time));  
   }
}
if (player_pos.intersects(rect_pos_2)){
    if (direction==0){ 
     player.sprite_player.move(sf::Vector2f(-0.3*time,0));
   }
}
if (player_pos.intersects(rect_pos_3)){
    if (direction==0){ 
     player.sprite_player.move(sf::Vector2f(0.3*time,0));
   }
}
if (player_pos.intersects(rect_pos_4)){
    if (direction==0){ 
     player.sprite_player.move(sf::Vector2f(0,0.3*time));
   }
}
if (player_pos.intersects(rect_pos_5)){
    if (direction==0){ 
     player.sprite_player.move(sf::Vector2f(0,0.3*time));
   }
}
if (player_pos.intersects(rect_pos_6)){
    if (direction==0){ 
     player.sprite_player.move(sf::Vector2f(0,0.3*time));
   }
}
if (Keyboard::isKeyPressed(Keyboard::W)){
// cout << "position sfml " << player.sprite_player.getPosition().x << " , " << player.sprite_player.getPosition().y << ", position box2d " << body->GetPosition().x << " , " << body->GetPosition().y << "\n";
CurrentFrame += 0.07*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
if (CurrentFrame > 20) CurrentFrame -= 20; //если пришли к третьему кадру - откидываемся назад.
player.sprite_player.setTextureRect(IntRect(106*int(CurrentFrame),0,100,59));
// body->ApplyForce(b2Vec2(cos(angel)*8,sin(angel)*8), body->GetPosition(),true);
player.sprite_player.move(sf::Vector2f((cos(angel5)*0.3)*time,0));
player.sprite_player.move(sf::Vector2f(0,(sin(angel5)*0.3)*time));
}
if (Keyboard::isKeyPressed(Keyboard::R)){
number_bullets = 6;
shoot = true;
}
else if (Keyboard::isKeyPressed(Keyboard::S)){
direction = 1;
player.sprite_player.move(sf::Vector2f(0,0.2*time));  
}
else if (Keyboard::isKeyPressed(Keyboard::Escape)){
window.close();
}
else if (Keyboard::isKeyPressed(Keyboard::M))
{
    view.zoom(1.0001f);
	window.setView(view);
}
window.setFramerateLimit(1500);
window.setMouseCursorVisible(false);
window.setView(view);
window.clear(color);
for (int i = 0; i < Height_map; i++){
	for (int j = 0; j < Width_map; j++)
	 {
		if ((Tilemap[i][j] == '0')) map.sprite_map.setTextureRect(sf::IntRect(0, 0, 50, 32));//если встретили символ 0, то рисуем 3й квадратик
        map.sprite_map.setPosition(j * 50, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
        window.draw(map.sprite_map);//рисуем квадратики на экран
	 }
}
for (int i = 0; i<click; i++){
	switch (visiable_bullet[i]){
        case true:
	// 		cout << i << "\n";
	// 		cout << "click = "<< click << "\n";
			bullet.draw();
			window.draw(bullet.sprite_bullet[i]);
			// angel2[i] = angel;
			// angl[i] = atan2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)).y - charecter.sprite.getPosition().y,window.mapPixelToCoords(sf::Mouse::getPosition(window)).x - charecter.sprite.getPosition().x)
			bullet.sprite_bullet[i].move(sf::Vector2f(1.0f*cos(angel[i+1]),0.0f));
			bullet.sprite_bullet[i].move(sf::Vector2f(0.0f,1.0f*sin(angel[i+1])));
			current_position[i]+=1.0f;
			// cout << i << "count = " << current_position[i] << "\n";
			// cout << i << "distance_patron = " << distance_patron[i] << "\n";
			if (current_position[i]>=distance_patron[i]){
					current_position[i] = 0;
					// cout << i << "\n";
					visiable_bullet[i] = false;
				}
	}
}
window.draw(home.sprite_home);
window.draw(player.sprite_player);
window.draw(word.text);
window.draw(word.text2);
window.draw(word.text3);
window.draw(word.text4);
window.draw(cursor.sprite_cursor);
window.draw(lines);
window.draw(coalission.rectangle);
window.draw(coalission.rectangle2);
window.draw(coalission.rectangle3);
window.draw(coalission.rectangle4);
window.draw(coalission.rectangle5);
window.draw(coalission.rectangle6);
window.display();    
}

}
