﻿#include"CameraController.h"
#include"Camera.h"
#include"Input/Input.h"
#include"Player.h"
void CameraController::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();
    Mouse& mouse = Input::Instance().GetMouse();
    Player& player = Player::Instance();
    POINT P = { 1920 * 0.5f, 1080 * 0.5f };
    /*float ax = gamePad.GetAxisRX();
    float ay   = gamePad.GetAxisRY();*/
    float ax = mouse.GetPositionX();
    float ay = mouse.GetPositionY();
    float oldAx = mouse.GetOldPositionX();
    float oldAy = mouse.GetOldPositionY();
    float dx = ax - oldAx;
    float dy = ay - oldAy;
    //カメラの回転速度
    float speed = rollSpeed * elapsedTime;
    //スティックの入力値に合わせてX軸とY軸を回転
    angle.y += dx * sensitivity;
    angle.x += dy * sensitivity;
    //X軸のカメラ回転を制限
  //  float speed = rollSpeed * elapsedTime;
    while (angle.x > maxAngleX)
    {
        angle.x = maxAngleX;
    }
    while (angle.x < minAngleX)
    {
        angle.x = minAngleX;
    }
    if ((fabsf(ax - P.x) > 50 || fabsf(ay - P.y) > 50))
    {
        mouse.setMouseCursorPos(P.x, P.y);
    }
    //Y軸の回転値を-3.14〜3.14に収まるようにする
    if (angle.y < -DirectX::XM_PI)
    {
        angle.y += DirectX::XM_2PI;
    }
    if (angle.y > DirectX::XM_PI)
    {
        angle.y -= DirectX::XM_2PI;
    }
    if (angle.x > DirectX::XMConvertToRadians(45))
    {
        angle.x = DirectX::XMConvertToRadians(45);
    }
    if (angle.x < DirectX::XMConvertToRadians(-45))
    {
        angle.x = DirectX::XMConvertToRadians(-45);
    }
    //カメラ回転値を回転行列に変換
    DirectX::XMMATRIX Transform = DirectX::XMMatrixRotationRollPitchYaw(angle.x, angle.y, angle.z);
    //回転行列から前方向ベクトルを取り出す
    DirectX::XMVECTOR Front = Transform.r[2];
    DirectX::XMFLOAT3 front;
    DirectX::XMStoreFloat3(&front, Front);
    //注意点から後ろベクトル方向に一定距離離れたカメラ視点を求める
    DirectX::XMFLOAT3 eye = target;
    /* eye.x = target.x - front.x * range;
     eye.y = target.y - front.y * range;
     eye.z = target.z - front.z * range;*/
    eye.x += front.x * 0.5f;//前方にオフセットを加える
    eye.y += player.GetHeight() / 3.0f;
    eye.z += front.z * 0.5f;
    //カメラの視点と注視点を設定
//  Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(0, 1, 0));
    Camera::Instance().SetLookAt(
        eye,
        DirectX::XMFLOAT3(target.x + front.x, target.y + front.y + player.GetHeight() / 3.0f, target.z + front.z),
        DirectX::XMFLOAT3(0, 1, 0));
}