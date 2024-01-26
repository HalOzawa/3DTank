#pragma once
#include "Engine/GameObject.h"
class TankUp :
    public GameObject
{
private:
    int hModel_;
public:
    TankUp(GameObject* parent);

    //デストラクタ
    ~TankUp();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    /// <summary>
    /// モデル番号を返す関数
    /// </summary>
    /// <returns>int hModel：モデル番号</returns>
    int GetModelHandle() { return hModel_; }
};

