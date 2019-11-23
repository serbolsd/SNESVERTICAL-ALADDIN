#include <imgui-SFML.h>
#include <imgui.h>
#include "../include/CWindow.h"
#include "../include/RenderManager.h"
#define GAME
int main()
{
	RenderManager play;

	play.init();
#ifdef GAME
	play.onUpdate();
#elif EDITOR
#endif
	play.onDelete();

}
