#include "mainwindow.h"
#include "BinaryTree.h"

void MainWindow::setupUi() {
    // Inizializzazione degli elementi grafici
    scene = new QGraphicsScene;
    view = new QGraphicsView(scene);
    refreshButton = new QPushButton("Random Tree", view);
    guaranteedLevelsLabel = new QLabel("Guaranteed Levels:", view);
    guaranteedLevelsCombo = new QComboBox(view);
    maxDepthLabel = new QLabel("Maximum Depth:", view);
    maxDepthCombo = new QComboBox(view);

    // Impostazione delle geometrie degli elementi
    refreshButton->setGeometry(10, 10, 230, 30);
    guaranteedLevelsLabel->setGeometry(10, 50, 120, 30);
    guaranteedLevelsCombo->setGeometry(120, 50, 120, 30);
    maxDepthLabel->setGeometry(10, 90, 120, 30);
    maxDepthCombo->setGeometry(120, 90, 120, 30);

    for (int i = 0; i <= 6; ++i) {
        guaranteedLevelsCombo->addItem(QString::number(i));
        maxDepthCombo->addItem(QString::number(i));
    }

    QIcon appIcon(":/icon/tree.png");
    qApp->setApplicationDisplayName("Root2Leaf 1.0");
    qApp->setWindowIcon(appIcon);
    view->setFixedSize(1280, 720);
    view->showMaximized();
}

void MainWindow::refreshPlot() {
    QObject::connect(refreshButton, &QPushButton::clicked, [&]() {
        int guaranteedLevels = guaranteedLevelsCombo->currentText().toInt();
        int maxDepth = maxDepthCombo->currentText().toInt();
        refreshTree(*scene, guaranteedLevels, maxDepth);
    });
}

