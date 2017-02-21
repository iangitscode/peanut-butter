#ifndef _DINO_H_
#define _DINO_H_
#include "Object.h"
#include <string>

class Dino: public Object{
	public:
		Dino(std::string,int,int);
		~Dino() override;
		void objectUpdate() override;
		void collisionDetected(Object*) override;
};
#endif  