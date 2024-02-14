#pragma once
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Type {
private:

	std::vector<std::string> everyType{ "Normal", "Fire", "Water", "Grass", "Electric", "Ice", "Fighting",
	"Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy" };

	std::string name;
	std::vector<std::string> superEffective;
	std::vector<std::string> notEffective;
	std::vector<std::string> fakeSuperEffective{ everyType };
	std::vector<std::string> fakeNotEffective{ everyType };
	std::string noEffect;


public:
	Type(std::string name_val, std::vector<std::string> superEffective_val, std::vector<std::string> notEffective_val, std::string noEffect_val);
	Type(std::string name_val, std::vector<std::string> superEffective_val, std::vector<std::string> notEffective_val);
	

	std::string getName();
	std::string getNoEffect();
	std::string getAndEraseRandomSuperEffective();
	std::string getAndEraseRandomNotEffective();
	std::string getAndEraseRandomFakeSuperEffective();
	std::string getAndEraseRandomFakeNotEffective();
	std::string getRandomNonNoEffectType();
	
	void setNoEffectToEmpty();
	bool superEffectiveSizeIsMoreThanZero();
	bool notEffectiveSizeIsMoreThanZero();
	bool fakeSuperEffectiveSizeIsMoreThanZero();
	bool fakeNotEffectiveSizeIsMoreThanZero();

	void removeStringFromVector(std::vector<std::string>& strings, std::string stringVal);

};