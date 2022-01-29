#pragma once
#include <string>
#include <iostream>

struct product{
  std::string name;
  std::string article;
  int price;
};

bool Comparator(const void *dataEl, const void *data);
bool IsErrorCondition(const void *dataEl, const void *newElData); 
bool FindByName(const void *dataEl, const void *dataCompare);
void DeleteEl(void *data); 
void PrintProduct(void *data);
