#include <fstream>
#include <sstream>
#include <iostream>
#include "City.h"

City::City(std::string& fx)
{
  std::ifstream in;
  in.open(fx);
  in >> score;
  in >> years;

  for(int i = 0; i < years; ++i)
  {
    std::string line;
    while(line.length()==0)
    {
      getline(in, line);
    }
    std::stringstream tourist_groups(line);
    int x;
    tourist_groups >> x;
    _tourists.push_back(new Japan(x));
    tourist_groups >> x;
    _tourists.push_back(new Modern(x));
    tourist_groups >> x;
    _tourists.push_back(new Others(x));

  }
  in.close();
}

City::~City()
{
  for(Tourist* x : _tourists)
  {
    delete x;
  }
}

void City::simulate()
{
  std::string filename;
  std::cout << "Enter filename: ";
  std::cin >> filename;
  City Bp(filename);

  for(int i = 0; i < Bp.years; ++i)
  {
    int curr_score = Bp.score;
    std::cout << curr_score << std::endl;
    Bp.profit = 0;
    int step = 0;
    while(step < 3)
    {
      Bp._tourists[i*3+step]->set_act_people(curr_score);
      Bp.profit += Bp._tourists[i*3+step]->get_act_people()*100000;

      if(Bp._tourists[i*3+step]->isJapan());
      else if (Bp._tourists[i*3+step]->isModern())
      {
        Bp.score = Bp.score - (Bp._tourists[i*3+step]->get_act_people() / 100);
      }
      else if (Bp._tourists[i*3+step]->isOthers())
      {
        Bp.score = Bp.score - (Bp._tourists[i*3+step]->get_act_people() / 50);
      }

      std::cout << Bp._tourists[i*3+step]->get_est_people() << " " << Bp._tourists[i*3+step]->get_act_people() << std::endl;

      ++step;
    }

    if(Bp.score < 1) Bp.score = 1;
    else if(Bp.score > 100) Bp.score = 100;

    std::cout << "Status: ";
    if(Bp.score > 0 && Bp.score < 34) std::cout << "Bad" << std::endl;
    else if (Bp.score > 33 && Bp.score < 68) std::cout << "Average" << std::endl;
    else if (Bp.score > 67 && Bp.score < 101) std::cout << "Good" << std::endl;

    std::cout << "Profit: " << Bp.profit << std::endl;

    if(Bp.profit >= Bp.money_threshold)
    {
      Bp.score += ((Bp.profit-Bp.money_threshold)/Bp.to_upgrade);
    }
  }
}
