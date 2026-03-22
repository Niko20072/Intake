#pragma once

namespace Tmpl8
{
	class Camera
	{
	public:
		///---Getters---
		float getCameraSpeed();
		float getCameraX();
		float getCameraY();
		///---Setters---
		void setCameraX(float x);
		void setCameraY(float y);
	private:
		const float cameraSpeed = 360.0f;
		float cameraX = 10.0f, cameraY = 50.0f; // Top-left corner of the screen in world coordinates
	};
}