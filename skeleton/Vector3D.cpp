#include "Vector3D.h"

Vector3D::Vector3D(float x, float y, float z)
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
	return 0.0f;
}

float Vector3D::DotProduct(const Vector3D other)
{
	return 0.0f;
}

Vector3D Vector3D::CrossProduct(const Vector3D other) {

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
