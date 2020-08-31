import pandas as pd
import numpy as np
import sys
from metric_utils import contest_metric

# read files
ans = pd.read_csv(sys.argv[1])
sub = pd.read_csv(sys.argv[2])
idx = set(pd.read_csv(sys.argv[3]).ImageId.values)

# deal with not filled images
ans_tu = ans[ans.ImageId.isin(idx)]
sub_tu = sub[sub.ImageId.isin(idx)]
unused_idx = set(idx) - set(sub_tu.ImageId.unique())
tmp = pd.DataFrame(unused_idx, columns=['ImageId'])
tmp['prop_size'] = 0
sub_tu = pd.concat([sub_tu, tmp])

res, _, _ = contest_metric(ans_tu, sub_tu)

print("ok: {}".format(res))
