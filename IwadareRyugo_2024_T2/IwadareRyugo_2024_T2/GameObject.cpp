#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : m_currentSpeed(gameObject::DEFAULT_SPEED) {};

void GameObject::M_MaxX() {
	m_position.x = Max(m_position.x, gameObject::MIN_POS.x);
	m_position.x = Min(m_position.x, gameObject::MAX_POS.x);
}

void GameObject::M_MaxY() {
	m_position.y = Max(m_position.y, gameObject::MIN_POS.y);
	m_position.y = Min(m_position.y, gameObject::MAX_POS.y);
}

void GameObject::M_Draw(Texture texture, double scale, bool mirror = false){
	texture.scaled(scale).mirrored(mirror).drawAt(m_position);
}
