#include "stdafx.h"
#include "SpawnBullet.h"

SpawnBullet::SpawnBullet(float x,float y,float offSetAngle){
	m_position = { x, y };
	m_offSetAngle = offSetAngle;
}

// スポーンポイントのの初期位置
Vec2 SpawnBullet::M_InitPosition() {
	return spawnBullet::INIT_POS;
}

// 没：スポーン方法の設定
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

// Forward方向に跳ぶ弾の生成
void SpawnBullet::M_ForwardSpawn(std::list<Bullet*>* bulletList, float speed)
{
	Bullet* p_bullet = new Bullet();
	p_bullet->M_SpawnInit(m_position, speed, Math::ToRadians(180), {Math::Cos(Math::ToRadians(180 - 90)), Math::Sin(Math::ToRadians(180 - 90))
});
	bulletList->push_back(p_bullet);
}

// 円型に等間隔で飛ばす弾の生成
void SpawnBullet::M_CircleSpawn(std::list<Bullet*>* bulletList,
	float disRota, float speed)
{
	for (auto i = 0; i < 360; i+= disRota)
	{
		Bullet* p_bullet = new Bullet();
		p_bullet->M_SpawnInit(m_position, 200, Math::ToRadians(i),
			{ Math::Cos(Math::ToRadians(i - 90)),Math::Sin(Math::ToRadians(i - 90)) });
		bulletList->push_back(p_bullet);
	}
}

//波状の形を作る弾の生成
void SpawnBullet::M_WaveSpawn(std::list<Bullet*>* bulletList,
	float disRota, float speed)
{
	m_currentOffsetTime += Scene::DeltaTime();
	if (m_currentOffsetTime > spawnBullet::OFFSET_TIME)
	{
		for (auto i = m_currentOffSetAngle; i < 360 + m_currentOffSetAngle; i += disRota)
		{
			Bullet* p_bullet = new Bullet();
			p_bullet->M_SpawnInit(m_position, 200,
				Math::ToRadians(i),
				{ Math::Cos(Math::ToRadians(i - 90)),
				Math::Sin(Math::ToRadians(i - 90)) });
			bulletList->push_back(p_bullet);
			if (m_currentWaveCount >= spawnBullet::WAVE_COUNT)
			{
				m_currentWaveCount = 0;
				m_offSetAngle = -m_offSetAngle;
				m_currentOffSetAngle = 0;
			}
		}
		m_currentOffSetAngle += m_offSetAngle;
		m_currentWaveCount++;
		m_currentOffsetTime = 0;
	}
}

// スポーンクールタイム
float SpawnBullet::M_CountTime()
{
	m_currentTime += Scene::DeltaTime();
	return m_currentTime;
}

