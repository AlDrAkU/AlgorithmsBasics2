#include "Player.h"



Player::Player( const std::string& name,int score )
	:m_Name(name )
	,m_Score{score}
{
}


void Player::IncrementScore( int value )
{
	m_Score += value;
}

const std::string& Player::GetName( ) const
{
	return m_Name;
}

int Player::GetScore( ) const
{
	return m_Score;
}

std::ostream& operator<<( std::ostream& out, const Player& player )
{
	out << player.GetName( );
	out << " (" << player.GetScore( ) << ")";
	return out;
}



