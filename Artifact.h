#ifndef ARTIFACT_H
#define ARTIFACT_H
#include "stat.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <array>
string Piece[] = { "Flower", "Feather", "Sands", "Goblet", "Circlet" };
using namespace std;
class Artifact {

private:
	int level=0;
	Stat m, s1, s2, s3, s4;
	vector <Stat> subs;
	//things in vector are not the same as variables declared above?

	string piece;
	vector<string> list = { "CritRate%", "CritDamage%", "EM", "ER%",
		"Atk%", "ATK", "Def%", "DEF", "Hp%", "HP" };
public:

	Artifact() {
		subs.push_back(m);
		subs.push_back(s1);
		subs.push_back(s2);
		subs.push_back(s3);
		subs.push_back(s4);
		//create piece
		
		piece = Piece[rand() % 5];
		CreateArtifact();
	}
	/*vector<string> Type= {"CritRate", "CritDamage", "EM", "ER", "AtkPercent", "ATK",
	"DefPercent", "DEF", "HpPercent", "HP"}*/
	Artifact(string piece) {
		if (piece == "Flower") {
			this->piece = "Flower";
		}
		else if (piece == "Feather") {
			this->piece = "Feather";
		}
		subs.push_back(m);
		subs.push_back(s1);
		subs.push_back(s2);
		subs.push_back(s3);
		subs.push_back(s4);
		CreateArtifact();
	}
	Artifact(string piece, string m) {
		this->piece = piece;
		this->m.setStat(m);
		subs.push_back(this->m);
		subs.push_back(s1);
		subs.push_back(s2);
		subs.push_back(s3);
		subs.push_back(s4);
		CreateArtifact();

	}
	//custom creation, choose the stats you want
	Artifact(string piece, string m, string s1, string s2, string s3, string s4) {
		this->piece = piece;
		this->m.setStat(m);
		this->s1.setStat(s1);
		this->s2.setStat(s2);
		this->s3.setStat(s3);
		this->s4.setStat(s4);
		/*subs.push_back(this->m);
		subs.push_back(this->s1);
		subs.push_back(this->s2);
		subs.push_back(this->s3);
		subs.push_back(this->s4);*/
		subs = { this->m,this->s1,this->s2,this->s3,this->s4 };
		CreateArtifact();
	}

	int getLevel() {
		return level;
	}
	void addLevel(int x) {
		level += x;
	}

	//default function to generate artifact stuff
	void CreateArtifact() {
		

		//make mainstat
		createList(piece, list);
		//make substats
		statRoll(m.getStat(), subs, list);
		
	}
	//plan to add 4th substat if artifact has 3 rolls
	void addTo(Stat x, vector<Stat> list) {
		list.push_back(x);
	}
	//makes substats for subs vector


	void statRoll(string ma, vector <Stat>&subs, vector <string> &list) {//initialize stat;
		//vector<string> list = { "CritRate%", "CritDamage%", "EM", "ER%",
		//"Atk%", "ATK","Def%", "DEF", "Hp%", "HP" };
		//subs.at(0).setStat(m);

									/*
									cout << "---------------------------\n";
									cout << subs[0].getStat() << endl;// prints deault empty string
									cout << m.getStat()<<endl;//prints the actual value
									cout << "-------------------------------\n";
									*/


		removeFromList(ma, list);//remove mainstat roll from list

		for (int i = 1; i < subs.size(); i++) {
			
			//what to remove

			int r = rand() % list.size();

			//if substat not declared

									/*
									cout << subs.at(i).getStat()<<endl;//why is this empty?
									*/

			if (subs.at(i).getStat().length() == 0) {
				subs[i].setStat(list.at(r));//set stat from modified list
			}
			rollStatValue(subs.at(i));//roll the value
			//cout << "removed " << z;
			removeFromList(subs.at(i).getStat(), list);

		
			/*cout << "\n\n-----new pool------" << endl;
			for (int j = 0; j < list.size(); j++) {
				cout << list.at(j) << ", ";
			}
			//cout <<"\n-------------------\n\nsubs:";
			
			
			for (int k = 0; k < subs.size(); k++) {
				cout << subs.at(k).getStat() << ", ";
			}
			cout << "\n\n";*/
		}

	}

