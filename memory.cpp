#include "memory.h"

bool Memory::replace(Sequence f){
    int i;
    for(i = 0; i < listSequence.count();i++){
        if(listSequence[i]->name == f.name){
            listSequence[i] = new Sequence(f);
        }
    }
}

bool Memory::remove(Sequence f){
    int i;
    for(i = 0; i < listSequence.count();i++){
        if(listSequence[i]->name == f.name){
            listSequence.removeAt(i);
        }
    }
}

bool Memory::add(Sequence f){
    listSequence.push_back(new Sequence(f));
}


