#pragma once


#include<vector>
#include<iostream>


class Newton_Interpolation{
	private:
	std::vector<float> X,Y,p{std::vector<float>(100,0)},p1{std::vector<float>(100,0)},N{std::vector<float>(100,0)};
	int Points_Quantity=0;
	public:
	Newton_Interpolation();
	Newton_Interpolation(float [],float [],int);
	void add(float );
	void add_point(float,float);
	float get_point(float );
};
