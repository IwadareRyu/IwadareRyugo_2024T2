#include "stdafx.h"
#include "SpawnBullet.h"

SpawnBullet::SpawnBullet(float x,float y,float offSetAngle){
	m_position = { x, y };
	_offSetAngle = offSetAngle;
}

Vec2 SpawnBullet::M_InitPosition() {
	return spawnBullet::INIT_POS;
}


//void SpawnBullet::M_Spawn(SpawnType type, std::list<Bullet*>* bulletList,float disRota) {
//	switch (type)
//	{
//	case ForwardSpawn:
//		M_ForwardSpawn(bulletList);
//		break;
//	case CircleSpawn:
//		M_CircleSpawn(bulletList,disRota);
//		break;
//	case WaveSpawn:
//		M_WaveSpawn(bulletList,disRota);
//		break;
//	}
//}

void SpawnBullet::M_ForwardSpawn(std::list<Bullet*>* bulletList)
{
	Bullet* bullet = new Bullet();
	bullet->M_SpawnInit(m_position, 200, Math::ToRadians(180), {Math::Cos(Math::ToRadians(180 - 90)), Math::Sin(Math::ToRadians(180 - 90))
});
	bulletList->push_back(bullet);
}

void SpawnBullet::M_CircleSpawn(std::list<Bullet*>* bulletList,
	float disRota)
{
	for (auto i = 0; i < 360; i+= disRota)
	{
		Bullet* bullet = new Bullet();
		bullet->M_SpawnInit(m_position, 200, Math::ToRadians(i),
			{ Math::Cos(Math::ToRadians(i - 90)),Math::Sin(Math::ToRadians(i - 90)) });
		bulletList->push_back(bullet);
	}
}

void SpawnBullet::M_WaveSpawn(std::list<Bullet*>* bulletList,
	float disRota)
{
	_currentOffsetTime += Scene::DeltaTime();
	if (_currentOffsetTime > spawnBullet::OFFSET_TIME)
	{
		for (auto i = _currentOffSetAngle; i < 360 + _currentOffSetAngle; i += disRota)
		{
			Bullet* bullet = new Bullet();
			bullet->M_SpawnInit(m_position, 200,
				Math::ToRadians(i),
				{ Math::Cos(Math::ToRadians(i - 90)),
				Math::Sin(Math::ToRadians(i - 90)) });
			bulletList->push_back(bullet);
			_currentOffSetAngle += _offSetAngle;

			_currentWaveCount++;
			if (_currentWaveCount >= spawnBullet::WAVE_COUNT)
			{
				_currentWaveCount = 0;
				_offSetAngle = -_offSetAngle;
				_currentOffSetAngle = 0;
			}
		}
		_currentOffsetTime = 0;
	}
}

float SpawnBullet::M_CountTime()
{
	_currentTime += Scene::DeltaTime();
	return _currentTime;
}

