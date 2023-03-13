/**
*	\file		mymath
*	\brief		mymath container for different mathematical functions
*	\author		Soumik SARKAR @ ITER Organization
*/


#pragma once
#ifndef MYMATH_HPP
#define MYMATH_HPP

//----------------
//	START HERE
//----------------



#include <cppHeaders.hpp>


/*---*/

/**
* \brief	radian * 180 / pi
* \param	double radian
* \return	double degree
*/
double ToDegree(double radian);

/*---*/

/**
* \brief	degree * pi / 180
* \param	double degree
* \return	double radian
*/
double ToRadian(double degree);

/*---*/

/**
* \brief	returns value rounded to 2 decimal points
* \param	double value
* \return	double value
*/
double setPrecision2(double value);

/*---*/

/**
* \brief	returns value rounded to 3 decimal points
* \param	double value
* \return	double value
*/
double setPrecision3(double value);

/*---*/

/**
* \brief	returns value rounded to 4 decimal points
* \param	double value
* \return	double value
*/
double setPrecision4(double value);

/*---*/

/**
* \brief	returns value rounded to 5 decimal points
* \param	double value
* \return	double value
*/
double setPrecision5(double value);

/*---*/


double cd(double q);

double sd(double q);

double cr(double q);

double sr(double q);

double td(double q);

double tr(double q);










//----------------
//	 END HERE
//----------------

#endif // MYMATH_HPP

