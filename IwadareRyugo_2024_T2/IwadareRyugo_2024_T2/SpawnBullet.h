#pragma once
#include "GameObject.h" 

namespace spawnBullet {
	const Vec2 INIT_POS{ 400,200 };
	const float SPAWN_TIME = 1.0f;
};

enum SpawnType
{
	ForwardSpawn,
	CircleSpawn,
	WaveSpawn,
};

class SpawnBullet : GameObject
{
public:
	SpawnBullet(float x, float y);
	~SpawnBullet() {};
	void M_Spawn(SpawnType type);
	float M_CountTime();
	float _currentTime = 0;
	

	Vec2 M_InitPosition() override;
};

