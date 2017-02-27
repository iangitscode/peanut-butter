#pragma once
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include "Object.h"
#include <string>
#include "constants.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Block : public Object {
public:
	Block(std::string, int, int);
	~Block() override;
	void objectUpdate() override;
	void collisionDetected(Object*) override;
};
#endif  