	//prints Artifact Details
	void printDetails() {
		cout << piece <<": Lv "<<level<< "\n";
		cout << "Main:\t";
		cout << m.getStat()<<endl;
		for (int i = 1; i < subs.size(); i++) {
			subs.at(i).print();
		}
		cout<< "\n";
	}
	//removes substat category from vector
	void removeFromList(string x, vector<string>& list) {
		vector<string>r;
		for (int i = 0; i < list.size(); i++) {
			if (list.at(i) != x) {
				r.push_back(list.at(i));
			}
		}
		list = r;
	}
	//generates artifact with different substats
	void createList(string x, vector<string>& list) {
		vector<string> mainS;
		double am = 0;
		int r = -1;
		/*pool: { "CritRate%", "CritDamage%", "EM", "ER%",
		"Atk%", "ATK","Def%", "DEF", "Hp%", "HP"}
		*/
		if (x == "Flower") {
			m.setStat("HP");
			m.setAmount(717);
			list = { "CritRate%", "CritDamage%", "EM", "ER%", "Atk%", "ATK",
							"Def%", "DEF", "Hp%" };

		}
		else if (x == "Feather") {
			m.setStat("ATK");
			m.setAmount(47);
			list = { "CritRate%", "CritDamage%", "EM", "ER%", "Atk%",
							"Def%", "DEF", "Hp%", "HP" };
		}
		if (m.getStat().size()==0) {
			if (x == "Sands") {
				mainS = { "Atk%", "Def%", "Hp%", "EM", "ER%" };
				r = rand() % 5;
				if (mainS.at(r) == "ER%") {
					am = .078;
				}
				else if (mainS.at(r).find('%') > -1) {
					am = .07;
				}
				else {
					am = 28;
				}

				m.setStat(mainS.at(r));
				m.setAmount(am);
			}
			else if (x == "Goblet") {
				mainS = { "Atk%", "Def%", "Hp%", "DmgBonus%", "EM" };
				r = rand() % 5;
				am = .07;
				if (mainS.at(r) == "EM")
					am = 28;
				m.setStat(mainS.at(r));
				m.setAmount(am);
			}
			else if (x == "Circlet") {
				mainS = { "Atk%", "Def%", "Hp%","CritRate%","CritDamage%","HealingBonus","EM" };
				r = rand() % 7;
				if (r == 3)//crit rate
					am = .047;
				if (r < 3)
					am = .07;
				if (r == 4)
					am = .093;
				if (r == 5)
					am = .058;
				if (r == 6)
					am = 28;
				m.setStat(mainS.at(r));
				m.setAmount(am);
			}
		}
		



	}//makes main stats
	//substat upgrade generator
	void rollStatValue(Stat& x) {
		int r;
		double HP[] = { 209, 239, 239, 299 };
		double ATK[] = { 14,16,18,19 };
		double DEF[] = { 16,19,21,23 };
		double HpPC[] = { .041,.047,.053,.058 };
		double AtkPC[] = { .041,.047,.053,.058 };
		double DEFPC[] = { .051,.058,.066,.073 };
		double EM[] = { 16,19,21,23 };
		double ER[] = { .045,.052,.058,.065 };
		double CR[] = { .027,.031,.035,.039 };
		double CD[] = { .058,.062,.07,.078 };
		//double *list[10][4] = {HP,ATK,DEF,HpPC,AtkPC,DEFPC,EM,ER,CR,CD};
		if (x.getStat() == "HP") {
			r = rand() % 4;
			x.addAmount(HP[r]);
		}
		else if (x.getStat() == "ATK") {
			r = rand() % 4;
			x.addAmount(ATK[r]);
		}
		else if (x.getStat() == "DEF") {
			r = rand() % 4;
			x.addAmount(DEF[r]);
		}
		else if (x.getStat() == "Hp%") {
			r = rand() % 4;
			x.addAmount(HpPC[r]);
		}
		else if (x.getStat() == "Atk%") {
			r = rand() % 4;
			x.addAmount(AtkPC[r]);
		}
		else if (x.getStat() == "Def%") {
			r = rand() % 4;
			x.addAmount(DEFPC[r]);
		}
		else if (x.getStat() == "EM") {
			r = rand() % 4;
			x.addAmount(EM[r]);
		}
		else if (x.getStat() == "ER%") {
			r = rand() % 4;
			x.addAmount(ER[r]);
		}
		else if (x.getStat() == "CritRate%") {
			r = rand() % 4;
			x.addAmount(CR[r]);
		}
		else if (x.getStat() == "CritDamage%") {
			r = rand() % 4;
			x.addAmount(CD[r]);
		}

	}
	void upgrade(int x) {
		// cout << "___________________\nadded "<< x << " levels...\n\n";
		for (int i = getLevel(); i <= x+getLevel(); i++) {
			if (i % 4 == 0&&i!=0) {
				int r = rand() % 4 + 1;
				rollStatValue(subs.at(r));
				subs.at(r).incrTime();
			}
		}
		addLevel(x);
	}
	bool isGodRoll() {
		for (int i = 0; i < subs.size(); i++) {
			if (subs.at(i).getTimes()>3) {
				return true;
			}
		}
		return false;
	}
	bool isGoodStart(){
		std::string main=m.getStat();
		if(main=="CritRate%"||main=="CritDamage%"||main=="ATK"||main=="HP"||((main=="Atk%"||main=="EM")&&piece=="Sands")||main=="DmgBonus%"&&piece=="Goblet")
			return true;
		return false;
	}
	bool tingsDream() {//has 3 or more crit rolls
		int rolls=0;
		std::string main=m.getStat();
		if(main=="CritRate%"||main=="CritDamage%"||main=="ATK"||main=="HP"||
			((main=="Atk%"||main=="EM")&&piece=="Sands")||main=="DmgBonus%"&&piece=="Goblet")
		{
			int i = 1;
			while(i < 5) {
				if (subs.at(i).isCritDmg()){
					rolls+=subs.at(i).getTimes();
				}
				if (subs.at(i).getStat()=="CritRate%"){
					rolls+=subs.at(i).getTimes();
				}
				i++;
			}
		}
		return rolls>4;
		
		// return rolls>=3;
	}

};


#endif