from datetime import datetime, timedelta

n = int(input())

a = datetime(year=2024, month=8, day=30) + timedelta(days=30*7*(n-1))
print(a.year, a.month)
