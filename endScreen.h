#pragma once
#pragma once
#include "surface.h"

namespace Tmpl8
{
	class House;

	class EndScreen
	{
	public:
		EndScreen(House& h);
		void DrawGameCompletedScreen(Surface* screen);
		void ManageFrames();
		void CheckGameCompleted(int coinCounter, bool& gameCompleted);
	private:
		Sprite gameendscreen = Sprite(new Surface("assets/endgame.png"), 7);
		int frame = 0; // Current frame of the game end screen
		House& house;
	};
}