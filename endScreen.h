#pragma once
#pragma once
#include "surface.h"

namespace Tmpl8
{
	class EndGame
	{
	public:
		void DrawGameCompletedScreen(Surface* screen); // Draw cutscene frames or exit game if cutscene is finished
		void ManageFrames(); // Handle input to advance cutscene frames
	private:
		Sprite cutscene = Sprite(new Surface("assets/image/endgame.png"), 7);
		int frame = 0; // Current frame of the game end screen
	};
}