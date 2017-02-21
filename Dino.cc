#include "Dino.h"
Dino::Dino(std::string image,bool movable, int x, int y):Object{image,movable,x,y}{
	this->yPos=900;
}
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

 	if(this->xPos<0) this->xPos=0;
 	if(this->xPos>850) this->xPos=850;
}

void Dino::collisionDetected(Object* other){
}