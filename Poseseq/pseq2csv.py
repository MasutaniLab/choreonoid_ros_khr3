import sys
import pathlib
import yaml
import csv
from math import degrees

if len(sys.argv) < 2:
    print('引数が必要')
    exit()

pseq_name = sys.argv[1]
try:
    with open(pseq_name, 'r') as file:
        obj = yaml.safe_load(file)
except FileNotFoundError:
    print(f'{pseq_name}が開けない')

output = []
refs = obj['refs']
first = True
time_prev = 0
for ref in refs:
    time = ref['time']
    if first:
        first = False
    else:
        refer = ref['refer']
        joints = [0,1,2,3,4,5,6,7,8,9,10,15,16,17,18,19,20,21,22,23,24,25]
        # joints = refer['joints']
        values = refer['q']
        q = [0] * 30
        for j, v in zip(joints, values):
            q[j] = round(degrees(v)*1)
        dt = round((time - time_prev)*10)
        output.append(q+[dt])
    time_prev = time

pp = pathlib.PurePath(pseq_name)
csv_name = pp.stem + '.txt'
print(f'出力ファイル： {csv_name}')

with open(csv_name, 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(output)
