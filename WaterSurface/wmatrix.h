#ifndef WMATRIX_H
#define WMATRIX_H

/**
 * Behelfsklasse f�r Matrizen belieber Gr��e.
 */
class WMatrix
{
public:

	/**
	 * Der Konstruktor
	 */
	WMatrix(unsigned int columns, unsigned int rows);

	/**
	 * Gibt den Wert des jeweiligen Elements zur�ck.
	 */
	virtual float getElement(int column, int row);

	/**
	 * Setzt den Wert des jeweiligen Elements zur�ck.
	 */
	virtual void setElement(int column, int row, float value);

	/**
	 * Die Gr��e der Matrix.
	 */
	virtual int getSize(void);

	/**
	 * Anzahl der Zeilen.
	 */
	virtual int getRowCount(void);

	/**
	 * Anzahl der Spalten.
	 */
	virtual int getColumnCount(void);

	virtual void printMatrix(void);

	virtual ~WMatrix(void);

	float* Values;

private:

	unsigned int rowCount;
	unsigned int columnCount;

	
};

#endif
