#############################################################################
# Makefile for building: test3
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat May 5 15:45:57 2012
# Project:  test3.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile test3.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lqjson -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		mylistwidget.cpp \
		mylistwidgetreceptor.cpp \
		images.cpp \
		imageinsequence.cpp \
		sequence.cpp \
		newsequence.cpp \
		util.cpp \
		memory.cpp \
		editordersequence.cpp \
		mylistwidgetinternalchange.cpp \
		mybaselistwidget.cpp \
		globval.cpp \
		mylistselector.cpp \
		widgetinselector.cpp \
		organizedialog.cpp \
		onereorganizewidget.cpp \
		casewidget.cpp \
		apiparse.cpp \
		importdialog.cpp \
		imagewidget.cpp \
		imagereceptordelegate.cpp \
		imageseqmodel.cpp \
		mybaselistview.cpp moc_mainwindow.cpp \
		moc_mylistwidget.cpp \
		moc_mylistwidgetreceptor.cpp \
		moc_newsequence.cpp \
		moc_editordersequence.cpp \
		moc_mylistwidgetinternalchange.cpp \
		moc_mybaselistwidget.cpp \
		moc_mylistselector.cpp \
		moc_widgetinselector.cpp \
		moc_organizedialog.cpp \
		moc_onereorganizewidget.cpp \
		moc_casewidget.cpp \
		moc_importdialog.cpp \
		moc_imagewidget.cpp \
		moc_imageseqmodel.cpp \
		moc_mybaselistview.cpp
OBJECTS       = main.o \
		mainwindow.o \
		mylistwidget.o \
		mylistwidgetreceptor.o \
		images.o \
		imageinsequence.o \
		sequence.o \
		newsequence.o \
		util.o \
		memory.o \
		editordersequence.o \
		mylistwidgetinternalchange.o \
		mybaselistwidget.o \
		globval.o \
		mylistselector.o \
		widgetinselector.o \
		organizedialog.o \
		onereorganizewidget.o \
		casewidget.o \
		apiparse.o \
		importdialog.o \
		imagewidget.o \
		imagereceptordelegate.o \
		imageseqmodel.o \
		mybaselistview.o \
		moc_mainwindow.o \
		moc_mylistwidget.o \
		moc_mylistwidgetreceptor.o \
		moc_newsequence.o \
		moc_editordersequence.o \
		moc_mylistwidgetinternalchange.o \
		moc_mybaselistwidget.o \
		moc_mylistselector.o \
		moc_widgetinselector.o \
		moc_organizedialog.o \
		moc_onereorganizewidget.o \
		moc_casewidget.o \
		moc_importdialog.o \
		moc_imagewidget.o \
		moc_imageseqmodel.o \
		moc_mybaselistview.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		test3.pro
