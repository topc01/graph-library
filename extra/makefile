CC=g++
flags=
lib=_figuras.so

#reemplace las rutas por las suyas
rutapython=/Users/amparoquiroz/opt/anaconda3/pkgs/python-3.7.6-h359304d_2/include/python3.7m/

# 2. La librería dinámica para Python se compila con -shared y se le da extensión
#    .pyd (.so en Linux)
# 3. Para compilar el wrapper le tenemos que decir dónde encontrar Python.h
#    (en este caso, -I$(rutapython)/include)
# 3. Al compilador le decimos que use la librería "python39"
#    (-lpython39) que está en $(rutapython) (-L$(rutapython))

$(lib): figuras_wrap.cxx rectangulo.o cuadrado.o elipse.o
# el wrapper se compila sin flags: no vamos a debuggear el código generado por SWIG
	$(CC) -fPIC -c figuras_wrap.cxx -o figuras_wrap.o -I$(rutapython)
	$(CC) -shared figuras_wrap.o rectangulo.o cuadrado.o elipse.o -undefined suppress -flat_namespace -o _figuras.so -L$(rutapython) -lpython2.7

figuras_wrap.cxx: figuras.i circulo.h cuadrado.h elipse.h rectangulo.h
	swig -python -c++ figuras.i

# 1. Las clases se compilan con -fPIC para prepararlas para ser parte
#    de una librería dinámica
rectangulo.o: rectangulo.cpp rectangulo.h
	$(CC) $(flags) -fPIC -c rectangulo.cpp -o rectangulo.o

cuadrado.o: cuadrado.cpp cuadrado.h rectangulo.h
	$(CC) $(flags) -fPIC -c cuadrado.cpp -o cuadrado.o

elipse.o: elipse.cpp elipse.h rectangulo.h
	$(CC) $(flags) -fPIC -c elipse.cpp -o elipse.o

clean:
	del *.o *.so *.pyd *.cxx
