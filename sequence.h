#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <dqmodel.h>
#include <imageinsequence.h>
#include <images.h>
#include <QMap>

class Sequence : public DQModel
{
    DQ_MODEL
public:
      DQField<QString> name;
      DQField<QDateTime> creationDate;
      void addImageInSequence(ImageInSequence is);
      DQForeignKey<ImageInSequence> is1;
      DQForeignKey<ImageInSequence> is2;
      DQForeignKey<ImageInSequence> is3;
      DQForeignKey<ImageInSequence> is4;
      DQForeignKey<ImageInSequence> is5;
      DQForeignKey<ImageInSequence> is6;
      DQForeignKey<ImageInSequence> is7;
      DQForeignKey<ImageInSequence> is8;
      DQForeignKey<ImageInSequence> is9;
      DQForeignKey<ImageInSequence> is10;
      DQForeignKey<ImageInSequence> is11;
      DQForeignKey<ImageInSequence> is12;
      DQForeignKey<ImageInSequence> is13;

private:
      QList<DQForeignKey<ImageInSequence>* > listIs;
      bool initIs();

      Images iFake;
      ImageInSequence isFake;

  };

  /// Declare the model and the field clause
  DQ_DECLARE_MODEL(Sequence,
                   "sequence", // the table name.
                   DQ_FIELD(creationDate , DQDefault("CURRENT_TIMESTAMP") ), // The default value for the field is the current timestamp
                   DQ_FIELD(name), // If no special requirement to the field , you don't need to pass the second argument
                   DQ_FIELD(is1),
                   DQ_FIELD(is2),
                   DQ_FIELD(is3),
                   DQ_FIELD(is4),
                   DQ_FIELD(is5),
                   DQ_FIELD(is6),
                   DQ_FIELD(is7),
                   DQ_FIELD(is8),
                   DQ_FIELD(is9),
                   DQ_FIELD(is10),
                   DQ_FIELD(is11),
                   DQ_FIELD(is12),
                   DQ_FIELD(is13)
                   );
#endif // SEQUENCE_H
