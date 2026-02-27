#include "inventory.h"

namespace Tmpl8//sterge
{
	//maybe states (kinda fixed it without states)
	enum class State
	{
		Closed,
		Inventory,
		Seeds
	};

	State m_State = State::Closed;

	void SetState(State newState)
	{
		m_State = newState;
	}

	void Inventory::update()
	{
		switch (m_State)
		{
		case State::Closed:
			// Update closed state..
			if (Input::GetKeyPressed(SDL_SCANCODE_E))
			{
				SetState(State::Inventory);
				break;
			}
		case State::Inventory:
			// Update inventory state..
			if (Input::GetKeyPressed(SDL_SCANCODE_E))
			{
				SetState(State::Closed);
			}
			break;
		case State::Seeds:
			// Update seeds state....
			break;
		};
	}
		//namespace to class de ce
		int Inventory::getFrame()
		{
			return frame;
		}
		int Inventory::MainInvIsOpen()
		{
			return inventoryisopen;
		}
		int Inventory::SeedInvIsOpen()
		{
			return seedsisopen;
		}
		void Inventory::setSeedState(bool state)
		{
			seedsisopen = state;
		}

		int Inventory::AddItem(Item item, int quantity)
		{
			items[item] += quantity; // Add quantity to the specified item in the inventory
			return items[item];
		}
		int Inventory::GetItemCount(Item item)
		{
			return items[item];
		}

		void Inventory::MainInventoryLogic(Surface* screen)
		{
			// Detect clicks
			bool clickedOutsideInv = Input::GetMouseButtonPressed(1) && !(WorldState::mouseX >= 207 && WorldState::mouseX <= 579 && WorldState::mouseY >= 78 && WorldState::mouseY <= 519);
			bool clickedOnPlantButton = Input::GetMouseButtonPressed(1) && WorldState::mouseX >= 323 && WorldState::mouseX <= 366 && WorldState::mouseY >= 471 && WorldState::mouseY <= 510;
			bool clickedOnPotionButton = Input::GetMouseButtonPressed(1) && WorldState::mouseX >= 375 && WorldState::mouseX <= 510 && WorldState::mouseY >= 471 && WorldState::mouseY <= 510;
			bool clickedOnSeedButton = Input::GetMouseButtonPressed(1) && WorldState::mouseX >= 430 && WorldState::mouseX <= 475 && WorldState::mouseY >= 471 && WorldState::mouseY <= 510;

			//Toggle normal inventory
			if (Input::GetKeyPressed(SDL_SCANCODE_E)) //add state :(
			{
				seedsisopen = false;
				inventoryisopen = !inventoryisopen;
				frame = 0;
			}

			//Click inventory
			if (inventoryisopen)
			{
				// Manage frame selection buttons
				if (clickedOnPlantButton)
					frame = 0;
				if (clickedOnPotionButton)
					frame = 1;
				if (clickedOnSeedButton)
					frame = 2;
				if (clickedOutsideInv || Input::GetKeyPressed(SDL_SCANCODE_Q))
					inventoryisopen = false;
			}
			inventory.SetFrame(frame);

		}
		void Inventory::SeedInventoryLogic(Surface* screen, bool tileClicekd)
		{
			// Detect clicks
			bool clickedOutsideInv = Input::GetMouseButtonPressed(1) && !(WorldState::mouseX >= 207 && WorldState::mouseX <= 579 && WorldState::mouseY >= 78 && WorldState::mouseY <= 519);
			bool moved = Input::GetKeyPressed(SDL_SCANCODE_W) || Input::GetKeyPressed(SDL_SCANCODE_A) || Input::GetKeyPressed(SDL_SCANCODE_S) || Input::GetKeyPressed(SDL_SCANCODE_D);

			//Toggle seed inventory
			if (tileClicekd && !seedsisopen && !wateringCan.getState())
			{
				inventoryisopen = false;
				seedsisopen = true;
				frame = 3;
			}

			//Click seed inventory
			if (seedsisopen)
				if (clickedOutsideInv || Input::GetKeyPressed(SDL_SCANCODE_Q) || Input::GetKeyPressed(SDL_SCANCODE_E) || moved)
					seedsisopen = false;
			inventory.SetFrame(frame);
		}
		void Inventory::Draw(Surface* screen)
		{
			if (inventoryisopen || seedsisopen)
				inventory.Draw(screen, 140, 20);
		}
		
		/*
		bool Inventory::VerifyRandomPotionOrder(int type, int quantity)
		{
			if (type == 0 && GetItemCount(Item::VitalTonic) >= quantity)
			{
				return true;
			}
			else if(type == 1 && GetItemCount(Item::CalmMind) >= quantity)
			{
				return true;
			}
			else if(type == 2 && GetItemCount(Item::DreamDraught) >= quantity)
			{
				return true;
			}
			else if(type == 3 && GetItemCount(Item::FireHeart) >= quantity)
			{
				return true;
			}
			else if(type == 4 && GetItemCount(Item::FrostVeil) >= quantity)
			{
				return true;
			}
			return false; // Return false for invalid potion type
		}
		void Inventory::RandomPotionOrder(int type, int quantity)
		{
			if(type == 0)
			{
				AddItem(Item::VitalTonic, -quantity);
			}
			else if(type == 1)
			{
				AddItem(Item::CalmMind, -quantity);
			}
			else if(type == 2)
			{
				AddItem(Item::DreamDraught, -quantity);
			}
			else if(type == 3)
			{
				AddItem(Item::FireHeart, -quantity);
			}
			else if(type == 4)
			{
				AddItem(Item::FrostVeil, -quantity);
			}
		}*/

		

		
}