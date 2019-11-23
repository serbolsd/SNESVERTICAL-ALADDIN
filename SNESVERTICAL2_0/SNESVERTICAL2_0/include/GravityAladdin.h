#pragma once

#include "component.h"
#include "Aladdin.h"

#define GRAVITYFORCE 9.81
class GravityAladdin : public Component
{
public:
	GravityAladdin();
	~GravityAladdin() {};
	void update() override;
private:

};