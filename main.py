import pandas as pd
import numpy as np

df = pd.read_csv("mainTable_Brain.csv", index_col=0)
diversities = df.apply(lambda x: len(np.unique(x)))
diversities.to_csv("diversities_py.csv", index=False, header=None)
