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
			cutscene.SetFrame(frame);
		}
	}
	void EndGame::DrawGameCompletedScreen(Surface* screen)
	{
		if (frame < 7) // There are still frames to draw
			cutscene.Draw(screen, 0, 0);
		else
			exit(0);
	}
}