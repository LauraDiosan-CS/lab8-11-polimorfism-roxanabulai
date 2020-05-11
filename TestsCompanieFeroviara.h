#pragma once
class TestCompanieFeroviara {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetNumeModel();
	void testSetNumeModel();
	void testGetNumeProducator();
	void testSetNumeProducator();
	void testGetNrVagoane();
	void testSetNrVagoane();
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