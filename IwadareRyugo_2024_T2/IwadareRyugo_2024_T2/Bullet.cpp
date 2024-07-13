#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet() : m_speed(bullet::DEFAULT_SPEED), m_rotaRange(0.0f), m_dir(bullet::INIT_DIRECTION){
	m_position = M_InitPosition();
}

Vec2 Bullet::M_InitPosition() {
	return bullet::INIT_POS;
}
void Bullet::M_SpawnInit(Vec2 spawnPos,float speed = bullet::DEFAULT_SPEED, float rotaRange = 0.0f, Vec2 dir = bullet::INIT_DIRECTION){
	m_position = spawnPos;
	m_speed = speed;
	m_rotaRange = rotaRange;
	m_dir = dir;
}

void Bullet::M_Move(){
	m_position = m_position + m_dir * m_speed * Scene::DeltaTime();
}

void Bullet::M_Rota(){}

