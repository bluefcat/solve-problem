import sys
import re
from collections import OrderedDict

from typing import Any

input = sys.stdin.readline
T = int(input())
pattern: dict[str, Any] = {
    "plan": re.compile(r"(Plan|plan) ([A-z|a-z]*)"),
    "premium": re.compile(r"(Premium|premium)[ |A-Z|a-z]*\$?([0-9]*)"),
    "copay": re.compile(r"(copayment|Copayment|copay|Copay)(.*)"),
}

for l in range(T):
    m, n = map(int, input().split())
    content = " ".join([input().strip() for _ in range(m)])
    payment = [int(input()) for _ in range(n)]

    content = [
        string.strip() for string in content.split('.')
        if string
    ]
    
    result = [{} for _ in content]


    for k, v in pattern.items():
        pattern[k] = re.compile(v)
        
        for idx, string in enumerate(content):
            f = pattern[k].findall(string)
            if not f:
                continue

            result[idx][k] = f[0][1].lower()

    result = [x for x in result if x]

    for token in result:
        for k, v in token.items():
            if k == 'copay':
                d = {}
                tmp = v.split()
                for i, x in enumerate(tmp):
                    if 'visit' == x.lower() and tmp[i-1] == 'per':
                        d['per visit'] = True
                    else:
                        d['total'] = True
                    if '%' in x:
                        d['percent'] = int(x[:-1])
                    if 'percent' in x:
                        d['percent'] = int(tmp[i-1])
                    if '$' in x:
                        if x[0] == '$':
                            x = x[1:]
                        else:
                            while not (ord('0') <= ord(x[-1]) <= ord('9')):
                                x = x[:-1]
                        d['dollars'] = int(x)
                    if 'dollars' in x:
                        d['dollars'] = int(tmp[i-1])
                token[k] = d
            try:
                token[k] = int(v)
            except:
                ...
    plans = OrderedDict()
    pay = OrderedDict()

    target_plan = ''
    for token in result:
        for k, v in token.items():
            if k == 'plan':
                target_plan = v
                plans[target_plan] = plans.get(target_plan, {})
                continue
            
            plans[target_plan][k] = v
            pay[target_plan] = 0
    
    for k, v in plans.items():
        if 'copay' not in v:
            plans[k]['copay'] = {'flag': True, 'total': True, 'dollars': 0}

        if 'total' not in v['copay'] and 'per visit' not in v['copay']:
            v['copay']['total'] = True

        if 'total' in v['copay'] and 'per visit' in v['copay']:
            del v['copay']['total']
    
    for k, v in plans.items():
        if 'total' in v['copay']:
            p = 10**10
            if 'percent' in v['copay']:
                percent = (v['copay'].get('percent', 100) / 100)
                p = min(p, sum(payment)*percent + v.get('premium', 0))
            if 'dollars' in v['copay']:
                p = min(p, v.get('dollars', 0) + v.get('premium', 0))
            
            pay[k] =p
            
        elif 'per visit' in v['copay']:
            r = v.get('premium', 0)
            for p in payment:
                q = 10**10
                if 'percent' in v['copay']:
                    percent = (v['copay'].get('percent', 100) / 100)
                    q = min(q, p*percent)
                if 'dollars' in v['copay']:
                    q = min(q, min(p, v['copay'].get('dollars', 0)))
                r += q

            pay[k] = r
    
    print(f"Data Set {l+1}:")
    for pp in pay.values():
        pp = round(pp, 2)
        print(f"{pp:.2f}")
    
    if l != T-1:
        print()

