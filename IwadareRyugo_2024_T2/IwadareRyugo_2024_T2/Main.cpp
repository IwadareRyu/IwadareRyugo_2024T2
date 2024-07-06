# include <Siv3D.hpp> // Siv3D v0.6.13
#include "Player.h"

void Main()
{
	const Texture PLAYER_TEXTURE{
	U"example/Tiles/tile_0097.png"
	};

	Player player;

	const double SCALE = 2;

	const Font FONT{ 40 };

	player.m_playerTexture = PLAYER_TEXTURE;

	while (System::Update())
	{
		player.M_PlayerInput();

		player.M_PlayerDraw(SCALE);

		FONT(U"俺たちの弾幕アクション！！！").drawAt(Scene::Width() / 2, Scene::Height() / 2);
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
