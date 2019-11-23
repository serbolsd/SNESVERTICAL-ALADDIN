#include "GravityAladdin.h"

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
			*aladdin->deltaTime = 0;
		}
		return;
	}
	float vy = *aladdin->currentJumpForce - ((GRAVITYFORCE - *aladdin->currentParachuteForce)* *aladdin->deltaTime);
	aladdin->position->y += vy;
}
