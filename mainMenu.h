#pragma once
#include "surface.h"

namespace Tmpl8
{
	class MainMenu
	{
	public:
		void Draw(Surface* screen);
		void DrawCutScene(Surface* screen);
		void Logic(bool &gameStarted);
		void CutSceneLogic(bool& cutScenePlayed);
	private:
		Sprite main = Sprite(new Surface("assets/mainMenu.png"),3);
		Sprite cutScene = Sprite(new Surface("assets/startgame.png"), 16);
		int frame = 0;
		int cutSceneFrame = 0;
		void ManageFrames();
	};
}