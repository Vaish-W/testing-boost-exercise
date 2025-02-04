#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(ReadMatrix3x3)
{
  const int expectedMatrixSize{3};

  // Arrange
  MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;
  // Act
  auto data = matrixIO::openData("m3_test.csv", 3);

  // Assert
  BOOST_TEST(expectedMatrixSize == data.rows());
  BOOST_TEST(expectedMatrixSize == data.cols());
  BOOST_TEST(expectedMatrix.isApprox(data));
}

BOOST_AUTO_TEST_CASE(ReadMatrix250x250)
{
  const int expectedMatrixSize{250};

  // Act
  auto data = matrixIO::openData("m250_test.csv", 250);

  // Assert
  BOOST_TEST(expectedMatrixSize == data.rows());
  BOOST_TEST(expectedMatrixSize == data.cols());
}
BOOST_AUTO_TEST_SUITE_END()