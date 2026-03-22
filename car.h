#pragma once
#include "orders.h"
#include "surface.h"	

namespace Tmpl8
{
	class Inventory;
	class Player;
	class Car
	{
	public:
		Car(Player& pl);
		//---Getters---
		int CarInvIsOpen(); // Returns whether the car inventory is open
		int getFrame(); // Returns the current frame of the car
		//---Main functions---
		void CarInventoryLogic(int& coinCounter, float mouseWorldX, float mouseWorldY); // Logic for handling car inventory interactions
		bool CheckIfAnySeedButtonPressed(); // Checks if any of the seed buying buttons are pressed
		void UpdateOrderDays(); // Updates the days until order reset
		void MakeNewOrders(); // Creates new orders for the car inventory
		void UpdateOrders(int& coinCounter); // Updates the orders in the car inventory
		void Draw(Surface* screen); // Draws the car inventory
		void DrawOrders(Surface* screen); // Draws the orders in the car inventory
	private:
		Player& player;
		Inventory& inventory;
		Sprite carinventory = Sprite(new Surface("assets/image/inventory.png"), 6);
		std::vector<Order> orders;
		bool carisopen = false; // Car open state
		int frame = 4;
		int daysUntilOrderReset = 0;
		bool button1 = false, button2 = false, button3 = false, button4 = false, button5 = false;// Buying seeds buttons
		void DrawCarText(Surface* screen); // Draws the text for the car inventory (seed counts)
		void BuySeeds(int& coinCounter); // Logic for buying seeds from the car inventory
	};
}
