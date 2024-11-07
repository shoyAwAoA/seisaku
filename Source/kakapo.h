#pragma once

#include"Graphics/Model.h"
#include"Graphics/Shader.h"
#include"Stage.h"
#include"Character.h"


class kakapo:public Character
{
public:

    static kakapo& Instance();

    kakapo();
    ~kakapo();

    void Update(float elapsedTime);

    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};


