/*
//
//
#################################################################################################
#											Class Point											#
#################################################################################################
//
//
*/

#include <ClassPoint.h>


/*---------------------------------------------------------------------*/


Point::Point()
{
	// Create
}


/*---------------------------------------------------------------------*/


Point::~Point()
{
	// Destroy 
}


/*---------------------------------------------------------------------*/


bool Point::CompareX(Point B)
{
	if (B.x == x)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------------------------*/


bool Point::CompareY(Point B)
{
	if (B.y == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------------------------*/


bool Point::CompareZ(Point B)
{
	if (B.y == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------------------------*/


bool Point::Compare2Points(Point B)
{
	if (CompareX(B) && CompareY(B) && CompareZ(B))
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*---------------------------------------------------------------------*/


double Point::ErrorX(Point B)
{
	return B.x - x;

}


/*---------------------------------------------------------------------*/


double Point::ErrorY(Point B)
{
	return B.y - y;
}


/*---------------------------------------------------------------------*/


double Point::ErrorZ(Point B)
{
	return B.z - z;
}


/*---------------------------------------------------------------------*/


std::vector<double> Point::ErrorBetween2Points(Point B)
{
	std::vector<double> err;
	err.push_back(ErrorX(B));
	err.push_back(ErrorY(B));
	err.push_back(ErrorZ(B));
	return err;
}


/*---------------------------------------------------------------------*/


void Point::Copy(Point B)
{
	x = B.x;
	y = B.y;
	z = B.z;
}



/*---------------------------------------------------------------------*/

void Point::PrintOutPointCoordinates(std::string pointName)
{
	std::cout << "Point: " << pointName << std::endl;
	std::cout << "X: " << x << std::endl;
	std::cout << "Y: " << y << std::endl;
	std::cout << "Z: " << z << std::endl;
}