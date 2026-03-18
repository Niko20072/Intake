#pragma once
#include "surface.h"

namespace Tmpl8
{
	class MainMenu
	{
	public:
		void Draw(Surface* screen);
		void Logic(bool &gameStarted);
	private:
		Sprite main = Sprite(new Surface("assets/mainMenu.png"),3);
		int frame = 0;
	};
}