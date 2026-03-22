#pragma once
#include "surface.h"
namespace Tmpl8
{
	class WateringCan
	{
	public:
		//---Getters---
		int getState();
		//---Setters---
		void setState(bool state);
		//--Main functions---
		void WateringCanLogic();
		void Draw(Surface* screen);
	private:
		Sprite wateringCan = Sprite(new Surface("assets/image/wateringCan.png"), 2);
		bool wateringCanState = false;
	};
}