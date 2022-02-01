#include <iostream>
#include <cstdlib>
#include "Artifact.h"
#include "stat.h"
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	
	srand(time(NULL));
	std::ofstream outfile;
	outfile.open("Artifact Rolling - Sheet1.csv");
	
	for(int c=0;c<100;c++){
		int sum=0;
		int good=1;
		
		for(int i=0;i<10;i++){//how many artifacts before we get 10 good ones?

			int artifacts = 0;
		
			bool found = false;
			Artifact x=Artifact();
			while (!found) {
				
				x= Artifact();
				x.upgrade(20);
				// x.printDetails();
				if (x.tingsDream()) {//has >3 crit rolls
					found = true;
					// goodies.push_back(x);
				}
				artifacts++;
			}
			// x.printDetails();
			
			// cout << artifacts << " Artifacts raised.\n";
			sum+=artifacts;
		}
		if(c==0){
			outfile<<sum<<", ";
		}
		else if((c+1)%10==0){//go to new column if multiple of 100
			outfile<<sum<<"\n";
		}
		else{//print down the column
			outfile<<sum<<", ";
		}
		// for(int i=0;i<500;i++){
		// 	goodies.at(i).printDetails();
		// }
		// std::cout<<"10 good, raised "<<sum<<"\n";
		// std::cout<<"average: "<<sum/10<<" artifacts needed per good artifact.\n";
	}
	
	/*int pog = 0;
	for (int i = 0; i < 100; i++) {
		cout << "\n\n---------------new Artifact--------------------------\n";
		Artifact x("Flower","Atk%","CritRate%","CritDamage%","ER%","Atk%");
		x.upgrade(20);
		if (x.isGodRoll()) {
			cout << "\nITS POGGERS DUDE!!!!!!!!!!!!!!!!!!!!!\n";
			pog++;
			
		}
		x.printDetails();
	}
	cout << "pogCount:\t " << pog;*/

	/*
	cout << "defaultConstructor Artifact\n";
	Artifact defaultConstructor;  //works, creating an Artifact automatically prints the details
	defaultConstructor.upgrade(20);
	defaultConstructor.printDetails();*/
	

	/*
	Artifact custom("Sands","Hp%","Atk%","CritRate%","CritDamage%","HP");//doesnt work, because of vector bug
	custom.upgrade(20);
	custom.printDetails();
	cout << "________________________\n";
	//Artifact y("Goblet", "DmgBonus%");
	*/
	
}