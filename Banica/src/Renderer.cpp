#include "Renderer.h"
#include "Particle.h"

#include <iostream>

namespace bnc
{
    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::RenderGrid()
    {
        m_CellsInfo = m_Data->levels->operator[](*m_Data->currentLevel)->GetGridCells();


        BeginShaderMode(m_Data->lightShader);

        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        { 
            switch(m_CellsInfo[i]->titleType)
            {
                case bnc::PLAYER:
                    DrawPlayer(i); break;

                case bnc::GATE:
                    DrawGate(i); break;

                case bnc::LAMP:
                    DrawLamp(i); break;

                default: 
                    DrawTile(i); break;
                    
            }
        }
        EndShaderMode();
    }

    inline void Renderer::DrawPlayer(uint32_t index)
    {
        DrawTextureRec(
            m_Data->spriteTexture,
            Rectangle({0, 60.0f * 3, 60.0f, 60.0f}),
            m_CellsInfo[index]->position,
            RAYWHITE
        );
    }

    inline void Renderer::DrawTile(uint32_t index)
    {
        DrawTextureRec(
            m_Data->spriteTexture,
            Rectangle({0.0f, 0.0f, 60.0f, 60.0f}),
            m_CellsInfo[index]->position,
            RAYWHITE
        );
    }

    void Renderer::DrawGate(uint32_t index)
    {

        //* Find the type of the gate and render it accordingly
        uint32_t temp; 
        for (size_t j = 0; j < m_Data->levels->operator[](*m_Data->currentLevel)->GetGates().size(); j++)
        {
            if(m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[j]->GetCellPosition() == index)
            {
                temp = m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[j]->GetType(); 
            }
        }
                
        switch (temp)
        {
        case bnc::AND:
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({0, 60.0f * 2, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );
            break;

        case bnc::OR:
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({60.0f, 60.0f * 2, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );
            break;

        case bnc::NOT:
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({60.0f * 2, 60.0f * 2, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );
            break;

        case bnc::XOR:
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({60.0f * 3, 60.0f * 2, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );
            break; 

        default:
            break;
        }
    }

    void Renderer::DrawLamp(uint32_t index)
    {
        std::vector<std::shared_ptr<Lamp>>& r_lamps = m_Data->levels->operator[](*m_Data->currentLevel)->GetLamps();

        uint32_t temp; 

        for (size_t j = 0; j < r_lamps.size(); j++)
        {
            if(r_lamps[j]->GetPosition() == index)
            {
                temp = r_lamps[j]->GetType(); 
            }
        }

        if(temp == bnc::LAMP_ON)
        {
            BeginShaderMode(m_Data->bloomShader);

            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({0, 60.0f, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );

            EndShaderMode();
        }
        else
        {
            EndShaderMode();
            
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({60.0f, 60.0f, 60.0f, 60.0f}),
                m_CellsInfo[index]->position,
                RAYWHITE
            );
        }

        
        BeginShaderMode(m_Data->lightShader);
    }

    void Renderer::GetLampsPosition()
    {
        std::vector<std::shared_ptr<Lamp>>& r_lamps = m_Data->levels->operator[](*m_Data->currentLevel)->GetLamps();

        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            uint32_t temp = 0; 

            for (size_t j = 0; j < r_lamps.size(); j++)
            {
                if(r_lamps[j]->GetPosition() == i)
                {
                    temp = r_lamps[j]->GetType(); 
                }
            }

            if(m_CellsInfo[i]->titleType == bnc::LAMP)
            {
                if(temp == bnc::LAMP_ON)
                {
                    m_Ligthcount++;
                    m_LigthPosition.push_back(Vector2({m_CellsInfo[i]->position.x + 30, GetScreenHeight() - m_CellsInfo[i]->position.y - 30}));
                }
            }
        }
    }

    void Renderer::RenderParticles()
    {
        std::vector<std::shared_ptr<Particle>>& r_Particles = *m_Data->particles;


        BeginShaderMode(m_Data->lightShader);

        for (size_t i = 0; i < r_Particles.size(); i++)
        {
            DrawRectangle(r_Particles[i]->pariclePosition.x, r_Particles[i]->pariclePosition.y, r_Particles[i]->particleSize, r_Particles[i]->particleSize, r_Particles[i]->particleColor);
        }

        EndShaderMode();
    }

    void Renderer::Render(std::shared_ptr<bnc::RenderData> data)
    {
        m_Data = data;

        Clear();

        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), CLITERAL(Color){30, 30, 30, 255});

        if(*m_Data->gameState == bnc::TUTORIAL || *m_Data->gameState == bnc::GAME)
        {
            GetLampsPosition();

            Vector2* arr = m_LigthPosition.data();

            
            SetShaderValue(m_Data->lightShader, GetShaderLocation(m_Data->lightShader, "numLights"), &m_Ligthcount, SHADER_UNIFORM_INT);
            SetShaderValueV(m_Data->lightShader, GetShaderLocation(m_Data->lightShader, "lightPositions"), arr, SHADER_UNIFORM_VEC2, m_LigthPosition.size());


            RenderGrid();
            RenderParticles();


            m_Ligthcount = 0;
            m_LigthPosition.clear();
        }
        


        DrawFPS(0, 0);
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}