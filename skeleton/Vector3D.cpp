#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D(const Vector3D& other)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3D::Normalize()
{
	//Cálculo de la normalización de vectores. Requiere utilizar Module()
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
	return other;
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
	return Vector3D(x * other.x, y * other.y, z * other.z);
}

Vector3D Vector3D::operator=(const Vector3D other)
{
	return other;
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
