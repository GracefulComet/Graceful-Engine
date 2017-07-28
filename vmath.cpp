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

// Constructor
Vec2DF::Vec2DF(void) {
  x = 0;
  y = 0;
}
// Constructor
Vec2DF::Vec2DF(float xi, float yi) {
  x = xi;
  y = yi;
}

void Vec2DF::Normalize(void) {
  float const tol = 0.0001f;
  float m = (float)sqrt(x * x + y * y );
  if (m <= tol)
    m = 1;
  x /= m;
  y /= m;

  if (fabs(x) < tol)
    x = 0.0f;
  if (fabs(y) < tol)
    y = 0.0f;
}

float Vec2DF::Magnitude(void) { return (float)sqrt(x * x + y * y); }

void Vec2DF::Reverse(void) {
  x = -x;
  y = -y;
}

Vec2DF &Vec2DF::operator+=(Vec2DF u) {

  x += u.x;
  y += u.y;
  return *this;
}

Vec2DF &Vec2DF::operator-=(Vec2DF u) {
  x -= u.x;
  y -= u.y;
  return *this;
}

Vec2DF &Vec2DF::operator*=(float s) {
  x *= s;
  y *= s;
  return *this;
}

Vec2DF &Vec2DF::operator/=(float s) {
  x /= s;
  y /= s;
  return *this;
}

Vec2DF operator+(Vec2DF u, Vec2DF v) {
  return Vec2DF(u.x + v.x, u.y + v.y);
}

Vec2DF operator-(Vec2DF u, Vec2DF v) {

  return Vec2DF(u.x - v.x, u.y - v.y );
}



float operator*(Vec2DF u, Vec2DF v) {
  return (u.x * v.x + u.y * v.y );
}

Vec2DF operator*(float s, Vec2DF u) {
  return Vec2DF(u.x * s, u.y * s);
}

Vec2DF operator*(Vec2DF u, float s) {
  return Vec2DF(u.x * s, u.y * s);
}

Vec2DF operator/(Vec2DF u, float s) {
  return Vec2DF(u.x / s, u.y / s);
}



float Vec2DF::Approach(float goal, float current, float dt) {
  float difference;
  difference = goal - current;

  if (difference > dt) {
    return current + dt;
  }

  if (difference < -dt) {
    return current - dt;
  }

  return goal;
}
bool Vec2DF::operator>=(Vec2DF rhs){
    bool check1 = false;
    bool check2 = false;
    if(x >= rhs.x){check1 = true;}
    if(y >= rhs.y){check2 = true;}
if (check1 == true){
    if(check2 ==true ){

    return true;
}else{return false;}
}}


bool Vec2DF::operator<=(Vec2DF rhs){
    bool check1 = false;
    bool check2 = false;
    if(x <= rhs.x){check1 = true;}
    if(y <= rhs.y){check2 = true;}
if (check1 == true){
    if(check2 ==true ){

    return true;
}else{return false;}
}}

Rect::Rect(){
    position.x =0;
    position.y =0;
    size.x =1;
    size.y =1;
}
Rect::Rect(Vec2DF pos, Vec2DF vsize){
    position = pos;
    size = vsize;
}
Vec2DF Rect::getCenterPos(){
    return (position+= (size /= 2));
}
bool Rect::RectColisionCheck(Rect compare){
   if((this->position >= compare.position) && (this->position+= this->size)<=(compare.position += compare.size)){
       return true;
   }

}// not yet tested.

float distance(Vec2DF first, Vec2DF second){
   float difx = first.x - second.x;
   float dify = first.y - second.y;
   float dist = (float)sqrt((difx * difx)+(dify * dify));
   return dist;
}// not yet tested
