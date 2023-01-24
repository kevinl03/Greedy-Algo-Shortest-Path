#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

// **************NOTE  *******************///
// ***CHECK MAIN FOR TEST DESCRIPTION******//

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << origin.getDistance(q) << endl;

}


// **************NOTE  *******************///
// ***CHECK MAIN() FOR TEST DESCRIPTION******//
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  if (solution.getSize() < 3) {
      cout << "NULL" << endl;
  }
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

// **************NOTE  *******************///
// ***CHECK MAIN() FOR TEST DESCRIPTION******//

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D"),
                //Point(20,20,"Z")
  };
                

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);

  //inputTSP.addPoint(Point&(21, 21, "Z"));
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// **************NOTE  *******************///
// ***CHECK MAIN() FOR TEST DESCRIPTION******//

void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(0,i,s);
    inputTSP.addPoint(p);
  }

  for (int i = 0; i < 10; i++) {
      string s;
      s = 'K' + i;
      p = Point(i, 0, s);
      inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


// **************NOTE  *******************///
// ***CHECK MAIN() FOR TEST DESCRIPTION******//

void test4() {
    ListOfPoints inputTSP;
    Point p(0, 0, "A");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i < 10; i++) {
        string s;
        s = 'A' + i;
        p = Point(0, i, s);
        inputTSP.addPoint(p);
    }

    for (int i = 0; i < 10; i++) {
        string s;
        s = 'K' + i;
        p = Point(0, i, s);
        inputTSP.addPoint(p);
    }

    cout << "Printing the list:" << endl;
    inputTSP.printList();
    inputTSP.draw();

    testSolver(inputTSP);

}

// **************NOTE  *******************///
// ***CHECK MAIN() FOR TEST DESCRIPTION******//

void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    p = Point(rand() % 100, rand() % 100,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
  inputTSP.draw();
}

void test5() {
    Point p[8] = { Point(2,2,"A"),
                Point(2,2,"E"),
                Point(2,6,"B"),
                Point(2,6,"F"),
                Point(5,6,"C"),
                Point(5,6,"G"),
                Point(5,9,"D"),
                Point(5,9,"H"),
        //Point(20,20,"Z")
    };


    
    ListOfPoints inputTSP;
    for (int i = 0; i < 8; i++)
        inputTSP.addPoint(p[i]);

    //inputTSP.addPoint(Point&(21, 21, "Z"));

    cout << "Printing the list:" << endl;
    inputTSP.printList();
    inputTSP.draw();

    testSolver(inputTSP);
}

void test6() {
    ListOfPoints inputTSP;
    Point p(3,4 , "A");
    Point d(5,2, "B");
    inputTSP.addPoint(p);
    inputTSP.addPoint(d);

    inputTSP.printList();
    testSolver(inputTSP);
    inputTSP.draw();


}

void test7() {
    ListOfPoints inputTSP;
    Point p(0, 0, "A");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i < 10; i++) {
        string s;
        s = 'A' + i;
        p = Point(5, 5, s);
        inputTSP.addPoint(p);
    }
cout << "Printing the list:" << endl;
inputTSP.printList();
inputTSP.draw();

testSolver(inputTSP);

}

void test8() {
    Point p[4] = { Point(-2,-2,"A"),
                Point(-2,-6,"B"),
                Point(-5,-6,"C"),
                Point(-5,-9,"D"),
        //Point(20,20,"Z")
    };


    cout << "Creating a list of points:" << endl;
    ListOfPoints inputTSP;
    for (int i = 0; i < 4; i++)
        inputTSP.addPoint(p[i]);

    //inputTSP.addPoint(Point&(21, 21, "Z"));

    cout << "Printing the list:" << endl;
    inputTSP.printList();
    inputTSP.draw();

    testSolver(inputTSP);
}

void test9() {
    ListOfPoints inputTSP;
    Point p(0, 0, "O");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i < 100; i++) {
        //p = Point(rand() % 100, rand() % 100, "P" + to_string(i));
        //randomizing negative values for coordinates
        if (i % 4 == 0) {
            p = Point(-(rand() % 100), rand() % 100, "P");
            inputTSP.addPoint(p);
        }
        else if (i % 3 == 0) {
            p = Point(-(rand() % 100), -(rand() % 100), "P");
            inputTSP.addPoint(p);
        }
        else if (i % 2 == 0) {
            p = Point((rand() % 100), -(rand() % 100), "P");
            inputTSP.addPoint(p);
        }
        else {
            p = Point((rand() % 100), (rand() % 100), "P");
            inputTSP.addPoint(p);
        }


    }
    // some coordinates values more than 20, so we do not use draw here


    testSolver(inputTSP);
    inputTSP.draw();
}

