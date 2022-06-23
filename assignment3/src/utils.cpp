//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"

StatisticalDistribution *choose_function(int const dist_type)
{
  NormalDistribution *normal_dist = new NormalDistribution;
  UniformDistribution *uniform_dist = new UniformDistribution;
  ExponentialDistribution *exp_dist = new ExponentialDistribution;
  if (dist_type == 0)
    return normal_dist;

  else if (dist_type == 1)
    return uniform_dist;

  else if (dist_type == 2)
    return exp_dist;

  else
    throw "Unidentified distribution function!";
}

double many_trials(StatisticalDistribution *const dist, std::vector<double> random_sample, double const t_value, int const trials, int const sample_size, int const seed_value)
{
  int success_count = 0;
  for (int i = 0; i < trials; i++)
  {
    random_sample = dist->sample(sample_size, seed_value + i);
    std::vector<double> confidence_interval = dist->calculate_confidence_interval(random_sample, sample_size, t_value);
    if (dist->getMean() <= confidence_interval[2] && dist->getMean() >= confidence_interval[0])
      success_count++;
  }
  return (float)success_count / (float)trials;
}
