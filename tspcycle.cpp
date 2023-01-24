#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
//  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
	//add up distances from vec[i] and vec[i+1]

	if (getSize() < 3) {
		return -1;
	}
	float distance = 0;
	for (int i = 0; i < this->getSize()-1; ++i) {
		distance += m_points[i].getDistance(m_points[i + 1]);
	}
	//add up final distance from vec[0] and vec[i], which is last edge in cycle
	distance += m_points[0].getDistance(m_points[this->getSize()-1]);

  return distance;
}
