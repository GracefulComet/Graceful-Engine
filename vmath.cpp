//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "vmath.h"

Vec2DF::Vec2DF()
	:
	x( 0 ), y( 0 )
{
}

Vec2DF::Vec2DF( float xi, float yi )
	:
	x( xi ), y( yi )
{
}

float Vec2DF::SqMagnitude() const
{
	return ( x * x ) + ( y * y );
}

Vec2DF Vec2DF::Normalize( void )const
{
	const float tol = 0.0001f;
	float m = Magnitude();
	if( m <= tol )
		m = 1;

	auto result = *this / m;

	if( fabs( x ) < tol )
		result.x = 0.0f;
	if( fabs( y ) < tol )
		result.y = 0.0f;

	return result;
}

float Vec2DF::Magnitude()const
{
	return sqrtf( SqMagnitude() );
}

Vec2DF &Vec2DF::operator+=( Vec2DF u )
{
	x += u.x;
	y += u.y;
	return *this;
}

Vec2DF &Vec2DF::operator-=( Vec2DF u )
{
	x -= u.x;
	y -= u.y;
	return *this;
}

Vec2DF &Vec2DF::operator*=( float s )
{
	x *= s;
	y *= s;
	return *this;
}

Vec2DF &Vec2DF::operator/=( float s )
{
	x /= s;
	y /= s;
	return *this;
}

float Vec2DF::Approach( float goal, float current, float dt )
{
	const float difference = goal - current;
	return difference > dt ?
		current + dt : difference < -dt ?
		current - dt : goal;
}

bool Vec2DF::operator>=( Vec2DF rhs )
{
	return ( x >= rhs.x ) && ( y >= rhs.y );
}

bool Vec2DF::operator<=( Vec2DF rhs )
{
	return ( x <= rhs.x ) && ( y <= rhs.y );
}

Rect::Rect()
	:
	position( 0.f, 0.f ),
	size( 1.f, 1.f )
{}

Rect::Rect( Vec2DF pos, Vec2DF vsize )
	:
	position( pos ),
	size( vsize )
{}

Vec2DF Rect::getCenterPos()
{
	return ( position + ( size * .5f ) );
}

bool Rect::RectColisionCheck( Rect compare )
{
	return 
		( position >= compare.position ) &&
		( position + size ) <= ( compare.position + compare.size );
}

Vec2DF operator+( const Vec2DF & U, const Vec2DF & V )
{
	return Vec2DF( U ) += V;
}

Vec2DF operator-( const Vec2DF & U, const Vec2DF & V )
{
	return Vec2DF( U ) -= V;
}

Vec2DF operator-( const Vec2DF & V )
{
	return Vec2DF( -V.x, -V.y );
}

float operator*( const Vec2DF & U, const Vec2DF & V )
{
	return ( U.x * V.x + U.y * V.y );
}

Vec2DF operator*( float s, Vec2DF u )
{
	return u * s;
}

Vec2DF operator*( const Vec2DF & V, const float & S )
{
	return Vec2DF( V ) *= S;
}

Vec2DF operator/( const Vec2DF & V, const float & S )
{
	return Vec2DF( V ) /= S;
}

float distance( Vec2DF first, Vec2DF second )
{
	const auto diff = first - second;
	const auto dist = diff * diff;
	return dist;
}
