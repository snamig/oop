//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

class StatisticalDistribution
{
protected:
  double mean;

public:
  // getter function of mean
  int getMean() const { return this->mean; };
  virtual std::vector<double> sample(int const, int const) const = 0;
  std::vector<double> calculate_confidence_interval(std::vector<double> const, int const, double const) const;
};

class NormalDistribution : public StatisticalDistribution
{
  double stddev;

public:
  NormalDistribution()
  {
    this->stddev = 1.0;
    this->mean = 0.0;
  }
  std::vector<double> sample(int const, int const) const;
};

class UniformDistribution : public StatisticalDistribution
{
  double a;
  double b;

public:
  UniformDistribution()
  {
    this->mean = 0.0;
    this->a = -1.0;
    this->b = 1.0;
  };
  std::vector<double> sample(int const, int const) const;
};

class ExponentialDistribution : public StatisticalDistribution
{
  double lambda;

public:
  ExponentialDistribution()
  {
    this->mean = 1.0;
    this->lambda = 1.0;
  } // default lambda = 1.0
  std::vector<double> sample(int const, int const) const;
};

#endif