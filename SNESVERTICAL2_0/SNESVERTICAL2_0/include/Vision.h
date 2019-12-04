#pragma once
#include "boxCollider.h"
struct Vision: boxCollider 
{
	void update();
	void init();
	void onDelete();
};