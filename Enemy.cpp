#include "Enemy.h"
#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Collider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\kinoko.fbx");
	assert(hModel_ >= 0);
	//�A�j���[�V�����̃Z�b�g
	Model::SetAnimFrame(hModel_, 0, 300, 2.0f);

	float x = (float)rand() / RAND_MAX;
	x = 2.0 * x;
	transform_.position_.x = 25.0 * (x - 1.0);
	float z = (float)rand() / RAND_MAX;
	z = 2.0 * z;
	transform_.position_.z = 25.0 * (z - 1.0);
	transform_.position_.y = 0;

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3({0, -1, 0});
	Model::RayCast(hGmodel, &data);

	if (data.hit == true) {
		transform_.position_.y = -data.dist + 0.5;
	}
	SphereCollider* spc = new SphereCollider({ 0,0,0 }, 0.5);
	AddCollider(spc);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
