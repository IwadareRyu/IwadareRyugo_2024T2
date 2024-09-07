#pragma once
#include <Siv3D.hpp>
#include "GameObject.h"
#include "Bullet.h"

namespace player
{
	const int DEFAULT_SPEED = 300;

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

	const void M_PlayerInput(std::list<Bullet*>* bulletList);

	const void M_PlayerXMove(const int minas);

	const void M_PlayerYMove(const int minas);

	const void M_PlayerShot(std::list<Bullet*>* bulletList);

	const void M_PlayerLife();

	const void M_PlayerDraw(const double scale);
};

