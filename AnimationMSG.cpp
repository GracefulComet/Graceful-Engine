#include "AnimationMSG.h"
#include <iostream>

AnimationMSG::AnimationMSG( int curTile, int AnimateFrames, state desiredState, ID target, ID Sender )
	:
	msg( target, Sender, MSGTYPE::Animation ),
	m_curFrameSet( curTile ),
	m_AnimationFramesSet( AnimateFrames ),
	m_state( desiredState )
{}

void AnimationMSG::update( void* Variables )
{
	if( ( Variables ) == nullptr )
	{
		std::cout << " Got Null" << std::endl;
	}
	else
	{
		auto &tilemap = *reinterpret_cast< TileMap* >( Variables );
		tilemap.setCurTile( m_curFrameSet );
		tilemap.setNumAnimFrames( m_AnimationFramesSet );
		tilemap.setState( m_state );
	}
}

