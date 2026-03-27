#pragma once
#include "surface.h"
#include "crafting.h"
#include <Audio/Sound.hpp>

namespace Tmpl8
{
	class Inventory;
	class Player;

	class House
	{
		
	public:
		House(Player& pl);
		//---Getters---
		Crafting& hCrafting(); // Reference to crafting system
		bool IsOpen();
		int getFrame();
		bool NightstandIsOpen();
		bool BedIsOpen();
		bool MainScreenOpen();
		bool getClickedYes(); // Player confirmed to sleep
		//---Main functions---
		void HouseLogic(float mouseWorldX, float mouseWorldY); // Handle house interactions (opening/closing, crafting menu)
		void Craftinglogic(); // Handle crafting menu interactions
		void BedLogic(int &dayCounter); // Handle bed click and day progression logic
		bool ConfirmedToSleep(); // Check if player confirmed to sleep and progress to next day
		void NightstandLogic(); // Handle nightstand interactions
		void CheckGameCompleted(int coinCounter, bool& gameCompleted); // Check if the game completion conditions are met and set gameCompleted to true if they are
		void Draw(Surface* screen);
	private:
		Player& player; // Reference to existing player
		Inventory& inventory; // Reference to existing inventory
		Crafting crafting; // Create crafting
		Sprite house = Sprite(new Surface("assets/image/house.png"), 3);
		Sprite nightstand = Sprite(new Surface("assets/image/nightstand.png"), 1);
		Sprite bed_hover = Sprite(new Surface("assets/image/bed_hover.png"), 1);
		Sprite table_hover = Sprite(new Surface("assets/image/table_hover.png"), 1);
		Sprite nightstand_hover = Sprite(new Surface("assets/image/nightstand_hover.png"), 1);
		Audio::Sound doorOpen;
		Audio::Sound doorClose;
		bool houseisopen = false; // House open state
		bool nightstandisopen = false; // Nightstand open state
		bool bedisopen = false; // Bed open state
		int frame = 0; // Current frame of the house
		bool clickedYes = 0; // Sleep interaction
		bool clickedNo = 0; // Sleep interaction
		void DrawHover(Surface* screen); // Hover over objects animation
	};
}