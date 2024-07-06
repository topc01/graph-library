CC = g++
prog = exe
flags = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
rutapython = /Users/topc/opt/anaconda3/pkgs/python-3.10.4-hdfd78df_0/include/python3.10/
rutalib = /Users/topc/opt/anaconda3/pkgs/python-3.10.4-hdfd78df_0/lib/python3.10

rutaswig = /usr/local/bin/swig

lib:
	$(CC) -o libgrafo.so -fPIC -shared grafo.cpp
	swig -python -c++ grafo.i

run: $(prog)
	./$(prog)

$(prog): main.o grafo.o
	$(CC) $(flags) main.o grafo.o -o $(prog)

tar: codigo_usuario_t4.py grafo.cpp grafo.h grafo.i makefile
	tar -czf CUEVAS-PFINGSTHORN-Tarea4.tar.gz codigo_usuario_t4.py grafo.cpp grafo.h grafo.i makefile

# main.o: main.cpp grafo.h
# 	$(CC) $(flags) -c main.cpp -o main.o

# grafo.o: grafo.cpp grafo.h
# 	$(CC) $(flags) -fPIC -c grafo.cpp -o grafo.o

# _grafo.so: grafo_wrap.cxx grafo.o
# 	$(CC) -fPIC -c grafo_wrap.cxx -o grafo_wrap.o -I$(rutapython)
# 	$(CC) -shared grafo_wrap.o grafo.o -undefined suppress -flat_namespace -o _grafo.so -L$(rutalib)

# grafo_wrap.cxx: grafo.i grafo.h
# 	$(rutaswig) -python -c++ grafo.i

%.o: %.cpp
	$(CC) $(flags) -c $< -o $@

clean:
	rm *.o $(prog) *.cxx grafo.py
	clear

again:
	make clean
	make run