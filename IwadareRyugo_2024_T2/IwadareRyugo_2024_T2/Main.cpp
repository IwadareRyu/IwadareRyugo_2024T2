﻿# include <Siv3D.hpp> // Siv3D v0.6.13
#include "Player.h"
#include "Bullet.h"
#include "SpawnBullet.h"

void LifeBullet(std::list<Bullet*>* bulletList,Texture texture,double scale)
{
	auto it = bulletList->begin();
	while (it != bulletList->end())
	{
		Bullet* bullet = *it;
		auto lifeTime = bullet->M_LifeTime();
		if (lifeTime <= 0)
		{
			it = bulletList->erase(it);
			delete bullet;
		}
		else
		{
			bullet->M_Move();
			bullet->M_Draw(texture, scale, false,bullet->m_rotaRange);
			it++;
		}
	}
}

namespace MainSpace{
	namespace Enemy {
		const Vec2 INIT_POS{ 400,200 };
	};
};

void Main()
{
	const Texture PLAYER_TEXTURE{
	    U"example/Tiles/tile_0097.png"
	};

	const Texture BULLET_TEXTURE{
		U"example/Tiles/tile_0103.png"
	};

	Texture enemyTexture{
		U"example/Tiles/tile_0121.png"
	};

	Player player;

	std::list<Bullet*> playerBulletList;

	std::list<Bullet*> enemyBulletList;

	SpawnBullet spawnPoint(MainSpace::Enemy::INIT_POS.x,MainSpace::Enemy::INIT_POS.y,5);

	const double SCALE = 2;

	const Font FONT{ 40 };

	player.m_playerTexture = PLAYER_TEXTURE;

	while (System::Update())
	{
		player.M_PlayerInput(&playerBulletList);

		player.M_PlayerDraw(SCALE);

		enemyTexture.scaled(10).mirrored(false).drawAt(MainSpace::Enemy::INIT_POS);

		spawnPoint.M_CountTime();

		if (spawnPoint._currentTime > spawnBullet::SPAWN_TIME)
		{
			//spawnPoint.M_ForwardSpawn(&enemyBulletList);
			//spawnPoint.M_CircleSpawn(&enemyBulletList, 30);
			spawnPoint._currentTime = 0;
		}
		spawnPoint.M_WaveSpawn(&enemyBulletList, 30);

		LifeBullet(&playerBulletList, BULLET_TEXTURE, SCALE);
		LifeBullet(&enemyBulletList, BULLET_TEXTURE, SCALE);
	}

	auto itP = playerBulletList.begin();
	for (; itP != playerBulletList.end(); itP++)
	{
		delete* itP;
	}

	auto itE = enemyBulletList.begin();
	for (; itE != enemyBulletList.end(); itE++)
	{
		delete* itE;
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
