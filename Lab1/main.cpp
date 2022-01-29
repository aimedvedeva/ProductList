#include <iostream>
#include <fstream>
#include <string>
#include <crtdbg.h>
#include "..\Lib\list.h"
#include "product.h"


using namespace std;




bool ReadData(List & list){
  ifstream F;
  string FileName = "ProductList.txt";
  
  
  F.open(FileName, ios::in);
  if (F)
  {
    while (!F.eof()){
      product *data = new product;
      
      F >> data->name;
      F >> data->article;
      F >> data->price;

      if (list.IsErrCond(IsErrorCondition, data) == true){
        delete data;
        F.close();
        return false;
      }

      void *placeEl = list.FindIf(Comparator, data);
      list.Add(placeEl, static_cast<void*>(data));
   
    }
  }
  else{
    return false;
  }
  return true;
}

int main(void){
  {
    List list;
   
    ReadData(list);
    
    list.ForEach(PrintProduct);
    
    char name[20];
    cin >> name;

    void *getData = list.FindByValue(FindByName, static_cast<void*>(name));
    PrintProduct(getData);
    list.ForEach(DeleteEl);
    /*cout << static_cast<product*>(getData)->name << " ";;
    cout << static_cast<product*>(getData)->article << " ";
    cout << static_cast<product*>(getData)->price << " ";*/
    
  }
  
  _CrtDumpMemoryLeaks();
  return 0;
}
