#include "Dino.h"
#include "constants.h"
Dino::Dino(std::string image, int x, int y):Object{image,x,y}{
    this->yAcc=1;
    this->setSize(100,100);
}

Dino::~Dino(){

}
void Dino::objectUpdate(){
    int lowestPos=worldHeight-this->height;
    if(this->yPos>lowestPos){
        this->yPos=lowestPos;
        this->yVel=0;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->yPos==lowestPos){
            this->yVel=-30;
    }
}

void Dino::collisionDetected(Object* other){}