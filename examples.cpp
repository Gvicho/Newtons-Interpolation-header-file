#include<iostream>
#include"Newton_Interpolation/Newton_Interpolation.h"

int main(){
	Newton_Interpolation NI;
	// let's add some points
	NI.add_point(1,19);
	NI.add_point(4,1);
	NI.add_point(5,5);
	
	// we will get -> 2.5x^(2)-18.5x+35
	
	//here we ask about y when x is 2 and 3 (u can ask float numbers)
	std::cout<<NI.get_point(2)<<'\n';
	std::cout<<NI.get_point(3)<<'\n';
	
	return 0;
}

/*
Output :
8
2
*/
