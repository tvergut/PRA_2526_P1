all: bin/testListArray bin/testNode bin/testListLinked bin/testPoint2D \
     bin/testCircle bin/testRectangle bin/testSquare bin/testDrawing


bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	 rm -r *.o *.gch bin

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h Node.h

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp


Circle.o: Circle.h Circle.cpp Shape.h Point2D.h
	g++ -c Circle.cpp


bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c    g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o


Rectangle.o: Rectangle.h Rectangle.cpp Shape.h Point2D.h
	g++ -c Rectangle.cpp



bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o


Square.o: Square.h Square.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp


bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

Drawing.o: Drawing.h Drawing.cpp List.h ListArray.h Shape.h Circle.h Square.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Rectangle.o  Shape.o Circle.o Square.o Point2D.o
	g++ -c testDrawing.cpp
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.o Drawing.o Rectangle.o Shape.o Circle.o Square.o Point2D.o








