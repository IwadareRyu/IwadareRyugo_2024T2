#pragma once
#include "GameObject.h"

namespace spawnBullet {
	const Vec2 INIT_POS{ 400,200 };
};

class SpawnBullet : GameObject
{
	virtual void Spawn() {};
	SpawnBullet();
	~SpawnBullet() {};
	Vec2 M_InitPosition() override;

};