QMAKE_TARGET  = test3
DESTDIR       = 
TARGET        = test3

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_newsequence.h ui_editordersequence.h ui_widgetinselector.h ui_organizedialog.h ui_onereorganizewidget.h ui_casewidget.h ui_importdialog.h ui_imagewidget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: test3.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile test3.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile test3.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/test31.0.0 || $(MKDIR) .tmp/test31.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/test31.0.0/ && $(COPY_FILE) --parents mainwindow.h mylistwidget.h mylistwidgetreceptor.h images.h imageinsequence.h sequence.h newsequence.h util.h memory.h editordersequence.h mylistwidgetinternalchange.h mybaselistwidget.h globval.h mylistselector.h widgetinselector.h organizedialog.h onereorganizewidget.h casewidget.h apiparse.h importdialog.h imagewidget.h imagereceptordelegate.h imageseqmodel.h mybaselistview.h .tmp/test31.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp mylistwidget.cpp mylistwidgetreceptor.cpp images.cpp imageinsequence.cpp sequence.cpp newsequence.cpp util.cpp memory.cpp editordersequence.cpp mylistwidgetinternalchange.cpp mybaselistwidget.cpp globval.cpp mylistselector.cpp widgetinselector.cpp organizedialog.cpp onereorganizewidget.cpp casewidget.cpp apiparse.cpp importdialog.cpp imagewidget.cpp imagereceptordelegate.cpp imageseqmodel.cpp mybaselistview.cpp .tmp/test31.0.0/ && $(COPY_FILE) --parents mainwindow.ui newsequence.ui editordersequence.ui widgetinselector.ui organizedialog.ui onereorganizewidget.ui casewidget.ui importdialog.ui imagewidget.ui .tmp/test31.0.0/ && (cd `dirname .tmp/test31.0.0` && $(TAR) test31.0.0.tar test31.0.0 && $(COMPRESS) test31.0.0.tar) && $(MOVE) `dirname .tmp/test31.0.0`/test31.0.0.tar.gz . && $(DEL_FILE) -r .tmp/test31.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_mylistwidget.cpp moc_mylistwidgetreceptor.cpp moc_newsequence.cpp moc_editordersequence.cpp moc_mylistwidgetinternalchange.cpp moc_mybaselistwidget.cpp moc_mylistselector.cpp moc_widgetinselector.cpp moc_organizedialog.cpp moc_onereorganizewidget.cpp moc_casewidget.cpp moc_importdialog.cpp moc_imagewidget.cpp moc_imageseqmodel.cpp moc_mybaselistview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_mylistwidget.cpp moc_mylistwidgetreceptor.cpp moc_newsequence.cpp moc_editordersequence.cpp moc_mylistwidgetinternalchange.cpp moc_mybaselistwidget.cpp moc_mylistselector.cpp moc_widgetinselector.cpp moc_organizedialog.cpp moc_onereorganizewidget.cpp moc_casewidget.cpp moc_importdialog.cpp moc_imagewidget.cpp moc_imageseqmodel.cpp moc_mybaselistview.cpp
moc_mainwindow.cpp: sequence.h \
		imageinsequence.h \
		images.h \
		imagewidget.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_mylistwidget.cpp: mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		mylistwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mylistwidget.h -o moc_mylistwidget.cpp

moc_mylistwidgetreceptor.cpp: mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		mylistwidgetreceptor.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mylistwidgetreceptor.h -o moc_mylistwidgetreceptor.cpp

moc_newsequence.cpp: sequence.h \
		imageinsequence.h \
		images.h \
		newsequence.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) newsequence.h -o moc_newsequence.cpp

moc_editordersequence.cpp: sequence.h \
		imageinsequence.h \
		images.h \
		editordersequence.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) editordersequence.h -o moc_editordersequence.cpp

moc_mylistwidgetinternalchange.cpp: mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		mylistwidgetinternalchange.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mylistwidgetinternalchange.h -o moc_mylistwidgetinternalchange.cpp

moc_mybaselistwidget.cpp: imageinsequence.h \
		images.h \
		sequence.h \
		mybaselistwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mybaselistwidget.h -o moc_mybaselistwidget.cpp

moc_mylistselector.cpp: mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		mylistselector.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mylistselector.h -o moc_mylistselector.cpp

moc_widgetinselector.cpp: mylistselector.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		widgetinselector.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) widgetinselector.h -o moc_widgetinselector.cpp

moc_organizedialog.cpp: onereorganizewidget.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		organizedialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) organizedialog.h -o moc_organizedialog.cpp

moc_onereorganizewidget.cpp: sequence.h \
		imageinsequence.h \
		images.h \
		onereorganizewidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) onereorganizewidget.h -o moc_onereorganizewidget.cpp

moc_casewidget.cpp: imageinsequence.h \
		images.h \
		casewidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) casewidget.h -o moc_casewidget.cpp

moc_importdialog.cpp: sequence.h \
		imageinsequence.h \
		images.h \
		importdialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) importdialog.h -o moc_importdialog.cpp

moc_imagewidget.cpp: imageinsequence.h \
		images.h \
		imagewidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) imagewidget.h -o moc_imagewidget.cpp

