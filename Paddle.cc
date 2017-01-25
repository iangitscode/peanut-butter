#include "Paddle.h"
Paddle::Paddle(std::string image):Object{image,true}{
	this->yPos=900;
}
Paddle::~Paddle(){

}
void Paddle::extraUpdate(){
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

void Paddle::collisionDetected(Object* other){
}