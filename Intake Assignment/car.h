#pragma once
#include "orders.h"
#include "surface.h"	

namespace Tmpl8
{
	class Inventory;
	class Car
	{
	public:
		Car(Inventory& inv) : inventory(inv) {};
		int CarInvIsOpen();
		int getFrame();
		void UpdateOrderDays();
		void CarInventoryLogic(int& coinCounter);
		void DrawCarText(Surface* screen);
		void BuySeeds(int& coinCounter); // Buying seeds logic
		void Draw(Surface* screen);
		void MakeNewOrders();
		void UpdateOrders(int& coinCounter);
		void DrawOrders(Surface* screen);
	private:
		Inventory& inventory;
		bool carisopen = false; // Car inventory open state
		int frame = 4;
		int daysUntilOrderReset = 0;
		Sprite carinventory = Sprite(new Surface("assets/inventory.png"), 6);
		std::vector<Order> orders;
	};
}
