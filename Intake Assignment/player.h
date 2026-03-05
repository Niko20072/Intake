#pragma once
#include "surface.h"
#include "template.h"
#include "inventory.h"
#include "wateringCan.h"


namespace Tmpl8
{
	class Map;
	class Player
	{
	public:
		Player(Map &m) : map(m), wateringCan(), inventory(wateringCan) {};
		Inventory& pInventory() { return inventory; }
		WateringCan& pWateringCan() { return wateringCan; }
		void HandleMovement(float deltaTime);
		void Draw(Surface* screen);
	private:
		Map &map; // reference to game map
		WateringCan wateringCan;
		Inventory inventory; // depends on wateringCan
		Sprite player1 = Sprite(new Surface("assets/Vera.png"), 4);
	};
}