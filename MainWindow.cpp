#include "MainWindow.h"

#include "GeoUtils.h"

#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QWidget>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Coordinate Converter");
    resize(500, 350);

    auto *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QVBoxLayout(central);

    //----------------------------------------
    // Title
    //----------------------------------------

    auto *title = new QLabel("<h2>Input Coordinates (DMS)</h2>");
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    //----------------------------------------
    // Latitude
    //----------------------------------------

    auto *latGroup = new QGroupBox("Latitude");

    auto *latLayout = new QGridLayout(latGroup);

    latLayout->addWidget(new QLabel("Degrees"), 0, 0);
    latLayout->addWidget(new QLabel("Minutes"), 0, 1);
    latLayout->addWidget(new QLabel("Seconds"), 0, 2);

    latDegEdit = new QLineEdit;
    latMinEdit = new QLineEdit;
    latSecEdit = new QLineEdit;

    latLayout->addWidget(latDegEdit, 1, 0);
    latLayout->addWidget(latMinEdit, 1, 1);
    latLayout->addWidget(latSecEdit, 1, 2);

    mainLayout->addWidget(latGroup);

    //----------------------------------------
    // Longitude
    //----------------------------------------

    auto *lonGroup = new QGroupBox("Longitude");

    auto *lonLayout = new QGridLayout(lonGroup);

    lonLayout->addWidget(new QLabel("Degrees"), 0, 0);
    lonLayout->addWidget(new QLabel("Minutes"), 0, 1);
    lonLayout->addWidget(new QLabel("Seconds"), 0, 2);

    lonDegEdit = new QLineEdit;
    lonMinEdit = new QLineEdit;
    lonSecEdit = new QLineEdit;

    lonLayout->addWidget(lonDegEdit, 1, 0);
    lonLayout->addWidget(lonMinEdit, 1, 1);
    lonLayout->addWidget(lonSecEdit, 1, 2);

    mainLayout->addWidget(lonGroup);

    //----------------------------------------
    // Validators
    //----------------------------------------

    latDegEdit->setValidator(new QDoubleValidator(-90.0, 90.0, 6, this));
    latMinEdit->setValidator(new QDoubleValidator(0.0, 59.999999, 6, this));
    latSecEdit->setValidator(new QDoubleValidator(0.0, 59.999999, 6, this));

    lonDegEdit->setValidator(new QDoubleValidator(-180.0, 180.0, 6, this));
    lonMinEdit->setValidator(new QDoubleValidator(0.0, 59.999999, 6, this));
    lonSecEdit->setValidator(new QDoubleValidator(0.0, 59.999999, 6, this));

    //----------------------------------------
    // Convert Button
    //----------------------------------------

    convertButton = new QPushButton("Convert");

    auto *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(convertButton);
    buttonLayout->addStretch();

    mainLayout->addLayout(buttonLayout);

    //----------------------------------------
    // Result
    //----------------------------------------

    auto *resultGroup = new QGroupBox("Result");

    auto *resultLayout = new QFormLayout(resultGroup);

    latResultLabel = new QLabel("---");
    lonResultLabel = new QLabel("---");

    resultLayout->addRow("Latitude:", latResultLabel);
    resultLayout->addRow("Longitude:", lonResultLabel);

    mainLayout->addWidget(resultGroup);

    //----------------------------------------
    // Connections
    //----------------------------------------

    connect(convertButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onConvertClicked);

    statusBar()->showMessage("Ready");
}

void MainWindow::onConvertClicked()
{
    GeoUtils utils;

    GeoPoint p = utils.ConvertHMStoDD(
        latDegEdit->text().toDouble(),
        latMinEdit->text().toDouble(),
        latSecEdit->text().toDouble(),
        lonDegEdit->text().toDouble(),
        lonMinEdit->text().toDouble(),
        lonSecEdit->text().toDouble());

    latResultLabel->setText(QString::number(p.lat, 'f', 6));
    lonResultLabel->setText(QString::number(p.lon, 'f', 6));

    statusBar()->showMessage("Conversion completed.", 3000);
}
