#include <iostream>
#include <vector>

inline std::ostream& operator<<(std::ostream &out, const std::vector<int>& nums)
{
  if (nums.size() == 0) {
    out << "[]";
    return out;
  }
  out << "[";
  for (int i = 0; i < nums.size() - 1; i++) {
    out << nums[i] << ", ";
  }
  out << nums[nums.size() - 1] << "]";
  return out;
}

template <typename T>
inline bool operator==(const std::vector<T> lh, const std::vector<T> rh)
{
  if (lh.size() != rh.size()) return false;
  for (int i = 0; i < lh.size(); i++) {
    if (lh[i] != rh[i]) return false;
  }
  return true;
}