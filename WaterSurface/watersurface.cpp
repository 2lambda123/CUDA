#include "watersurface.h"
#include <QtGui/QVBoxLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QCheckBox>
#include <QtOpenGL/QGLFormat>
#include <QtGui/QDoubleSpinBox>
#include <iostream>

WaterSurface::WaterSurface(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	renderWidget = new RenderWidget();
	centralWidget = new QWidget();
	QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
	QGridLayout *controlLayout = new QGridLayout();
	controlLayout->setAlignment(Qt::AlignLeft);
	controlLayout->addWidget(new QLabel("Wave Size"),1,1);
	waveSize = new QDoubleSpinBox();
	waveSize->setRange(0.01,0.5);
	waveSize->setSingleStep(0.01);
	waveSize->setFixedWidth(100);
	waveSize->setValue(0.1);
	QObject::connect(waveSize, SIGNAL(valueChanged(double)),this, SLOT(changeWaveSettingsSize(double)));
	controlLayout->addWidget(waveSize,1,2);

	controlLayout->addWidget(new QLabel("Wave Intensity"),2,1);
	waveIntens = new QDoubleSpinBox();
	waveIntens->setRange(0.05,0.5);
	waveIntens->setSingleStep(0.01);
	waveIntens->setValue(0.1);
	waveIntens->setFixedWidth(100);
	QObject::connect(waveIntens, SIGNAL(valueChanged(double)),this, SLOT(changeWaveSettingsIntens(double)));
	controlLayout->addWidget(waveIntens,2,2);

	QPushButton *reset = new QPushButton("Reset");
	QObject::connect(reset, SIGNAL(clicked()),this, SLOT(resetWaveSettings()));
	reset->setFixedWidth(100);

	QCheckBox *checkbox = new QCheckBox("Toggle Edges");
	QObject::connect(checkbox, SIGNAL(stateChanged(int)),this, SLOT(toggleEdges(int)));

	controlLayout->addWidget(checkbox,1,3);
	controlLayout->addWidget(new QLabel("To rotate the scene press CTRL+mouse movement"),2,3);
	controlLayout->addWidget(reset,3,1);
	setCentralWidget(centralWidget);
	mainLayout->addLayout(controlLayout);
	mainLayout->addWidget(renderWidget);  
	setWindowTitle(tr("Water Surface"));
	resize(1044,800);
}

void WaterSurface::changeWaveSettingsIntens(double waveI)
{
	float waveS = waveSize->value();
	renderWidget->changeWaveSettings(waveS,waveI);
}

void WaterSurface::changeWaveSettingsSize(double waveS)
{
	float waveI = waveIntens->value();
	renderWidget->changeWaveSettings(waveS,waveI);
}

void WaterSurface::resetWaveSettings()
{
	waveIntens->setValue(0.1);
	waveSize->setValue(0.1);
	renderWidget->changeWaveSettings(0.1,0.1);
	renderWidget->resetWaterPlane();
}

void WaterSurface::toggleEdges(int state)
{
	renderWidget->toggleEdges();
}

WaterSurface::~WaterSurface()
{

}