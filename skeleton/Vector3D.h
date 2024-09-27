#pragma once
class Vector3D
{
private:
	float x;
	float y;
	float z;
public:
	Vector3D(float x, float y, float z);
	Vector3D();
	void Normalize();
	float Module();
	float DotProduct(const Vector3D other);
	void Scale(float n);

	Vector3D CrossProduct(const Vector3D other);
	Vector3D GetNormalized();

	Vector3D operator+(const Vector3D other);
	Vector3D operator-(const Vector3D other);
	Vector3D operator=(const Vector3D other);
	Vector3D operator*(const float other);
	Vector3D operator*(const Vector3D other);

	float getX();
	float getY();
	float getZ();

};