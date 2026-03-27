#pragma once
#include "surface.h"
#include <iostream>
#include <vector>

namespace Tmpl8
{
	class Inventory;

	class Order
	{
	public:
		Order(int number, Inventory	&inv); // Constructor
		void Update(int& coinCounter); // Logic for order processing
		void Draw(Surface* screen); // Draw order on screen
	private:
		Inventory& inventory; // Reference to player's inventory

		// Potion types and their prices
		const std::vector<const char*> potionsTypes = { "Vital Tonic", "Calm Mind", "Dream Draught", "FireHeart", "FrostVeil" };
		const std::vector<int> priceNumbers = { 60,45,70,95,85 };

		int orderNumber; // Index of the order
		int potionNumber; // Number of potion types in the order (order with 1 potion or with 2 potions)
		int numberPotionType1; // Quantity of the first potion type
		int numberPotionType2; // Quantity of the second potion type
		int potionType1; // Type of potion1
		int potionType2; // Type of potion2
		int price; // Price of the order
		bool completed = false; // Is the order completed?
		char order[64] = "", send[32] = ""; // Text buffers
		int range = 5; // Click range (and Button outline)
	};
}