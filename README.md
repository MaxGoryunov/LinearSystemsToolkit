<img src="./logo/LST.png" height="80px"/>

[![EO principles respected here](https://www.elegantobjects.org/badge.svg)](https://www.elegantobjects.org)

[![PDD status](https://www.0pdd.com/svg?name=MaxGoryunov/LinearSystemsToolkit)](https://www.0pdd.com/p?name=MaxGoryunov/LinearSystemsToolkit)
[![codecov](https://codecov.io/gh/MaxGoryunov/LinearSystemsToolkit/branch/master/graph/badge.svg?token=fEHOo3uRp6)](https://codecov.io/gh/MaxGoryunov/LinearSystemsToolkit)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/MaxGoryunov/LinearSystemsToolkit/blob/master/LICENSE)

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/2db6f6abce1441629ba53c3157ad3ea7)](https://app.codacy.com/gh/MaxGoryunov/LinearSystemsToolkit/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![CodeFactor](https://www.codefactor.io/repository/github/maxgoryunov/linearsystemstoolkit/badge)](https://www.codefactor.io/repository/github/maxgoryunov/linearsystemstoolkit)
[![Hits-of-Code](https://hitsofcode.com/github/MaxGoryunov/LinearSystemsToolkit)](https://hitsofcode.com/github/MaxGoryunov/LinearSystemsToolkit/view)
<!---![Lines-of-Code](https://tokei.rs/b1/github/MaxGoryunov/LinearSystemsToolkit?branch=master)--->

**LinearSystemsToolkit** is a library for solving systems of linear equations
 or SLE for short. It includes methods for matrix factorization and iterative
 methods like Preconditioned Conjugate Gradients method(PCG).

## How to use it

### Visual Studio setup

Clone this repository into some folder, for example, `LST`:

```git
git clone https://github.com/MaxGoryunov/LinearSystemsToolkit.git
```

Then in your Visual Studio project's properties in `All configurations` > 
`C/C++` > `General` > `Additional Include Directories` add
`*path_to_LST/*LST/LinearSystemsToolkit` folder.

After that in `All configurations` > `Linker` > `General` > 
`Additional Library Directories` add `*path_to_LST/*LST` folder.

If you have any questions, ask them at 
[Discussions](https://github.com/MaxGoryunov/LinearSystemsToolkit/discussions).

## Vector operations

To add two vectors:

```c
Vector* left  = vectorCreate(3); // {1, 2, 3}
Vector* right = vectorCreate(3); // {4, 5, 6}
Vector* sum = vectorSum(left, right); // {5, 7, 9}
```

To subtract a vector from another vector:

```c
Vector* left  = vectorCreate(3); // {7, 8, 9}
Vector* right = vectorCreate(3); // {4, 5, 6}
Vector* diff = vectorDiff(left, right); // {3, 3, 3}
```

To calculate vector's second norm:

```c
Vector* vec = vectorCreate(3); // {3, 4, 12}
double norm = secondNorm(vec); // norm == 13
```

To scale a vector by some factor:

```c
Vector* vec    = vectorCreate(3); // {3, 4, 5}
Vector* scaled = vectorScale(vec, 3); // {9, 12, 15}
```

To create a linearly spaced vector:

```c
Vector* points = linspace(0, 1, 5); // {0, 0.25, 0.5, 0.75, 1.0}
```

To multiply two vectors:

```c
Vector* row = vectorCreate(3); // {1, 2, 3}
Vector* col = vectorCreate(3); // {4, 5, 6}
double mult = scalarMultiplication(row, col); // 1*4 + 2*5 + 3*6 == 32
```

To check for vector equality:

```c
Vector* left  = vectorCreate(3); // {1, 2, 3}
Vector* right = vectorCreate(3); // {1, 2, 3}
Vector* other = vectorCreate(3); // {4, 5, 6}
assert(1 == vectorEqual(left, right));
assert(0 == vectorEqual(left, other));
```

## How to contribute

[Fork this repository](https://docs.github.com/en/get-started/quickstart/fork-a-repo),
then create a folder for it and install [GCC](https://gcc.gnu.org/install/).
After it run

```bash
gcc -fprofile-arcs -ftest-coverage -O0 -o AllTest LinearSystemsToolkit/*.c -lm
./AllTest
```

This script will run all tests, they are not supposed to fail. Commit changes,
open a [Pull Request](https://github.com/MaxGoryunov/saving-iterator/pulls).
Your Pull Request will be reviewed and eventually accepted if it does not fail
our build pipeline.