#pragma once
#include"Stage.h"
#include"Player.h"
#include"CameraController.h"
#include"Scene.h"
#include"Graphics/Sprite.h"
#include"kakapo.h"


// �Q�[���V�[��
//class SceneGame
class SceneGame:public Scene
{
public:
	SceneGame() {}
	//~SceneGame() {}
	~SceneGame()override {}

	// ������
	//void Initialize();
	void Initialize()override;

	// �I����
	//void Finalize();
	void Finalize()override;

	// �X�V����
	//void Update(float elapsedTime);
	void Update(float elapsedTime)override;

	// �`�揈��
	//void Render();
	void Render()override;


private:
	//�G�l�~�[HP�Q�[�W�`��
	void RenderEnemyGauge(
		ID3D11DeviceContext* dc,
		const DirectX::XMFLOAT4X4& view,
		const DirectX::XMFLOAT4X4& projection
	);

private:
	//Stage* stage = nullptr;
	Player* player = nullptr;
	kakapo* kaka = nullptr;

	CameraController* cameraController = nullptr;
	Sprite* guage = nullptr;
	
};
