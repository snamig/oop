//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H

#include "statistics.h"

StatisticalDistribution *choose_function(int const);
double many_trials(StatisticalDistribution *const, std::vector<double>, double const, int const, int const, int const);

#endif