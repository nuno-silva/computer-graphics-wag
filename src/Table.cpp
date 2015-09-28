#include "Table.hpp"

Table::Table()
{
}

Table::~Table()
{
}

void Table::draw()
{
	glColor3f(1.0, 0, 0);
	glutSolidCube(TABLE_SIZE);
}
