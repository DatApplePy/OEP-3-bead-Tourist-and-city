#ifndef TOURIST_H
#define TOURIST_H
#include <iostream>

class Tourist
{
protected:
  int est_people;
  int act_people;
public:
  Tourist(int x) : est_people(x) {}
  virtual ~Tourist(){}

  int get_est_people() {return est_people;}
  int get_act_people() {return act_people;}
  virtual void set_act_people(const int& score) = 0;

  virtual bool isJapan() {return false;}
  virtual bool isModern() {return false;}
  virtual bool isOthers() {return false;}
};

class Japan : public Tourist
{
public:
  Japan(int x) : Tourist(x) {}
  bool isJapan() override {return true;}
  void set_act_people(const int& score) override
  {
    if(score > 0 && score < 34) {act_people = (est_people * 0);}
    else if (score > 33 && score < 68) {act_people = (est_people * 1);}
    else if (score > 67 && score < 101) {act_people = (est_people * 1.2);}
  }
};

class Modern : public Tourist
{
public:
  Modern(int x) : Tourist(x) {}
  bool isModern() override {return true;}
  void set_act_people(const int& score) override
  {
    if(score > 0 && score < 34) {act_people = (est_people * 1);}
    else if (score > 33 && score < 68) {act_people = (est_people * 1.1);}
    else if (score > 67 && score < 101) {act_people = (est_people * 1.3);}
  }
};

class Others : public Tourist
{
public:
  Others(int x) : Tourist(x) {}
  bool isOthers() override {return true;}
  void set_act_people(const int& score) override
  {
    if(score > 0 && score < 34) {act_people = (est_people * 1);}
    else if (score > 33 && score < 68) {act_people = (est_people * 1.1);}
    else if (score > 67 && score < 101) {act_people = (est_people * 1);}
  }
};

#endif
