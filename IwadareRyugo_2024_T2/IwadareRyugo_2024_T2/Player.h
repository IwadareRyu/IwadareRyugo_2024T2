#pragma once
#include <Siv3D.hpp>
#include "GameObject.h"
#include "Bullet.h"

namespace player
{
	const int DEFAULT_SPEED = 200;

	const Vec2 INIT_POS{ 400,400 };
}

class Player : GameObject
{
public:

	bool m_isPlayerFacingRight;

	Texture m_playerTexture;

	Player();

	~Player();

	Vec2 M_InitPosition() override;

	void M_PlayerInput(std::list<Bullet*>* bulletList);

	void M_PlayerXMove(int minas);

	void M_PlayerYMove(int minas);

	void M_PlayerShot(std::list<Bullet*>* bulletList);

	void M_PlayerLife();

	void M_PlayerDraw(double scale);
};