moc_imageseqmodel.cpp: imageinsequence.h \
		images.h \
		imageseqmodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) imageseqmodel.h -o moc_imageseqmodel.cpp

moc_mybaselistview.cpp: mybaselistview.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mybaselistview.h -o moc_mybaselistview.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_newsequence.h ui_editordersequence.h ui_widgetinselector.h ui_organizedialog.h ui_onereorganizewidget.h ui_casewidget.h ui_importdialog.h ui_imagewidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_newsequence.h ui_editordersequence.h ui_widgetinselector.h ui_organizedialog.h ui_onereorganizewidget.h ui_casewidget.h ui_importdialog.h ui_imagewidget.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_newsequence.h: newsequence.ui
	/usr/bin/uic-qt4 newsequence.ui -o ui_newsequence.h

ui_editordersequence.h: editordersequence.ui \
		mylistwidgetinternalchange.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	/usr/bin/uic-qt4 editordersequence.ui -o ui_editordersequence.h

ui_widgetinselector.h: widgetinselector.ui \
		mylistselector.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	/usr/bin/uic-qt4 widgetinselector.ui -o ui_widgetinselector.h

ui_organizedialog.h: organizedialog.ui
	/usr/bin/uic-qt4 organizedialog.ui -o ui_organizedialog.h

ui_onereorganizewidget.h: onereorganizewidget.ui \
		mylistselector.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	/usr/bin/uic-qt4 onereorganizewidget.ui -o ui_onereorganizewidget.h

ui_casewidget.h: casewidget.ui
	/usr/bin/uic-qt4 casewidget.ui -o ui_casewidget.h

ui_importdialog.h: importdialog.ui
	/usr/bin/uic-qt4 importdialog.ui -o ui_importdialog.h

ui_imagewidget.h: imagewidget.ui
	/usr/bin/uic-qt4 imagewidget.ui -o ui_imagewidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		imagewidget.h \
		util.h \
		memory.h \
		globval.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		imagewidget.h \
		ui_mainwindow.h \
		newsequence.h \
		mylistwidget.h \
		mybaselistwidget.h \
		widgetinselector.h \
		mylistselector.h \
		globval.h \
		memory.h \
		util.h \
		organizedialog.h \
		onereorganizewidget.h \
		casewidget.h \
		apiparse.h \
		importdialog.h \
		imageseqmodel.h \
		imagereceptordelegate.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mylistwidget.o: mylistwidget.cpp mylistwidget.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mylistwidget.o mylistwidget.cpp

mylistwidgetreceptor.o: mylistwidgetreceptor.cpp mylistwidgetreceptor.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mylistwidgetreceptor.o mylistwidgetreceptor.cpp

images.o: images.cpp images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o images.o images.cpp

imageinsequence.o: imageinsequence.cpp imageinsequence.h \
		images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageinsequence.o imageinsequence.cpp

sequence.o: sequence.cpp sequence.h \
		imageinsequence.h \
		images.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sequence.o sequence.cpp

newsequence.o: newsequence.cpp newsequence.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		ui_newsequence.h \
		util.h \
		memory.h \
		globval.h \
		editordersequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newsequence.o newsequence.cpp

util.o: util.cpp util.h \
		sequence.h \
		imageinsequence.h \
		images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o util.o util.cpp

memory.o: memory.cpp memory.h \
		sequence.h \
		imageinsequence.h \
		images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o memory.o memory.cpp

editordersequence.o: editordersequence.cpp editordersequence.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		ui_editordersequence.h \
		mylistwidgetinternalchange.h \
		mybaselistwidget.h \
		globval.h \
		memory.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o editordersequence.o editordersequence.cpp

mylistwidgetinternalchange.o: mylistwidgetinternalchange.cpp mylistwidgetinternalchange.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mylistwidgetinternalchange.o mylistwidgetinternalchange.cpp

mybaselistwidget.o: mybaselistwidget.cpp mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mybaselistwidget.o mybaselistwidget.cpp

