a.exe:avl_app.o avl_imp.o
	c++ avl_app.o avl_imp.o -o a.exe
avl_app.o:avl_app.cpp
	c++ -c avl_app.cpp
avl_imp.o:avl_imp.cpp
	c++ -c avl_imp.cpp