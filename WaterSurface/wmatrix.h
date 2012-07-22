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
	float getElement(int column, int row);

	/**
	 * Setzt den Wert des jeweiligen Elements zur�ck.
	 */
	void setElement(int column, int row, float value);

	/**
	 * Die Gr��e der Matrix.
	 */
	int getSize(void);

	/**
	 * Anzahl der Zeilen.
	 */
	int getRowCount(void);

	/**
	 * Anzahl der Spalten.
	 */
	int getColumnCount(void);

	void printMatrix(void);

public:
	~WMatrix(void);
	float** Values;

private:
	unsigned int rowCount;
	unsigned int columnCount;

	
};

#endif
