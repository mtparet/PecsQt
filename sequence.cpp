#include <sequence.h>

void Sequence::addImageInSequence(ImageInSequence is){
    if(listIs.count() == 0){
        initIs();
    }
    int i = 0;
    DQForeignKey<ImageInSequence> *istest;
    do{
        istest = listIs.value(i);
        i++;
    }while( istest->isLoaded() && (listIs.count() > i));

    if(listIs.count() > i){
        i--;
        *listIs[i] = is;
    }
}

bool Sequence::initIs(){
    listIs.insert(listIs.count(),&is1);
    listIs.insert(listIs.count(),&is2);
    listIs.insert(listIs.count(),&is3);
    listIs.insert(listIs.count(),&is4);
    listIs.insert(listIs.count(),&is5);
    listIs.insert(listIs.count(),&is6);
    listIs.insert(listIs.count(),&is7);
    listIs.insert(listIs.count(),&is8);
    listIs.insert(listIs.count(),&is9);
    listIs.insert(listIs.count(),&is10);
    listIs.insert(listIs.count(),&is11);
    listIs.insert(listIs.count(),&is12);
    listIs.insert(listIs.count(),&is13);
}
