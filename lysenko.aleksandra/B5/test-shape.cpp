#include <boost/test/unit_test.hpp>

#include <sstream>
#include <numeric>

#include "Shape.h"
#include "typeOfShape.h"

namespace lysenko
{
  void testShapeWithInpData(std::string data)
  {
    std::stringstream in(data);
    lysenko::Shape shp;
    BOOST_CHECK_THROW(in >> shp, std::invalid_argument);
  }

  Shape executeShapeFromData(std::string data)
  {
    std::stringstream in(data);
    lysenko::Shape shp;
    in >> shp;
    return shp;
  }

  struct fillResVect
  {
    std::vector< bool > operator()(std::vector< bool >& results, bool res)
    {
      results.push_back(res);
      return results;
    }
  };

  void testRectAndSquare(std::vector<bool>& expResOfTest)
  {
    namespace plc = std::placeholders;
    namespace lab = lysenko;

    std::string corr = "4 (1;1) (2;1) (2;2) (1;2)";
    std::string rectButNotSquare = "4 (8;1) (8;2) (1;1) (1;2)";
    std::string polygon = "5 (1;1) (2;1) (2;2) (1;2) (0;1)";
    std::string sizeFourButNotRect = "4 (1;1) (2;2) (2;3) (1;2)";

    std::vector< std::string > testData = { corr, rectButNotSquare, polygon, sizeFourButNotRect };

    auto typeOfShape = expResOfTest[1] == false ? lab::isSquare: lab::isRectangle;

    auto test = std::bind(typeOfShape, std::bind(lab::executeShapeFromData, plc::_2));
    auto fill = std::bind(lab::fillResVect(), plc::_1, test);

    std::vector< bool > resOfTest = std::accumulate(testData.begin(), testData.end(), std::vector< bool >(), fill);

    BOOST_CHECK_EQUAL_COLLECTIONS(resOfTest.begin(), resOfTest.end(), expResOfTest.begin(), expResOfTest.end());
  }
}

BOOST_AUTO_TEST_SUITE(testShapeInput)

BOOST_AUTO_TEST_CASE(testCorrectionOfRead)
{
  std::string testData = "3 (1;1) (2;2) (3;1)";
  lysenko::Shape shp = lysenko::executeShapeFromData(testData);
  BOOST_CHECK_EQUAL(shp[0].x, 1);
  BOOST_CHECK_EQUAL(shp[0].y, 1);
  BOOST_CHECK_EQUAL(shp[1].x, 2);
  BOOST_CHECK_EQUAL(shp[1].y, 2);
  BOOST_CHECK_EQUAL(shp[2].x, 3);
  BOOST_CHECK_EQUAL(shp[2].y, 1);
}

BOOST_AUTO_TEST_CASE(testNullVertices)
{
  std::string testData = "0 (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_CASE(testInvalidVertices)
{
  std::string testData = "fkfk (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_CASE(testNewLineInside)
{
  std::string testData = "3\n (1;1) (2;2) (3;1)";
  lysenko::testShapeWithInpData(testData);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeType)

BOOST_AUTO_TEST_CASE(testTriangle)
{
  std::string testData = "3 (1;1) (2;2) (3;1)";
  lysenko::Shape shp = lysenko::executeShapeFromData(testData);
  BOOST_CHECK_EQUAL(lysenko::isTriangle(shp), true);
}

BOOST_AUTO_TEST_CASE(testRectangle)
{
  std::vector< bool > expResOfTest = { true, true, false, false };

  lysenko::testRectAndSquare(expResOfTest);
}

BOOST_AUTO_TEST_CASE(testSquare)
{
  std::vector< bool > expResOfTest = { true, false, false, false };

  lysenko::testRectAndSquare(expResOfTest);
}

BOOST_AUTO_TEST_CASE(testPentagon)
{
  std::string testData = "5 (1;2) (3;2) (3;3) (1;3) (2;3)";
  lysenko::Shape shp = lysenko::executeShapeFromData(testData);
  BOOST_CHECK_EQUAL(lysenko::isPentagon(shp), true);
}

BOOST_AUTO_TEST_SUITE_END()
