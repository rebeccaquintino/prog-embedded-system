#pragma once
#include <iostream>
#include <string>

class Oled
{
  public:
    void init();
    void clear();
    void print_display(std::string, float, float);
};