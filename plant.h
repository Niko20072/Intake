#pragma once
#include "surface.h"
#include <vector>
#include "camera.h"



namespace Tmpl8
{
	class Inventory;
	class Camera;

	class Plant
	{
	public:
		Plant(float x, float y, int harvestDay, int frame, Inventory& inv, Camera& cam);
		//---Getters---
		int getGrown();
		int getAlive();
		//---Setters---
		void setWatered(bool state);
		//--Main functions---
		void Update();
		void Collect();
		void Draw(Surface* screen);
	private:
		Inventory& inventory;
		Camera& camera;
		Sprite plant = Sprite(new Surface("assets/image/plants.png"), 20);
		int harvestDay; //the day when the plant is grown
		int daysPassed = 0; //plant age
		int frame; //sprite frame
		float x, y;
		bool grown = false;
		bool alive = true;
		bool watered = false;
	};
}