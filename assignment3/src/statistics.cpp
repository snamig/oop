//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

// template <typename StDis> //StDis is a type of StatisticalDistribution

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> const random_sample, int const size, double const val) const
{
  std::vector<double> confidence_interval;
  double mean = 0.0;
  double std_deviation = 0.0;
  double lower_bound = 0.0;
  double upper_bound = 0.0;

  for (int i = 0; i < size; i++)
    mean += random_sample[i];
 
  mean /= (double)size;

  for (int i = 0; i < size; i++)
    std_deviation += pow((random_sample[i]) - mean, 2);

  std_deviation /= size;
  std_deviation = sqrt(std_deviation);

  lower_bound = mean - val * std_deviation / sqrt(size);
  upper_bound = mean + val * std_deviation / sqrt(size);

  confidence_interval.push_back(lower_bound); // lower bound as the first element
  confidence_interval.push_back(mean);        // mean as the second element
  confidence_interval.push_back(upper_bound); // upper bound as the third element

  return confidence_interval;
}

std::vector<double> NormalDistribution::sample(int const size, int const val) const
{
  std::vector<double> return_vector;
  std::default_random_engine generator;
  generator.seed(val);
  std::normal_distribution<double> distribution(this->getMean(), this->stddev);

  for (int i = 0; i < size; i++)
    return_vector.push_back(distribution(generator)); // sample from normal distribution

  return return_vector;
}

std::vector<double> UniformDistribution::sample(int const size, int const val) const
{
  std::vector<double> return_vector;
  std::default_random_engine generator;
  generator.seed(val);
  std::uniform_real_distribution<double> distribution(this->a, this->b);

  for (int i = 0; i < size; i++)
    return_vector.push_back(distribution(generator)); // sample from uniform distribution

  return return_vector;
}

std::vector<double> ExponentialDistribution::sample(int const size, int const val) const
{
  std::vector<double> return_vector;
  std::default_random_engine generator;
  generator.seed(val);
  std::exponential_distribution<double> distribution(this->lambda);

  for (int i = 0; i < size; i++)
    return_vector.push_back(distribution(generator)); // sample from exponential distribution

  return return_vector;
}
