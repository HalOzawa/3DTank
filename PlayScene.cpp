#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "TankUp.h"
#include "Enemy.h"
#include "HUD.h"
#include "Engine//SceneManager.h"

#include "Engine/Camera.h"

namespace
{
	const int ENEMY_NUM{ 2 };
}

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), pText(nullptr)
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	enemyNum = ENEMY_NUM;
	for(int i=0; i<enemyNum; i++)
		Instantiate<Enemy>(this);

	Instantiate<HUD>(this);
	//Instantiate<TankUp>(this);
	//Camera::SetPosition(XMFLOAT3(0, 5, -15));
	
}

void PlayScene::Update()
{
	//Camera::SetTarget(player->GetPosition());
	//XMFLOAT3 camPos = player->GetPosition();
	//camPos.y += 8;
	//camPos.x -= 15;
	//Camera::SetPosition(camPos);
	if (enemyNum < 0) {
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		//SceneManager* pSM = static_cast<SceneManager *>(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	
}

void PlayScene::Release()
{
}
