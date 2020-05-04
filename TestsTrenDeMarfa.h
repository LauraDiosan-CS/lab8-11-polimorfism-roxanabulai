#pragma once
class TestTrenDeMarfa {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testClone();
	void testGetMarfa();
	void testSetMarfa();
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