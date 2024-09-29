#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D()
{
}


void Vector3D::Normalize()
{
	float mod = Module();
	x = x / mod;
	y = y / mod;
	z = z / mod;
}

float Vector3D::Module()
{
	return sqrt(x*x + y*y + z*z);
}

float Vector3D::DotProduct(const Vector3D other)
{
	return x * other.x + y * other.y + z*other.z;
}

Vector3D Vector3D::CrossProduct(const Vector3D other) {
	//Cálculo del producto vectorial
	float resx = y * other.z - z * other.y;
	float resy = x * other.z - z * other.x;
	float resz = x * other.y - x * other.y;
	return Vector3D(resx, resy, resz);
}

Vector3D Vector3D::GetNormalized()
{
	Vector3D v = *this;
	v.Normalize();
	return v;
}

void Vector3D::Scale(float n)
{
	x = x * n;
	y = y * n;
	z = z * n;
}

Vector3D Vector3D::operator+(const Vector3D other)
{
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D other)
{
	return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(const Vector3D other)
{
	//Cálculo del producto vectorial
	return CrossProduct(other);
}

Vector3D Vector3D::operator*(const float n)
{
	//Cálculo del producto vectoria
	Vector3D v = *this;
	v.Scale(n);
	return v;
}

float Vector3D::getX()
{
	return x;
}

float Vector3D::getY()
{
	return y;
}

float Vector3D::getZ()
{
	return z;
}
