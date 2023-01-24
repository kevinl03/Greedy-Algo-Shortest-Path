#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) 
{
	//cout << "TSP vector size is " << m_list.getSize() << endl;
	//cout << "TSP cycle size is " << m_solution.getSize() << endl;

	//create a copy of the vectors
	m_list = list;

	if (m_list.getSize() < 3) {
		return;
	}

	//creates cycle of lenght 3 for initial cycle of greedy algo
	for (int i = 0; i < 3; ++i) {
		m_solution.addPoint(m_list.getPointAt(i));
	}
	//cout << "TSP cycle size is " << m_solution.getSize() << endl;
	//cout << "TSP vector size is " << m_list.getSize() << endl;
}

void TSPSolver::solve() {
	
	// O(n^2) running time, n size of points
	//start with 3 comparisons (very smallest cycle)
	//then add one, then iterate through cycle again
	//3+4+5 ... n-1, n comparisons *= n(n+1)/2 -> O(n^2)

	if (m_solution.getSize() < 3) {
		cout << "input requires minimum 3 points" << endl;
		return;
	}

	 
	for (int ilist = 3; ilist < m_list.getSize() ; ++ilist) {
		//store first two points of cycle as place holder for smallest distance
		//these will hold points for which adding to cycle minimizes size increase
		

		Point holder1 = (m_solution.getPointAt(0));
		Point holder2 = (m_solution.getPointAt(1));

		//keep track of the distance between points
		float distAtoB = holder1.getDistance(holder2);

		float distAtoNew = holder1.getDistance(m_list.getPointAt(ilist));
		float distNewtoB = m_list.getPointAt(ilist).getDistance(holder2);

		float smallestHeuristic = distAtoNew + distNewtoB - distAtoB;

		//loop through cycle to find smallest heuristic increase
		//start at index 1 for cycle since previous lines of code already checks heurisitc
		//for first 2 points in cycle

		for (int icycle = 1; icycle < m_solution.getSize()-1; ++icycle) {

			Point current = m_solution.getPointAt(icycle);
			Point next = m_solution.getPointAt(icycle + 1);

			//local smallest heuristic calculation

			float distCurtoNext = current.getDistance(next);

			float distCurtoNew = current.getDistance(m_list.getPointAt(ilist));
			float distNewtoNext = m_list.getPointAt(ilist).getDistance(next);

			float localHeuristic = distCurtoNew + distNewtoNext - distCurtoNext;

			//update holder of smallest heursitic distance as well as points

			//need to include less than or *equal* in case identical points pop up

			if (localHeuristic < smallestHeuristic) {
				smallestHeuristic = localHeuristic;
				holder1 = current;
				holder2 = next;
			}

		}
		//last comparison: heuristic for last point to first point
		Point first = (m_solution.getPointAt(0));
		Point last = (m_solution.getPointAt(m_solution.getSize()-1));

		float distFirsttoLast = first.getDistance(last);
		float distFirstToNew = first.getDistance(m_list.getPointAt(ilist));
		float distNewtoLast = m_list.getPointAt(ilist).getDistance(last);

		float finalHeuristic = distFirstToNew + distNewtoLast - distFirsttoLast;

		//in the case last point heuristic was smaller than the rest
		//we require new logic since the vector does not act like a cycle,
		//so I can't insert a point inbetween two points when it is 
		//the end of a vector
		if (finalHeuristic <= smallestHeuristic) {
			smallestHeuristic = finalHeuristic;
			holder1 = last;
			holder2 = first;

			//push element to the back of the vector
			m_solution.addPoint(m_list.getPointAt(ilist));
	
		}
		//add new point between the two points which resulted in lowest heurisitc
		else {
			m_solution.addBefore(m_list.getPointAt(ilist), holder2);
		}
	





	}
	return;
}

TSPCycle& TSPSolver::getSolution() {
  // implement me

  // 
  return m_solution;
}

