#include <SFML/System/Clock.hpp>
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace sf;
float d;
bool timer(float time){
Clock clock;
if (d)
  {   
    d += clock.getElapsedTime().asSeconds();
    if (d==time){
        clock.restart();
        d = 0;
        return true;
     }
  }
}