globval.o: globval.cpp globval.h \
		memory.h \
		sequence.h \
		imageinsequence.h \
		images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o globval.o globval.cpp

mylistselector.o: mylistselector.cpp mylistselector.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mylistselector.o mylistselector.cpp

widgetinselector.o: widgetinselector.cpp widgetinselector.h \
		mylistselector.h \
		mybaselistwidget.h \
		imageinsequence.h \
		images.h \
		sequence.h \
		ui_widgetinselector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widgetinselector.o widgetinselector.cpp

organizedialog.o: organizedialog.cpp organizedialog.h \
		onereorganizewidget.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		ui_organizedialog.h \
		globval.h \
		memory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o organizedialog.o organizedialog.cpp

onereorganizewidget.o: onereorganizewidget.cpp onereorganizewidget.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		ui_onereorganizewidget.h \
		mylistselector.h \
		mybaselistwidget.h \
		editordersequence.h \
		util.h \
		globval.h \
		memory.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o onereorganizewidget.o onereorganizewidget.cpp

casewidget.o: casewidget.cpp casewidget.h \
		imageinsequence.h \
		images.h \
		ui_casewidget.h \
		util.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o casewidget.o casewidget.cpp

apiparse.o: apiparse.cpp apiparse.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o apiparse.o apiparse.cpp

importdialog.o: importdialog.cpp importdialog.h \
		sequence.h \
		imageinsequence.h \
		images.h \
		ui_importdialog.h \
		apiparse.h \
		globval.h \
		memory.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o importdialog.o importdialog.cpp

imagewidget.o: imagewidget.cpp imagewidget.h \
		imageinsequence.h \
		images.h \
		util.h \
		sequence.h \
		ui_imagewidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imagewidget.o imagewidget.cpp

imagereceptordelegate.o: imagereceptordelegate.cpp imagereceptordelegate.h \
		imageinsequence.h \
		images.h \
		util.h \
		sequence.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imagereceptordelegate.o imagereceptordelegate.cpp

imageseqmodel.o: imageseqmodel.cpp imageseqmodel.h \
		imageinsequence.h \
		images.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageseqmodel.o imageseqmodel.cpp

mybaselistview.o: mybaselistview.cpp mybaselistview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mybaselistview.o mybaselistview.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_mylistwidget.o: moc_mylistwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mylistwidget.o moc_mylistwidget.cpp

moc_mylistwidgetreceptor.o: moc_mylistwidgetreceptor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mylistwidgetreceptor.o moc_mylistwidgetreceptor.cpp

moc_newsequence.o: moc_newsequence.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newsequence.o moc_newsequence.cpp

moc_editordersequence.o: moc_editordersequence.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_editordersequence.o moc_editordersequence.cpp

moc_mylistwidgetinternalchange.o: moc_mylistwidgetinternalchange.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mylistwidgetinternalchange.o moc_mylistwidgetinternalchange.cpp

moc_mybaselistwidget.o: moc_mybaselistwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mybaselistwidget.o moc_mybaselistwidget.cpp

moc_mylistselector.o: moc_mylistselector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mylistselector.o moc_mylistselector.cpp

moc_widgetinselector.o: moc_widgetinselector.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widgetinselector.o moc_widgetinselector.cpp

moc_organizedialog.o: moc_organizedialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_organizedialog.o moc_organizedialog.cpp

moc_onereorganizewidget.o: moc_onereorganizewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_onereorganizewidget.o moc_onereorganizewidget.cpp

moc_casewidget.o: moc_casewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_casewidget.o moc_casewidget.cpp

moc_importdialog.o: moc_importdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_importdialog.o moc_importdialog.cpp

moc_imagewidget.o: moc_imagewidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_imagewidget.o moc_imagewidget.cpp

moc_imageseqmodel.o: moc_imageseqmodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_imageseqmodel.o moc_imageseqmodel.cpp

moc_mybaselistview.o: moc_mybaselistview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mybaselistview.o moc_mybaselistview.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

