#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "shape.hpp"

void make_bad_circle();
void make_bad_rectangle();

shkurov::Shape* make_circle();
shkurov::Shape* make_rectangle();
shkurov::Shape* make_composite();

void test_move_to_point(shkurov::Shape* shape);
void test_scale(shkurov::Shape* shape);
void invalid_scale(shkurov::Shape* shape);

#endif