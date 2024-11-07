#pragma once

#include"Graphics/Model.h"
#include"Graphics/Shader.h"


class kakapo
{
public:
    kakapo();
    ~kakapo();

    void Update(float elapsedTime);

    void Render(ID3D11DeviceContext* dc, Shader* shader);

private:
    Model* model = nullptr;
};


