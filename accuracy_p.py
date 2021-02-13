from sklearn.metrics import accuracy_score
import pandas as pd
import numpy as np
import sys


def accuracy_score_n(ans, user, idx, gen):
    ans_ = ans.loc[idx]
    user_ = user.loc[idx]
    acc = accuracy_score(ans_, user_)
    acc_t = accuracy_score(ans_[ans_.index.isin(gen)], user_[user_.index.isin(gen)])
    print(acc_t/acc)
    if acc_t/acc > 0.5:
        return acc
    else:
        return (acc + acc_t)/2

BASE = '.'

ans = pd.read_csv(sys.argv[1])
ans = ans.set_index(ans.columns[0])

user = pd.read_csv(sys.argv[2])
user = user.set_index(user.columns[0])

idx = pd.read_csv(sys.argv[3])
idx = idx.iloc[:, 0].values


gen = pd.read_csv(f'{BASE}/generated_samples.csv')['id']


if ans.loc[idx].shape[0] != user.loc[idx].shape[0]:
    print('Error: missing client')
else:
    res = accuracy_score_n(ans, user, idx, gen)

    print("ok: {}".format(res))