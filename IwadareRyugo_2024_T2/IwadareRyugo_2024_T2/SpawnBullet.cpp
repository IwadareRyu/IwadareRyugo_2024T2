#include "stdafx.h"
#include "SpawnBullet.h"

SpawnBullet::SpawnBullet(){
	m_position = M_InitPosition();
}

Vec2 SpawnBullet::M_InitPosition() {
	return spawnBullet::INIT_POS;
}


