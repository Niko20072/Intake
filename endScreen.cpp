#include "endScreen.h"
#include "house.h"
#include "input.h"
#include "Windows.h"

namespace Tmpl8
{

	EndGame::EndGame(House& h) : house(h)//late constructor
	{
		//gamescreen = std::make_unique<Sprite>(new Surface("assets/endgame.png"), 7);
	};
	void EndGame::ManageFrames()
	{
		if (Input::GetMouseButtonPressed(1))
		{
			frame++;
			cutScene.SetFrame(frame);
		}
	}
	void EndGame::DrawGameCompletedScreen(Surface* screen)
	{
		if (frame < 7)
			cutScene.Draw(screen, 0, 0);
		else
			exit(0);
	}
}