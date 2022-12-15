#include"Newton_Interpolation.h"

Newton_Interpolation::Newton_Interpolation(){};

Newton_Interpolation::Newton_Interpolation(float X_p[],float Y_p[],int Size){
	for(int i=0;i<Size;i++){
		add_point(X_p[i],Y_p[i]);
	}
}

void Newton_Interpolation::add(float x){
	if(Points_Quantity==2){
		p[0]=-x; p[1]=1;
		return;
	}
	for(int i=0;i<Points_Quantity;i++){
		p1[i+1]=p[i];
	}
	for(int i=0;i<Points_Quantity;i++){
		p1[i]-=x*p[i];
	}
	for(int i=0;i<100;i++){
		p[i]=p1[i];
		p1[i]=0;
	}
}

void Newton_Interpolation::add_point(float x,float y){
	if(Points_Quantity>=100){
		std::cout<<"Overflow!\n";
		return;
	}
	X.push_back(x);
	Y.push_back(y);
	Points_Quantity++;
	float sm=0;
	for(int i = 0;i < Points_Quantity;i++){
		float ml=1; 
		for(int j = 0;j < Points_Quantity;j++){
			if(i==j)continue;
			ml*=X[i]-X[j];
		}
		sm+=(Y[i]/ml);	
	}
	if(Points_Quantity==1){
		N[0]=Y[0];
		return;
	}
	add(X[Points_Quantity-2]);
	for(int i=99;i>=0;i--){
		N[i]+=p[i]*sm;
	}
}

float Newton_Interpolation::get_point(float x){
	float ans=0,xx;
	for(int i=0;i<Points_Quantity;i++){
		xx=1;
		for(int j=0;j<i;j++){
			xx*=x;
		}
		ans+=N[i]*xx;
	}
	return ans;
}

