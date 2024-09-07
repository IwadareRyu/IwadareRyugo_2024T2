#pragma once
#include "GameObject.h"
#include "Bullet.h"

namespace spawnBullet {
	const Vec2 INIT_POS{ 400,200 };
	const float SPAWN_TIME = 1.0f;
	const float OFFSET_TIME = 0.1f;
	const int WAVE_COUNT = 10;
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
	void M_ForwardSpawn(std::list<Bullet*>* bulletList,float speed = 200);
	void M_CircleSpawn(std::list<Bullet*>* bulletList, float disRota, float speed = 200);
	void M_WaveSpawn(std::list<Bullet*>* bulletList, float disRota, float speed = 200);
	float M_CountTime();
	float m_currentTime = 0;
	float m_offSetAngle;
	float m_currentOffSetAngle = 0;
	int m_currentWaveCount = 0;
	float m_currentOffsetTime = 0;
	

	Vec2 M_InitPosition() override;
};

