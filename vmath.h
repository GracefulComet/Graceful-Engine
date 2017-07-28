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

class Vec2DF {
public:
  float x;
  float y;
  Vec2DF(void);
  Vec2DF(float xi, float yi);
  float Magnitude(void);
  void Normalize(void);
  void Reverse(void);
  Vec2DF &operator+=(Vec2DF u);
  Vec2DF &operator-=(Vec2DF u);
  Vec2DF &operator*=(float s);
  Vec2DF &operator/=(float s);
  Vec2DF &operator-(void);
  bool operator>=(Vec2DF rhs);
  bool operator<=(Vec2DF rhs);
  float Approach(float goal, float current, float dt);
};


float distance(Vec2DF first, Vec2DF second);

class Rect{
	public:
    Vec2DF position;
    Vec2DF size;
	Rect();
    Rect(Vec2DF pos, Vec2DF vsize);
	
    Vec2DF getCenterPos();
    bool RectColisionCheck(Rect compare);
    bool RectColisionCheck(Rect compare1, Rect compare2);
	

};

class circle{
public:
    Vec2DF position;
    float radius;

};
