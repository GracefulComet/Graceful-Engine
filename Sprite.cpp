//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "Sprite.h"
#include "TexL.h"
#include <fstream>
#include <iostream>
#include <sstream>

Sprite::Sprite( int width, int height, int nCol, int nRow, std::string textureID )
	:
	m_tiles( nCol, nRow, height, width ),
	m_textureID( textureID ),
	m_animOffset( 0 )
{
	m_tiles.setCurTile( 0 );
}

Sprite::Sprite( std::string FileName, SDL_Renderer *Render )
{
	LoadFromFile( FileName, Render );
	m_tiles.setState( state::idle );
}
Sprite::Sprite( std::string FileName, SDL_Renderer *Render, state stat, int id )
	:
	m_ID( id ),
	m_messenger( std::make_unique<MSGreciever>( ID{ id, OBJTYPE::Sprite } ) )
{
	LoadFromFile( FileName, Render );
	m_tiles.setState( stat );
}


void Sprite::LoadFromFile( std::string FileName, SDL_Renderer *Render )
{
   std::ifstream ifs( FileName );
   if( !ifs.is_open() )
   {
      std::cout << "file " << FileName << " not found " << std::endl;
      return;
   }

   std::string tempTexName;
   std::string tempTexID;
   int tempW = 0;
   int tempH = 0;
   int tempNcol = 0;
   int tempNrow = 0;
   int tempCTile = 0;
   float tempX = 0.f;
   float tempY = 0.f;

   ifs >>
      tempTexName >>
      tempTexID >>
      tempW >>
      tempH >>
      tempNcol >>
      tempNrow >>
      tempCTile >>
      tempX >>
      tempY;

   ifs.close();

   TheTextureManager::Instance()->LoadWErrorChecking( tempTexName, tempTexID, Render );

   m_textureID = tempTexID;
   m_tiles = TileMap( tempNcol, tempNrow, tempH, tempW );
   m_position = { tempX, tempY };

   m_movespeed = Vec2DF( 0, 0 );


   m_tiles.setCurTile( tempCTile );
   m_animOffset = 0;
   m_tiles.setNumAnimFrames( 0 );
}

void Sprite::SaveToFile( std::string FileName, std::string TextureFilename,std::string textureID )
{

	std::ofstream ofs( FileName, std::ios::trunc );
	ofs << TextureFilename << std::endl
		<< textureID << std::endl
		<< m_tiles.getW() << std::endl
		<< m_tiles.getH() << std::endl
		<< m_tiles.getNCol() << std::endl
		<< m_tiles.getNRow() << std::endl
		<< m_tiles.getCurrTile() << std::endl
		<< m_position.x << std::endl
		<< m_position.y << std::endl;
	ofs.close();
}

void Sprite::update( float DeltaTime )
{

	this->HandleMSG();
	//    m_position.x = m_movespeed.Approach(m_movespeed.x,m_position.x, (DeltaTime * 0.15f));
	//    m_position.y = m_movespeed.Approach(m_movespeed.y,m_position.y, (DeltaTime * 0.15f));
	m_position += ( m_movespeed );
	switch( m_tiles.getState() )
	{

		case  state::idle:
			break;
		case  state::animated:
			animate( DeltaTime, m_tiles.getNumAnimFrames(), false );

			break;
		case  state::cycle:
			animate( DeltaTime, m_tiles.getNumAnimFrames(), true );
			break;

		default:

			m_tiles.setState( state::idle );
			break;


	}

}

void Sprite::draw( SDL_Renderer *pRenderer )
{
	TheTextureManager::Instance()->drawFrame(
		m_textureID, m_position.x, m_position.y, this->m_tiles.getW(),
		this->m_tiles.getH(), this->m_tiles.getCurrRow(),
		( this->m_tiles.getCurrCol() + m_animOffset ), pRenderer, SDL_FLIP_NONE );
}

void Sprite::animate( float DurPerFrame, int NumOfFrames, bool Cycle )
{

	if( m_timer.cooldown( DurPerFrame ) == true )
	{
		m_timer.reset();
		if( Cycle == true )
		{
			if( reverse == false )
			{
				m_animOffset++;
			}

			if( m_animOffset >= NumOfFrames )
			{
				reverse = true;
			}
			if( reverse == true )
			{
				m_animOffset--;
			}
			if( m_animOffset <= 0 )
			{
				reverse = false;
			}
		}
		else if( Cycle == false )
		{
			m_animOffset++;
			if( m_animOffset >= NumOfFrames )
			{
				m_animOffset = 0;
			}
		}
	}
}

void Sprite::Nanimate( float DurPerFrame, int NumOfFrames, bool Cycle )
{

	if( m_timer.cooldown( DurPerFrame ) == true )
	{
		m_timer.reset();
		if( Cycle == true )
		{
			if( reverse == false )
			{
				m_animOffset++;
			}

			if( m_animOffset >= NumOfFrames )
			{
				reverse = true;
			}
			if( reverse == true )
			{
				m_animOffset--;
			}
			if( m_animOffset <= 0 )
			{
				reverse = false;
			}
		}
		else if( Cycle == false )
		{
			m_animOffset++;
			if( m_animOffset >= NumOfFrames )
			{
				m_animOffset = 0;
			}
		}
	}
}

void Sprite::SetPos( float x, float y )
{
	m_position.x = x;
	m_position.y = y;
}
Vec2DF* Sprite::getPosition()
{
	return &m_position;
}

Vec2DF* Sprite::getVec()
{

	return  &m_movespeed;


}

void Sprite::HandleMSG()
{

	//todo setup msgpeak. then use a switch statement options
	//void* data;
	//data = this->getVec();
	switch( m_messenger->peakatMSGS() )
	{
		case MSGTYPE::Failed:

			break;
		case MSGTYPE::Physics:

			if( m_messenger->handleMSG( this->getVec() ) == false )
			{
				this->HandleMSG();
			}
			break;
		case MSGTYPE::Animation:


			if( m_messenger->handleMSG( this->getTiles() ) == false )
			{
				this->HandleMSG();
			}
			break;

		default:

			break;
	}



}
MSGreciever* Sprite::getListener()
{
	return m_messenger.get();
}
int Sprite::getID()
{
	return m_ID;
}

TileMap* Sprite::getTiles()
{
	return &m_tiles;
}
