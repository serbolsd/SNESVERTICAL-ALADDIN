#pragma once
#include "boxCollider.h"

class HitBoxAladdin : public boxCollider
{
public:
	HitBoxAladdin();
	HitBoxAladdin(float sizeX=10,float sizeY=10);
	~HitBoxAladdin();
	void update() override;
private:

};