#include "endScreen.h"
#include "house.h"
#include "input.h"
#include "Windows.h"

namespace Tmpl8
{
	void EndGame::ManageFrames()
	{
		// Advance to the next frame of the cutscene
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