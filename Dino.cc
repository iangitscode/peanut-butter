#include "Dino.h"
Dino::Dino(std::string image, int x, int y):Object{image,x,y}{}

Dino::~Dino(){

}
void Dino::objectUpdate(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            this->xVel=-7;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            this->xVel=7;
        }
        else{
            this->xVel=0;
        }
}

void Dino::collisionDetected(Object* other){}