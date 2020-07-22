from sklearn.metrics import roc_curve
import pandas as pd
import numpy as np
import sys


def score(idx, submission, test, all_data, t):
    alpha = 1e-4
    beta = 10
    submission = submission.loc[idx]
    test = test.loc[idx]
    submission['z'] = all_data[submission.y, submission.index.values]
    test.index = submission.index
    test['z'] = all_data[test.y, test.index.values]
    y_err = (test.y - submission.y) ** 2
    z_err = alpha * (test.z - submission.z) ** 2
    return np.sqrt(np.sum(y_err + z_err)) + beta*t


ans = pd.read_csv(sys.argv[1])

user = pd.read_csv(sys.argv[2], header=None)
time = float(user.iloc[0, 1])
user = user.iloc[2:]
user = user.rename({0: 'x', 1: 'y'}, axis=1)
user['x'] = user['x'].astype(int)
user['y'] = user['y'].astype(int)

idx = pd.read_csv(sys.argv[3])
z = np.load('/home/workspace/boosters.pro/backend/metrics/metrics/all_data.npy')

user = user.set_index('x')
ans = ans.set_index('x')

res = score(idx.iloc[:, 0].values, user, ans, z, time)

print("ok: {}".format(res))
