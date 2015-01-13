#include <boost/test/unit_test.hpp>
#include "include/DefaultNumberFactoryImpl.h"


BOOST_AUTO_TEST_SUITE(testVectorSuite)

BOOST_AUTO_TEST_CASE(testVector) {
	using namespace std;
	int dimension = Vector<Real,3>::getDimension();
	BOOST_CHECK_EQUAL(dimension, 3);
	NumberFactory const & factory = DefaultNumberFactoryImpl();

	typedef Vector<Real,3>::ModulePtr RealVector3;
	RealVector3 zero(factory.createRealVector3());
	RealVector3 foo(factory.createRealVector3(2,6,8));
	RealVector3 bar(factory.createRealVector3(3.75,10,0));
	//check equals
	BOOST_REQUIRE(zero == zero);
	BOOST_REQUIRE_NE( foo,zero);
	//check assignment
	RealVector3 foosum = foo + zero;
	BOOST_REQUIRE_EQUAL(foosum, foo);

	BOOST_REQUIRE_EQUAL( (*bar)[1], factory.createReal(10));
	BOOST_REQUIRE_EQUAL( bar->get(2), factory.createReal());

	/* Check that ->get cannot change the content of the vector*/
	Group<Real>::Ptr nine = factory.createReal(9);
	Group<Real>::Ptr bar0 = bar->get(0); //(*bar)[0];
	// now attempt to change it
	bar0 = nine;
	BOOST_REQUIRE_EQUAL(bar0, nine);
	BOOST_REQUIRE_NE((*bar)[0], nine);

	// check minus
	BOOST_REQUIRE_EQUAL(foo -foo, zero);
	RealVector3 fooMbar = factory.createRealVector3(-1.75,-4,8);
	RealVector3 diff = foo - bar;
	BOOST_REQUIRE_EQUAL(diff, fooMbar);

	//check scalar multiplication
	RealVector3 bar2 = bar->scalarTimes(foo->get(0));
	RealVector3 barT2 = factory.createRealVector3(7.5,20,0);
	BOOST_REQUIRE_EQUAL(bar2, barT2);
	// check operator *
	RealVector3 barStar2 = foo->get(0) * bar;
	BOOST_REQUIRE_EQUAL(bar2, barStar2);
}

//BOOST_AUTO_TEST_CASE(testDualVector) {}

BOOST_AUTO_TEST_SUITE_END()
