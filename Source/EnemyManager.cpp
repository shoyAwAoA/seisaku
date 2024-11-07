#include"EnemyManager.h"
#include"Collision.h"

void EnemyManager::Update(float elapsedTime)
{
    for (Enemy* enemy : enemies)
    {
        enemy->Update(elapsedTime);
    }

    //�j������
    for (Enemy* enemy : removes)
    {
        std::vector<Enemy*>::iterator it = std::find(enemies.begin(), enemies.end(), enemy);

        if (it != enemies.end())
        {
            enemies.erase(it);
        }

    }


    //�G���m�̏Փˏ���
    CollisionEnemyVsEnemies();
}

void EnemyManager::Render(ID3D11DeviceContext* context, Shader* shader)
{
    for (Enemy* enemy : enemies)
    {
        enemy->Render(context, shader);
    }
}

//�G�l�~�[�o�^
void EnemyManager::Register(Enemy* enemy)
{
    enemies.emplace_back(enemy);
}

//�G�l�~�[�S�폜
void EnemyManager::Clear()
{
    for (Enemy* enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();
}

//�G�l�~�[�폜
void EnemyManager::Remove(Enemy* enemy)
{

    //�j�����X�g�ɒǉ�
    removes.insert(enemy);
}

void EnemyManager::DrawDebugPrimitive()
{
    for (Enemy* enemy : enemies)
    {
        enemy->DrawDebugPrimitive();
    }
}

void EnemyManager::CollisionEnemyVsEnemies()
{
    for (size_t i = 0; i < enemies.size(); ++i)
    {
        for (size_t j = 0; j < enemies.size(); ++j)
        {
            DirectX::XMFLOAT3 outenemyPosition;
            if (Collision::IntersectCylinderVsCylinder(
                enemies[i]->GetPosition(),
                enemies[i]->GetRadius(),
                enemies[i]->GetHeight(),
                enemies[j]->GetPosition(),
                enemies[j]->GetRadius(),
                enemies[j]->GetHeight(),
                outenemyPosition))
            {
                enemies[j]->SetPosition(outenemyPosition);
            }
        }
    }
}
