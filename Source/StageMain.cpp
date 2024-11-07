//#include"Stage.h"
#include"StageMain.h"

//static Stage* instance = nullptr;

////�C���X�^���X�擾
//Stage& Stage::Instance()
//{
//
//    return *instance;
//}
//
////�R���X�g���N�^
//Stage::Stage()
//{
//
//    instance = this;
//
//    //�X�e�[�W���f����ǂݍ���
//    model = new Model("Data/Model/ExampleStage/ExampleStage.mdl");
//}
//
//Stage::~Stage()
//{
//    //�X�e�[�W���f���̔j��
//    delete model;
//}
//
//void Stage::Update(float elapsedTime)
//{
//    //���͓��ɂ�邱�ƂȂ�
//}
//
//void Stage::Render(ID3D11DeviceContext* dc, Shader* shader)
//{
//    //�V�F�[�_�[�Ƀ��f����`�悵�Ă��炤
//    shader->Draw(dc, model);
//}
//
////���C�L���X�g
//bool Stage::RayCast(const DirectX::XMFLOAT3& start, const DirectX::XMFLOAT3& end, HitResult& hit)
//{
//    return Collision::IntersectRayVsModel(start,end,model,hit);
//}

//�R���X�g���N�^
StageMain::StageMain()
{
    //�X�e�[�W���f����ǂݍ���
    model = new Model("Data/Model/ExampleStage/ExampleStage.mdl");
}

//�f�X�g���N�^
StageMain::~StageMain()
{
    //�X�e�[�W���f����j��
    delete model;
}

//�X�V����
void StageMain::Update(float elapsedTime)
{
    //���͓��ɂ�邱�Ƃ͂Ȃ�
}

//�`�揈��
void StageMain::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    //�V�F�[�_�[�Ƀ��f����`�悵�Ă��炤
    shader->Draw(dc, model);
}

//���C�L���X�g
bool StageMain::RayCast(const DirectX::XMFLOAT3& start, const DirectX::XMFLOAT3& end, HitResult& hit)
{
    return Collision::IntersectRayVsModel(start, end, model, hit);;
}
