#include "product.h"



bool Comparator(const void *dataEl, const void *data){
  if (static_cast<const product*>(dataEl)->name.compare(static_cast<const product*>(data)->name) <= 0){
    return true;
  }
  else{
    return false;
  }
}

bool IsErrorCondition(const void *dataEl, const void *newElData){

  if (static_cast<const product*>(dataEl)->name.compare(static_cast<const product*>(newElData)->name) != 0){
    if (static_cast<const product*>(dataEl)->article.compare(static_cast<const product*>(newElData)->article) == 0){
      return true;
    }
  }
  return false;
}

bool FindByName(const void *dataEl, const void *dataCompare){
  if (static_cast<const product*>(dataEl)->name.compare(static_cast<const char*>(dataCompare)) == 0){
    return false;
  }
  else{
    return true;
  }
}

void DeleteEl(void *data){
  delete static_cast<product*>(data);
}


void PrintProduct(void *data){
  std::cout << static_cast<const product*>(data)->name << " ";
  std::cout << static_cast<const product*>(data)->article << " ";
  std::cout << static_cast<const product*>(data)->price << std::endl;
}



