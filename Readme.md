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
- *pandas*: 8.3s
<!-- time ./diversity.out mainTable_Brain.csv -->
- pure C++ single Thread: 3.2s
<!-- time ./diversity.out mainTable_Brain.csv 12-->
- pure C++ with multiThread: 0,6s
<!-- time python3 -c 'import pydiversity;pydiversity.diversity("../mainTable_Brain.csv")' -->
- Pyhton binding single Thread: 3.3s
<!-- time python3 -c 'import pydiversity;pydiversity.diversity("../mainTable_Brain.csv")' -->
- Pyhton binding with multiThread: 0,7s

