#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Tourist.h"

class City
{
private:
  std::vector<Tourist*> _tourists;
  int years;
  int score;
  long int profit;
  const int modern_div = 100;
  const int others_div = 50;
  const long int to_upgrade = 20000000;
  const long int money_threshold = 1000000000;
public:
  City(std::string& fx);
  ~City();
  static void simulate();
};

#endif
