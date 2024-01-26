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
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void DescEnemy() { enemyNum--; }
	bool IsEnemyLeft() { return enemyNum > 0; }
	int  GetEnemyNum() { return enemyNum; }

};

