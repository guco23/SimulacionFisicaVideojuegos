#pragma once
class Vector3D
{
private:
	float x;
	float y;
	float z;
public:
	Vector3D(float x, float y, float z);
	void Normalize();
	float Module();
	float DotProduct(const Vector3D other);
	Vector3D CrossProduct(const Vector3D other);
	void Scale(float n);

	Vector3D operator+(const Vector3D other);
	Vector3D operator-(const Vector3D other);
	Vector3D operator=(const Vector3D other);
	Vector3D operator*(const Vector3D other);

};