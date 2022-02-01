#ifndef STAT_H
#define STAT_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> Type= { "CritRate%", "CritDamage%", "EM", "ER%",
		"Atk%", "ATK","Def%", "DEF", "Hp%", "HP" };
//{"CritRate", "CritDamage", "EM", "ER", "AtkPercent", "ATK", "DefPercent", "DEF", "HpPercent", "HP"}
class Stat {
private:
	double amount;
	int times;
	string substat;
public:
	Stat() {
		amount = 0;
		times = 0;
		substat="";//string length=0 for condition to see if the stat has been assigned yet
	}
	Stat(double amount, string substat) {
		this->amount = amount;
		int r = rand() % 10;
		substat = Type.at(r);
		times = 0;
	}
	~Stat() {
	}
	void increase(double x) {
		amount += x;
	}
	void setStat(string x) {
		substat = x;
	}
	void setAmount(double x) {
		amount = x;
	}
	void addAmount(double x) {
		amount += x;
	}
	void incrTime() {
		times += 1;
	}

	string getStat() {
		return substat;
	}
	int getTimes() {
		return times;
	}
	double getAmount() {
		return amount;
	}
	bool isCritDmg() {
		if (substat == "CritDamage%") {
			return true;
		}
		return false;
	}

	void printPercent(double x) {
		if (x < 1) {
			cout<< x * 100.00 << "%";
		}
		else {
			cout << x;
		}
	}
	void print() {
		string x = ":";
		for(int i=0;i<(14-getStat().length())/4;i++) {
			x += "\t";
		}
		cout << getStat() << x; 
		printPercent(getAmount());
		cout<< "(" << times << ")" <<"\n";
	}
};

#endif