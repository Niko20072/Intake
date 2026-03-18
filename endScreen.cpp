#include "endScreen.h"
#include "house.h"
#include "input.h"
#include "Windows.h"

namespace Tmpl8
{

	EndScreen::EndScreen(House& h) : house(h) {};
	void EndScreen::CheckGameCompleted(int coinCounter, bool& gameCompleted)
	{
		// Check if player clicked on send money button
		bool sendMoney = Input::GetMouseButtonPressed(1) && Input::GetMouseX() >= 336 && Input::GetMouseX() <= 468 && Input::GetMouseY() >= 446 && Input::GetMouseY() <= 498; //say youre gonna improve this later

		// Complete game if send money button is clicked, nightstand is open, and player has enough coins
		if (sendMoney && house.NightstandIsOpen() && coinCounter >= 2000)
		{
			gameCompleted = true;
			frame = 0;
		}
	}
	void EndScreen::ManageFrames()
	{
		if (Input::GetMouseButtonPressed(1))
		{
			frame++;
			gameendscreen.SetFrame(frame);
		}
	}
	void EndScreen::DrawGameCompletedScreen(Surface* screen)
	{
		if (frame <= 6)
			gameendscreen.Draw(screen, 0, 0);
		if (frame > 6)
			exit(0);
	}
}