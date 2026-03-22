#include "camera.h"

namespace Tmpl8
{
	float Camera::getCameraSpeed()
	{
		return cameraSpeed;
	}
	float Camera::getCameraX() 
	{
		return cameraX; 
	}
	float Camera::getCameraY() 
	{
		return cameraY;
	}
	void Camera::setCameraX(float x) 
	{ 
		cameraX = x; 
	}
	void Camera::setCameraY(float y) 
	{ 
		cameraY = y; 
	}
}
