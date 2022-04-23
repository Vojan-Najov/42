
#ifndef UTILS_H
# define UTILS_H

# include <string>

bool	tryToChar(const std::string &str, char *value);
bool	tryToChar(int value_int, char *value);
bool	tryToInt(const std::string &str, int *value);
bool	tryToInt(double value_double, int *value);
bool	tryToFloat(const std::string &str, float *value);
bool	tryToFloat(int value_int, float *value);
bool	tryToDouble(const std::string &str, double *value);

#endif
