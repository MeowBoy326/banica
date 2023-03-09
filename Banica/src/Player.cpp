#include "Player.h"

namespace bnc
{
    Player::Player(std::vector<GridCell*>* cells, std::vector<Level*>* levels, uint32_t* currentLevel)
    {
        m_GridCells = cells; 
        m_Levels = levels;
        m_CurrentLevel = currentLevel;

        cells->operator[](m_PlayerCurrentPosition)->isPlayerHere = true;
    }

    Player::~Player()
    {
        delete m_GridCells;
        delete m_CurrentLevel;
    }

    void Player::UpdatePlayer()
    {
        m_GridCells->operator[](m_PlayerCurrentPosition)->isPlayerHere = false; 
        m_PlayerCurrentPosition = m_PlayerNewPositon;
        m_GridCells->operator[](m_PlayerNewPositon)->isPlayerHere = true;
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