#ifndef _HelperFunctions_h_
#define  _HelperFunctions_h_

inline float FitToBounds(float value, float upperBound, float lowerBound)
{
  if (value > upperBound)
    value = upperBound;

  if (value < lowerBound)
    value = lowerBound;

  return value;
}

#endif
