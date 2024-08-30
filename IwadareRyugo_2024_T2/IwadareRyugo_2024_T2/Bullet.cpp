#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet() : m_speed(bullet::DEFAULT_SPEED), m_rotaRange(0.0f), m_dir(bullet::INIT_DIRECTION),m_life(bullet::LIFE_TIME){
	m_position = M_InitPosition();
}

Vec2 Bullet::M_InitPosition() {
	return bullet::INIT_POS;
}
const void Bullet::M_SpawnInit(const Vec2 spawnPos, const float speed = bullet::DEFAULT_SPEED, const float rotaRange = 0.0f, const Vec2 dir = bullet::INIT_DIRECTION){
	m_position = spawnPos;
	m_speed = speed;
	m_rotaRange = rotaRange;
	m_dir = dir;
}

const void Bullet::M_Move(){
	m_position = m_position + m_dir * m_speed * Scene::DeltaTime();
}

const void Bullet::M_Rota(){

}

const float Bullet::M_LifeTime() {
	return m_life = m_life - Scene::DeltaTime();
}
