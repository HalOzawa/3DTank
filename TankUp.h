#pragma once
#include "Engine/GameObject.h"
class TankUp :
    public GameObject
{
private:
    int hModel_;
public:
    TankUp(GameObject* parent);

    //�f�X�g���N�^
    ~TankUp();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    /// <summary>
    /// ���f���ԍ���Ԃ��֐�
    /// </summary>
    /// <returns>int hModel�F���f���ԍ�</returns>
    int GetModelHandle() { return hModel_; }
};

