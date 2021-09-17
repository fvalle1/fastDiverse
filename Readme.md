# Diversity estimator

Estimate the number of different elements in a rectangular matrix in a fast end efficient way.
This can be done easily with Python, but this implementation is 10x time faster. Moreover, thanks to Boost.Pyhton it can still be used as a Python Module.

## c++ version
### compile

```bash
make
```

and **run** with

```bash
./diversity.out mainTable.csv
```

## python module
```bash
mkdir build && cd build
cmake ..
make
```

in a python session **run** 

```python
import pydiversity
pydiversity.diversity("mainTable.csv")
```

# Requirements
- [Boost](https://www.boost.org/)

- Pyhton 3.9

# Benchmark

<!-- time python3 main.py -->
- Python using *pandas*: (8.05 ± 0,11)s
<!-- time python3 -c 'import pydiversity;pydiversity.diversity("../mainTable.csv")' -->
- Pyhton binding single Thread: (3.3 ± 0,4)s
<!-- time python3 -c 'import pydiversity;pydiversity.diversity("../mainTable.csv", 12, true)' -->
- Pyhton binding with multiThread: (0,71 ± 0,14)s
<!-- time ./diversity.out mainTable.csv -->
- pure C++ single Thread: (3.2 ± 0,3)s
<!-- time ./diversity.out mainTable.csv 12-->
- pure C++ with multiThread: (0,66 ± 0,11)s
