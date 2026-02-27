#pragma once
#include "surface.h"
#include <windows.h>
#include "inventory.h"
#include "template.h"
#include "crafting.h"
#include "worldState.h"
#include "buttons.h"

namespace Tmpl8
{
	class House
	{
		
	public:
		House(Inventory& inv) : inventory(inv), crafting(inv) {};
		Crafting& hCrafting() { return crafting; } // Reference to crafting system
		int IsOpen();
		int getFrame();
		int MainScreenOpen();
		bool getClickedYes() { return clickedYes; }
		void HouseLogic(); // Handle house interactions (opening/closing, crafting menu)
		void Craftinglogic(); // Handle crafting menu interactions
		void BedLogic(int &dayCounter); // Handle bed click and day progression logic
		bool ConfirmedToSleep();
		void NightstandLogic(int coinCounter); // Handle nightstand click
		void DrawHover(Surface* screen);
		void Draw(Surface* screen);
		void GameCompleted(Surface* screen, int coinCounter, bool& gameCompleted); // Show game completed screen
	private:
		Sprite house = Sprite(new Surface("assets/house.png"), 3);
		Sprite nightstand = Sprite(new Surface("assets/nightstand.png"), 1);
		Sprite gameendscreen = Sprite(new Surface("assets/endgame.png"), 7);
		Sprite bed_hover = Sprite(new Surface("assets/bed_hover.png"), 1);
		Sprite table_hover = Sprite(new Surface("assets/table_hover.png"), 1);
		Sprite nightstand_hover = Sprite(new Surface("assets/nightstand_hover.png"), 1);
		Inventory& inventory; // reference to existing inventory
		Crafting crafting;
		bool houseisopen = false; // Is the house menu open?
		bool nightstandisopen = false; // Is the nightstand menu open?
		bool bedisopen = false; // Is the bed menu open?
		int frame = 0; // Current frame of the house
		int gameframe = 0; // Current frame of the game end screen
		bool clickedYes = 0;
		bool clickedNo = 0;
	};
}