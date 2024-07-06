#pragma once
#include <Siv3D.hpp>

namespace player
{
	const int DEFAULT_SPEED = 200;

	const Vec2 INIT_POS{ 400,400 };

	const Vec2 MIN_POS = { 60.0 ,30.0 };

	const Vec2 MAX_POS = { 740.0,550.0 };


}

class Player
{
public:
	int m_currentSpeed;

	Vec2 m_position;

	bool m_isPlayerFacingRight;

	Texture m_playerTexture;

	Player();

	~Player() {}

	void M_PlayerInput();

	void M_PlayerXMove(int minas);

	void M_PlayerYMove(int minas);

	void M_PlayerShot();

	void M_PlayerLife();

	void M_PlayerDraw(double scale);
};

