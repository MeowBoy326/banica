#include "Player.h"

namespace bnc
{
    Player::Player(std::vector<bnc::GridCell*>* cells, std::vector<bnc::Level*>* levels, uint32_t* currentLevel)
    {
        m_GridCells = cells; 
        m_Levels = levels;
        m_CurrentLevel = currentLevel;

        // cells->operator[](m_PlayerCurrentPosition)->isPlayerHere = true;
    }

    Player::~Player()
    {
        delete m_GridCells;
        delete m_CurrentLevel;
    }

    void Player::UpdatePlayer()
    {
        m_GridCells->operator[](m_PlayerCurrentPosition)->titleType = bnc::NONE; 
        m_PlayerCurrentPosition = m_PlayerNewPositon;
        m_GridCells->operator[](m_PlayerNewPositon)->titleType = bnc::PLAYER;
    }

    void Player::SetPlayerPosition(uint32_t position)
    {
        m_PlayerCurrentPosition = position;
        m_PlayerNewPositon = position;
    }

    uint32_t Player::GetPlayerPosition() const
    {
        return m_PlayerCurrentPosition;
    }

    void Player::MovePlayerLeft()
    {
        m_PlayerNewPositon--;
    }

    void Player::MovePlayerRight()
    {
        m_PlayerNewPositon++;
    }

    void Player::MovePlayerUp()
    {
        m_PlayerNewPositon -= m_Levels->operator[](*m_CurrentLevel)->GetSizeX();
    }

    void Player::MovePlayerDown()
    {
        m_PlayerNewPositon += m_Levels->operator[](*m_CurrentLevel)->GetSizeX();
    }
}