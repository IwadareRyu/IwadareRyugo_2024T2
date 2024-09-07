#include "stdafx.h"
#include "Player.h"

Player::Player() : m_isPlayerFacingRight(false){
	m_position = M_InitPosition();
}

Player::~Player() {}

// Playerの初期位置
Vec2 Player::M_InitPosition(){
	return player::INIT_POS;
}

// Inputによって処理をするメソッド
const void Player::M_PlayerInput(std::list<Bullet*>* bulletList){
	if (KeyLeft.pressed() || KeyA.pressed()){
		M_PlayerXMove(-1);
		m_isPlayerFacingRight = true;
	}
	else if (KeyRight.pressed() || KeyD.pressed()){
		M_PlayerXMove(1);
		m_isPlayerFacingRight = false;
	}

	if (KeyUp.pressed() || KeyW.pressed()){
		M_PlayerYMove(-1);
	}
	else if (KeyDown.pressed() || KeyS.pressed()){
		M_PlayerYMove(1);
	}

	if (KeySpace.down())
	{
		M_PlayerShot(bulletList);
	}
}

// X方向のPlayerの動き(Normalizeしてないです)
const void Player::M_PlayerXMove(const int minas){
	m_position.x = m_position.x + minas * m_currentSpeed * Scene::DeltaTime();
	M_MaxX();
}

// Y方向のPlayerの動き(Normalizeしてないです)
const void Player::M_PlayerYMove(const int minas){
	m_position.y = m_position.y + minas * m_currentSpeed * Scene::DeltaTime();
	M_MaxY();
}

// 弾を生成して飛ばすメソッド
const void Player::M_PlayerShot(std::list<Bullet*>* bulletList){
	Bullet* bullet = new Bullet();
	bullet->M_SpawnInit(m_position, 200, 0, {0,-1});
	bulletList->push_back(bullet);
}

//Playerのライフ(未実装)
const void Player::M_PlayerLife(){

}

// Playerの描画
const void Player::M_PlayerDraw(const double scale)
{
	M_Draw(m_playerTexture,scale,m_isPlayerFacingRight);
}
