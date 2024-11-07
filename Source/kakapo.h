#pragma once

#include"Graphics/Model.h"
#include"Graphics/Shader.h"
#include"Stage.h"


class kakapo
{
public:

    //唯一のインスタンス取得
    static kakapo& Instance()
    {
        static kakapo instance;
        return instance;
    }

    kakapo();
    ~kakapo();

    void Update(float elapsedTime);

    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};


