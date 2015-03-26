#include <geometry.h>

const double epsilon = 0;
const double PI = std::acos(-1);

//-----------------------------------------Implementation--------------------------------------------

inline double norm(Vector3& v)
{
	return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

inline double dot(Vector3& a, Vector3& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline void Vector3::normalize()
{
	x /= norm(*this);
	y /= norm(*this);
	z /= norm(*this);
}

Vector3& Vector3::operator *= (double c)
{
	x *= c; y *= c; z *= c;
	return *this;
}

Vector3& Vector3::operator * (double c)
{
	Vector3 out(*this);
	out *= c;
	return out;
}

Vector3& Vector3::operator += (Vector3& v)
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

Vector3& Vector3::operator + (Vector3& v)
{
	Vector3 out(*this);
	out += v;
	return out;
}

Vector3& Vector3::operator = (Vector3& v)
{
	x = v.x; y = v.y; z = v.z;
	return *this;
}

Vector3& rotate_around_X(Vector3& v,double ang)
{
	Vector3 out;
	out.x = v.x;
	out.y = v.y*std::cos(ang) + v.z*(-std::sin(ang));
	out.z = v.y*std::sin(ang) + v.z*std::cos(ang);
	return out;
}

Vector3& rotate_around_Y(Vector3& v,double ang)
{
	Vector3 out;
	out.x = v.x*std::cos(ang) + v.z*(-std::sin(ang));
	out.y = v.y;
	out.z = v.x*std::sin(ang) + v.z*std::cos(ang);
	return out;
}

Vector3& rotate_around_Z(Vector3& v,double ang)
{
	Vector3 out;
	out.x = v.x*std::cos(ang) + v.y*(-std::sin(ang));
	out.y = v.x*std::sin(ang) + v.y*std::cos(ang);
	out.z = v.z;
	return out;
}

std::pair<bool,double> Line::intersects(const Plane& P)
{
	double denom = dot(P.normal,direction);

	if (std::abs(denom) <= epsilon)
	// Line is parallel to plane
		return std::pair<bool, double>(false, 0);
	else
	{
		double nom = dot(P.normal,origin) + P.d;
		double t = -(nom/denom);
		return std::pair<bool, double>(true, t);
	}
}

Vector3& Line::get_point(double t)
{
	return origin + direction*t;
}

std::vector<Vector3>& project_to_plane(std::vector<Vector3>& points, const Plane& P)
{
	std::vector<Vector3> out;
	for (int i=0; i<points.size(); i++)
	{
		Line line(points[i], P.normal);
		std::pair<bool,double> intersection = line.intersects(P);
		if (intersection.first)
			out.push_back(line.get_point(intersection.second));
		else
			std::cout << "Error: point number " << (i+1)
			<< " with coordinates (" << points[i].x << "," << points[i].y << "," << points[i].z << ")
			can not be projected.\n";
	}
	return out;
}

std::vector<Vector2>& project_to_OXY(std::vector<Vector3>& points, const Plane& P)
{
	std::vector<Vector2> out;

	Vector3 intersect_vec(P.normal.y,-P.normal.x,0);
	// vector of intersaection of plane P and OXY
	double ang1 = std::acos(intersect_vec.x);
	if (intersect_vec.y < 0)
		ang += PI;
	double ang2 = std::acos(P.normal.z);

	for (int i=0; i<points.size(); i++)
	{
		Vector3 tmp;
		tmp = rotate_around_Z(points[i],-ang1);
		tmp = rotate_around_Y(tmp,-ang2);
		Vector2 v(tmp.x,tmp.y);
		out.push_back(v);
	}

	return out;
}


std::vector<Vector2>& get_points_projection(std::vector<Vector3> points,std::vector<Vector3> normals)
{
	Vector3 avg_vec;
	for (int i=0; i<points.size(); i++)
		avg_vec += normals[i];
	avg_vec.normalize();

	Plane P(avg_vec,0);

	std::vector<Vector3> tmp = project_to_plane(points,P);

	std::vector<Vector2> out = project_to_OXY(tmp,P);

	return out;
}

        
