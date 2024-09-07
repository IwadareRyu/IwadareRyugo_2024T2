#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() : m_currentSpeed(gameObject::DEFAULT_SPEED) {};

// X方向の画面外の確認
const void GameObject::M_MaxX() {
	m_position.x = Max(m_position.x, gameObject::MIN_POS.x);
	m_position.x = Min(m_position.x, gameObject::MAX_POS.x);
}

// Y方向の画面外の確認
const void GameObject::M_MaxY() {
	m_position.y = Max(m_position.y, gameObject::MIN_POS.y);
	m_position.y = Min(m_position.y, gameObject::MAX_POS.y);
}

// 描画
const void GameObject::M_Draw(const Texture texture, const double scale, const bool mirror,float rota){
	texture.scaled(scale).mirrored(mirror).rotated(rota).drawAt(m_position);
}
