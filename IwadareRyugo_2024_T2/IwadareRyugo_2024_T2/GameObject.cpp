#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : m_currentSpeed(gameObject::DEFAULT_SPEED) {};

const void GameObject::M_MaxX() {
	m_position.x = Max(m_position.x, gameObject::MIN_POS.x);
	m_position.x = Min(m_position.x, gameObject::MAX_POS.x);
}

const void GameObject::M_MaxY() {
	m_position.y = Max(m_position.y, gameObject::MIN_POS.y);
	m_position.y = Min(m_position.y, gameObject::MAX_POS.y);
}

const void GameObject::M_Draw(const Texture texture, const double scale, const bool mirror = false){
	texture.scaled(scale).mirrored(mirror).drawAt(m_position);
}
