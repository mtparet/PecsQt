#include <sequence.h>

void Sequence::addImageInSequence(ImageInSequence is){
    if(listIs.count() == 0){
        initIs();
    }
    int i = 0;

    do{
        DQForeignKey<ImageInSequence> *is2 = listIs.value(i);
        i++;
    }while(is2.isLoaded() && (listIs.count() > i));

    if(listIs.count() > i){
        i--;
        *listIs[i] = is;
    }
}

QList<DQForeignKey<ImageInSequence>*> Sequence::getListImageInSequence(){

    QList<DQForeignKey<ImageInSequence>*> iis;

    int i = 0;
    while((listIs.count() > i)){
        if(listIs.value(i)->isLoaded()){
            iis.insert(iis.count(),listIs.value(i));
        }

        i++;
    }

    return iis;
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
