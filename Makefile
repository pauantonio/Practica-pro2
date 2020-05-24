OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

practica.tar:
	tar -cvf practica.tar html.zip Makefile program.cc Especie.cc Especie.hh Cjt_especies.cc Cjt_especies.hh Cluster.cc Cluster.hh Cjt_clusters.cc Cjt_clusters.hh Taula_distancies.cc Taula_distancies.hh

program.exe: program.o 
	g++ -o program.exe *.o

program.o: program.cc Especie.cc Cjt_especies.cc Cluster.cc Cjt_clusters.cc Taula_distancies.cc
	g++ -c *.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
