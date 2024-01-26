#pragma once
#include "Engine/GameObject.h"

class Tank;
class Text;

class PlayScene :
    public GameObject
{
	Tank* player;
	Text* pText;
	int enemyNum;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void DescEnemy() { enemyNum--; }
	bool IsEnemyLeft() { return enemyNum > 0; }
	int  GetEnemyNum() { return enemyNum; }

};

