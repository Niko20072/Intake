#pragma once
#pragma once
#include "surface.h"
#include <memory>

namespace Tmpl8
{
	class House;

	class EndGame
	{
	public:
		EndGame(House& h);
		void DrawGameCompletedScreen(Surface* screen);
		void ManageFrames();
		void CheckGameCompleted(int coinCounter, bool& gameCompleted);
	private:
		Sprite cutScene = Sprite(new Surface("assets/endgame.png"), 7);
		int frame = 0; // Current frame of the game end screen
		House& house;
	};
}