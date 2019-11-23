#pragma once
#include "boxCollider.h"
#include <vector>

class headCollider : public boxCollider
{
public:
	headCollider();
	headCollider(float sizeX, float sizeY);
	~headCollider();
	void update() override;
private:

};
