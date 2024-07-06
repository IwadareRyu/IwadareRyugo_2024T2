#include "stdafx.h"
#include "Player.h"

Player::Player() : m_currentSpeed(player::DEFAULT_SPEED),m_position(player::INIT_POS),m_isPlayerFacingRight(false){}



void Player::M_PlayerInput(){
	if (KeyLeft.pressed() || KeyA.pressed()){
		M_PlayerXMove(-1);
		
	}
	else if (KeyRight.pressed() || KeyD.pressed()){
		M_PlayerXMove(1);
	}

	if (KeyUp.pressed() || KeyW.pressed()){
		M_PlayerYMove(-1);
	}
	else if (KeyDown.pressed() || KeyS.pressed()){
		M_PlayerYMove(1);
	}

	if (KeySpace.pressed())
	{
		M_PlayerShot();
	}
}

void Player::M_PlayerXMove(int minas){
	m_position.x = m_position.x + minas * m_currentSpeed * Scene::DeltaTime();
	if(minas < 0){
		m_position.x = Max(m_position.x, player::MIN_POS.x);
		m_isPlayerFacingRight = true;
	}
	else {
		m_position.x = Min(m_position.x, player::MAX_POS.x);
		m_isPlayerFacingRight = false;
	}
}

void Player::M_PlayerYMove(int minas){
	m_position.y = m_position.y + minas * m_currentSpeed * Scene::DeltaTime();
	if (minas < 0) {
		m_position.y = Max(m_position.y, player::MIN_POS.y);
	}
	else {
		m_position.y = Min(m_position.y, player::MAX_POS.y);
	}
}

void Player::M_PlayerShot(){

}

void Player::M_PlayerLife(){

}

void Player::M_PlayerDraw(double scale)
{
	m_playerTexture.scaled(scale).mirrored(m_isPlayerFacingRight).drawAt(m_position);
}
