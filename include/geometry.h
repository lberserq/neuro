
#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <cmath>
#include <vector>
#include <iostream>

//-----------------------------------------Basic elements--------------------------------------------

struct Vector3
{
	double x, y, z;

	Vector3(double a, double b, double c): x(a), y(b), z(c)
	{};
	Vector3(const Vector3& other): x(other.x), y(other.y), z(other.z)
	{};

	void normalize();
	Vector3& operator *= (double);
	Vector3& operator * (double);
	Vector3& operator += (Vector3&);
	Vector3& operator + (Vector3&);
	Vector3& operator = (Vector3&);
};

struct Vector2
{
	double x, y;

	Vector3(double a, double b, double c): x(a), y(b)
	{};
	Vector3(const Vector3& other): x(other.x), y(other.y)
	{};
};

struct Line
{
	Vector3 origin, direction;

	Line(Vector3& orig, Vector3& dir) : origin(orig), direction(dir)
	{}

	std::pair<bool,double> intersects(const Plane&);
	Vector3& get_point(double t);
};

// Note: normal vector should be normalized
struct Plane
{
	Vector3 normal;
	double d;

	Plane(Vector3& norm, double D): normal(norm), d(D)
	{}
};

double norm(Vector3& v);

double dot(Vector3& a, Vector3& b);

Vector3& rotate_around_X(Vector3& v,double ang);

Vector3& rotate_around_Y(Vector3& v,double ang);

Vector3& rotate_around_Z(Vector3& v,double ang);

//-----------------------------------------Necessary functions--------------------------------------------

std::vector<Vector3> project_to_plane(std::vector<Vector3> points, const Plane& P);

std::vector<Vector3> project_to_OXY(std::vector<Vector3> points, const Plane& P);
// This function works only if plane goes through origin: point (0,0,0) (so d == 0)

std::vector<Vector2> get_points_projection(std::vector<Vector3> points);
// Main function

#endif // GEOMETRY_H