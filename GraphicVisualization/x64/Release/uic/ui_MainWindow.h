/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <LayerManagement.h>
#include <LayerView.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ToolManagement.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddPoint;
    QAction *actionAddLine;
    QAction *actionAddPolyLine;
    QAction *actionAddRectangle;
    QAction *actionAddCircle;
    QAction *actionAddSector;
    QAction *actionAddPolygon;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionScollHand;
    QAction *actionrubberBand;
    QAction *actionGlobal;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionAddLayer;
    QAction *actionSaveLayerPixmap;
    QAction *actionRemoveLayer;
    QAction *actionSaveLayerPDF;
    QAction *actionDataAnalysis;
    QAction *actionAddCurve;
    QAction *actionAddText;
    QAction *actionAddPicture;
    QAction *actionWindowColor;
    QAction *actionWindowFont;
    QAction *actionConvexHull;
    QAction *actionDelaunayTriangulation;
    QAction *actionToolBox;
    QAction *actionChessBoard;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    LayerView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuAddShape;
    QMenu *menuFile;
    QMenu *menuLayer;
    QMenu *menuStyle;
    QMenu *menuVector;
    QMenu *menuVectorProcessingTool;
    QMenu *menuGeometryTools;
    QMenu *menuRaster;
    QMenu *menuImgProc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *treeDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    LayerManagement *layerManagement;
    QDockWidget *toolDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *toolBoxSearchBar;
    QVBoxLayout *verticalLayout_2;
    ToolManagement *toolManagement;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1115, 748);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/me.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionAddPoint = new QAction(MainWindow);
        actionAddPoint->setObjectName(QString::fromUtf8("actionAddPoint"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\347\202\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPoint->setIcon(icon1);
        actionAddLine = new QAction(MainWindow);
        actionAddLine->setObjectName(QString::fromUtf8("actionAddLine"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddLine->setIcon(icon2);
        actionAddPolyLine = new QAction(MainWindow);
        actionAddPolyLine->setObjectName(QString::fromUtf8("actionAddPolyLine"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\346\212\230\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPolyLine->setIcon(icon3);
        actionAddRectangle = new QAction(MainWindow);
        actionAddRectangle->setObjectName(QString::fromUtf8("actionAddRectangle"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\347\237\251\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddRectangle->setIcon(icon4);
        actionAddCircle = new QAction(MainWindow);
        actionAddCircle->setObjectName(QString::fromUtf8("actionAddCircle"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\345\234\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddCircle->setIcon(icon5);
        actionAddSector = new QAction(MainWindow);
        actionAddSector->setObjectName(QString::fromUtf8("actionAddSector"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\346\211\207\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddSector->setIcon(icon6);
        actionAddPolygon = new QAction(MainWindow);
        actionAddPolygon->setObjectName(QString::fromUtf8("actionAddPolygon"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\345\244\232\350\276\271\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPolygon->setIcon(icon7);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/\346\211\223\345\274\200\346\226\207\344\273\266.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon8);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/\344\277\235\345\255\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon9);
        actionScollHand = new QAction(MainWindow);
        actionScollHand->setObjectName(QString::fromUtf8("actionScollHand"));
        actionScollHand->setCheckable(true);
        actionScollHand->setChecked(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/\346\211\213\346\216\214.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScollHand->setIcon(icon10);
        actionrubberBand = new QAction(MainWindow);
        actionrubberBand->setObjectName(QString::fromUtf8("actionrubberBand"));
        actionrubberBand->setCheckable(true);
        actionrubberBand->setChecked(false);
        actionrubberBand->setEnabled(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/\351\274\240\346\240\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionrubberBand->setIcon(icon11);
        actionGlobal = new QAction(MainWindow);
        actionGlobal->setObjectName(QString::fromUtf8("actionGlobal"));
        actionGlobal->setCheckable(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/\345\234\260\347\220\203.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGlobal->setIcon(icon12);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        actionZoomIn->setCheckable(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/\346\224\276\345\244\247.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon13);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        actionZoomOut->setCheckable(false);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/\347\274\251\345\260\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon14);
        actionAddLayer = new QAction(MainWindow);
        actionAddLayer->setObjectName(QString::fromUtf8("actionAddLayer"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/\346\226\260\345\273\272\345\233\276\345\261\202.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddLayer->setIcon(icon15);
        actionSaveLayerPixmap = new QAction(MainWindow);
        actionSaveLayerPixmap->setObjectName(QString::fromUtf8("actionSaveLayerPixmap"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/\344\277\235\345\255\230\345\233\276\345\261\202.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveLayerPixmap->setIcon(icon16);
        actionRemoveLayer = new QAction(MainWindow);
        actionRemoveLayer->setObjectName(QString::fromUtf8("actionRemoveLayer"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemoveLayer->setIcon(icon17);
        actionSaveLayerPDF = new QAction(MainWindow);
        actionSaveLayerPDF->setObjectName(QString::fromUtf8("actionSaveLayerPDF"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/\344\277\235\345\255\230\345\233\276\345\261\202\344\270\272PDF.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveLayerPDF->setIcon(icon18);
        actionDataAnalysis = new QAction(MainWindow);
        actionDataAnalysis->setObjectName(QString::fromUtf8("actionDataAnalysis"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/\346\225\260\346\215\256\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDataAnalysis->setIcon(icon19);
        actionAddCurve = new QAction(MainWindow);
        actionAddCurve->setObjectName(QString::fromUtf8("actionAddCurve"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/\346\233\262\347\272\277.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddCurve->setIcon(icon20);
        actionAddText = new QAction(MainWindow);
        actionAddText->setObjectName(QString::fromUtf8("actionAddText"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/\346\226\207\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddText->setIcon(icon21);
        actionAddPicture = new QAction(MainWindow);
        actionAddPicture->setObjectName(QString::fromUtf8("actionAddPicture"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/\345\233\276\347\211\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPicture->setIcon(icon22);
        actionWindowColor = new QAction(MainWindow);
        actionWindowColor->setObjectName(QString::fromUtf8("actionWindowColor"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/\350\203\214\346\231\257\351\242\234\350\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWindowColor->setIcon(icon23);
        actionWindowFont = new QAction(MainWindow);
        actionWindowFont->setObjectName(QString::fromUtf8("actionWindowFont"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/\345\255\227\344\275\223.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWindowFont->setIcon(icon24);
        actionConvexHull = new QAction(MainWindow);
        actionConvexHull->setObjectName(QString::fromUtf8("actionConvexHull"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/\345\207\270\345\214\205.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvexHull->setIcon(icon25);
        actionDelaunayTriangulation = new QAction(MainWindow);
        actionDelaunayTriangulation->setObjectName(QString::fromUtf8("actionDelaunayTriangulation"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/\344\270\215\350\247\204\345\210\231\344\270\211\350\247\222\347\275\221.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelaunayTriangulation->setIcon(icon26);
        actionToolBox = new QAction(MainWindow);
        actionToolBox->setObjectName(QString::fromUtf8("actionToolBox"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/\345\267\245\345\205\267\347\256\261.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToolBox->setIcon(icon27);
        actionChessBoard = new QAction(MainWindow);
        actionChessBoard->setObjectName(QString::fromUtf8("actionChessBoard"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/\346\243\213\347\233\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChessBoard->setIcon(icon28);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new LayerView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1115, 26));
        menuAddShape = new QMenu(menuBar);
        menuAddShape->setObjectName(QString::fromUtf8("menuAddShape"));
        menuAddShape->setCursor(QCursor(Qt::ArrowCursor));
        menuAddShape->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/\346\267\273\345\212\240\345\233\276\345\275\242.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAddShape->setIcon(icon29);
        menuAddShape->setSeparatorsCollapsible(false);
        menuAddShape->setToolTipsVisible(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/\346\226\207\344\273\266\345\244\271.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuFile->setIcon(icon30);
        menuLayer = new QMenu(menuBar);
        menuLayer->setObjectName(QString::fromUtf8("menuLayer"));
        menuLayer->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/\345\233\276\345\261\202.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLayer->setIcon(icon31);
        menuStyle = new QMenu(menuBar);
        menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
        menuStyle->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/\346\240\267\345\274\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuStyle->setIcon(icon32);
        menuVector = new QMenu(menuBar);
        menuVector->setObjectName(QString::fromUtf8("menuVector"));
        menuVector->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/\347\237\242\351\207\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuVector->setIcon(icon33);
        menuVectorProcessingTool = new QMenu(menuVector);
        menuVectorProcessingTool->setObjectName(QString::fromUtf8("menuVectorProcessingTool"));
        menuVectorProcessingTool->setStyleSheet(QString::fromUtf8("QMenu {\n"
"      margin: 2px; /* some spacing around the menu */\n"
"  }\n"
"\n"
"  QMenu::item {\n"
"      padding: 2px 25px 2px 20px;\n"
"      border: 1px solid transparent; /* reserve space for selection border */\n"
"  }\n"
"\n"
"  QMenu::item:selected {\n"
"      border-color: darkblue;\n"
"      background: rgba(100, 100, 100, 150);\n"
"  }\n"
"\n"
"  QMenu::icon:checked { /* appearance of a 'checked' icon */\n"
"      background: gray;\n"
"      border: 1px inset gray;\n"
"      position: absolute;\n"
"      top: 1px;\n"
"      right: 1px;\n"
"      bottom: 1px;\n"
"      left: 1px;\n"
"  }\n"
"\n"
"  QMenu::separator {\n"
"      height: 2px;\n"
"      background: lightblue;\n"
"      margin-left: 10px;\n"
"      margin-right: 5px;\n"
"  }\n"
"\n"
"  QMenu::indicator {\n"
"      width: 13px;\n"
"      height: 13px;\n"
"  }\n"
"\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:non-exclusive:unchecked {\n"
"      image: url(:/images/"
                        "checkbox_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:unchecked:selected {\n"
"      image: url(:/images/checkbox_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked {\n"
"      image: url(:/images/checkbox_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:non-exclusive:checked:selected {\n"
"      image: url(:/images/checkbox_checked_hover.png);\n"
"  }\n"
"\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"  QMenu::indicator:exclusive:unchecked {\n"
"      image: url(:/images/radiobutton_unchecked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:unchecked:selected {\n"
"      image: url(:/images/radiobutton_unchecked_hover.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked {\n"
"      image: url(:/images/radiobutton_checked.png);\n"
"  }\n"
"\n"
"  QMenu::indicator:exclusive:checked:selected {\n"
"      image: url(:/images/radiobutton_checked_hover.png);\n"
"  } "));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/\347\237\242\351\207\217\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuVectorProcessingTool->setIcon(icon34);
        menuGeometryTools = new QMenu(menuVector);
        menuGeometryTools->setObjectName(QString::fromUtf8("menuGeometryTools"));
        menuGeometryTools->setTearOffEnabled(false);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/\345\207\240\344\275\225\345\210\206\346\236\220.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuGeometryTools->setIcon(icon35);
        menuRaster = new QMenu(menuBar);
        menuRaster->setObjectName(QString::fromUtf8("menuRaster"));
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/\346\240\205\346\240\274.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuRaster->setIcon(icon36);
        menuImgProc = new QMenu(menuBar);
        menuImgProc->setObjectName(QString::fromUtf8("menuImgProc"));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/\345\233\276\345\203\217\345\244\204\347\220\206.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuImgProc->setIcon(icon37);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setStyleSheet(QString::fromUtf8("QToolBar\n"
"{\n"
"	border: none;\n"
"	padding: 1px;\n"
"}\n"
"QToolBar QToolButton:hover {\n"
"    background-color: #E6F0E6;\n"
"    border: 2px solid #00BB9E;\n"
"}\n"
"QToolBar QToolButton:pressed {\n"
"    background-color: #969696;\n"
"    border: 2px solid #00BB9E;\n"
"}\n"
"\n"
""));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("  QStatusBar::item {\n"
"      border-radius: 3px;\n"
"  }"));
        MainWindow->setStatusBar(statusBar);
        treeDockWidget = new QDockWidget(MainWindow);
        treeDockWidget->setObjectName(QString::fromUtf8("treeDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        layerManagement = new LayerManagement(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        layerManagement->setHeaderItem(__qtreewidgetitem);
        layerManagement->setObjectName(QString::fromUtf8("layerManagement"));
        layerManagement->setStyleSheet(QString::fromUtf8("QTreeView::branch:has-siblings:!adjoins-item {\n"
"    border-image: url(:/vline.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:adjoins-item {\n"
"    border-image: url(:/branch-more.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"    border-image: url(:/branch-end.png) 0;\n"
"}\n"
"\n"
"QTreeView::branch:has-children:!has-siblings:closed,\n"
"QTreeView::branch:closed:has-children:has-siblings {\n"
"        border-image: none;\n"
"        image: url(:/branch-closed.png);\n"
"}\n"
"\n"
"QTreeView::branch:open:has-children:!has-siblings,\n"
"QTreeView::branch:open:has-children:has-siblings  {\n"
"        border-image: none;\n"
"        image: url(:/branch-open.png);\n"
"}"));

        verticalLayout_3->addWidget(layerManagement);


        verticalLayout->addLayout(verticalLayout_3);

        treeDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, treeDockWidget);
        toolDockWidget = new QDockWidget(MainWindow);
        toolDockWidget->setObjectName(QString::fromUtf8("toolDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        toolBoxSearchBar = new QLineEdit(dockWidgetContents_2);
        toolBoxSearchBar->setObjectName(QString::fromUtf8("toolBoxSearchBar"));
        toolBoxSearchBar->setEnabled(true);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        toolBoxSearchBar->setFont(font);
        toolBoxSearchBar->setFocusPolicy(Qt::ClickFocus);
        toolBoxSearchBar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"border: 1px solid gray;\n"
"border-radius: 5px;\n"
"padding: 0 8px;\n"
"background: white;\n"
"selection-background-color: darkgray;\n"
"}"));
        toolBoxSearchBar->setMaxLength(32767);
        toolBoxSearchBar->setFrame(true);
        toolBoxSearchBar->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(toolBoxSearchBar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        toolManagement = new ToolManagement(dockWidgetContents_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        toolManagement->setHeaderItem(__qtreewidgetitem1);
        toolManagement->setObjectName(QString::fromUtf8("toolManagement"));

        verticalLayout_2->addWidget(toolManagement);


        verticalLayout_4->addLayout(verticalLayout_2);

        toolDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, toolDockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLayer->menuAction());
        menuBar->addAction(menuAddShape->menuAction());
        menuBar->addAction(menuVector->menuAction());
        menuBar->addAction(menuRaster->menuAction());
        menuBar->addAction(menuImgProc->menuAction());
        menuBar->addAction(menuStyle->menuAction());
        menuAddShape->addAction(actionAddPoint);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddLine);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddPolyLine);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddRectangle);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddCircle);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddSector);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddPolygon);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddCurve);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddText);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionAddPicture);
        menuAddShape->addSeparator();
        menuAddShape->addAction(actionChessBoard);
        menuAddShape->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuLayer->addAction(actionAddLayer);
        menuLayer->addSeparator();
        menuLayer->addAction(actionRemoveLayer);
        menuLayer->addSeparator();
        menuLayer->addAction(actionSaveLayerPDF);
        menuLayer->addSeparator();
        menuLayer->addAction(actionSaveLayerPixmap);
        menuLayer->addSeparator();
        menuStyle->addAction(actionWindowColor);
        menuStyle->addSeparator();
        menuStyle->addAction(actionWindowFont);
        menuStyle->addSeparator();
        menuVector->addAction(menuVectorProcessingTool->menuAction());
        menuVector->addSeparator();
        menuVector->addAction(menuGeometryTools->menuAction());
        menuVector->addSeparator();
        menuVectorProcessingTool->addAction(actionConvexHull);
        menuVectorProcessingTool->addSeparator();
        menuGeometryTools->addAction(actionDelaunayTriangulation);
        menuGeometryTools->addSeparator();
        mainToolBar->addAction(actionScollHand);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionrubberBand);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionGlobal);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoomIn);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionZoomOut);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDataAnalysis);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionToolBox);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Graphic Visualization", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        actionAddPoint->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\202\271", nullptr));
        actionAddLine->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\272\277", nullptr));
        actionAddPolyLine->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\212\230\347\272\277", nullptr));
        actionAddPolyLine->setIconText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\244\232\350\276\271\345\275\242", nullptr));
        actionAddRectangle->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\347\237\251\345\275\242", nullptr));
        actionAddCircle->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\234\206", nullptr));
        actionAddSector->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\211\207\345\275\242", nullptr));
        actionAddPolygon->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\244\232\350\276\271\345\275\242", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        actionScollHand->setText(QCoreApplication::translate("MainWindow", "scollHand", nullptr));
#if QT_CONFIG(tooltip)
        actionScollHand->setToolTip(QCoreApplication::translate("MainWindow", "\346\213\226\345\212\250", nullptr));
#endif // QT_CONFIG(tooltip)
        actionrubberBand->setText(QCoreApplication::translate("MainWindow", "rubberBand", nullptr));
#if QT_CONFIG(tooltip)
        actionrubberBand->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
#endif // QT_CONFIG(tooltip)
        actionGlobal->setText(QCoreApplication::translate("MainWindow", "global", nullptr));
#if QT_CONFIG(tooltip)
        actionGlobal->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\250\345\261\200\346\265\217\350\247\210", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "zoomIn", nullptr));
#if QT_CONFIG(tooltip)
        actionZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "zoomOut", nullptr));
#if QT_CONFIG(tooltip)
        actionZoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAddLayer->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\276\345\261\202", nullptr));
        actionSaveLayerPixmap->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\261\202\344\270\272\345\233\276\347\211\207", nullptr));
        actionRemoveLayer->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\233\276\345\261\202", nullptr));
        actionSaveLayerPDF->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\261\202\344\270\272PDF", nullptr));
        actionDataAnalysis->setText(QCoreApplication::translate("MainWindow", "dataAnalysis", nullptr));
#if QT_CONFIG(tooltip)
        actionDataAnalysis->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAddCurve->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\233\262\347\272\277", nullptr));
        actionAddText->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\346\226\207\346\234\254", nullptr));
        actionAddPicture->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\345\233\276\347\211\207", nullptr));
        actionWindowColor->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\351\242\234\350\211\262", nullptr));
        actionWindowFont->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\345\255\227\344\275\223", nullptr));
        actionConvexHull->setText(QCoreApplication::translate("MainWindow", "\345\207\270\345\214\205", nullptr));
        actionDelaunayTriangulation->setText(QCoreApplication::translate("MainWindow", "Delaunay\344\270\211\350\247\222\347\275\221", nullptr));
        actionToolBox->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", nullptr));
#if QT_CONFIG(tooltip)
        actionToolBox->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", nullptr));
#endif // QT_CONFIG(tooltip)
        actionChessBoard->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266\346\243\213\347\233\230", nullptr));
#if QT_CONFIG(tooltip)
        menuAddShape->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\276\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        menuAddShape->setTitle(QCoreApplication::translate("MainWindow", "addShape", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "file", nullptr));
#if QT_CONFIG(tooltip)
        menuLayer->setToolTip(QCoreApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
#endif // QT_CONFIG(tooltip)
        menuLayer->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\261\202", nullptr));
        menuStyle->setTitle(QCoreApplication::translate("MainWindow", "\346\240\267\345\274\217", nullptr));
        menuVector->setTitle(QCoreApplication::translate("MainWindow", "\347\237\242\351\207\217", nullptr));
        menuVectorProcessingTool->setTitle(QCoreApplication::translate("MainWindow", "\347\237\242\351\207\217\345\244\204\347\220\206\345\267\245\345\205\267", nullptr));
        menuGeometryTools->setTitle(QCoreApplication::translate("MainWindow", "\345\207\240\344\275\225\345\233\276\345\275\242\345\267\245\345\205\267", nullptr));
        menuRaster->setTitle(QCoreApplication::translate("MainWindow", "\346\240\205\346\240\274", nullptr));
        menuImgProc->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#if QT_CONFIG(tooltip)
        mainToolBar->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBoxSearchBar->setInputMask(QString());
        toolBoxSearchBar->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
