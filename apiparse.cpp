#include "apiparse.h"
#include "qjson/parser.h"
#include "qjson/serializer.h"
#include "util.h"


QList<Sequence> ApiParse::parseList(QByteArray json){
    QJson::Parser parser;
    bool ok;

    QVariantMap variantMap = parser.parse (json, &ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
    }

    QString origin = variantMap["origin"].toString();
    if (origin == "application_qt"){
    }else{
        return parseListFromROR(json);
    }
}


QList<Sequence> ApiParse::parseListFromROR(QByteArray json){
    QList<Sequence> listSequence;

    QJson::Parser parser;
    bool ok;

    QVariantList variantList = parser.parse (json, &ok).toList();
    if (!ok) {
        qFatal("An error occurred during parsing");
    }

    foreach (QVariant imgSeqVariant, variantList) {
        Sequence sq = parseSeqFromROR(imgSeqVariant.toMap());
        listSequence << sq;
    }

    return listSequence;
}

Sequence ApiParse::parseSeqFromROR(QVariantMap variantMap){
    Sequence seq;

    seq.name = variantMap["name"].toString();
    foreach (QVariant imgSeqVariant, variantMap["sequence_liste"].toList()) {
       ImageInSequence imgSeq;
       QVariantMap imgSeqMap = imgSeqVariant.toMap();

       imgSeq.orderIn = imgSeqMap["order_sequence"].toInt();

       QVariantMap variantMapImage = imgSeqMap["image"].toMap();
       Images im;
       im.name = variantMapImage["name"].toString();
       im.image_file = variantMapImage["image_file"].toMap()["url"].toString();

       imgSeq.img = im;

       seq.listImageInSequence << imgSeq;
    }
    return seq;
}
