#pragma once

typedef enum{
  DeleteMode_WithData,
  DeleteMode_WithoutData
}DeleteModes;

class List{

public:
  List();
  ~List();

  void Add(void *placeEl, void *dataForNewEl);

  void *FindIf(bool(*Comparator)(const void* dataEl,const void* dataCompare),const void *dataCompare);

  void ForEach(void(*ActionFun)(void *dataEl)); 

  bool IsErrCond(bool(*Comparator)(const void* dataEl, const void* dataCompare), const void *dataCompare);

  void* FindByValue(bool(*Comparator)(const void* dataEl, const void* dataCompare), const void *dataCompare);

  void Clear(void(*DeleteEl)(void *data));

private:
  struct listElem{
    void *data;
    listElem * Next;
  };

  listElem *m_ListHead;

};