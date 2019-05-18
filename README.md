# TP Final Taller de Programacion 1

| Integrantes    | Padron |
|----------------|--------|
| Blanco Joaquin |        |
| Bravo Victor   | 98882  |
| Rack Lucas     | 99425  |

## Instalacion de CxxTest
Para poder correr los tests lo mas facil es instalar CxxTest en ubuntu mediante
~~~
sudo apt update
sudo apt install cxxtest
~~~

## Agregar tests
Los test deben ser agregados en el directorio test y deben seguir la siguiente
estructura.

~~~
# Suponer que esta en ./test/my_test.h
#include <cxxtest/TestSuite.h>

class MyTestSuite : public CxxTest::TestSuite {
public:
   void testAddition() {
       int a = 3;
       int b = 2;  
       TS_ASSERT_EQUALS(5, a + b);
   }
};
~~~

- Deben ser headers (.h)
- Deben incluir la biblioteca `#include <cxxtest/TestSuite.h>`.
- Son clases que heredan de `CxxTest::TestSuite`
- Los test son metodos y siguen el estilo
  `void testXXXXX(void) { <codigo> }`
- Para checkear condiciones se suele utilizar `TEST_ASSERT(expr)`,
 `TEST_ASSERT_EQUALS(x, y)`, `TS_ASSERT_THROWS(expr,type)`. Hay mas en
  http://cxxtest.com/guide.html#testAssertions.

## Ejecucion
Solo basta con ejecutar en build
~~~
cmake ..
make
./unittest
~~~

Una correcta ejecucion deberia verse como
~~~
Running cxxtest tests (1 test).OK!
~~~

Y una con problemas
~~~
Running cxxtest tests (1 test)
In MyTestSuite::testAddition:
../test/foo_test.h:10: Error: Expected (99 == a + b), found (99 != 5)
Failed 1 and Skipped 0 of 1 test
Success rate: 0%
~~~
