# Diversity estimator

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
[Boost](https://www.boost.org/)

# Benchmark

<!-- time python3 main.py -->
- *pandas*: 8.38s
<!-- time ./diversity.out mainTable_Brain.csv -->
- pure C++: 2.5s
<!-- time python3 -c 'import pydiversity;pydiversity.diversity("../mainTable_Brain.csv")' -->
- pyhton binding: 2.5s

