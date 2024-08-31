#pragma once
#include "GameObject.h"
#include "Bullet.h"

namespace spawnBullet {
	const Vec2 INIT_POS{ 400,200 };
	const float SPAWN_TIME = 1.0f;
	const float OFFSET_TIME = 0.5f;
	const int WAVE_COUNT = 4;
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
	SpawnBullet(float x, float y,float offSet);
	~SpawnBullet() {};
	//void M_Spawn(SpawnType type,std::list<Bullet*>* bulletList,float disRota = 30);
	void M_ForwardSpawn(std::list<Bullet*>* bulletList);
	void M_CircleSpawn(std::list<Bullet*>* bulletList, float disRota);
	void M_WaveSpawn(std::list<Bullet*>* bulletList, float disRota);
	float M_CountTime();
	float _currentTime = 0;
	float _offSetAngle;
	float _currentOffSetAngle = 0;
	int _currentWaveCount = 0;
	float _currentOffsetTime = 0;
	

	Vec2 M_InitPosition() override;
};

