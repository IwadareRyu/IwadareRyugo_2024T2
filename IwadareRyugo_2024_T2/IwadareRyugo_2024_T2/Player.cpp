#include "stdafx.h"
#include "Player.h"

Player::Player() : m_isPlayerFacingRight(false){
	m_position = M_InitPosition();
}

Player::~Player() {}

Vec2 Player::M_InitPosition(){
	return player::INIT_POS;
}

void Player::M_PlayerInput(std::list<Bullet*>* bulletList){
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

void Player::M_PlayerXMove(int minas){
	m_position.x = m_position.x + minas * m_currentSpeed * Scene::DeltaTime();
	M_MaxX();
}

void Player::M_PlayerYMove(int minas){
	m_position.y = m_position.y + minas * m_currentSpeed * Scene::DeltaTime();
	M_MaxY();
}

void Player::M_PlayerShot(std::list<Bullet*>* bulletList){
	Bullet* bullet = new Bullet();
	bullet->M_SpawnInit(m_position, 200, 0, {0,-1});
	bulletList->push_back(bullet);
}

void Player::M_PlayerLife(){

}

void Player::M_PlayerDraw(double scale)
{
	m_playerTexture.scaled(scale).mirrored(m_isPlayerFacingRight).drawAt(m_position);
}
