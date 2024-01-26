#include "TankUp.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

TankUp::TankUp(GameObject* parent)
	:GameObject(parent, "TankUp"), hModel_(-1)
{
}

TankUp::~TankUp()
{
}

void TankUp::Initialize()
{
	hModel_ = Model::Load("Model\\TankUp.fbx");
	assert(hModel_ >= 0);
}

void TankUp::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		this->transform_.rotate_.y -= 2.0;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		this->transform_.rotate_.y += 2.0;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);

		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);

		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.2);
	}
}

void TankUp::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankUp::Release()
{
	
}
