#include "wateringCan.h"
#include "input.h"

namespace Tmpl8
{
	int WateringCan::getState()
	{ 
		return wateringCanState; 
	}
	void WateringCan::setState(bool state)
	{ 
		wateringCanState = state;
	}
	void WateringCan::WateringCanLogic()
	{
		if (Input::GetKeyPressed(SDL_SCANCODE_R))
			wateringCanState = !wateringCanState;
	}
	void WateringCan::Draw(Surface *screen)
	{
		if (wateringCanState)
			wateringCan.SetFrame(1); // Watering can in use frame
		else
			wateringCan.SetFrame(0); // Watering can idle frame
		wateringCan.Draw(screen, 376, 540); // 800/2 - 48/2 (half of watering can width) to center the watering can
		screen->PrintScaled("R", 397, 585, 2 , 2 ,0xFFFFFF); // Draw "R" key below the watering can
	}
}
