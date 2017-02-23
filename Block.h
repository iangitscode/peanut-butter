#pragma once
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "Object.h"
#include <string>
#include "constants.h"

class Block : public Object {
public:
	Block(std::string, int, int);
	~Block() override;
	void objectUpdate() override;
	void collisionDetected(Object*) override;
};
#endif  
