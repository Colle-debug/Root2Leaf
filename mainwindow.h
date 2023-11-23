#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QApplication>
#include <QIcon>
#include <chrono> // utilizzata per benchmark tempo di esecuzione

class MainWindow : public QWidget {
public:
    MainWindow() {
        setupUi();
        refreshPlot();
    }

private:
    void setupUi();
    void refreshPlot();
    QGraphicsScene* scene;
    QGraphicsView* view;
    QPushButton* refreshButton;
    QLabel* guaranteedLevelsLabel;
    QComboBox* guaranteedLevelsCombo;
    QLabel* maxDepthLabel;
    QComboBox* maxDepthCombo;
};
