#pragma once
#include "boxCollider.h"

class WallCollider :public boxCollider
{
public:
	WallCollider();//the pivot is down to the middle
	WallCollider(float sizeX, float sizeY);//the pivot is down to the middle
	~WallCollider();
	void update() override;
private:

};