#ifndef _PADDLE_H_
#define _PADDLE_H_
#include "Object.h"
#include <string>

class Paddle: public Object{
	public:
		Paddle(std::string);
		~Paddle() override;
		void extraUpdate() override;
		void collisionDetected(Object*) override;
};
#endif  