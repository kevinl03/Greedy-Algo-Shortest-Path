#include "listofpoints.hpp"
using namespace std;



ListOfPoints::ListOfPoints() 
{
	//cout << "constructed Vector" << endl;
}

void ListOfPoints::addBefore(Point& newPt, Point& aheadPt) {
	int i = 0;
	while (i < this->getSize() - 1) {
		if (this->getPointAt(i).getX() == aheadPt.getX() && this->getPointAt(i).getY() == aheadPt.getY()) {
			break;
		}
		i++;
	}
	m_points.insert(m_points.begin() + i, newPt);
}

void ListOfPoints::addPoint(Point& newPt)  {
	m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  return m_points.size();
}

void ListOfPoints::printList() const {
	for (int i = 0; i < m_points.size(); ++i) {
		m_points[i].printPoint();
	}
}

void ListOfPoints::draw() const {
	//2d arrays are whack instead I used a 1d array to store points
	//first 21 elements represent x = 0  (and all y) coords associated with x val
	//second 21 elements represents x = 1 (and all y) coords 
	//and so on

	//default values to "-"
	std::string screen[441];
	for (int i = 0; i < 441; ++i) {
		screen[i] = "-";
	}
	for (int i = 0; i < m_points.size(); ++i) {
		int x = m_points[i].getX();
		int y = m_points[i].getY();

		//in case points are out of 20x20 display bounds

		if (x > 20 || y > 20)
			//ignore point
			continue;

		//negative points
		if (x < 0 || y < 0)
			continue;
		//replace any coords inside 20x20 by name of Point
		screen[x * 21 + y] = m_points[i].getName();
	}

	//start from row 20 and print down wards so we don't print upside down
	for (int x = 20; x >= 0; --x) {
		for (int y = 0; y < 21; ++y) {
			cout << screen[y * 21 + x] << " ";
		}
		cout << endl;
	}
}
 
