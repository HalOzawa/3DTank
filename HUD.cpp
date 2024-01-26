#include "HUD.h"
#include "Engine/Image.h"

HUD::HUD(GameObject* parent)
	:GameObject(parent, "HUD"), hHUD_(-1), hNumbers_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("HUD2.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("numbers.png");
	assert(hNumbers_ >= 0);
}

void HUD::Update()
{
	tHud_.position_ = { -0.72, 0.87, 1.5 };
	tHud_.scale_ = { 0.7, 0.7, 1.5 };
}

void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 0.9, 0.9, 0 };
	trans.position_ = { -0.68, 0.87, 0 };

	Image::SetRect(hNumbers_, 51 * 0, 0, 51, 61);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);

	trans.position_ = { -0.63, 0.87, 0 };
	Image::SetRect(hNumbers_, 51 * 9, 0, 51, 61);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);
}

void HUD::Release()
{
}
