#pragma once

enum class MSGTYPE { Uninitialized, Failed, Physics, Animation, Collision };
enum class OBJTYPE { Uninitialized, Sprite, CollisionSystem, GameOBJ };


class ID
{
public:
	ID() = default;
	ID( int idnumber, OBJTYPE type );

	bool matchMyID( ID target );

	bool checkIDmatch( ID target, ID comparison );
	bool checkIDmatch( ID* target, ID* comparison );


	int m_IDNumber = 0;
	OBJTYPE m_IDType = OBJTYPE::Uninitialized;
};
