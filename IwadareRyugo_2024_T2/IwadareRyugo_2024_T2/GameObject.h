#pragma once

namespace gameObject
{
	const int DEFAULT_SPEED = 200;

	const Vec2 MIN_POS = { 60.0 ,30.0 };

	const Vec2 MAX_POS = { 740.0,550.0 };

	const Vec2 INIT_POS{ 200,400 };
}

class GameObject
{
public:
	int m_currentSpeed;

	Vec2 m_position;

	GameObject();
	~GameObject() {};
	void M_MaxX();
	void M_MaxY();
	void M_Draw(Texture texture, double scale, bool mirror);
	virtual Vec2 M_InitPosition() { return gameObject::MIN_POS; };
};

