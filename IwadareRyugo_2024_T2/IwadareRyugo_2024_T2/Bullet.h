#pragma once
#include "GameObject.h"

namespace bullet
{
	const int DEFAULT_SPEED = 200;

	const Vec2 INIT_POS{ 1000,1000 };

	const Vec2 INIT_DIRECTION{ 0,-1 };

	const float LIFE_TIME = 5.0f;
}

class Bullet : public GameObject{
public:
	float m_speed;
	float m_rotaRange;
	Vec2 m_dir;
	float m_life;

	Bullet();
	~Bullet() {};
	Vec2 M_InitPosition() override;
	const void M_SpawnInit(const Vec2 initPos, const float speed, const float rotaRange, const Vec2 dir);
	const void M_Move();
	const void M_Rota();
	const float M_LifeTime();
};

