# include <Siv3D.hpp> // Siv3D v0.6.13
#include "Player.h"
#include "Bullet.h"

void Main()
{
	const Texture PLAYER_TEXTURE{
	U"example/Tiles/tile_0097.png"
	};
	const Texture BULLET_TEXTURE{ U"example/Tiles/tile_0103.png" };

	Texture enemyTexture{
		U"example/Tiles/tile_0121.png"
	};

	Player player;

	std::list<Bullet*> playerBulletList;

	std::list<Bullet*> enemyBulletList;

	const double SCALE = 2;

	const Font FONT{ 40 };

	player.m_playerTexture = PLAYER_TEXTURE;

	while (System::Update())
	{
		player.M_PlayerInput(&playerBulletList);

		player.M_PlayerDraw(SCALE);

		enemyTexture.scaled(10).mirrored(false).drawAt(400,200);

		//FONT(U"俺たちの弾幕アクション！！！").drawAt(Scene::Width() / 2, Scene::Height() / 2);

		auto it = playerBulletList.begin();
		while (it != playerBulletList.end())
		{
			Bullet* bullet = *it;
			auto lifeTime = bullet->M_LifeTime();
			if (lifeTime <= 0)
			{
				it = playerBulletList.erase(it);
				delete bullet;
			}
			else
			{
				bullet->M_Move();
				bullet->M_Draw(BULLET_TEXTURE, SCALE, false);
				it++;
			}
		}
	}

	auto it = playerBulletList.begin();
	for (; it != playerBulletList.end(); it++)
	{
		delete* it;
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
