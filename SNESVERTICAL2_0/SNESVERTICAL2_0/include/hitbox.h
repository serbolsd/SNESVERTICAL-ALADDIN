#pragma once
#include "boxCollider.h"

class HitBox : public boxCollider
{
public:
	HitBox();
	HitBox(float sizeX,float sizeY);
	~HitBox();
	void update() override;
private:

};
