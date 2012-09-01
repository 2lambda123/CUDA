#ifndef WAVEMAPCUDA_H
#define WAVEMAPCUDA_H

class WMatrix;
#include "wavemap.h"

/**
 * Das H�henfeld der WaterPlane.
 *
 * Zur Berechnung der H�henfeldwerttver�nderungen werden zwei 
 * Exemplare der Klasse: WMatrix ben�tgt um den DoubleBuffer - Mechanismus zu realisieren.
 * So kann der alte Zustand (Belegung der H�henfelder) gehalten werden
 * um auf von diesem Zustand ausgehend die neue Belegung der H�henfelder 
 * zu berechnen. F�r den n�chsten Schritt tauschen die Buffer die Rollen.
 */
class WaveMapCUDA : public WaveMap
{
public:

	WaveMapCUDA(unsigned int pX, unsigned int pY, float damp);
	/**
	 * Berechnet die aktuelle H�henfledbelegung
	 */
	virtual void updateWaveMap();

	virtual ~WaveMapCUDA(void);

private:

	float* dev_oldWave;
	float* dev_newWave;

	unsigned int *rowSize;
	unsigned int *arraySize;
	unsigned int *dev_arraySize;
	unsigned int *dev_arrayDIM;

};
#endif



