#pragma once
#include "boxCollider.h"
#include <vector>
class footsCollider :public boxCollider
{
public:
	footsCollider();
	footsCollider(float sizeX, float sizeY);
	~footsCollider();
	void update() override;
	

private:

};