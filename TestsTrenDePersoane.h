#pragma once
class TestTrenDePersoane {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetNrLocuri();
	void testSetNrLocuri();
	void testGetNrGarnituriDisponibile();
	void testSetNrGarnituriDisponibile();
	void testGetNrGarnituriRezervate();
	void testSetNrGarnituriRezervate();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToStringDelimiter();
public:
	void testAll();
};