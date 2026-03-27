#include "map.h"
#include "camera.h"

namespace Tmpl8
{
	const int Map::TileSize = 48;
	Map::Map(Camera& cam) : camera(cam) {}
	bool Map::IsBlocked(int x,int y)
	{
		//Transform screen coordinates to tile coordinates
		int tx = x / TileSize;
		int ty = y / TileSize;

		//return true if tile is blocked/ false if not
		return map[ty][tx] == 'X';
	}
	bool Map::CheckCollision(float x1, float y1, float x2, float y2)
	{
		//sprit corners
		int left = static_cast<int>(x1);
		int top = static_cast<int>(y1);
		int right = static_cast<int>(x2);
		int bottom = static_cast<int>(y2);

		//check all corners for collision
		if (IsBlocked(left, top)) 
			return false;
		if (IsBlocked(right, top)) 
			return false;
		if (IsBlocked(left, bottom)) 
			return false;
		if (IsBlocked(right, bottom)) 
			return false;

		return true; //no collision
	}
	void Map::Draw(Surface*screen)
	{
		tiles.CopyTo(screen, static_cast<int>(-camera.getCameraX()), static_cast<int>(-camera.getCameraY()));
	}
};