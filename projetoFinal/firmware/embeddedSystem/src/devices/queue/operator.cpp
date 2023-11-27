#include "../queue/operator.hpp"

std::string operator%(int n, std::string data){   
  std::string complements = " - UID: ";
  std::string str_n = std::to_string(n);

  str_n.append(complements);
  str_n.append(data);

  return str_n;
}