void test10() {
    ListOfPoints inputTSP;
    Point p(0, 0, "O");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i < 20; i++) {
        //p = Point(rand() % 100, rand() % 100, "P" + to_string(i));
        //randomizing negative values for coordinates

        if (i % 2 == 0) {
            p = Point(-(rand() % 20), -(rand() % 20), "P");
            inputTSP.addPoint(p);
        }
        else {
            p = Point((rand() % 20), (rand() % 20), "P");
            inputTSP.addPoint(p);
        }


    }
    // some coordinates values more than 20, so we do not use draw here

    testSolver(inputTSP);
    inputTSP.draw();
}

void test11() {
    ListOfPoints inputTSP;
    Point p(0, 0, "O");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i <= 20; i++) {
        //p = Point(rand() % 100, rand() % 100, "P" + to_string(i));
        //randomizing negative values for coordinates

        for (int j = 0; j <= 20; j++){
            p = Point(i, j, "P");
            inputTSP.addPoint(p);

}


    }

    TSPSolver solving(inputTSP);
    solving.solve();
    TSPCycle solution = solving.getSolution();
    cout << "the length of the solution is: " << solution.getLength() << endl;

    inputTSP.draw();
}

void test12() {
    ListOfPoints inputTSP;
    Point p(0, 0, "O");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i <= 20; i++) {
            p = Point(i, i, "P");
            inputTSP.addPoint(p);

    }




    testSolver(inputTSP);

    TSPSolver solving(inputTSP);
    solving.solve();
    TSPCycle solution = solving.getSolution();
    cout << "solution divided by sqrt(2) (since we're working with diagonals)" << endl;
    cout << " = " << solution.getLength() / 1.4142135 << " ";
    cout << "meaning solution only found straight lines, and computed correctectly" << endl;
    inputTSP.draw();
}

void test13() {
    Point p[8]= {Point(2,2,"A"),
                  Point(2,6,"B"),
                  Point(5,6,"C"),
                  Point(5,9,"D"),
                  Point(2,2,"E"),
                  Point(2,6,"F"),
                  Point(5,6,"G"),
                  Point(5,9,"H"),
        //Point(20,20,"Z")
    };


    cout << "Creating a list of points:" << endl;
    ListOfPoints inputTSP;
    for (int i = 0; i < 8; i++)
        inputTSP.addPoint(p[i]);

    //inputTSP.addPoint(Point&(21, 21, "Z"));

    cout << "Printing the list:" << endl;
    inputTSP.printList();
    inputTSP.draw();

    testSolver(inputTSP);
}

void test14() {
    Point p[4] = { Point(10,10,"A"),
                  Point(-10,10,"B"),
                  Point(10,-10,"C"),
                  Point(-10,-10,"D"),
        //Point(20,20,"Z")
    };


    cout << "Creating a list of points:" << endl;
    ListOfPoints inputTSP;
    for (int i = 0; i < 4; i++)
        inputTSP.addPoint(p[i]);

    //inputTSP.addPoint(Point&(21, 21, "Z"));

    cout << "Printing the list:" << endl;
    inputTSP.printList();
    inputTSP.draw();

    testSolver(inputTSP);
    cout << "points make a sqaure of lenght 20 across 4 quadrants" << endl;
    cout << "so a solution of lenght 80 is ideal" << endl;

}

void test15() {
    ListOfPoints inputTSP;
    Point p(0, 0, "O");
    cout << "Creating a list of points:" << endl;

    for (int i = 0; i <= 20; i++) {
        p = Point(0, i, "P");
        inputTSP.addPoint(p);

    }

    for (int i = 1; i <= 20; i++) {
        p = Point(i, 20, "P");
        inputTSP.addPoint(p);

    }

    for (int i = 0; i < 20; i++) {
        p = Point(20, i, "P");
        inputTSP.addPoint(p);

    }

    for (int i = 1; i < 20; i++) {
        p = Point(i, 0, "P");
        inputTSP.addPoint(p);

    }





    cout << "perimiter of points, sides lenght 20" << endl;
    cout << "so a solution of lenght 80 is the best cycle" << endl;
    testSolver(inputTSP);

    TSPSolver solving(inputTSP);
    solving.solve();
    TSPCycle solution = solving.getSolution();
    inputTSP.draw();
}



