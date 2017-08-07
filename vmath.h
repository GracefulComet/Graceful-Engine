//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#pragma once
#include <cmath>

class Vec2DF
{
public:
	Vec2DF( void );
	Vec2DF( float xi, float yi );
	
	Vec2DF &operator+=( Vec2DF u );
	Vec2DF &operator-=( Vec2DF u );
	Vec2DF &operator*=( float s );
	Vec2DF &operator/=( float s );
	
	float SqMagnitude()const;
	float Magnitude()const;
	Vec2DF Normalize()const;

	bool operator>=( Vec2DF rhs );
	bool operator<=( Vec2DF rhs );
	float Approach( float goal, float current, float dt );

public:
	float x, y;
};

Vec2DF operator+( const Vec2DF &U, const Vec2DF &V );
Vec2DF operator-( const Vec2DF &U, const Vec2DF &V );
Vec2DF operator-( const Vec2DF &V );

float operator*( const Vec2DF &U, const Vec2DF &V );
Vec2DF operator*( float s, Vec2DF u );
Vec2DF operator*( const Vec2DF &V, const float &S );
Vec2DF operator/( const Vec2DF &V, const float &S );

float distance( Vec2DF first, Vec2DF second );

class Rect
{
public:
	Vec2DF position;
	Vec2DF size;
	Rect();
	Rect( Vec2DF pos, Vec2DF vsize );

public:
	Vec2DF getCenterPos();
	bool RectColisionCheck( Rect compare );
};

class circle
{
public:
	Vec2DF position;
	float radius;
};
