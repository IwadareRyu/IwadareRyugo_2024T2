#pragma once
#include "GameObject.h"

namespace bullet
{
	const int DEFAULT_SPEED = 200;

	const Vec2 INIT_POS{ 1000,1000 };

	const Vec2 INIT_DIRECTION{ 0,-1 };
}

class Bullet : public GameObject{
public:
	float m_speed;
	float m_rotaRange;
	Vec2 m_dir;

	Bullet();
	~Bullet() {};
	Vec2 M_InitPosition() override;
	void M_SpawnInit(Vec2 initPos,float speed,float rotaRange,Vec2 dir);
	void M_Move();
	void M_Rota();
};

