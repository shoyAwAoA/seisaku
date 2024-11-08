#pragma once
#include"Stage.h"
#include"Player.h"
#include"CameraController.h"
#include"Scene.h"
#include"Graphics/Sprite.h"
#include"kakapo.h"


// ゲームシーン
//class SceneGame
class SceneGame:public Scene
{
public:
	SceneGame() {}
	//~SceneGame() {}
	~SceneGame()override {}

	// 初期化
	//void Initialize();
	void Initialize()override;

	// 終了化
	//void Finalize();
	void Finalize()override;

	// 更新処理
	//void Update(float elapsedTime);
	void Update(float elapsedTime)override;

	// 描画処理
	//void Render();
	void Render()override;


private:
	//エネミーHPゲージ描画
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
