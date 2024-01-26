#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include <string>
class HUD :
    public GameObject
{
public:
    HUD(GameObject* parent);
    int hHUD_;
    int hNumbers_;
    Transform tHud_;
    std::vector<Transform> tNumbers_;
    //‰Šú‰»
    void Initialize() override;

    //XV
    void Update() override;

    //•`‰æ
    void Draw() override;

    //ŠJ•ú
    void Release() override;
};

