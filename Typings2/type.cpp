#include "type.h"

Type::Type(std::string name_val, std::vector<std::string> superEffective_val, std::vector<std::string> notEffective_val, std::string noEffect_val)
	: name{ name_val }, superEffective{ superEffective_val }, notEffective{ notEffective_val }, noEffect{noEffect_val} {
	for (int i{ 0 }; i < fakeSuperEffective.size(); i++) {
		for (int j{ 0 }; j < superEffective.size(); j++) {
			if (fakeSuperEffective.at(i) == superEffective.at(j)) {
				fakeSuperEffective.erase(fakeSuperEffective.begin() + i);
			}
		}
	}

	for (int i{ 0 }; i < fakeNotEffective.size(); i++) {
		for (int j{ 0 }; j < notEffective.size(); j++) {
			if (fakeNotEffective.at(i) == notEffective.at(j)) {
				fakeNotEffective.erase(fakeNotEffective.begin() + i);
			}
		}
	}
}

Type::Type(std::string name_val, std::vector<std::string> superEffective_val, std::vector<std::string> notEffective_val)
	: Type{ name_val, superEffective_val, notEffective_val, "" } {
}

std::string Type::getName()
{
	return name;
}

std::string Type::getNoEffect()
{
	return noEffect;
}

std::string Type::getAndEraseRandomSuperEffective()
{
	int randomNumber{ rand() % static_cast<int>(superEffective.size()) };
	std::string returnString{ superEffective.at(randomNumber) };
	superEffective.erase(superEffective.begin() + randomNumber);
	return returnString;
}

std::string Type::getAndEraseRandomNotEffective()
{
	int randomNumber{ rand() % static_cast<int>(notEffective.size()) };
	std::string returnString{ notEffective.at(randomNumber) };
	notEffective.erase(notEffective.begin() + randomNumber);
	return returnString;
}

std::string Type::getAndEraseRandomFakeSuperEffective()
{
	int randomNumber{ rand() % static_cast<int>(fakeSuperEffective.size()) };
	std::string returnString{ fakeSuperEffective.at(randomNumber) };
	fakeSuperEffective.erase(fakeSuperEffective.begin() + randomNumber);
	return returnString;
}

std::string Type::getAndEraseRandomFakeNotEffective()
{
	int randomNumber{ rand() % static_cast<int>(fakeNotEffective.size()) };
	std::string returnString{ fakeNotEffective.at(randomNumber) };
	fakeNotEffective.erase(fakeNotEffective.begin() + randomNumber);
	return returnString;
}

std::string Type::getRandomNonNoEffectType()
{
	std::vector<std::string> NonNoEffectType = everyType;
	removeStringFromVector(NonNoEffectType, noEffect);
	int randomNumber{ rand() % static_cast<int>(everyType.size()) };
	return NonNoEffectType.at(randomNumber);
}

void Type::setNoEffectToEmpty()
{
	noEffect = "";
}

bool Type::superEffectiveSizeIsMoreThanZero()
{
	return superEffective.size() > 0;
}

bool Type::notEffectiveSizeIsMoreThanZero()
{
	return notEffective.size() > 0;
}

bool Type::fakeSuperEffectiveSizeIsMoreThanZero()
{
	return fakeSuperEffective.size() > 0;
}

bool Type::fakeNotEffectiveSizeIsMoreThanZero()
{
	return fakeNotEffective.size() > 0;
}

void Type::removeStringFromVector(std::vector<std::string>& strings, std::string stringVal)
{
	for (int i{ 0 }; i < strings.size(); i++) {
		if (strings.at(i) == stringVal) {
			strings.erase(strings.begin() + i);
			break;
		}
	}
}
