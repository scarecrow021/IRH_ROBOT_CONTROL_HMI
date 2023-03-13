/*
//
//
#################################################################################################
#										My Math Functions										#
#################################################################################################
//
//
*/

#include <mymath.hpp>

double ToDegree(double radian)
{
	return radian * 180 / M_PI;
}

double ToRadian(double degree)
{
	return degree * M_PI / 180;
}

double setPrecision2(double value)
{
	return round(value * 100) / 100;
}
	


double setPrecision3(double value)
{
	return round(value * 1000) / 1000;
}

double setPrecision4(double value)
{
	return round(value * 10000) / 10000;
}

double setPrecision5(double value)
{
	return round(value * 100000) / 100000;
}



double cd(double q)
{
	return cos(ToRadian(q));
}

double sd(double q)
{
	return sin(ToRadian(q));
}

double cr(double q)
{
	return cos(q);
}

double sr(double q)
{
	return sin(q);
}

double td(double q)
{
	return tan(ToRadian(q));
}

double tr(double q)
{
	return tan(q);
}