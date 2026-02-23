#include "input.h"
#include <bitset>

namespace //internal 
{
    std::bitset<SDL_NUM_SCANCODES> keys; // store key states here
    std::bitset<SDL_NUM_SCANCODES> held; // store key states from the previous tick here
    std::bitset<SDL_NUM_SCANCODES> pressed; // store key press events here (set to true on key down, reset to false after processing in Tick)
    std::bitset<SDL_NUM_SCANCODES> released; // store key release events here (set to true on key up, reset to false after processing in Tick)
	std::bitset<5> mouseButtons; // store mouse button states here (0: left, 1: middle, 2: right, 3: X1, 4: X2)
    void SetKeyState(SDL_Scancode key, bool isDown)
    {
        keys.set(key, isDown);
    }
}

namespace Input
{
    bool GetKey(SDL_Scancode key) { return held.test(key); } // returns true if the key is currently held down
    bool GetKeyPressed(SDL_Scancode key) { return pressed.test(key); } // returns true if the key was pressed since the last Tick
    bool GetKeyReleased(SDL_Scancode key) { return released.test(key); } // returns true if the key was released since the last Tick
	bool GetMouseButton(int button) { return mouseButtons.test(button - 1); } // returns true if the mouse button is currently held down
    void onKeyDown(SDL_Scancode key)
    {
        SetKeyState(key, true);
	}
    void onKeyUp(SDL_Scancode key)
    {
        SetKeyState(key, false);
    }
    void onMouseButtonDown(int button)
    {
        mouseButtons.set(button - 1, true);
	}
    void onMouseButtonUp(int button)
    {
        mouseButtons.set(button - 1, false);
	}
    void Update()
    {
        // Update key states
        pressed = keys & ~held; // keys that are currently down but were not down in the previous tick
        released = ~keys & held; // keys that were down in the previous tick but are not down now
        held = keys; // update prevKeys for the next tick
    }
};