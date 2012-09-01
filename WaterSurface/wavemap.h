#ifndef WAVEMAP_H
#define WAVEMAP_H

class WMatrix;

/**
 * Das H�henfeld der WaterPlane.
 *
 * Zur Berechnung der H�henfeldwerttver�nderungen werden zwei 
 * Exemplare der Klasse: WMatrix ben�tgt um den DoubleBuffer - Mechanismus zu realisieren.
 * So kann der alte Zustand (Belegung der H�henfelder) gehalten werden
 * um auf von diesem Zustand ausgehend die neue Belegung der H�henfelder 
 * zu berechnen. F�r den n�chsten Schritt tauschen die Buffer die Rollen.
 */
class WaveMap
{
public:

	/**
	 * Erzeugt eine neue WaveMap mit der Ausdehnung pX * pY und einem damp - Factor.
	 * Dieser wird f�r die Berechnung der Welle bzw. deren Ausdehnung herangezogen.
	 */
	WaveMap(int pX, int pY, float damp);
	WaveMap();

	/**
	 * Vertauscht die beiden Buffer in ihrer Rolle.
	 */
	void swap();

	/**
	 * Verh�ndert den H�henwert um an der Stelle (x,y).
	 */
	void push(int x, int y, float value);

	/**
	 * Berechnet die aktuelle H�henfledbelegung
	 */
	virtual void updateWaveMap();

	/**
	 * Anzahl der Punkte in X - Richtung
	 */
	int getPointsX();

	/**
	 * Anzahl der Punkte in Y - Richtung
	 */
	int getPointsY();

	/** 
	 * H�henwert an Stelle (x,y)
	 */
	virtual float getHeight(int x, int y);

	virtual ~WaveMap(void);

protected:
	WMatrix* newWave;
	WMatrix* tmp;
	WMatrix* oldWave;
	
protected:
	int pointsX;
	int pointsY;
	
	float sizeX;
	float sizeY;

	float stepSize;
	
	float dampFactor;

};
#endif