//--------PURPOSE OF TESTS LISTED HERE BELOW---------------//

int main() {

  //normal cycle, all points are positive
  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;

  //points lie on straight line, and one duplicate point is added at origin
  //duplicate points does not directely proceed in input list
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

 //input random positive numbers, and shows that draw works for points outside of drawing grid
    cout << "****test3**:" << endl;
  test3();
    cout << "****end of test3**:" << endl << endl;
  



  //all points have duplicates, and all points lie on the same axis, and duplicates 
  //do not directly follow one another in the list of points input
  //either way, no difference is made in the resulting cycle lenght (ideal solution found)

    cout << "****test4**:" << endl;
      test4();
    cout << "****end of test4**:" << endl << endl;

    //all points in cycle have duplicates, but the duplicates directly follow 
    //in the input list. This form of duplicates means the cycle lenght should not 
    //depend on number duplicates [in this case: same as test1() ] since distance from  Point->duplicate = 0
    // and the algorithm is guaranteed to choose duplicate since 0 is smallest heuristic
    cout << "****test5**:" << endl;
    test5();
    cout << "****end of test5**:" << endl << endl;


    //solving an input with less than 3 points
    cout << "****test6**:" << endl;
    test6();
    cout << "****end of test6**:" << endl << endl;


    //cycle where all points are the exact same, solution is 0 since
    //since no need to move anywhere.
    cout << "****test7**:" << endl;
    test7();
    cout << "****end of test7**:" << endl << endl;

    //******COORDINATE QUADRANTS **********

    /*             |
                   |
           II      |      I
                   |
                   |
                   |
    -----------------------------
                   |
                   |
        III        |      IV
                   |
                   |
                   |
 
    */
 


    //Negative Points (all in the third quadrant)
    cout << "****test8**:" << endl;
    test8();
    cout << "****end of test8**:" << endl << endl;


    //Points that have both negative and positive x and y coords
    //in all quadrants : I , II , III , IV

    cout << "****test9**:" << endl;
    test9();
    cout << "****end of test9**:" << endl << endl;

    //strictly Negative Points AND strictly Positive Points (3rd and 1st Quadrant)

    cout << "****test10**:" << endl;
    test10();
    cout << "****end of test10**:" << endl << endl;

    
    //use the entire drawing space and fill it with points
    //the solution is nonetheless the minimal using the algorithm,
    //however not the ideal solution (it doesnt just follow along
    //the axis like a snake because of the way the points are ordered in the input list)

    // (20*20) -> going across the axis
    // + 20    -> moving up one (or right) to get to next parellel axis
    // + sqrt(20^2+20^2)) -> taking last diagonal
    // == 448.28
    
   
    cout << "****test11**:" << endl;
    test11();
    cout << "algorithm found one " << endl << endl;
    cout << "****end of test11**:" << endl << endl;
    

    //working with diagonals
    //since we have 21 points, meaning 20 edges in each direction.
    //so a total of 20 + 20 [need to come back for the cycle]
    // = 40 lenght should be the solution
    // 40*sqrt(2) is ideal solution
    //my algorithm found ideal solution
   
    cout << "****test12**:" << endl;
    test12();
    cout << "****end of test12**:" << endl << endl;

    //every point has a duplicate, but the order in which it is input is:
    //sequence of points, same sequence of points again
    //the solution should nevertheless result in the lenght
    //which is simply the lenght of first sequence
    cout << "****test13**:" << endl;
    test13();
    cout << "****end of test13**:" << endl << endl;


    //4 point cycle, one point in each quadrant
    //normal test, output should 80 as well
    cout << "****test14**:" << endl;
    test14();
    cout << "****end of test14**:" << endl << endl;

    //a perimiter of points around the drawing board of lenght 80
    //this checks so final heuristic is chosen accurately and placed at the 
    //end of cycle correctly 
    cout << "****test15**:" << endl;
    test15();
    cout << "****end of test15**:" << endl << endl;


  return 0;
}
