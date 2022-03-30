#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


float f(float x){
	return ((668.061/x)*(1-pow(2.718281828459045235360,-0.146843*x))-40);
}
 
 
void evalua (float f(float), float x){
	printf(" \nf(%g) = %g",x,f(x));
}


float biseccion(float xl,float xu,float es,float imax,float xr,float iter,float ea){
	iter=1;
	float test;
	float xrold;
	cout<<"i		Xl		Xu		Xa		f(XL)		f(XU)		f(Xa)		Ea(%)"<<endl;
	do{
		 xrold=xr;
		xr=(xl+xu)/2;
		cout<<iter<<"		"<<xl<<"		"<<xu<<"		"<<xr<<"		";
		iter=iter+1;
		if(xr!=0){
			ea=fabs((xr-xrold)/xr)*100;
		}
		test=f(xl)*f(xr);
		
		cout<<f(xl)<<"		"<<f(xr)<<"		"<< ea<<endl;
		if(test<0){
			xu=xr;
		}
		else if(test>0){
			xl=xr;
		}else{
			ea=0;
		}
		
		if(iter==imax)break;
	
	}while(ea>=es);
	cout<<"La raiz obtenida es: "<<xr<<endl;
	cout<<"La funcion evaluada con la raiz es: "<<f(xr);
	
}

int main(){
	int i; 
	float xl=0,xu=0,es=0.5,imax=0,xr=0,iter=0,ea=0;
	
	int opc;
	do{
		cout<<"**************************************************************************"<<endl;
		cout<<"*******************Práctica 6. Método de Bisección*******************"<<endl;
		cout<<"**************************************************************************"<<endl;
		cout<<endl;
		cout<<"Seleccione su opcion"<<endl;
		cout<<"1.-Inicar su programa con los valores dados"<<endl;
		cout<<"2.-Inicar su programa ingresando nuevos valores"<<endl;
		cout<<"3.-Creditos"<<endl;
		cout<<"4.-Salir"<<endl;
		scanf("%d",&opc);
		system("CLS");
		
		switch(opc){
			case 1: 
				xl=12;
				xu=16;
				imax=20;
				system("cls");
				biseccion( xl,xu,es,imax,xr,iter,ea);
				cout<<"\n";
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				cout<<"Ingrese el valor de xl : ";
				cin>>xl;
				cout<<"Ingrese el valor de xu : ";
				cin>>xu;
				cout<<"Ingrese las cantidad de iteraciones : ";
				cin>>imax;
				biseccion( xl,xu,es,imax,xr,iter,ea);
				cout<<"";
				system("pause");
				system("cls");
				break;
			case 3:
				system("CLS");
				cout<<"Universidad Autonoma de Aguascalientes"<<endl;
				cout<<"**********************************************************"<<endl;
				cout<<"MAESTRA:"<<endl;
				cout<<"Dra. Aurora Torres Soto"<<endl;
				cout<<"Alumno:                               ID:"<<endl;
				cout<<"Juan Pablo Martínez Rocha              243645"<<endl;
				cout<<"**********************************************************"<<endl;
				system("pause");
				system("CLS");
		}
	}while(opc!=4);

}
