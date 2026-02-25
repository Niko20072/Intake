#include "wateringCan.h"
namespace Tmpl8
{
	void WateringCan::WateringCanLogic()
	{
		if (Input::GetKey(SDL_SCANCODE_R))
			wateringCanState = !wateringCanState;
	}
	void WateringCan::Draw(Surface *screen)
	{
		if (wateringCanState)
			wateringCan.SetFrame(1); // Watering can in use frame
		else
			wateringCan.SetFrame(0); // Watering can idle frame
		wateringCan.Draw(screen, 376, 540); // 400 - 24 (half of watering can width) to center the hint below the watering can
		screen->Print("R", 400, 590, 0xFFFFFF); // Draw "R" key hint below the watering can
	}
}
