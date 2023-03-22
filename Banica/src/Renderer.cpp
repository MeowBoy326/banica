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

        for(size_t i = 0; i < m_CellsInfo.size(); i++)
        { 
            DrawTextureRec(
                m_Data->spriteTexture,
                Rectangle({0.0f, 0.0f, 60.0f, 60.0f}),
                m_CellsInfo[i]->position,
                RAYWHITE
            );
        }
    }

    void Renderer::RenderPlayer()
    {
        for(size_t i = 1; i < m_CellsInfo.size(); i++)
        {
            if(m_CellsInfo[i]->titleType == bnc::PLAYER)
            {
                DrawRectangle(m_CellsInfo[i]->position.x + m_LineSize, m_CellsInfo[i]->position.y + m_LineSize, 60 - m_LineSize * 2, 60 - m_LineSize * 2, DARKGREEN);   
            }
        }
    }

    void Renderer::RenderGates()
    {
        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            BeginShaderMode(m_Data->lightShader);

            if(m_CellsInfo[i]->titleType == bnc::GATE)
            {
                //* Find the type of the gate and render it accordingly
                uint32_t temp; 
                for (size_t j = 0; j < m_Data->levels->operator[](*m_Data->currentLevel)->GetGates().size(); j++)
                {
                    if(m_Data->levels->operator[](*m_Data->currentLevel)->GetGates()[j]->GetCellPosition() == i)
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
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );
                    break;
                case bnc::OR:
                    DrawTextureRec(
                        m_Data->spriteTexture,
                        Rectangle({60.0f, 60.0f * 2, 60.0f, 60.0f}),
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );
                    break;
                case bnc::NOT:
                    DrawTextureRec(
                        m_Data->spriteTexture,
                        Rectangle({60.0f * 2, 60.0f * 2, 60.0f, 60.0f}),
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );
                    break;
                case bnc::XOR:
                    DrawTextureRec(
                        m_Data->spriteTexture,
                        Rectangle({60.0f * 3, 60.0f * 2, 60.0f, 60.0f}),
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );
                    break; 
                default:
                    break;
                }
            }

            EndShaderMode();
        }
    }

    void Renderer::RenderLamps()
    {
        std::vector<std::shared_ptr<Lamp>>& r_lamps = m_Data->levels->operator[](*m_Data->currentLevel)->GetLamps();


        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            uint32_t temp; 

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
                    BeginShaderMode(m_Data->bloomShader);

                    DrawTextureRec(
                        m_Data->spriteTexture,
                        Rectangle({0, 60.0f, 60.0f, 60.0f}),
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );

                    EndShaderMode();
                }
                else
                {
                    DrawTextureRec(
                        m_Data->spriteTexture,
                        Rectangle({60.0f, 60.0f, 60.0f, 60.0f}),
                        m_CellsInfo[i]->position,
                        RAYWHITE
                    );
                }
            }
        }

    }

    void Renderer::GetLampsPosition()
    {
        std::vector<std::shared_ptr<Lamp>>& r_lamps = m_Data->levels->operator[](*m_Data->currentLevel)->GetLamps();

        for (size_t i = 0; i < m_CellsInfo.size(); i++)
        {
            uint32_t temp; 

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


        for (size_t i = 0; i < r_Particles.size(); i++)
        {
            DrawRectangle(r_Particles[i]->pariclePosition.x, r_Particles[i]->pariclePosition.y, r_Particles[i]->particleSize, r_Particles[i]->particleSize, r_Particles[i]->particleColor);
        }
        
    }

    void Renderer::Render(std::shared_ptr<bnc::RenderData> data)
    {
        m_Data = data;

        Clear();

        GetLampsPosition();

        Vector2* arr = m_LigthPosition.data();

        
        SetShaderValue(m_Data->lightShader, GetShaderLocation(m_Data->lightShader, "numLights"), &m_Ligthcount, SHADER_UNIFORM_INT);
        SetShaderValueV(m_Data->lightShader, GetShaderLocation(m_Data->lightShader, "lightPositions"), arr, SHADER_UNIFORM_VEC2, m_LigthPosition.size());

        BeginShaderMode(m_Data->lightShader);

        RenderGrid();
        RenderPlayer();
        RenderLamps();
        RenderGates();
        RenderParticles();

        DrawFPS(0, 0);


        m_Ligthcount = 0;
        m_LigthPosition.clear();

        EndShaderMode();
        
    }

    void Renderer::Clear()
    {
        ClearBackground(RAYWHITE);
    }
}