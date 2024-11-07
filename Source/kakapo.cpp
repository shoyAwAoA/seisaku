#include "kakapo.h"

static kakapo* instance = nullptr;


kakapo& kakapo::Instance()
{

    return *instance;
}

kakapo::kakapo()
{
    instance = this;

    model = new Model("Data/Model/me/me.mdl");

}

kakapo::~kakapo()
{
    if (model != nullptr)
    {
        model = nullptr;
        delete model;
    }
}

void kakapo::Update(float elapsedTime)
{
    //‚¢‚Ü‚Í‚¢‚¢‚âB
}

void kakapo::Render(ID3D11DeviceContext* dc, Shader* shader)
{
    shader->Draw(dc, model);
}
