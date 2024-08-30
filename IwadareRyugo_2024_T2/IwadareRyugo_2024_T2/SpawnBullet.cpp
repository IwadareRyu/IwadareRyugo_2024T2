#include "stdafx.h"
#include "SpawnBullet.h"

SpawnBullet::SpawnBullet(float x,float y){
	m_position = { x, y };
}

Vec2 SpawnBullet::M_InitPosition() {
	return spawnBullet::INIT_POS;
}


void SpawnBullet::M_Spawn(SpawnType type)
{

}

float SpawnBullet::M_CountTime()
{
	_currentTime += Scene::DeltaTime();
	return _currentTime;
}

