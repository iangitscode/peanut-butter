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


 	if(this->xPos<0) this->xPos=0;		//prevents dino from going off left side of screen
 	if(this->xPos>850) this->xPos=850;	//prevents dino from going off right side of screen
}

void Dino::collisionDetected(Object* other){}