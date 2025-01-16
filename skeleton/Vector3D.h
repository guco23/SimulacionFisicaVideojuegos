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
	float Module() const;
	float DotProduct(const Vector3D& other) const;
	void Scale(float n);
	Vector3D CrossProduct(const Vector3D& other) const;
	Vector3D GetNormalized() const;

	Vector3D& operator+(const Vector3D& other) const;
	Vector3D& operator-(const Vector3D& other) const;
	Vector3D& operator=(const Vector3D& other);
	Vector3D& operator*(const float& other) const;
	Vector3D& operator*(const Vector3D& other) const;
	Vector3D& operator/(const float& other) const;

	float getX();
	float getY();
	float getZ();

	void setX(float);
	void setY(float);
	void setZ(float);

};