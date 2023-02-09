/**
*	\class		Point
*	\brief		Point Class and Functions
*	\author		Soumik SARKAR @ ITER Organization
*/


#pragma once
#ifndef CLASSPOINT_H
#define CLASSPOINT_H

//----------------
//	START HERE
//----------------


#include <cppHeaders.h>

// public class
// (x,y,z)
class Point
{
public:
	double x; // X coordinate of the point.
	double y; // Y coordinate of the point.
	double z; // Z coordinate of the point.

	/*---*/

	// Constructor
	Point();

	/*---*/

	// Destructor
	~Point();

	/*---*/

	/**
	* \brief	Compares X coordinates of two points
	* \brief	Call as: pointA.CompareX(pointB);
	* \param	Point B
	* \return	true or false
	*/
	bool CompareX(Point B);

	/*---*/

	/**
	* \brief	Compares Y coordinates of two points
	* \brief	Call as: pointA.CompareY(pointB);
	* \param	Point B
	* \return	true or false
	*/
	bool CompareY(Point B);

	/*---*/

	/**
	* \brief	Compares Z coordinates of two points. 
	* \brief	Call as: pointA.CompareZ(pointB);
	* \param	Point B
	* \return	true or false
	*/
	bool CompareZ(Point B);

	/*---*/

	/**
	* \brief	Compares 2 points.
	* \brief	Call as: pointA.Compare2Points(pointB);
	* \param	Point B
	* \return	true or false
	*/
	bool Compare2Points(Point B);

	/*---*/

	/**
	* \brief	Gives Error in X axis between two points.
	* \brief	Call as: pointA.ErrorX(pointB);
	* \param	Point B
	* \returns	double
	*/
	double ErrorX(Point B);

	/*---*/

	/**
	* \brief	Gives Error in Y axis between two points.
	* \brief	Call as: pointA.ErrorY(pointB);
	* \param	Point B
	* \returns	double
	*/
	double ErrorY(Point B);

	/*---*/

	/**
	* \brief	Gives Error in Z axis between two points.
	* \brief	Call as: pointA.ErrorZ(pointB);
	* \param	Point B
	* \returns	double
	*/
	double ErrorZ(Point B);

	/*---*/

	/**
	* \brief	Gives Error Vector between two points.
	* \brief	Call as: pointA.ErrorBetween2Points(pointB);
	* \param	Point B
	* \returns	vector<double>
	*/
	std::vector<double> ErrorBetween2Points(Point B);


	/**
	* \brief	To copy pointB to pointA
	* \brief	Call as: pointA.Copy(pointB);
	* \param	Point B
	*/
	void Copy(Point B);


	/**
	* \brief	To print point coordinates to terminal
	* \brief	Call as: pointA.PrintOutPointCoordinates();
	* \param	
	* \return	Prints point info in terminal using std::cout
	*/
	void PrintOutPointCoordinates(std::string pointName);

};



//----------------
//	 END HERE
//----------------

#endif // !CLASSPOINT_H

