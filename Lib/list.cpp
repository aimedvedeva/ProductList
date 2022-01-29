# include <cstdlib>
#include <windows.h>
#include "..\Lib\list.h"

List::List(){
  m_ListHead = NULL;
}

List::~List(){
  Clear(NULL);
  m_ListHead = NULL;
}

void List:: Add(void *placeEl, void *dataForNewEl){

  listElem *newEl = new listElem();
  newEl->data = dataForNewEl;
  int c = sizeof(listElem*);
  if (m_ListHead ==  NULL){
    m_ListHead = newEl;
    newEl->Next = NULL;
    return;
  }

  /*listElem *each = m_ListHead;
  listElem *prevEach = NULL;

  
  while (each && Comparator(each->data, dataForNewEl)){
    prevEach = each;
    each = each->Next;
  }*/

  if (placeEl != NULL){
    newEl->Next = static_cast<listElem*>(placeEl)->Next;
    static_cast<listElem*>(placeEl)->Next = newEl;
  }
  else{
    newEl->Next = m_ListHead;
    m_ListHead = newEl;
  }

  return;
}


void* List::FindIf(bool(*Comparator)(const void* dataEl, const void* dataCompare), const void *dataCompare){
  listElem *each = m_ListHead;
  listElem *prevEach = NULL;

  if (m_ListHead == NULL){
    return NULL;
  }

  while (each && Comparator(each->data, dataCompare)){
    prevEach = each;
    each = each->Next;
  }

  return prevEach;
}

void* List::FindByValue(bool(*Comparator)(const void* dataEl, const void* dataCompare), const void *dataCompare){
  listElem *each = m_ListHead;

  if (m_ListHead == NULL){
    return NULL;
  }

  while (each && Comparator(each->data, dataCompare)){
    each = each->Next;
  }

  return each->data;
}

bool List::IsErrCond(bool(*Comparator)(const void* dataEl, const void* dataCompare), const void *dataCompare){
  listElem *each = m_ListHead;

  while (each && !Comparator(each->data, dataCompare)){
    each = each->Next;
  }

  if (each != NULL){
    return true;
  }
  else {
    return false;
  }
}
void List::ForEach(void(*ActionFun)(void *dataEl)){
  listElem *each = m_ListHead;
  while (each){
    ActionFun(each->data);
    if (each->Next != NULL){
      each = each->Next;
    }
    else{
      return;
    }
  }
}

void List::Clear(void (*DeleteEl)(void *data)){
  listElem *each = m_ListHead;

  if (each == NULL)
    return;

  listElem *nextEach = NULL;

  while (each){
    nextEach = each->Next;
    if (DeleteEl != NULL){
      DeleteEl(each->data);
    }
    
    delete each;
    each = nextEach;
  }
  return;
}