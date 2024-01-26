#include "ClearScene.h"
#include "Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), cPict_(-1)
{
}

void ClearScene::Initialize()
{
	cPict_ = Image::Load("Clear.png");
	assert(cPict_ >= 0);
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Image::SetTransform(cPict_, transform_);
	Image::Draw(cPict_);
}

void ClearScene::Release()
{
}
