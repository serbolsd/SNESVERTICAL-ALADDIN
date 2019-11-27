#include "../include/GravityAladdin.h"

GravityAladdin::GravityAladdin()
{
	type = gravity;
}

void GravityAladdin::update()
{
	Aladdin *aladdin = dynamic_cast<Aladdin*> (myObject);
	if (aladdin->isGrounded || aladdin->isGrabbed)
	{
		*aladdin->currentJumpForce = 0;
		if (!aladdin->isSwinging)
		{
			*aladdin->fallTime = 0;
		}
		return;
	}
	float vy = *aladdin->currentJumpForce - ((GRAVITYFORCE - *aladdin->currentParachuteForce)* *aladdin->fallTime);
	aladdin->position->y -= vy;
}
