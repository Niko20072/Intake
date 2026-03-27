#pragma once
#include "surface.h"

namespace Tmpl8
{
	class MainMenu
	{
	public:
		void Logic(bool &gameStarted); // Menu logic
		void CutsceneLogic(bool& cutScenePlayed); // Cutscene logic
		void Draw(Surface* screen); // Draw menu
		void DrawCutscene(Surface* screen); // Draw cutscene
	private:
		Sprite main = Sprite(new Surface("assets/image/mainMenu.png"),3);
		Sprite cutscene = Sprite(new Surface("assets/image/startgame.png"), 16);
		int frame = 0; // Frames for animation
		int cutsceneFrame = 0;
		void ManageFrames();// Handle input to advance cutscene frames
	};
}